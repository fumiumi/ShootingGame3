#include "TackleEnemy.h"
#include "DXLib.h"
#include "GameInfo.h"
#include "BulletManager.h"
#include <cmath>

class BulletBase;

namespace
{
const char *kTackleEnemyImageFilePath = "E:/ゲーム開発/クリアカ/ShootingGame3/Shooting3/Assets/Image/Battle/Enemy/TackleEnemy.png";
const int kTackleEnemyVelocity = 10;
const int kTackleEnemyWidth = 64;
const int kTackleEnemyHeight = 64;

}

TackleEnemy::TackleEnemy()
{
  // 直進しかできない木偶の坊
  velocity_x_ = 0;
  velocity_y_ = kTackleEnemyVelocity;
  SetBulletKind(BulletManager::BulletKind::kPlayer);
}

TackleEnemy::~TackleEnemy()
{
}

void TackleEnemy::Update(float delta_time)
{
  GameInfo *game_info = GameInfo::GetInstance();

  if (!is_active_ )
  {
    return;
  }

  // 前フレームで死亡していたら非アクティブにする
  if (is_dead_)
  {
    is_active_ = false;
  }

  pos_y_ += velocity_y_;

  // 弾との当たり判定を走査
  CheckHitBullet();

  // 画面外に出たら非アクティブにする
  if (pos_y_ >= game_info->GetResolutionY())
  {
    Death();
    is_active_ = false;
  }
}

void TackleEnemy::Render()
{
  if (!is_active_ )
  {
    return;
  }

  if (!is_dead_)
  {
    DrawGraph(pos_x_, pos_y_, enemy_handle_, TRUE);
  }
  else
  {
    // update()でDeath()した場合はエネミーの爆散を描画
    // エフェクトマネージャをじっそうするまでは描画しないことで代用
  }
}

void TackleEnemy::LoadImageHandle()
{
  enemy_handle_ = LoadGraph(kTackleEnemyImageFilePath);
}

void TackleEnemy::SetBulletKind(BulletManager::BulletKind bullet_kind)
{
  bullet_kind_ = bullet_kind;
}

void TackleEnemy::CheckHitBullet()
{
  if (is_dead_ || bullet_manager_ == nullptr)
  {
    return;
  }
  GameInfo *game_info = GameInfo::GetInstance();

  const std::vector<BulletBase *> &bullet_list = bullet_manager_->GetBulletList(bullet_kind_);

  // 画像には余白もあるので、半径は内接円でとる
  int radius_enemy = kTackleEnemyWidth / 2;
  int radius_bullet = game_info->GetPlayerBulletImageWidth() / 2;

  int enemy_center_x = pos_x_ + kTackleEnemyWidth / 2;
  int enemy_center_y = pos_y_ + kTackleEnemyHeight / 2;

  // 円での当たり判定
  for (auto &bullet : bullet_list)
  {
    int bullet_center_x = bullet->GetPosX() + game_info->GetPlayerBulletImageWidth() / 2;
    int bullet_center_y = bullet->GetPosY() + game_info->GetPlayerBulletImageHeight() / 2;

    int distance = static_cast<int>(
      std::pow(enemy_center_x - bullet_center_x, 2) + std::pow(enemy_center_y - bullet_center_y, 2)
    );

    if (distance <= std::pow(radius_enemy + radius_bullet, 2)) // 暗黙の型変換
    {
      // エネミーは爆破処理をするので、Deathしてもまだactiveのまま
      Death();
      bullet->SetIsActive(false);

      break;
    }
  }
}

void TackleEnemy::Death()
{
  is_dead_ = true;
}

// ハンドルの解放は基底クラスで実装済み