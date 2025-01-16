#include "DxLib.h"
#include "LevelChanger.h"
#include "BattleLevel.h"
#include "TaskManager.h"


namespace
{
/// <summary>
/// DXライブラリに渡すので、const char*型を使用（互換性の問題）
/// </summary>
const char *kBattleBgImageFilePath = "E:/ゲーム開発/クリアカ/ShootingGame3/Shooting3/Assets/Image/Battle/Background/BaseBgSky01.png";

const int kBgPosX = 200;
const int kBgPosY = 0;

/// <summary>
/// レベルの切り替え時間
/// 画面遷移に時間を設ける
/// </summary>
const float kChangeTitleTime = 3.0f;
}

BattleLevel::BattleLevel()
  : battle_level_state_(BattleLevelState::kNone),
    player_(nullptr),
    elapsed_time_(0.0f),
    back_ground_(new BackGround)
{
}

BattleLevel::~BattleLevel() = default;

void BattleLevel::Update(float delta_time)
{
  // 何もしない状態なら実行しない
  if (battle_level_state_ == BattleLevelState::kNone)
  {
    return;
  }
  // 経過時間を計算
  // 毎フレーム加算
  elapsed_time_ += delta_time;

  // 一定時間経過したら、次の状態へ遷移
  if (elapsed_time_ >= kChangeTitleTime)
  {
    // 経過時間をリセット
    elapsed_time_ = 0.0f;

    // バトルレベルの状態をリセット
    battle_level_state_ = BattleLevelState::kNone;

    //レベルチェンジャーの状態をタイトルレベル終了へ
    LevelChanger::GetInstance()
      ->SetLevelChangerState(LevelChanger::LevelChangerState::kFinBattleLevel);
  }
}

void BattleLevel::Render()
{
  // 背景画像を描画
  //x, y　　　: グラフィックを描画する領域の左上頂点の座標
  //GrHandle　 : 描画するグラフィックのハンドル
  //TransFlag　 : 画像の透明度を有効にするかどうか(TRUE：有効にする　FALSE：無効にする)
  back_ground_->Render();
}

void BattleLevel::BeginLevel()
{
  // 背景画像の読み込み
  back_ground_->LoadImages();

  // プレイヤー
  player_ = new Player();
  player_->BeginPlayer();

  //タスクマネージャーに放り込む
  TaskManager::GetInstance()->AddTask(player_);

  // バトルレベルの状態をプレイに設定
  battle_level_state_ = BattleLevelState::kPlay;
  //=> Updateが動くようになる
}

void BattleLevel::ReleaseLevel()
{
  // プレイヤーの解放
  TaskManager::GetInstance()->ReleaseTask(player_->GetTaskId());
}

void BattleLevel::DestroyLevel()
{
  // 背景画像の破棄
  back_ground_->RemoveImages();
  delete back_ground_;
  back_ground_ = nullptr;

  delete player_;
  player_ = nullptr;
}
