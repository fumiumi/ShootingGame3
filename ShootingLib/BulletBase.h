#pragma once

class BulletBase
{
public:
  BulletBase();

  virtual ~BulletBase() = default;

  /// <summary>
  /// BulletManagerから呼び出される
  /// </summary>
  /// <param name="delta_time"></param>
  virtual void Update(float delta_time);

  /// <summary>
  /// BulletManagerから呼び出される
  /// </summary>
  virtual void Render();

  /// <summary>
  /// BulletManagerから呼び出される
  /// </summary>
  /// <param name="x"></param>
  /// <param name="y"></param>
  virtual void Fire(int bullet_x, int bullet_y);

  virtual void LoadImageHandle();

  void RemoveImageHandle();

  void SetPosX(int bullet_x);
  void SetPosY(int bullet_y);
  void SetVelocity(int bullet_velocity);

  int GetPosX() const;
  int GetPosY() const;
  int GetVelocity() const;

  void SetIsFired(bool is_fired);
  void SetIsActive(bool is_active);

  bool GetIsFired() const;
  bool GetIsActive() const;


protected:
  int bullet_x_;
  int bullet_y_;
  int bullet_velocity_;

  bool is_fired_;

  bool is_active_;

  int bullet_handle_;
};
