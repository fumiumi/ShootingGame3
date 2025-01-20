#pragma once
#include "BulletBase.h"
#include <vector>

class EnemyBase
{
public:
  friend class EnemyManager;

  EnemyBase();

  virtual ~EnemyBase() = default;

  virtual void Update(float delta_time);

  virtual void Render();

  virtual void LoadImageHandle();

  virtual void GetBulletList(std::vector<BulletBase *> &bullet_list);

  virtual void CheckHitBullet();

  void RemoveImageHandle();

  void SetPosX(int pos_x);
  void SetPosY(int pos_y);
  // velocityはエネミー固有のものなので外部からは変更不可

  int GetPosX() const;
  int GetPosY() const;
  int GetVelocityX() const;
  int GetVelocityY() const;

  bool GetIsDead() const;
  void SetIsDead(bool is_dead);

  bool GetIsActive() const;
  void SetIsActive(bool is_active);

  void CorrectPosX();

protected:
  int pos_x_;
  int pos_y_;
  int velocity_x_;
  int velocity_y_;

  bool is_active_;

  bool is_dead_;

  int enemy_handle_;

  std::vector<BulletBase *> bullet_list_;
};
