#pragma once

class BulletBase
{
public:
  BulletBase();
  virtual ~BulletBase() = default;

  /// <summary>
  /// BulletManager����Ăяo�����
  /// </summary>
  /// <param name="delta_time"></param>
  virtual void Update(float delta_time);

  /// <summary>
  /// BulletManager����Ăяo�����
  /// </summary>
  virtual void Render() = 0;

  /// <summary>
  /// BulletManager����Ăяo�����
  /// </summary>
  /// <param name="x"></param>
  /// <param name="y"></param>
  virtual void Fire(int bullet_x, int bullet_y) = 0;

  int GetX() const;

  int GetY() const;

  // ���x�͏��������ɌŒ�l��ݒ肷��
  //virtual void SetVelocity(int bullet_velocity);

  int GetVelocity() const;

  bool GetIsFired() const;

  void SetIsFired(bool is_fired);

  bool GetIsActive() const;

  void SetIsActive(bool is_active);

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