#include "EnemyManager.h"
#include "TackleEnemy.h"
#include "BossEnemy.h"
#include "GameInfo.h"
#include "DXLib.h"
#include <vector>
#include <random>

namespace
{
const int kInitialEnemyNum = 50;

/// <summary>
/// １体
/// </summary>
EnemyPattern kEnemyPattern1st = { 5, 1 };
/// <summary>
/// 3体横並び
/// </summary>
EnemyPattern kEnemyPattern2nd = { 5, 3 };
/// <summary>
/// 縦に5体
/// </summary>
EnemyPattern kEnemyPattern3rd = { 5, 5 };
/// <summary>
/// 縦に5体
/// </summary>
EnemyPattern kEnemyPattern4th = { 3, 5 };
/// <summary>
/// 縦に5体
/// </summary>
EnemyPattern kEnemyPattern5th = { 3, 5 };
/// <summary>
/// 横並びに10体
/// </summary>
EnemyPattern kEnemyPatternRest = { 8, 10 };
}

EnemyManager::EnemyManager() 
{
  Initialize(kInitialEnemyNum);
}

// TaskManagerから呼び出される
void EnemyManager::Update(float delta_time)
{
  GameInfo *game_info = GameInfo::GetInstance();

  play_time_ += delta_time;
  int level_step = 0;
  int count = 0;

  // ゲームの進行に応じて敵の出現パターンを変更する
  // 最初の敵の出現
  switch (level_step)
  {
    // 1回目の敵の出現
  case 0:
    if (static_cast<int>(play_time_) == kEnemyPattern1st.elapsed_time)
    {
      enemy_list_[0]->pos_x_ = game_info->GetCenterX() - game_info->GetTackleEnemyImageWidth() / 2;
      enemy_list_[0]->pos_y_ = -game_info->GetTackleEnemyImageHeight();
      enemy_list_[0]->is_dead_ = false;
      enemy_list_[0]->is_active_ = true;

      last_enemy_apper_time_ = play_time_;
      level_step++;
    }
    break;
    // 2回目の敵の出現
  case 1:
    if (static_cast<int>(play_time_ - last_enemy_apper_time_) == kEnemyPattern2nd.elapsed_time)
    {
      for (EnemyBase *enemy : enemy_list_)
      {
        if (count >= kEnemyPattern2nd.enemy_num)
        {
          break;
        }

        // enemy_list_の中で生きている敵を利用する
        if (enemy->is_dead_ && !enemy->is_active_)
        {
          enemy->pos_x_ = 300 * (count + 1);
          enemy->CorrectPosX();
          enemy->pos_y_ = -game_info->GetTackleEnemyImageHeight();
          enemy->is_dead_ = false;
          enemy->is_active_ = true;
          count++;
        }
      }
      level_step++;
    }
    break;
    // 3回目の敵の出現
  case 2:
    if (static_cast<int>(play_time_ - last_enemy_apper_time_) == kEnemyPattern3rd.elapsed_time)
    {
      for (EnemyBase *enemy : enemy_list_)
      {
        if (count >= kEnemyPattern3rd.enemy_num)
        {
          break;
        }
        // enemy_list_の中で生きている敵を利用する
        if (enemy->is_dead_ && !enemy->is_active_)
        {
          enemy->pos_x_ = GetRandomEnemyPosX();
          enemy->CorrectPosX();
          enemy->pos_y_ = -(game_info->GetTackleEnemyImageHeight() * (count + 1));
          enemy->is_dead_ = false;
          enemy->is_active_ = true;
          count++;
        }
      }
      last_enemy_apper_time_ = play_time_;
      level_step++;
    }
    break;
    // 4回目の敵の出現
  case 3:
    if (static_cast<int>(play_time_ - last_enemy_apper_time_) == kEnemyPattern4th.elapsed_time)
    {
      for (EnemyBase *enemy : enemy_list_)
      {
        if (count >= kEnemyPattern3rd.enemy_num)
        {
          break;
        }
        // enemy_list_の中で生きている敵を利用する
        if (enemy->is_dead_ && !enemy->is_active_)
        {
          enemy->pos_x_ = GetRandomEnemyPosX();
          enemy->CorrectPosX();
          enemy->pos_y_ = -(game_info->GetTackleEnemyImageHeight() * (count + 1));
          enemy->is_dead_ = false;
          enemy->is_active_ = true;
          count++;
        }
      }
      last_enemy_apper_time_ = play_time_;
      level_step++;
    }
    break;
    // 5回目の敵の出現
  case 4:
    if (static_cast<int>(play_time_ - last_enemy_apper_time_) == kEnemyPattern5th.elapsed_time)
    {
      for (EnemyBase *enemy : enemy_list_)
      {
        if (count >= kEnemyPattern3rd.enemy_num)
        {
          break;
        }
        // enemy_list_の中で生きている敵を利用する
        if (enemy->is_dead_ && !enemy->is_active_)
        {
          enemy->pos_x_ = GetRandomEnemyPosX();
          enemy->CorrectPosX();
          enemy->pos_y_ = -(game_info->GetTackleEnemyImageHeight() * (count + 1));
          enemy->is_dead_ = false;
          enemy->is_active_ = true;
          count++;
        }
      }
      last_enemy_apper_time_ = play_time_;
      level_step++;
    }
    break;
    // 6回目以降の敵の出現
  case 5:
      if (static_cast<int>(play_time_ - last_enemy_apper_time_) == kEnemyPatternRest.elapsed_time)
      {
        for (EnemyBase *enemy : enemy_list_)
        {
          if (count >= kEnemyPatternRest.enemy_num)
          {
            break;
          }
          
          // enemy_list_の中で生きている敵を利用する
          if (enemy->is_dead_ && !enemy->is_active_)
          {
            enemy->pos_x_ = game_info->GetMinPosX() + 64 * (count + 1);
            enemy->pos_y_ = -game_info->GetTackleEnemyImageHeight();
            enemy->is_dead_ = false;
            enemy->is_active_ = true;
            count++;
          }
        }
        last_enemy_apper_time_ = play_time_;
      }
    break;
  }


  for (auto enemy : enemy_list_)
  {
    if (enemy->GetIsActive())
    {
      enemy->Update(delta_time);
    }
  }

  boss_enemy_->Update(delta_time);

  count = 0;
}

// TaskManagerから呼び出される
void EnemyManager::Render()
{
  for (auto enemy : enemy_list_)
  {
    if (enemy->GetIsActive() && !enemy->GetIsDead())
    {
      enemy->Render();
    }
  }
  if (boss_enemy_->GetIsActive() && !boss_enemy_->GetIsDead())
  {
    boss_enemy_->Render();
  }
}

void EnemyManager::Initialize(int enemy_num)
{
  for (int i = 0; i < enemy_num; i++)
  {
    enemy_list_.emplace_back(new TackleEnemy);
  }
  boss_enemy_ = new BossEnemy;
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
  delete boss_enemy_;
}

void EnemyManager::LoadEnemyImageHandle()
{
  for (auto enemy : enemy_list_)
  {
    enemy->LoadImageHandle();
  }
  boss_enemy_->LoadImageHandle();
}

int EnemyManager::GetRandomEnemyPosX()
{
  std::mt19937_64 mt(0);

  std::uniform_int_distribution<int> rand_x(3, 16);

  return rand_x(mt);
}