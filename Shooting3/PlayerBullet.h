#pragma once
#include "BulletBase.h"

class PlayerBullet : public BulletBase
{
public:
  PlayerBullet();
  ~PlayerBullet();

  void Update(float delta_time) override;

  void Render() override;

  void Fire(int x, int y) override;

};