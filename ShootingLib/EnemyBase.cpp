#include "EnemyBase.h"
#include "DXLib.h"

EnemyBase::EnemyBase()
  : pos_x_(0),
    pos_y_(0),
    velocity_x_(0),
    velocity_y_(0),
    is_dead_(false),
    image_handle_(0)
{
}

EnemyBase::~EnemyBase()
{
}

void EnemyBase::Update(float delta_time)
{
}

void EnemyBase::RemoveImageHandle()
{
  if (image_handle_ != 0)
  {
    DeleteGraph(image_handle_);
    image_handle_ = 0;
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