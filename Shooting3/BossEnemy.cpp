#include "BossEnemy.h"
#include "DXLib.h"

namespace
{
const char *kBossEnemyImageFilePath = "E:/ゲーム開発/クリアカ/ShootingGame3/Shooting3/Assets/Image/Battle/Enemy/BossEnemy.png";
}

//TODO: 座標、速度の設定
BossEnemy::BossEnemy()
{
}

BossEnemy::~BossEnemy()
{
}

void BossEnemy::Update(float delta_time)
{
}

void BossEnemy::Render()
{
}

void BossEnemy::LoadImage()
{
  enemy_handle = LoadGraph(kBossEnemyImageFilePath);
}
