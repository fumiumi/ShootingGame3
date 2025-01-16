#pragma once
#include "Task.h"
#include "BulletBase.h"
#include <vector>
#include <unordered_map>

class BulletManager : public Task
{
public:
  enum class BulletKind
  {
    //íeÇÃéÌóﬁÇÕÇ±Ç±Ç≈ä«óù
    kPlayer,
    kEnemy,
  };

  BulletManager();

  ~BulletManager() = default;

  void Update(float delta_time) override;

  void Render() override;

  void Initialize(int bullet_num);


  void DeactiveBullet();

private:
  void FireBullet(BulletKind bullet_kind, int bullet_x, int bullet_y);

  using BulletContainer = std::vector<BulletBase *> ;
  std::unordered_map<BulletKind, BulletContainer> bullet_map_;
  std::unordered_map<BulletKind, BulletContainer> inactive_bullet_map_;

};