#pragma once

class BulletBase
{
public:
  BulletBase();
  virtual ~BulletBase();

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

  void SetX(int bullet_x);

  void SetY(int bullet_y);

  int GetX() const;

  int GetY() const;

  virtual void SetVelocity(int bullet_velocity);

  int GetVelocity() const;

  void SetIsFired(bool is_fired);

  bool GetIsFired() const;

  void LoadImageHandle(const char *file_path);

  void RemoveImageHandle();

protected:
  int bullet_x_;
  int bullet_y_;
  int bullet_velocity_;

  bool is_fired_;

  int bullet_handle_;

};