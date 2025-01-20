#include "TackleEnemy.h"
#include "DXLib.h"
#include "GameInfo.h"

namespace
{
const char *kTackleEnemyImageFilePath = "E:/ゲーム開発/クリアカ/ShootingGame3/Shooting3/Assets/Image/Battle/Enemy/TackleEnemy.png";
const int kTackleEnemyVelocity = 10;


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

// ハンドルの解放は基底クラスで実装済み