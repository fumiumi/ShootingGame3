#pragma once


class BulletBase
{
public:
  BulletBase();
  virtual ~BulletBase() = default;

  /// <summary>
  /// BulletManager‚©‚çŒÄ‚Ño‚³‚ê‚é
  /// </summary>
  /// <param name="delta_time"></param>
  virtual void Update(float delta_time);

  /// <summary>
  /// BulletManager‚©‚çŒÄ‚Ño‚³‚ê‚é
  /// </summary>
  virtual void Render() = 0;

  /// <summary>
  /// BulletManager‚©‚çŒÄ‚Ño‚³‚ê‚é
  /// </summary>
  /// <param name="x"></param>
  /// <param name="y"></param>
  virtual void Fire(int bullet_x, int bullet_y) = 0;

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
