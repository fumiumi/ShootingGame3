#include "DxLib.h"
#include <TaskManager.h>
#include "LevelChanger.h"
#include "TitleLevel.h"
#include "BattleLevel.h"

//レベルチェンジャーのインスタンス初期化
LevelChanger *LevelChanger::instance_ = nullptr;

LevelChanger::LevelChanger()
  : current_level_changer_state_(LevelChangerState::kWait),
    current_level_(nullptr),
    next_level_changer_state_after_destroy_(LevelChangerState::kWait)
{
}

LevelChanger::~LevelChanger() = default;

void LevelChanger::SetLevelChangerState(LevelChanger::LevelChangerState level_changer_state)
{
  //DEBUG
  printfDx("レベルチェンジ\n");
  current_level_changer_state_ = level_changer_state;
}

void LevelChanger::Update(float delta_time) {

  //新しくレベルを生成したフラグ
  bool is_created_level = false;

  //レベル解放フラグ
  bool is_release_level = false;

  //タイトルレベルの初期化
  if (current_level_changer_state_ == LevelChangerState::kInitTitleLevel) {

    //タイトルレベルを生成
    current_level_ = new TitleLevel();

    //新しくレベルを生成したフラグをtrue
    is_created_level = true;
  }
  //タイトルレベルの後処理
  else if (current_level_changer_state_ == LevelChangerState::kFinTitleLevel) {

    //次はバトルレベルの初期化へ
    next_level_changer_state_after_destroy_ = LevelChangerState::kInitBattleLevel;

    //レベル解放フラグをtrue
    is_release_level = true;
  }
  //バトルレベルの初期化
  else if (current_level_changer_state_ == LevelChangerState::kInitBattleLevel) {

    //バトルレベルを生成
    current_level_ = new BattleLevel();

    //新しくレベルを生成したフラグをtrue
    is_created_level = true;
  }
  //バトルレベルの後処理
  else if (current_level_changer_state_ == LevelChangerState::kFinBattleLevel) {

    //次はタイトルの初期化へ
    next_level_changer_state_after_destroy_ = LevelChangerState::kInitTitleLevel;

    //レベル解放フラグをtrue
    is_release_level = true;
  }
  //現在レベルの破棄
  else if (current_level_changer_state_ == LevelChangerState::kDestroyCurrentLevel) {

    //現在レベルに関するオブジェクトの破棄
    current_level_->DestroyLevel();

    //現在レベルを破棄
    delete current_level_;
    current_level_ = nullptr;

    //レベル破棄後に予約された状態へ
    current_level_changer_state_ = next_level_changer_state_after_destroy_;
  }

  //新しくレベルが生成されたなら
  if (is_created_level) {

    //生成したレベルをタスクに登録
    TaskManager::GetInstance()->AddTask(current_level_);

    //レベルの開始処理
    current_level_->BeginLevel();

    //レベルチェンジャーの状態は待機へ
    current_level_changer_state_ = LevelChangerState::kWait;
  }

  //現在のレベルは解放するなら
  if (is_release_level) {

    //現在レベルに関連するものをタスクマネージャーから解放する
    current_level_->ReleaseLevel();

    //現在レベルをタスクから解放
    TaskManager::GetInstance()->ReleaseTask(current_level_->GetTaskId());

    //レベルチェンジャーの状態は現在のレベル破棄へ
    current_level_changer_state_ = LevelChangerState::kDestroyCurrentLevel;
  }
}

/// <summary>
/// 現在のレベルを強制破棄
/// ウィンドウの×ボタンでゲームを終了した場合などの対応
/// </summary>
void LevelChanger::ForceDestroyCurrentLevel()
{
  //現在のレベルが破棄されてないなら
  if (current_level_ != nullptr) {

    //現在のレベルに関係のあるオブジェクトの破棄
    current_level_->DestroyLevel();

    //現在のレベルを破棄
    delete current_level_;
    current_level_ = nullptr;
  }
}
