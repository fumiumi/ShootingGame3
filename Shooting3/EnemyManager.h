#pragma once

#include "Task.h"
#include "EnemyBase.h"
#include <vector>

class EnemyManager : public Task
{
public:
  EnemyManager();
  ~EnemyManager() = default;

  void Update(float delta_time) override;
  void Render() override;

  void Initialize(int enemy_num);

  void AddEnemy(EnemyBase *enemy);
  void RemoveEnemy(EnemyBase *enemy);

  void LoadEnemyImageHandle();

private:
  std::vector<EnemyBase *> enemy_list_;
  EnemyBase *boss_enemy;
};