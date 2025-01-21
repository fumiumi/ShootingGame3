#pragma once

#include "Task.h"
#include "EnemyBase.h"
#include <vector>

struct EnemyPattern
{
  int elapsed_time;
  int enemy_num;
};

class EnemyManager : public Task
{
public:
  EnemyManager();
  ~EnemyManager() = default;

  void Update(float delta_time) override;
  void Render() override;

  void Initialize(int enemy_num);

  void AddEnemy(EnemyBase *enemy);

  void AddBulletManagerToEnemy(BulletManager *bullet_manager);
  
  void Destroy();

  void LoadEnemyImageHandle();

  const std::vector<EnemyBase *> &GetEnemyList() const;
  EnemyBase *GetBossEnemy() const;

private:
  std::vector<EnemyBase *> enemy_list_;
  EnemyBase *boss_enemy_;

  float play_time_;
  float last_enemy_apper_time_;

  int level_step_;

};