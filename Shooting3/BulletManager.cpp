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
  for (const auto &bullet_kind : { BulletKind::kPlayer, BulletKind::kEnemy })
  {
    for (auto bullet : bullet_map_[bullet_kind])
    {
      bullet->Update(delta_time);
    }
  }
}

void BulletManager::Render()
{
  for (const auto &bullet_kind : { BulletKind::kPlayer, BulletKind::kEnemy })
  {
    for (auto bullet : bullet_map_[bullet_kind])
    {
      bullet->Render();
    }
  }
}

void BulletManager::Initialize(int bullet_num)
{
  for (int i = 0; i < bullet_num; i++)
  {
    bullet_map_[BulletKind::kPlayer].emplace_back(new PlayerBullet);
  }
}

void BulletManager::AddBullet(BulletKind bullet_kind, BulletBase *bullet)
{
  bullet_map_[bullet_kind].emplace_back(bullet);
}


//XXX: 謎のエラーが出たので実装は保留
//void BulletManager::ActivateBullet(BulletKind bullet_kind)
//{
//  auto &inactive_bullet_map = inactive_bullet_map_[bullet_kind];
//
//  if (inactive_bullet_map.empty())
//  {
//    AddBullet(bullet_kind, new PlayerBullet);
//  }
//
//  auto first = inactive_bullet_map.begin();
//  (*first)->SetIsFired(false);
//  (*first)->SetIsActive(true);
//  bullet_map_[bullet_kind].emplace_back((*first));
//  inactive_bullet_map.erase(first);
//}


/// <summary>
/// 使用済みの弾を非アクティブ化し、オブジェクトプールに移動
/// </summary>
/// <param name="bullet_kind">弾の種類を指定</param>
void BulletManager::DeactiveBullet(BulletKind bullet_kind)
{
  auto &bullet_map = bullet_map_[bullet_kind];
  for (auto it = bullet_map.begin(); it != bullet_map.end();)
  {
    if (!(*it)->GetIsActive())
    {
      inactive_bullet_map_[BulletKind::kPlayer].emplace_back(*it);
      it = bullet_map.erase(it); // イテレーターを更新
    }
    else
    {
      ++it;
    }
  }
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