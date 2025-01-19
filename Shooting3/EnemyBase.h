#pragma once

class EnemyBase
{
public:
  EnemyBase();
  virtual ~EnemyBase();

  virtual void Update(float delta_time);
  virtual void Render() = 0;

  virtual void LoadImage() = 0;

  void RemoveImageHandle();

protected:
  int pos_x_;
  int pos_y_;
  int velocity_x_;
  int velocity_y_;

  bool is_dead_;

  int image_handle_;
};