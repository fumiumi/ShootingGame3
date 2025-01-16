#pragma once

class BulletBase
{
public:
  BulletBase();
  virtual ~BulletBase() = 0;

  /// <summary>
  /// BulletManager‚©‚çŒÄ‚Ño‚³‚ê‚é
  /// </summary>
  /// <param name="delta_time"></param>
  void Update(float delta_time);

  /// <summary>
  /// BulletManager‚©‚çŒÄ‚Ño‚³‚ê‚é
  /// </summary>
  void Render();

  /// <summary>
  /// BulletManager‚©‚çŒÄ‚Ño‚³‚ê‚é
  /// </summary>
  /// <param name="x"></param>
  /// <param name="y"></param>
  void Fire(float x, float y);

private:
  float x_;
  float y_;
  float velocity_;

  bool is_fired_;

  int bulllet_handle_;

};