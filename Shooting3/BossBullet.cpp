#include "BossBullet.h"
#include "DXLib.h"

namespace
{
const char *kBossBulletImageFilePath = "E:/ゲーム開発/クリアカ/ShootingGame3/Shooting3/Assets/Image/Battle/Bullet/BossEnemyBullet.png";
}

// PlayerBulletと同様、BattleLevelから間接的にアクセス
//TODO: 速度の設定
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
