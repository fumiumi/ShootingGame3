#pragma once
#include "BulletBase.h"

class BossBullet : public BulletBase
{
public:
  BossBullet();
  ~BossBullet();
  void Update(float delta_time) override;
  void Render() override;
  void Fire(int bullet_x, int bullet_y) override;
  void LoadImageHandle() override;
  // �����o�ϐ��͊��N���X�Œ�`�ς�
};