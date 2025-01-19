#include "EnemyManager.h"
#include "TackleEnemy.h"
#include "BossEnemy.h"

namespace
{
const int kInitialEnemyNum = 30;
}

EnemyManager::EnemyManager() 
{
  Initialize(kInitialEnemyNum);
}

void EnemyManager::Update(float delta_time)
{
  for (auto enemy : enemy_list_)
  {
    enemy->Update(delta_time);
  }

  boss_enemy->Update(delta_time);
}

void EnemyManager::Render()
{
  for (auto enemy : enemy_list_)
  {
    enemy->Render();
  }
  boss_enemy->Render();
}

void EnemyManager::Initialize(int enemy_num)
{
  for (int i = 0; i < enemy_num; i++)
  {
    enemy_list_.emplace_back(new TackleEnemy);
  }
  boss_enemy = new BossEnemy;
}