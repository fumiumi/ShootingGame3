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
    //弾の種類はここで管理
    kPlayer,
    kEnemy,
  };

  BulletManager();
  ~BulletManager() = default;

  void Update(float delta_time) override;
  void Render() override;
  
  void Initialize(int player_bullet_num, int enemy_bullet_num);

  void FireBullet(BulletKind bullet_kind, int bullet_x, int bullet_y);

  void AddBullet(BulletKind bullet_kind, BulletBase *bullet);

  void Destroy();

  void LoadBulletImageHandle();

private:
  using BulletList = std::vector<BulletBase *>;
  std::unordered_map<BulletKind, BulletList> bullet_list_map_;

};