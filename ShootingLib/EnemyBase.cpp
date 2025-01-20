#include "EnemyBase.h"
#include "DXLib.h"
#include "GameInfo.h"

EnemyBase::EnemyBase()
  : pos_x_(0),
    pos_y_(0),
    velocity_x_(0),
    velocity_y_(0),
    is_dead_(true),
    is_active_(false),
    enemy_handle_(0)
{
}

void EnemyBase::Update(float delta_time)
{
}

void EnemyBase::Render()
{
}

void EnemyBase::LoadImageHandle()
{
}

void EnemyBase::GetBulletList(std::vector<BulletBase *> &bullet_list)
{
}

void EnemyBase::CheckHitBullet()
{
}

void EnemyBase::RemoveImageHandle()
{
  if (enemy_handle_ != 0)
  {
    DeleteGraph(enemy_handle_);
    enemy_handle_ = 0;
  }
}

void EnemyBase::SetPosX(int pos_x)
{
  pos_x_ = pos_x;
}

void EnemyBase::SetPosY(int pos_y)
{
  pos_y_ = pos_y;
}

int EnemyBase::GetPosX() const
{
  return pos_x_;
}

int EnemyBase::GetPosY() const
{
  return pos_y_;
}

int EnemyBase::GetVelocityX() const
{
  return velocity_x_;
}

int EnemyBase::GetVelocityY() const
{
  return velocity_y_;
}

bool EnemyBase::GetIsActive() const
{
  return is_active_;
}

void EnemyBase::SetIsActive(bool is_active)
{
  is_active_ = is_active;
}

bool EnemyBase::GetIsDead() const
{
  return is_dead_;
}

void EnemyBase::SetIsDead(bool is_dead)
{
  is_dead_ = is_dead;
}

void EnemyBase::CorrectPosX()
{
  GameInfo *game_info = GameInfo::GetInstance();

  if (pos_x_ <= game_info->GetMinPosX())
  {
    pos_x_ = game_info->GetMinPosX();
  }
  else if (pos_x_ >= game_info->GetMaxPosX())
  {
    pos_x_ = game_info->GetMaxPosX() - game_info->GetTackleEnemyImageWidth();
  }
}