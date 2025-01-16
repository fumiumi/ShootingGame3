#include "BulletManager.h"
#include "DxLib.h"

namespace
{
const int kInitialBulletNum = 30;
}

BulletManager::BulletManager()
{
  InitializeBullet(kInitialBulletNum);
}

void BulletManager::Update(float delta_time)
{
  for (auto bullet : bullets_)
  {
    bullet->Update(delta_time);
  }
}

void BulletManager::Render()
{
  for (auto bullet : bullets_)
  {
    bullet->Render();
  }
}

