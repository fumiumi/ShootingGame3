#pragma once

class BulletBase
{
public:
  BulletBase();
  virtual ~BulletBase() = 0;

  /// <summary>
  /// BulletManagerから呼び出される
  /// </summary>
  /// <param name="delta_time"></param>
  void Update(float delta_time);

  /// <summary>
  /// BulletManagerから呼び出される
  /// </summary>
  void Render();

  /// <summary>
  /// BulletManagerから呼び出される
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