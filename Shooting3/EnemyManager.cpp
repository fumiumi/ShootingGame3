#include "EnemyManager.h"
#include "TackleEnemy.h"
#include "BossEnemy.h"
#include "GameInfo.h"
#include "DXLib.h"
#include <vector> 

class EnemyBase;

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

void SpawnEnemy(EnemyBase *enemy, int pos_x, int pos_y) {
  enemy->SetPosX(pos_x);
  enemy->SetPosY(pos_y);
  enemy->SetIsDead(false);
  enemy->SetIsActive(true);
}

EnemyManager::EnemyManager()
  : play_time_(0.0f)
  , last_enemy_apper_time_(0.0f)
  // level_step_ ���R���X�g���N�^�ŏ�����
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
    // �Q�l�ɂȂ�C����(���Ɏ����ς�)
    if (static_cast<int>(play_time_) == kEnemyPattern1st.elapsed_time)
    {
      SpawnEnemy(
        enemy_list_[0], 
        game_info->GetCenterX() - game_info->GetTackleEnemyImageWidth() / 2, 
        -game_info->GetTackleEnemyImageHeight()
      );

      last_enemy_apper_time_ = play_time_;
      level_step_++;
    }
    break;

  case 1:
    if (static_cast<int>(play_time_ - last_enemy_apper_time_) == kEnemyPattern2nd.elapsed_time)
    {
      for (EnemyBase *enemy : enemy_list_)
      {
        if (count >= kEnemyPattern2nd.enemy_num)
        {
          break;
        }

        // �����o�ϐ����ڃA�N�Z�X�ł͂Ȃ� Getter/Setter ���g��
        if (enemy->GetIsDead() && !enemy->GetIsActive())
        {
          SpawnEnemy(enemy, 300 * (count + 1), -game_info->GetTackleEnemyImageHeight() * (count + 1));
          // �K�v�ł���΍��W�␳
          enemy->CorrectPosX();

          count++;
        }
      }
      last_enemy_apper_time_ = play_time_;
      level_step_++;
    }
    break;

  case 2:
    if (static_cast<int>(play_time_ - last_enemy_apper_time_) == kEnemyPattern3rd.elapsed_time)
    {
      for (EnemyBase *enemy : enemy_list_)
      {
        if (count >= kEnemyPattern3rd.enemy_num)
        {
          break;
        }

        if (enemy->GetIsDead() && !enemy->GetIsActive())
        {
          SpawnEnemy(
            enemy, 
            GetRand(game_info->GetMaxPosX()) + game_info->GetMinPosX(), 
            -game_info->GetTackleEnemyImageHeight() * (count + 1)
          );
          enemy->CorrectPosX();

          count++;
        }
      }
      last_enemy_apper_time_ = play_time_;
      level_step_++;
    }
    break;

  case 3:
    if (static_cast<int>(play_time_ - last_enemy_apper_time_) == kEnemyPattern4th.elapsed_time)
    {
      for (EnemyBase *enemy : enemy_list_)
      {
        if (count >= kEnemyPattern4th.enemy_num)
        {
          break;
        }

        if (enemy->GetIsDead() && !enemy->GetIsActive())
        {
          SpawnEnemy(
            enemy, 
            GetRand(game_info->GetMaxPosX()) + game_info->GetMinPosX(), 
            -game_info->GetTackleEnemyImageHeight() * (count + 1)
          );
          enemy->CorrectPosX();

          count++;
        }
      }
      last_enemy_apper_time_ = play_time_;
      level_step_++;
    }
    break;

  case 4:
    if (static_cast<int>(play_time_ - last_enemy_apper_time_) == kEnemyPattern5th.elapsed_time)
    {
      for (EnemyBase *enemy : enemy_list_)
      {
        if (count >= kEnemyPattern5th.enemy_num)
        {
          break;
        }

        if (enemy->GetIsDead() && !enemy->GetIsActive())
        {
          SpawnEnemy(
            enemy, 
            game_info->GetCenterX() - game_info->GetTackleEnemyImageWidth() / 2, 
            -game_info->GetTackleEnemyImageHeight() * (count + 1)
          );
          enemy->CorrectPosX();

          count++;
        }
      }
      last_enemy_apper_time_ = play_time_;
      level_step_++;
    }
    break;

  case 5:
    if (static_cast<int>(play_time_ - last_enemy_apper_time_) == kEnemyPatternRest.elapsed_time)
    {
      for (EnemyBase *enemy : enemy_list_)
      {
        if (count >= kEnemyPatternRest.enemy_num)
        {
          break;
        }

        if (enemy->GetIsDead() && !enemy->GetIsActive())
        {
          SpawnEnemy(
            enemy,
            game_info->GetMinPosX() + 64 * (count + 1),
            -game_info->GetTackleEnemyImageHeight()
          );
 
          count++;
        }
      }
      last_enemy_apper_time_ = play_time_;
      // �K�v�ɉ����ăp�^�[�������[�v�������I�����������Ȃ�
      // level_step_++;
    }
    break;
  }

  // �o�������Ƃ͕ʂɁA�A�N�e�B�u��Ԃ̃G�l�~�[���X�V
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

void EnemyManager::AddBulletManagerToEnemy(BulletManager *bullet_manager)
{
  if (bullet_manager == nullptr || enemy_list_.empty())
  {
    return;
  }

  for (auto enemy : enemy_list_)
  {
    enemy->SetBulletManager(bullet_manager);
  }

  if (boss_enemy_ != nullptr)
  {
    boss_enemy_->SetBulletManager(bullet_manager);
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

const std::vector<EnemyBase *> &EnemyManager::GetEnemyList() const
{
  return enemy_list_;
}

EnemyBase *EnemyManager::GetBossEnemy() const
{
  return boss_enemy_;
}