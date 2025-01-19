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

void EnemyBase::Render()
{
}

void EnemyBase::LoadImage()
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
