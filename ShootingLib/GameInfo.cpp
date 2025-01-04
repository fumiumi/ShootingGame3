#include "GameInfo.h"

/// <summary>
/// 定数を保持する無名名前空間
/// </summary>
namespace
{
/// <summary>
/// 解像度横幅
/// </summary>
int kWidth = 1280;

/// <summary>
/// 解像度縦幅
/// </summary>
int kHeight = 720;

/// <summary>
/// カラービット数
/// </summary>
int kColorBit = 32;
}

/// <summary>
/// インスタンスはnullptrで初期化
/// </summary>
GameInfo *GameInfo::instance_ = nullptr;

std::mutex GameInfo::mutex_;

/// <summary>
/// GetInstance()から呼び出すコンストラクタ
/// </summary>
GameInfo::GameInfo() 
  : x_resolution_(kWidth),
    y_resolution_(kHeight),
    x_center_(kWidth / 2),
    y_center_(kHeight / 2),
    color_bit_(kColorBit),
    is_end_game_(false),
    is_debug_display_(false)
{
}

/// <summary>
/// デストラクタ
/// </summary>
GameInfo::~GameInfo() = default;

/// <summary>
/// x方向の画面解像度を取得するメンバ関数
/// </summary>
/// <returns>x方向の画面解像度を整数で返す</returns>
int GameInfo::GetResolutionX()
{
  return x_resolution_;
}

/// <summary>
/// y方向の画面解像度を取得するメンバ関数
/// </summary>
/// <returns>y方向の画面解像度を整数で返す</returns>
int GameInfo::GetResolutionY()
{
  return y_resolution_;
}

/// <summary>
/// 画面の中心座標のx成分を取得するメンバ関数
/// </summary>
/// <returns>中心座標のx成分</returns>
int GameInfo::GetCenterX()
{
  return x_center_;
}

/// <summary>
/// 画面の中心座標のy成分を取得するメンバ関数
/// </summary>
/// <returns>中心座標のy成分</returns>
int GameInfo::GetCenterY()
{
  return y_center_;
}

/// <summary>
/// カラービット数を取得するメンバ関数
/// </summary>
/// <returns>カラービット数</returns>
int GameInfo::GetColorBit()
{
  return color_bit_;
}

/// <summary>
/// デバッグモードの情報を取得
/// </summary>
/// <returns>デバッグ表示するならtrue</returns>
bool GameInfo::IsDebugDisplay()
{
  return is_debug_display_;
}

/// <summary>
/// デバッグモードに応じて表示を切り替える
/// </summary>
/// <param name="is_debug">trueを渡したらデバッグモード</param>
void GameInfo::SetDebugDisplay(bool is_debug)
{
  is_debug_display_ = is_debug;
}

/// <summary>
/// ゲーム終了フラグの設定
/// </summary>
/// <returns>trueなら終了</returns>
bool GameInfo::IsEndGame()
{
  return is_end_game_;
}

/// <summary>
/// ゲーム終了フラグをセット
/// </summary>
/// <param name="is_end_game">設定するゲーム終了フラグ</param>
void GameInfo::SetEndGame(bool is_end_game)
{
  is_end_game_ = is_end_game;
}
