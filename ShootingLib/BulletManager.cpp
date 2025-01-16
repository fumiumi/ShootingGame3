#include "BulletManager.h"
#include "DxLib.h"
#include "PlayerBullet.h"
#include <vector>
#include <unordered_map>


namespace
{
const int kInitialBulletNum = 30;
}

BulletManager::BulletManager()
{
  Initialize(kInitialBulletNum);
}

void BulletManager::Update(float delta_time)
{
  for (auto bullet : bullet_map_[BulletKind::kPlayer])
  {
    bullet->Update(delta_time);
  }
  for (auto bullet : bullet_map_[BulletKind::kEnemy])
  {
    bullet->Update(delta_time);
}

void BulletManager::Render()
{
  for (auto bullet : bullet_map_[BulletKind::kPlayer])
  {
    bullet->Render();
  }
  for (auto bullet : bullet_map_[BulletKind::kEnemy])
  {
    bullet->Render();
  }
}

void BulletManager::Initialize(int bullet_num)
{
  for (int i = 0; i < bullet_num; i++)
  {
    bullet_map_[BulletKind::kPlayer].emplace(new PlayerBullet);
  }
}

void BulletManager::DeactiveBullet()
{

}

void BulletManager::FireBullet(BulletKind bullet_kind, int bullet_x, int bullet_y)
{
  if (bullet_map_[bullet_kind].empty())
  {
    return;
  }

  for (auto bullet : bullet_map_[bullet_kind])
  {
    if (!bullet->GetIsFired())
    {
      bullet->Fire(bullet_x, bullet_y);
      return;
    }
  }
}