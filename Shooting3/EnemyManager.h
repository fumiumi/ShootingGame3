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
  
  void Destroy();

  void LoadEnemyImageHandle();

  std::vector<EnemyBase *> &GetEnemyList() { return enemy_list_; }

private:
  std::vector<EnemyBase *> enemy_list_;
  EnemyBase *boss_enemy_;

  float play_time_;
  float last_enemy_apper_time_;

  int level_step_;

};