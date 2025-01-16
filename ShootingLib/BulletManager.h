#pragma once
#include "Task.h"
#include "BulletBase.h"
#include <vector>

class BulletManager : public Task
{
public:
  enum class BulletKind
  {
    //弾の種類はここで管理
    kPlayer,
    kEnemy,
  };

  BulletManager();

  ~BulletManager();

  void Update(float delta_time) override;

  void Render() override;

  void InitializeBullet(int bullet_num);

  void FireBullet(BulletKind bullet_kind, float x, float y);

private:
  std::vector<BulletBase *> bullet_array_;


};