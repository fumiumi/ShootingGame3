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
}

void TackleEnemy::Render()
{
}

void TackleEnemy::LoadImage()
{
  image_handle_ = LoadGraph(kTackleEnemyImageFilePath);
}
