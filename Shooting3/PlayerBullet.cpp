#include "PlayerBullet.h"
#include "DxLib.h"

namespace
{
const char *kPlayerBulletImageFilePath = "E:/�Q�[���J��/�N���A�J/ShootingGame3/Shooting3/Assets/Image/Battle/Bullet/PlayerBullet.png";

const int kPlayerBulletWidth = 32;
const int kPlayerBulletHeight = 32;

const int kPlayerBulletVelocity = 50;
}

PlayerBullet::PlayerBullet()
  : bullet_velocity_(kPlayerBulletVelocity)
{
}

PlayerBullet::~PlayerBullet()
{
}

void PlayerBullet::Update(float delta_time)

  // �e�̈ړ�����
  if (is_fired_)
  {
    bullet_y_ -= bullet_velocity_;
    if (bullet_y_ < 0)
    {
      is_fired_ = false;
      // �n���h���̉����BulletManager�ōs��
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

void PlayerBullet::Fire(int center_x, int center_y)
{
  bullet_x_ = center_x - kPlayerBulletWidth / 2;
  bullet_y_ = center_y - kPlayerBulletHeight / 2;
  is_fired_ = true;
}

// Load��Remove�͊��N���X�Œ�`�ς�
