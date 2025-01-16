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

  ~BulletManager() = default;

  void Update(float delta_time) override;

  void Render() override;

  void InitializeBullet(int bullet_num);


  void RemoveBullet();

private:
  void FireBullet(BulletKind bullet_kind, int x, int y);

  std::vector<BulletBase *> bullets_;


};