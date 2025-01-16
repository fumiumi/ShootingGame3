#pragma once
#include "BulletBase.h"

class PlayerBullet : public BulletBase
{
public:
  PlayerBullet();
  ~PlayerBullet();

  void Update(float delta_time) override;

  void Render() override;

  void Fire(int center_x, int center_y) override;

  // メンバ変数は基底クラスで定義済み
};