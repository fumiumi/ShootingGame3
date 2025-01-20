#include "EnemyManager.h"
#include "TackleEnemy.h"
#include "BossEnemy.h"
#include "GameInfo.h"
#include "DXLib.h"
#include <vector> 

namespace
{
const int kInitialEnemyNum = 50;

EnemyPattern kEnemyPattern1st = { 1, 1 };
EnemyPattern kEnemyPattern2nd = { 2, 3 };
EnemyPattern kEnemyPattern3rd = { 2, 5 };
EnemyPattern kEnemyPattern4th = { 2, 5 };
EnemyPattern kEnemyPattern5th = { 2, 5 };
EnemyPattern kEnemyPatternRest = { 5, 10 };
}

EnemyManager::EnemyManager()
  : play_time_(0.0f)
  , last_enemy_apper_time_(0.0f)
  // level_step_ をコンストラクタで初期化
  , level_step_(0)
{
  Initialize(kInitialEnemyNum);
}

void EnemyManager::Update(float delta_time)
{
  GameInfo *game_info = GameInfo::GetInstance();

  play_time_ += delta_time;
  int count = 0;

  switch (level_step_)
  {
  case 0:
    if (static_cast<int>(play_time_) == kEnemyPattern1st.elapsed_time)
    {
      enemy_list_[0]->pos_x_ = game_info->GetCenterX() - game_info->GetTackleEnemyImageWidth() / 2;
      enemy_list_[0]->pos_y_ = -game_info->GetTackleEnemyImageHeight();
      enemy_list_[0]->is_dead_ = false;
      enemy_list_[0]->is_active_ = true;

      last_enemy_apper_time_ = play_time_;
      // 次の状態へ進む
      level_step_++;
    }
    break;

  case 1:
    if (static_cast<int>(play_time_ - last_enemy_apper_time_) == kEnemyPattern2nd.elapsed_time )
    {
      for (EnemyBase *enemy : enemy_list_)
      {
        if (count >= kEnemyPattern2nd.enemy_num)
        {
          break;
        }

        if (enemy->is_dead_ && !enemy->is_active_)
        {
          enemy->pos_x_ = 300 * (count + 1);
          enemy->CorrectPosX();
          enemy->pos_y_ = -game_info->GetTackleEnemyImageHeight() * (count + 1);
          enemy->is_dead_ = false;
          enemy->is_active_ = true;
          count++;
        }
      }
      // 必要ならここでも last_enemy_apper_time_ を更新
      last_enemy_apper_time_ = play_time_;
      level_step_++;
    }
    break;

  case 2:
    if (static_cast<int>(play_time_ - last_enemy_apper_time_) == kEnemyPattern3rd.elapsed_time )
    {
      for (EnemyBase *enemy : enemy_list_)
      {
        if (count >= kEnemyPattern3rd.enemy_num)
        {
          break;
        }
        if (enemy->is_dead_ && !enemy->is_active_)
        {
          enemy->pos_x_ = GetRand(game_info->GetMaxPosX()) + game_info->GetMinPosX();
          enemy->CorrectPosX();
          enemy->pos_y_ = -(game_info->GetTackleEnemyImageHeight() * (count + 1));
          enemy->is_dead_ = false;
          enemy->is_active_ = true;
          count++;
        }
      }
      last_enemy_apper_time_ = play_time_;
      level_step_++;
    }
    break;

  case 3:
    if (static_cast<int>(play_time_ - last_enemy_apper_time_) == kEnemyPattern4th.elapsed_time )
    {
      for (EnemyBase *enemy : enemy_list_)
      {
        if (count >= kEnemyPattern4th.enemy_num)
        {
          break;
        }
        if (enemy->is_dead_ && !enemy->is_active_)
        {
          enemy->pos_x_ = GetRand(game_info->GetMaxPosX()) + game_info->GetMinPosX();
          enemy->CorrectPosX();
          enemy->pos_y_ = -(game_info->GetTackleEnemyImageHeight() * (count + 1));
          enemy->is_dead_ = false;
          enemy->is_active_ = true;
          count++;
        }
      }
      last_enemy_apper_time_ = play_time_;
      level_step_++;
    }
    break;

  case 4:
    if (static_cast<int>(play_time_ - last_enemy_apper_time_) == kEnemyPattern5th.elapsed_time )
    {
      for (EnemyBase *enemy : enemy_list_)
      {
        if (count >= kEnemyPattern5th.enemy_num)
        {
          break;
        }
        if (enemy->is_dead_ && !enemy->is_active_)
        {
          enemy->pos_x_ = GetRand(game_info->GetMaxPosX()) + game_info->GetMinPosX();
          enemy->CorrectPosX();
          enemy->pos_y_ = -(game_info->GetTackleEnemyImageHeight() * (count + 1));
          enemy->is_dead_ = false;
          enemy->is_active_ = true;
          count++;
        }
      }
      last_enemy_apper_time_ = play_time_;
      level_step_++;
    }
    break;

  case 5:
    if (static_cast<int>(play_time_ - last_enemy_apper_time_) == kEnemyPatternRest.elapsed_time )
    {
      for (EnemyBase *enemy : enemy_list_)
      {
        if (count >= kEnemyPatternRest.enemy_num)
        {
          break;
        }
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
      // case 5 は繰り返し出現
      // もし出現パターンをループせず 1回きりにしたい場合は level_step_++ を使う
      // level_step_++;
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
}

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