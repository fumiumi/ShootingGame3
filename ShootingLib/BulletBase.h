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
  virtual void Render() = 0;

  /// <summary>
  /// BulletManagerから呼び出される
  /// </summary>
  /// <param name="x"></param>
  /// <param name="y"></param>
  virtual void Fire(int bullet_x, int bullet_y) = 0;

  int GetX() const;

  int GetY() const;

  // 速度は初期化時に固定値を設定する
  //virtual void SetVelocity(int bullet_velocity);

  int GetVelocity() const;

  void SetIsFired(bool is_fired);

  bool GetIsFired() const;

  virtual void LoadImageHandle() = 0;

  void RemoveImageHandle();

protected:
  int bullet_x_;
  int bullet_y_;
  int bullet_velocity_;

  bool is_fired_;

  bool is_active_;

  int bullet_handle_;

};