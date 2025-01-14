#include <DxLib.h>
#include "Player.h"

namespace
{
/// <summary>
/// プレイヤー画像のファイルパス
/// 左上：デフォルト
/// 右上：左矢印入力時
/// 左下：右矢印入力時
/// 右下：空白
/// </summary>
const char *kPlayerImageFilePath = "E:/ゲーム開発/クリアカ/ShootingGame3/Shooting3/Assets/Image/Battle/Player/Player.png";

/// <summary>
/// x方向の分割数
/// </summary>
const int kPlayerImageDivX = 2;
/// <summary>
/// y方向の分割数
/// </summary>
const int kPlayerImageDivY = 2;
/// <summary>
/// 分割した画像の幅
/// </summary>
const int kPlayerImageDivSizeX = 64;
/// <summary>
/// 分割した画像の高さ
/// </summary>
const int kPlayerImageDivSizeY = 64;
}

/// <summary>
/// コンストラクタ
/// </summary>
Player::Player()
  : Task(),
  positionX_(640), // マジックナンバーはやめたい
  positionY_(360), // 数マジックナンバーはやめたい
  player_state_(PlayerState::kStraight),
  player_handle_array_{0, 0, 0, 0}
{
}

/// <summary>
/// デストラクタ
/// </summary>
Player::~Player()
{
  // 画像の解放
  RemovePlayerImage();
}

void Player::SetPosition(int x, int y)
{
  positionX_ = x;
  positionY_ = y;
}

int Player::GetPositionX() const
{
  return positionX_;
}

int Player::GetPositionY() const
{
  return positionY_;
}

void Player::Update(float delta_time)
{
  if (player_state_ == PlayerState::kError)
  {
    //TODO: エラー時の処理を考える
  }

  // 仮実装
  // 画像の読み込み
  //CAUTION: DxLib_Init()が呼ばれていることが前提
  LoadPlayerImage();
  player_state_ = PlayerState::kStraight;
}

void Player::Render()
{
  //状態をハンドル指定に変換
  int drawHandleNum = static_cast<int>(player_state_);

  //DEBUG: ハンドルの中身を確認
  for (int i = 0; i < kPlayerImageDivNum; i++)
  {
    printfDx("handle[%d] is %d\n", i, player_handle_array_[i]);
  }

  // 画像の描画
  int result = DrawGraph(
    positionX_,
    positionY_,
    player_handle_array_[drawHandleNum],
    TRUE
  );

  if (result == -1)
  {
    // エラーログを出力
    printfDx("画像の出力に失敗しました\n");
    //TODO: とりあえずkErrorにしておくけど、その後の処理はまだ未定
    player_state_ = PlayerState::kError;
  }
}


void Player::LoadPlayerImage()
{
  int result = LoadDivGraph(
    kPlayerImageFilePath,
    kPlayerImageDivNum, // ヘッダでstatic宣言している
    kPlayerImageDivX,
    kPlayerImageDivY,
    kPlayerImageDivSizeX,
    kPlayerImageDivSizeY,
    player_handle_array_ // 配列の先頭アドレスを渡す
  );

  //handle_ = LoadGraph(kPlayerImageFilePath);

  // 画像の読み込みに失敗
  if (result == -1)
  {
    // エラーログを出力
    printfDx("画像の読み込みに失敗しました\n");
    //TODO: とりあえずkErrorにしておくけど、その後の処理はまだ未定
    player_state_ = PlayerState::kError;
  }
}

void Player::RemovePlayerImage()
{
  for (int handle : player_handle_array_)
  {
    DeleteGraph(handle);
  }
}
