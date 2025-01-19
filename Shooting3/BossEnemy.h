#pragma once
#include "EnemyBase.h"

class BossEnemy : public EnemyBase
{
public:
  BossEnemy();
  ~BossEnemy();
  void Update(float delta_time) override;
  void Render() override;
  void LoadImage() override;
};