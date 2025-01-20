#include "EnemyManager.h"
#include "TackleEnemy.h"
#include "BossEnemy.h"

namespace
{
const int kInitialEnemyNum = 50;
const float kFirstEnemyAppearTimeSec = 5;
const float kSecondEnemyAppearTimeSec = 10;
const float kThirdEnemyAppearTimeSec = 15;
const float kFourthEnemyAppearTimeSec = 20;
}

EnemyManager::EnemyManager() 
{
  Initialize(kInitialEnemyNum);
}

// TaskManager‚©‚çŒÄ‚Ño‚³‚ê‚é
void EnemyManager::Update(float delta_time)
{
  plaly_time_ += delta_time;

  for (auto enemy : enemy_list_)
  {
    enemy->Update(delta_time);
  }

  boss_enemy->Update(delta_time);
}

// TaskManager‚©‚çŒÄ‚Ño‚³‚ê‚é
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

void EnemyManager::AddEnemy(EnemyBase *enemy)
{
  if (dynamic_cast<BossEnemy *>(enemy) != nullptr)
  {
    return;
  }
  else
  {
    enemy_list_.emplace_back(enemy);
  }
}

void EnemyManager::Destroy()
{
  enemy_list_.clear();
  delete boss_enemy;
}

void EnemyManager::LoadEnemyImageHandle()
{
  for (auto enemy : enemy_list_)
  {
    enemy->LoadImage();
  }
  boss_enemy->LoadImage();
}