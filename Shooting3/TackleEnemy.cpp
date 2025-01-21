#include "TackleEnemy.h"
#include "DXLib.h"
#include "GameInfo.h"
#include "BulletManager.h"
#include <cmath>

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
}

TackleEnemy::~TackleEnemy()
{
}

void TackleEnemy::Update(float delta_time)
{
  GameInfo *game_info = GameInfo::GetInstance();

  if (is_dead_)
  {
    return;
  }

  pos_y_ += velocity_y_;

  if (pos_y_ >= game_info->GetResolutionY())
  {
    is_dead_ = true;
    is_active_ = false;
  }
}

void TackleEnemy::Render()
{
  if (is_dead_)
  {
    return;
  }

  DrawGraph(pos_x_, pos_y_, enemy_handle_, TRUE);
}

void TackleEnemy::LoadImageHandle()
{
  enemy_handle_ = LoadGraph(kTackleEnemyImageFilePath);
}

void SetBulletList(std::vector<BulletBase *> &bullet_list)
{
  bullet_list_ = bullet_list;
}

void TackleEnemy::GetBulletList(std::vector<BulletBase *> &bullet_list)
{
  bullet_list = bullet_list_;
}

void TackleEnemy::CheckHitBullet()
{
  if (is_dead_ || bullet_manager_ == nullptr)
  {
    return;
  }
  GameInfo *game_info = GameInfo::GetInstance();

  // 画像には余白もあるので、半径は内接円でとる
  int radius_enemy = kTackleEnemyWidth / 2;
  int radius_bullet = game_info->GetPlayerBulletImageWidth() / 2;

  int enemy_center_x = pos_x_ + kTackleEnemyWidth / 2;
  int enemy_center_y = pos_y_ + kTackleEnemyHeight / 2;

  // 円での当たり判定
  for (auto &bullet : bullet_list_)
  {
    int bullet_center_x = bullet->GetPosX() + game_info->GetPlayerBulletImageWidth() / 2;
    int bullet_center_y = bullet->GetPosY() + game_info->GetPlayerBulletImageHeight() / 2;

    int distance = std::pow(enemy_center_x - bullet_center_x, 2) + std::pow(enemy_center_y - bullet_center_y, 2);

    if (distance <= std::pow(radius_enemy + radius_bullet, 2)) // 暗黙の型変換
    {
      is_dead_ = true;
      is_active_ = false;
      bullet->SetIsActive(false);

      break;
    }
  }
}



// ハンドルの解放は基底クラスで実装済み