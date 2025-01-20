#include "BulletManager.h"
#include "DxLib.h"
#include <vector>

namespace
{
const int kInitialPlayerBulletNum = 30;
const int kInitialEnemyBulletNum = 30;
}

BulletManager::BulletManager()
{
  Initialize(kInitialPlayerBulletNum, kInitialEnemyBulletNum);
}

void BulletManager::Update(float delta_time)
{
  for (const auto &bullet_kind : { BulletKind::kPlayer, BulletKind::kEnemy })
  {
    auto &bullets = bullet_list_map_[bullet_kind];
    for (auto &bullet : bullets)
    {
      bullets.Update(delta_time);
    }
  }
}

void BulletManager::Render()
{
  for (const auto &bullet_kind : { BulletKind::kPlayer, BulletKind::kEnemy })
  {
    auto &bullets = bullet_list_map_[bullet_kind];
    for (auto &bullet : bullets)
    {
      bullet.Render();
    }
  }
}

void BulletManager::Initialize(int player_bullet_num, int enemy_bullet_num)
{
  for (int i = 0; i < player_bullet_num; i++)
  {
    AddBullet(BulletKind::kPlayer, new BulletBase);
  }
  for (int i = 0; i < enemy_bullet_num; i++)
  {
    AddBullet(BulletKind::kEnemy, new BulletBase);
  }
}

void BulletManager::FireBullet(BulletKind bullet_kind, int bullet_x, int bullet_y)
{
  if (bullet_list_map_[bullet_kind].empty())
  {
    return;
  }

  auto &bullets = bullet_list_map_[bullet_kind];
  for (auto &bullet : bullets)
  {
    if (!bullet.GetIsFired())
    {
      bullet.Fire(bullet_x, bullet_y);
      return;
    }
  }
}

void BulletManager::AddBullet(BulletKind bullet_kind, BulletBase *bullet)
{
  bullet_list_map_[bullet_kind].emplace_back(bullet);
}

void BulletManager::Destroy()
{
  for (const auto &bullet_kind : { BulletKind::kPlayer, BulletKind::kEnemy })
  {
    bullet_list_map_[bullet_kind].clear();
  }
}

void BulletManager::LoadBulletImageHandle()
{
  for (const auto &bullet_kind : { BulletKind::kPlayer, BulletKind::kEnemy }) 
  {
    auto &bullets = bullet_list_map_[bullet_kind];

    for (auto &bullet : bullets) 
    {
      bullet.LoadImageHandle();
    }
  }
}
