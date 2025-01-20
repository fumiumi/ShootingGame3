#pragma once

class EnemyBase
{
public:
  EnemyBase();

  virtual ~EnemyBase() = default;

  virtual void Update(float delta_time);

  virtual void Render();

  virtual void LoadImageHandle();

  void RemoveImageHandle();

  void SetPosX(int pos_x);
  void SetPosY(int pos_y);
  // velocityはエネミー固有のものなので外部からは変更不可

  int GetPosX() const;
  int GetPosY() const;
  int GetVelocityX() const;
  int GetVelocityY() const;

protected:
  int pos_x_;
  int pos_y_;
  int velocity_x_;
  int velocity_y_;

  bool is_dead_;

  int enemy_handle_;
};
