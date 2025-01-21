#pragma once
#include "EnemyBase.h"
#include "BulletManager.h"
#include "BulletManager.h"

class TackleEnemy : public EnemyBase
{
public:
  TackleEnemy();

  ~TackleEnemy();

  void Update(float delta_time) override;

  void Render() override;

  void LoadImageHandle() override;

  void SetBulletKind(BulletManager::BulletKind bullet_kind) override;

  void CheckHitBullet() override;

  void Death() override;

  // ハンドルの解放は基底クラスで実装済み
};
