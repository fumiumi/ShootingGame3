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
  for (bullet_kind : BulletKind)
  {
    for (auto bullet : bullet_map_[bullet_kind])
    {
      bullet->Update(delta_time);
    }
  }
}

void BulletManager::Render()
{
  for (bullet_kind : BulletKind)
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
    bullet_map_[BulletKind::kPlayer].emplace(new PlayerBullet);
  }
}

/// <summary>
/// �g�p�ς݂̒e���A�N�e�B�u�����A�I�u�W�F�N�g�v�[���Ɉړ�
/// </summary>
/// <param name="bullet_kind">�e�̎�ނ��w��</param>
void BulletManager::DeactiveBullet(BulletKind bullet_kind)
{
  auto &playerBullets = bullet_map_[bullet_kind];
  for (auto it = playerBullets.begin(); it != playerBullets.end(); )
  {
    if (!(*it)->GetIsActive())
    {
      inactive_bullet_map_[BulletKind::kPlayer].emplace_back(*it);
      it = playerBullets.erase(it); // �C�e���[�^�[���X�V
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