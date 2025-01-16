#include "PlayerBullet.h"
#include "DxLib.h"
#include "InputManager.h"

namespace
{
const char *kPlayerBulletImageFilePath = "E:/�Q�[���J��/�N���A�J/ShootingGame3/Shooting3/Assets/Image/Battle/Bullet/PlayerBullet.png";

const int kPlayerBulletWidth = 32;
const int kPlayerBulletHeight = 32;

const int kPlayerBulletVelocity = 50;
}

PlayerBullet::PlayerBullet()
{
  bullet_velocity_ = kPlayerBulletVelocity;
}

PlayerBullet::~PlayerBullet()
{
}

void PlayerBullet::Update(float delta_time)
{
  // �e�̈ړ�����
  if (is_fired_)
  {
    bullet_y_ -= bullet_velocity_;

    if (bullet_y_ < 0)
    {
      is_fired_ = false;
      is_active_ = false;
      // �n���h���̉����BulletManager�ōs��
    }
  }
}

void PlayerBullet::Render()
{
  if (is_fired_ && bullet_handle_ != 0)
  {
    DrawGraph(bullet_x_, bullet_y_, bullet_handle_, TRUE);
  }
}

// BulletManager����Ăяo�����
void PlayerBullet::Fire(int bullet_x, int bullet_y)
{
  if (!is_fired_)
  {  
  bullet_x_ = bullet_x - kPlayerBulletWidth / 2;
  // �O�̈�+ bullet_velocity_
  bullet_y_ = bullet_y - kPlayerBulletHeight / 2 + bullet_velocity_;
  is_fired_ = true;
  }
}

void PlayerBullet::LoadImageHandle()
{
  bullet_handle_ = LoadGraph(kPlayerBulletImageFilePath);
}

// RemoveImageHandle()�͋���
