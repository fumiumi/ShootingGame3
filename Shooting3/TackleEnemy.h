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

  void GetBulletManager(BulletManager *bullet_manager);

  void CheckHitBullet() override;

  // ハンドルの解放は基底クラスで実装済み

private:
  BulletManager *bullet_manager_;
};
