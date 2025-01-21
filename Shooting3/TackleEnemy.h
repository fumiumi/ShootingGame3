#pragma once
#include "EnemyBase.h"
#include "BulletManager.h"

class TackleEnemy : public EnemyBase
{
public:
  TackleEnemy();

  ~TackleEnemy();

  void Update(float delta_time) override;

  void Render() override;

  void LoadImageHandle() override;

  void GetBulletList(std::vector<BulletBase *> &bullet_list) override;

  void CheckHitBullet() override;

  // ハンドルの解放は基底クラスで実装済み
};
