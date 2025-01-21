#pragma once
#include "BulletBase.h"
#include "BulletManager.h"
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

  virtual void CheckHitBullet();
  
  virtual void SetBulletKind(BulletManager::BulletKind bullet_kind);

  void RemoveImageHandle();

  void SetBulletManager(BulletManager *bullet_manager);


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

  BulletManager *bullet_manager_;
  BulletManager::BulletKind bullet_kind_;
};
