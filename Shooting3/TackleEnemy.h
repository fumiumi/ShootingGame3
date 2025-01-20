#pragma once
#include "EnemyBase.h"

class TackleEnemy : public EnemyBase
{
public:
  TackleEnemy();
  ~TackleEnemy();
  void Update(float delta_time) override;
  void Render() override;
  void LoadImageHandle() override;
  // ハンドルの解放は基底クラスで実装済み
};
