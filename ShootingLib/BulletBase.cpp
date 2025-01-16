#include "DxLib.h"
#include "BulletBase.h"
#include "GameInfo.h"

// äÓíÍÉNÉâÉXë§Ç≈Ç‡Ç§ÉÅÉìÉoïœêîÇèâä˙âªÇµÇƒÇ®Ç≠
BulletBase::BulletBase()
  : bullet_x_(0),
    bullet_y_(0),
    bullet_velocity_(0),
    is_fired_(false),
    bullet_handle_(0)
{
}

BulletBase::~BulletBase()
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

void BulletBase::SetX(int bullet_x)
{
  GameInfo *game_info = GameInfo::GetInstance();

  if (bullet_x < 0)
  {
    bullet_x_ = 0;
  }
  else if (bullet_x > game_info->GetResolutionX())
  {
    bullet_x_ = game_info->GetResolutionX();
  }
  else
  {
    bullet_x_ = bullet_x;
  }
}

void BulletBase::SetY(int bullet_y)
{
  GameInfo *game_info = GameInfo::GetInstance();

  if (bullet_y < 0)
  {
    bullet_y_ = 0;
  }
  else if (bullet_y > game_info->GetResolutionY())
  {
    bullet_y_ = game_info->GetResolutionY();
  }
  else
  {
    bullet_y_ = bullet_y;
  }
}

int BulletBase::GetX() const
{
  return bullet_x_;
}

int BulletBase::GetY() const
{
  return bullet_y_;
}

void BulletBase::SetVelocity(int bullet_velocity)
{
  bullet_velocity_ = bullet_velocity;
}

int BulletBase::GetVelocity() const
{
  return bullet_velocity_;
}

void BulletBase::SetIsFired(bool is_fired)
{
  is_fired_ = is_fired;
}

bool BulletBase::GetIsFired() const
{
  return is_fired_;
}

void BulletBase::LoadImageHandle(const char *file_path)
{
  bullet_handle_ = LoadGraph(file_path);
}

void BulletBase::RemoveImageHandle()
{
  DeleteGraph(bullet_handle_);
}