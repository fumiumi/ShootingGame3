#include "DxLib.h"
#include "BulletBase.h"
#include "GameInfo.h"

// Šî’êƒNƒ‰ƒX‘¤‚Å‚à‚¤ƒƒ“ƒo•Ï”‚ğ‰Šú‰»‚µ‚Ä‚¨‚­
BulletBase::BulletBase()
  : bullet_x_(0),
  bullet_y_(0),
  bullet_velocity_(0),
  is_fired_(false),
  is_active_(true),
  bullet_handle_(0)
{
}

void BulletBase::Update(float delta_time)
{
}

void BulletBase::Render()
{
}

void BulletBase::Fire(int bullet_x, int bullet_y)
{
}

void BulletBase::LoadImageHandle()
{
}

void BulletBase::RemoveImageHandle()
{
  DeleteGraph(bullet_handle_);
  bullet_handle_ = 0;
}

void BulletBase::SetPosX(int bullet_x)
{
  bullet_x_ = bullet_x;
}

void BulletBase::SetPosY(int bullet_y)
{
  bullet_y_ = bullet_y;
}

void BulletBase::SetVelocity(int bullet_velocity)
{
  bullet_velocity_ = bullet_velocity;
}

int BulletBase::GetPosX() const
{
  return bullet_x_;
}

int BulletBase::GetPosY() const
{
  return bullet_y_;
}

int BulletBase::GetVelocity() const
{
  return bullet_velocity_;
}

void BulletBase::SetIsFired(bool is_fired)
{
  is_fired_ = is_fired;
}

void BulletBase::SetIsActive(bool is_active)
{
  is_active_ = is_active;
}

bool BulletBase::GetIsFired() const
{
  return is_fired_;
}

bool BulletBase::GetIsActive() const
{
  return is_active_;
}