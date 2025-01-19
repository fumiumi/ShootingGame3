#include "BattleLevel.h"
#include "DxLib.h"
#include "LevelChanger.h"
#include "TaskManager.h"
#include "InputManager.h"
#include "FadeManager.h"

namespace
{
/// <summary>
/// DXライブラリに渡すので、const char*型を使用（互換性の問題）
/// </summary>
const char *kBattleBgImageFilePath = "E:/ゲーム開発/クリアカ/ShootingGame3/Shooting3/Assets/Image/Battle/Background/BaseBgSky01.png";

const int kBgPosX = 200;
const int kBgPosY = 0;
}

BattleLevel::BattleLevel()
  : battle_level_state_(BattleLevelState::kNone),
    back_ground_(new BackGround),
    bullet_manager_(new BulletManager),
    battle_ui_(new BattleUi)
{
  player_ = new Player(this);
}

BattleLevel::~BattleLevel() = default;

void BattleLevel::Update(float delta_time)
{
  InputManager *input_manager = InputManager::GetInstance();

  // 何もしない状態なら実行しない
  if (battle_level_state_ == BattleLevelState::kNone)
  {
    return;
  }

  //DEBUG: KEY_INPUT_ESCAPEを押したらタイトルレベルに戻る
  if (input_manager->IsPushThisFrame(input_manager->GameKeyKind::kPause))
  {

    //レベルチェンジャーの状態をタイトルレベル終了へ
    LevelChanger::GetInstance()
      ->SetLevelChangerState(LevelChanger::LevelChangerState::kFinBattleLevel);

    // フェードインをリクエスト
    FadeManager::GetInstance()->RequestFadeIO(2000, FadeManager::FadeManagerState::kFadeIn);
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
  player_->BeginPlayer();

  // 弾
  bullet_manager_->LoadBulletImageHandle();

  //タスクマネージャーに放り込む
  TaskManager::GetInstance()->AddTask(player_);
  TaskManager::GetInstance()->AddTask(bullet_manager_);
  // 描画順を考慮して、UIは最後に登録
  TaskManager::GetInstance()->AddTask(battle_ui_);

  // バトルレベルの状態をプレイに設定
  battle_level_state_ = BattleLevelState::kPlay;
  //=> Updateが動くようになる

  // フェードアウトをリクエスト
  FadeManager::GetInstance()->RequestFadeIO(300, FadeManager::FadeManagerState::kFadeOut);
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
