#include "TackleEnemy.h"
#include "DXLib.h"
#include "GameInfo.h"
#include "BulletManager.h"
#include <cmath>

class BulletBase;

namespace
{
const char *kTackleEnemyImageFilePath = "E:/�Q�[���J��/�N���A�J/ShootingGame3/Shooting3/Assets/Image/Battle/Enemy/TackleEnemy.png";
const int kTackleEnemyVelocity = 10;
const int kTackleEnemyWidth = 64;
const int kTackleEnemyHeight = 64;

}

TackleEnemy::TackleEnemy()
{
  // ���i�����ł��Ȃ��؋�̖V
  velocity_x_ = 0;
  velocity_y_ = kTackleEnemyVelocity;
  SetBulletKind(BulletManager::BulletKind::kPlayer);
}

TackleEnemy::~TackleEnemy()
{
}

void TackleEnemy::Update(float delta_time)
{
  GameInfo *game_info = GameInfo::GetInstance();

  if (!is_active_ )
  {
    return;
  }

  // �O�t���[���Ŏ��S���Ă������A�N�e�B�u�ɂ���
  if (is_dead_)
  {
    is_active_ = false;
  }

  pos_y_ += velocity_y_;

  // �e�Ƃ̓����蔻��𑖍�
  CheckHitBullet();

  // ��ʊO�ɏo�����A�N�e�B�u�ɂ���
  if (pos_y_ >= game_info->GetResolutionY())
  {
    Death();
    is_active_ = false;
  }
}

void TackleEnemy::Render()
{
  if (!is_active_ )
  {
    return;
  }

  if (!is_dead_)
  {
    DrawGraph(pos_x_, pos_y_, enemy_handle_, TRUE);
  }
  else
  {
    // update()��Death()�����ꍇ�̓G�l�~�[�̔��U��`��
    // �G�t�F�N�g�}�l�[�W����������������܂ł͕`�悵�Ȃ����Ƃő�p
  }
}

void TackleEnemy::LoadImageHandle()
{
  enemy_handle_ = LoadGraph(kTackleEnemyImageFilePath);
}

void TackleEnemy::SetBulletKind(BulletManager::BulletKind bullet_kind)
{
  bullet_kind_ = bullet_kind;
}

void TackleEnemy::CheckHitBullet()
{
  if (is_dead_ || bullet_manager_ == nullptr)
  {
    return;
  }
  GameInfo *game_info = GameInfo::GetInstance();

  const std::vector<BulletBase *> &bullet_list = bullet_manager_->GetBulletList(bullet_kind_);

  // �摜�ɂ͗]��������̂ŁA���a�͓��ډ~�łƂ�
  int radius_enemy = kTackleEnemyWidth / 2;
  int radius_bullet = game_info->GetPlayerBulletImageWidth() / 2;

  int enemy_center_x = pos_x_ + kTackleEnemyWidth / 2;
  int enemy_center_y = pos_y_ + kTackleEnemyHeight / 2;

  // �~�ł̓����蔻��
  for (auto &bullet : bullet_list)
  {
    int bullet_center_x = bullet->GetPosX() + game_info->GetPlayerBulletImageWidth() / 2;
    int bullet_center_y = bullet->GetPosY() + game_info->GetPlayerBulletImageHeight() / 2;

    int distance = static_cast<int>(
      std::pow(enemy_center_x - bullet_center_x, 2) + std::pow(enemy_center_y - bullet_center_y, 2)
    );

    if (distance <= std::pow(radius_enemy + radius_bullet, 2)) // �Öق̌^�ϊ�
    {
      // �G�l�~�[�͔��j����������̂ŁADeath���Ă��܂�active�̂܂�
      Death();
      bullet->SetIsActive(false);

      break;
    }
  }
}

void TackleEnemy::Death()
{
  is_dead_ = true;
}

// �n���h���̉���͊��N���X�Ŏ����ς�