#include "BossEnemy.h"
#include "DXLib.h"

namespace
{
const char *kBossEnemyImageFilePath = "E:/�Q�[���J��/�N���A�J/ShootingGame3/Shooting3/Assets/Image/Battle/Enemy/BossEnemy.png";
}

//TODO: ���W�A���x�̐ݒ�
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
  image_handle_ = LoadGraph(kBossEnemyImageFilePath);
}
