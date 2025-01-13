#include "DxLib.h"
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
    positionX_(0),
    positionY_(0),
    playerState_(PlayerState::kStraight)
{
  // 画像の読み込み
  //CAUTION: DxLib_Init()が呼ばれていることが前提
 LoadPlayerImage();
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
  if (playerState_ == PlayerState::kError)
  {
    return;
  }

  // 仮実装
  playerState_ = PlayerState::kStraight;
}

void Player::Render()
{
  //状態をハンドル指定に変換
  int drawHandleNum_ = static_cast<int>(playerState_);

  if (drawHandleNum_ < 0 || drawHandleNum_ >= kPlayerImageDivNum)
  {
    printfDx("無効なハンドル番号です: %d", drawHandleNum_);
    playerState_ = PlayerState::kError;
    return;
  }

  // 画像の描画
  int result = DrawGraph(
    positionX_, 
    positionY_, 
    playerImageHandleArray_[drawHandleNum_],
    TRUE
  );

  if (result == -1)
  {
    // エラーログを出力
    printfDx("画像の出力に失敗しました");
    playerState_ = PlayerState::kError;
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
    playerImageHandleArray_ // 配列の先頭アドレスを渡す
  );

  // 画像の読み込みに失敗
  if (result == -1)
  {
    // エラーログを出力
    printfDx("画像の読み込みに失敗しました");
    playerState_ = PlayerState::kError;
  }
}

void Player::RemovePlayerImage()
{
  for (int handle : playerImageHandleArray_)
  {
    DeleteGraph(handle);
  }
}
