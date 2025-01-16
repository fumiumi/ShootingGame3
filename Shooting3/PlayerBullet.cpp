#include "PlayerBullet.h"
#include "DxLib.h"

PlayerBullet::PlayerBullet()
{
}

PlayerBullet::~PlayerBullet()
{
}

void PlayerBullet::Update(float delta_time)
{
  // 弾の移動処理
  if (is_fired_)
  {
    bullet_y_ -= bullet_velocity_;
    if (bullet_y_ < 0)
    {
      is_fired_ = false;
      // ハンドルの解放はBulletManagerで行う
    }
  }
}

void PlayerBullet::Render()
{
  if (is_fired_ && bullet_handle != 0)
  {
    DrawGraph(bullet_x_, bullet_y_, bullet_handle_, TRUE);
  }
}

void PlayerBullet::Fire(int x, int y)
{
  bullet_x_ = x;
  bullet_y_ = y;
  is_fired_ = true;
}