#include "DxLib.h"
#include "LevelChanger.h"
#include "BattleLevel.h"
#include "TaskManager.h"

/// <summary>
/// TitleLevel.cppのみで使用する定数
/// </summary>
namespace
{
/// <summary>
/// 背景画像
/// DXライブラリに渡すので、const char*型を使用（互換性の問題）
/// </summary>
const char *kBattleBgImageFilePath = "E:/ゲーム開発/クリアカ/ShootingGame3/Shooting3/Assets/Image/Battle/Background/BaseBgSky01.png";

/// <summary>
/// ウィンドウ内における、背景画像のX座標
/// </summary>
const int kBgPosX = 200;

/// <summary>
/// ウィンドウ内における、背景画像のY座標
/// </summary>
const int kBgPosY = 0;

/// <summary>
/// レベルの切り替え時間
/// 画面遷移に時間を設ける
/// </summary>
const float kChangeTitleTime = 3.0f;
}

/// <summary>
/// コンストラクタ
/// </summary>
BattleLevel::BattleLevel()
  : battle_level_state_(BattleLevelState::kNone),
    battle_bg_handle_(0),
    player_(nullptr),
    elapsed_time_(0.0f)
{
}

/// <summary>
/// デストラクタ
/// </summary>
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

/// <summary>
/// 描画処理
/// </summary>
void BattleLevel::Render()
{
  // 背景画像を描画
  //x, y　　　: グラフィックを描画する領域の左上頂点の座標
  //GrHandle　 : 描画するグラフィックのハンドル
  //TransFlag　 : 画像の透明度を有効にするかどうか(TRUE：有効にする　FALSE：無効にする)
  DrawGraph(kBgPosX, kBgPosY, battle_bg_handle_, TRUE);
  //printfDx("handle is %d\n", battle_bg_handle_);
}

/// <summary>
/// レベルの開始
/// </summary>
void BattleLevel::BeginLevel()
{
  // 背景画像の読み込み
  battle_bg_handle_ = LoadGraph(kBattleBgImageFilePath);

  // プレイヤーの生成
  player_ = new Player();

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
  DeleteGraph(battle_bg_handle_);
  delete player_;
  player_ = nullptr;
}