#include "DxLib.h"
#include "TitleLevel.h"
#include "LevelChanger.h"


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

/// <summary>
/// レベルの切り替え時間
/// 画面遷移に時間を設ける
/// </summary>
const float kChangeLevelTime = 3.0f;
}

/// <summary>
/// コンストラクタ
/// </summary>
TitleLevel::TitleLevel()
  : title_level_state_(TitleLevelState::kNone),
  title_bg_handle_(0),
  elapsed_time_(0.0f)
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
  //何もしない状態なら実行しない
  if (title_level_state_ == TitleLevelState::kNone)
  {
    return;
  }

  //経過時間を計算
  elapsed_time_ += delta_time;

  //レベル切り替えの時間が来たら
  if (elapsed_time_ >= kChangeLevelTime)
  {
    //時間リセット
    elapsed_time_ = 0.0f;

    //状態を何もしないへ
    title_level_state_ = TitleLevelState::kNone;

    //レベルチェンジャーの状態をタイトルレベル終了へ
    LevelChanger::GetInstance()
      ->SetLevelChangerState(LevelChanger::LevelChangerState::kFinTitleLevel);
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
}

/// <summary>
/// レベルの開始処理
/// </summary>
void TitleLevel::BeginLevel()
{
  //背景読み込み
  title_bg_handle_ = LoadGraph(kTitleBgImageFilePath);

  //状態を通常へ
  title_level_state_ = TitleLevelState::kPlay;
}

/// <summary>
/// タイトルレベルの管理するものをタスクマネージャーから解放する
/// </summary>
void TitleLevel::ReleaseLevel()
{
  //今はタスクマネージャーに登録しているものはない
}

/// <summary>
/// タイトルレベルの管理するものを破棄
/// </summary>
void TitleLevel::DestroyLevel()
{
  //背景画像破棄
  DeleteGraph(title_bg_handle_);
}