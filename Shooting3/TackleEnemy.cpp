#include "TackleEnemy.h"
#include "DXLib.h"

namespace
{
const char *kTackleEnemyImageFilePath = "E:/ゲーム開発/クリアカ/ShootingGame3/Shooting3/Assets/Image/Battle/Enemy/TackleEnemy.png";
}

TackleEnemy::TackleEnemy()
{
}

TackleEnemy::~TackleEnemy()
{
}

void TackleEnemy::Update(float delta_time)
{
  if (pos_y >= 720)
  {
    is_dead_ = true;
  }
}

void TackleEnemy::Render()
{
  DrawGraph(pos_x_, pos_y_, image_handle_, TRUE);
}

void TackleEnemy::LoadImage()
{
  image_handle_ = LoadGraph(kTackleEnemyImageFilePath);
}
