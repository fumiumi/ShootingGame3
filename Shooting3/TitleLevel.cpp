#include "DxLib.h"
#include "TitleLevel.h"
#include "LevelChanger.h"
#include "TitleUi.h"
#include "InputManager.h"
#include "FadeManager.h"


/// <summary>
/// TitleLevel.cppのみで使用する定数
/// </summary>
namespace
{
/// <summary>
/// 背景画像
/// DXライブラリに渡すので、const char*型を使用（互換性の問題）
/// </summary>
const char *kTitleBgImageFilePath = "E:/ゲーム開発/クリアカ/ShootingGame3/Shooting3/Assets/Image/Title/TitleBg01.png";

/// <summary>
/// ウィンドウ内における、背景画像のX座標
/// </summary>
const int kBgPosX = 200;

const int kBgPosY = 0;
}

/// <summary>
/// コンストラクタ
/// </summary>
TitleLevel::TitleLevel()
  : title_level_state_(TitleLevelState::kNone),
    title_bg_handle_(0),
    title_ui_(new TitleUi)
    // 最終的に消す
    //elapsed_time_(0.0f)
{
}

/// <summary>
/// デストラクタ
/// </summary>
TitleLevel::~TitleLevel() = default;

/// <summary>
/// 毎フレームの更新処理
/// </summary>
/// <param name="delta_time">kPlayになってからの、前回実行フレームからの経過時間（秒）</param>
void TitleLevel::Update(float delta_time)
{
  InputManager *input_manager = InputManager::GetInstance();

  //何もしない状態なら実行しない
  if (title_level_state_ == TitleLevelState::kNone)
  {
    return;
  }

  //zキーが押されたらレベル遷移
  if (input_manager->IsPushThisFrame(input_manager->GameKeyKind::kPlayerFire))
  {
    ////状態を何もしないへ
    //title_level_state_ = TitleLevelState::kNone;

    //レベルチェンジャーの状態をタイトルレベル終了へ
    LevelChanger::GetInstance()
      ->SetLevelChangerState(LevelChanger::LevelChangerState::kFinTitleLevel);

    // フェードインをリクエスト
    FadeManager::GetInstance()->RequestFadeIO(1000, FadeManager::FadeManagerState::kFadeIn);
  }
}

/// <summary>
/// 毎フレームの描画処理
/// </summary>
void TitleLevel::Render()
{
  //背景画像描画
  //x, y　　　: グラフィックを描画する領域の左上頂点の座標
  //GrHandle　 : 描画するグラフィックのハンドル
  //TransFlag　 : 画像の透明度を有効にするかどうか(TRUE：有効にする　FALSE：無効にする)
  DrawGraph(kBgPosX, kBgPosY, title_bg_handle_, TRUE);

  //UIの描画はタスクマネージャーに任せる
}

/// <summary>
/// レベルの開始処理
/// </summary>
void TitleLevel::BeginLevel()
{
  //背景読み込み
  title_bg_handle_ = LoadGraph(kTitleBgImageFilePath);

  //UIをタスクマネージャーに登録
  TaskManager::GetInstance()->AddTask(title_ui_);

  //状態を通常へ
  title_level_state_ = TitleLevelState::kPlay;

  // フェードアウトをリクエスト
  FadeManager::GetInstance()->RequestFadeIO(1000, FadeManager::FadeManagerState::kFadeOut);
}

/// <summary>
/// タイトルレベルの管理するものをタスクマネージャーから解放する
/// </summary>
void TitleLevel::ReleaseLevel()
{
  TaskManager::GetInstance()->ReleaseTask(title_ui_->GetTaskId());
}

/// <summary>
/// タイトルレベルの管理するものを破棄
/// </summary>
void TitleLevel::DestroyLevel()
{
  //背景画像破棄
  DeleteGraph(title_bg_handle_);
  title_ui_->Destroy();
  delete title_ui_;
  title_ui_ = nullptr;
}