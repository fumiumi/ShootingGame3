#include "DxLib.h"
#include "Player.h"

namespace
{
/// <summary>
/// プレイヤー画像のファイルパス
/// サイズ：120x120（60x60 x 4枚）
/// 左上：デフォルト'
/// 右上：左矢印入力時
/// 左下：右矢印入力時
/// 右下：空白
/// </summary>
const char *kPlayerImageFilePath = "E:ゲーム開発/クリアカ/ShootingGame3/Shooting3/Assets/Image/Battle/Player/Player.png";

/// <summary>
/// x方向の分割数
/// </summary>
const int kPlayerImageDivX = 2;

/// <summary>
/// y方向の分割数
/// </summary>
const int kPlayerImageDivY = 2;

/// <summary>
/// 分割画像の横幅
/// </summary>
const int kPlayerImageDivSizeX = 60;

/// <summary>
/// 分割画像の縦幅
/// </summary>
const int kPlayerImageDivSizeY = 60;
}

Player::Player()
  : Task(),
  positionX_(0),
  positionY_(0),
  playerState_(PlayerState::kStraight)
{
  // 画像の読み込み
 LoadPlayerImage();
}

Player::~Player()
{
  // 画像の解放
  RemovePlayerImage();
}

void Player::Update(float delta_time)
{
  // 表示するplayerImageDivArrayを決定
  if (playerState_ == PlayerState::kError)
  {
    return;
  }

  // 仮実装
  playerState_ = PlayerState::kStraight;

}

void Player::Render()
{
  // 画像の描画
  DrawGraph(
    positionX_, 
    positionY_, 
    playerImageHandleArray_[static_cast<int>(playerState_)], 
    TRUE
  );
}

/// <summary>
/// 自機の座標を設定
/// </summary>
/// <param name="x">x座標</param>
/// <param name="y">y座標</param>
void Player::SetPosition(int x, int y)
{
  positionX_ = x;
  positionY_ = y;
}

/// <summary>
/// x座標を取得
/// </summary>
/// <returns>x座標</returns>
int Player::GetPositionX() const
{
  return positionX_;
}

/// <summary>
/// y座標を取得
/// </summary>
/// <returns>y座標</returns>
int Player::GetPositionY() const
{
  return positionY_;
}

void Player::LoadPlayerImage()
{
  // LoadDivGraph関数
  // FileName:分割読み込みする画像ファイル文字列のポインタ
  // AllNum:画像の分割総数
  // XNum, YNum:画像の横向きに対する分割数と縦に対する分割数
  // SizeX, SizeY:分割された画像一つの大きさ
  // HandleBuf:分割読み込みして得たグラフィックハンドルを
  // 保存するint型の配列へのポインタ
  int result = LoadDivGraph(
    kPlayerImageFilePath,
    kPlayerImageDivNum, // ヘッダでstatic宣言している
    kPlayerImageDivX,
    kPlayerImageDivY,
    kPlayerImageDivSizeX,
    kPlayerImageDivSizeY,
    playerImageHandleArray_ // 配列の先頭アドレスを渡す
  );

  if (result == -1)
  {
    // 画像の読み込みに失敗
    // エラーログを出力
    printfDx("画像の読み込みに失敗しました");
    playerState_ = PlayerState::kError;
  }
}

void Player::RemovePlayerImage()
{
  for (int image : playerImageHandleArray_)
  {
    DeleteGraph(image);
  }
}


