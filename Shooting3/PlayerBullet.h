#pragma once
#include "BulletBase.h"

class PlayerBullet : public BulletBase
{
public:
  PlayerBullet();
  ~PlayerBullet();

  void Update(float delta_time) override;

  void Render() override;

  void Fire(int bullet_x, int bullet_y) override;

  void LoadImageHandle() override;

  // メンバ変数は基底クラスで定義済み
};