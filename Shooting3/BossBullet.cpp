#include "BossBullet.h"
#include "DXLib.h"

namespace
{
const char *kBossBulletImageFilePath = "E:/�Q�[���J��/�N���A�J/ShootingGame3/Shooting3/Assets/Image/Battle/Bullet/BossEnemyBullet.png";
}

// PlayerBullet�Ɠ��l�ABattleLevel����ԐړI�ɃA�N�Z�X
//TODO: ���x�̐ݒ�
BossBullet::BossBullet()
{
}

BossBullet::~BossBullet()
{
}

void BossBullet::Update(float delta_time)
{
}

void BossBullet::Render()
{
}

void BossBullet::Fire(int bullet_x, int bullet_y)
{
}

void BossBullet::LoadImageHandle()
{
  bullet_handle_ = LoadGraph(kBossBulletImageFilePath);
}
