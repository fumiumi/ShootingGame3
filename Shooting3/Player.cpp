#include <DxLib.h>
#include "Player.h"
#include "InputManager.h"
#include "GameInfo.h"

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

const int kPlayerImageDivX = 2;
const int kPlayerImageDivY = 2;
const int kPlayerImageDivSizeX = 64;
const int kPlayerImageDivSizeY = 64;

const int kPlayerStraightVelocity = 30;
const int kPlayerBankVelocity = 30;
const int kPlayerBackVelocity = 20;

const int kPlayerInitPosX = 640;
const int kPlayerInitPosY = 360;

const int kBgSizeX = 880; // BattleLevel.cppを参照
const int kBgSizeY = 720; // BattleLevel.cppを参照

// プレイヤーが移動できる範囲
GameInfo *game_info = GameInfo::GetInstance();
const int kBgEndLeft = game_info->GetCenterX() - kBgSizeX / 2;
const int kBgEndRight = game_info->GetCenterX() + kBgSizeX / 2;
const int kBgEndTop = 0;
const int kBgEndBottom = game_info->GetResolutionY();
}

Player::Player()
  : Task(),
  positionX_(kPlayerInitPosX),
  positionY_(kPlayerInitPosY),
  player_state_(PlayerState::kStraight),
  player_handle_array_{0, 0, 0, 0}
{
}

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

  // 入力処理
  InputManager *input_manager = InputManager::GetInstance();
  // 右
  if (input_manager->IsPushThisFrame(InputManager::GameKeyKind::kRight))
  {
    player_state_ = PlayerState::kRightBank;
    
    positionX_ += kPlayerBankVelocity;

    // 画面外に出ないようにする
    // 画像のサイズを考慮
    if (positionX_ >= kBgEndRight - kPlayerImageDivSizeX)
    {
      positionX_ = kBgEndRight - kPlayerImageDivSizeX;
    }
    else if (positionX_ < kBgEndLeft)
    {
      positionX_ = kBgEndLeft;
    }
  }
  // 左
  else if (input_manager->IsPushThisFrame(InputManager::GameKeyKind::kLeft))
  {
    player_state_ = PlayerState::kLeftBank;
    positionX_ -= kPlayerBankVelocity;

    // 画面外に出ないようにする
    if (positionX_ > kBgEndRight - kPlayerImageDivSizeX)
    {
      positionX_ = kBgEndRight - kPlayerImageDivSizeX;
    }
    else if (positionX_ <= kBgEndLeft)
    {
      positionX_ = kBgEndLeft;
    }
  }
  // 上
  else if (input_manager->IsPushThisFrame(InputManager::GameKeyKind::kUp))
  {
    player_state_ = PlayerState::kStraight;
    positionY_ -= kPlayerStraightVelocity;

    // 画面外に出ないようにする
    if (positionY_ > kBgEndBottom - kPlayerImageDivSizeY)
    {
      positionY_ = kBgEndBottom - kPlayerImageDivSizeY;
    }
    else if (positionY_ <= kBgEndTop)
    {
      positionY_ = kBgEndTop;
    }
  }
  // 下
  else if (input_manager->IsPushThisFrame(InputManager::GameKeyKind::kDown))
  {
    player_state_ = PlayerState::kStraight;
    positionY_ += kPlayerBackVelocity;

    // 画面外に出ないようにする
    if (positionY_ >= kBgEndBottom - kPlayerImageDivSizeY)
    {
      positionY_ = kBgEndBottom - kPlayerImageDivSizeY;
    }
    else if (positionY_ < kBgEndTop)
    {
      positionY_ = kBgEndTop;
    }
  }
  else if (input_manager->IsPushThisFrame(InputManager::GameKeyKind::kPlayerFire))
  {
    // fire
  };
}

void Player::Render()
{
  //状態をハンドル指定に変換
  int drawHandleNum = static_cast<int>(player_state_);

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
    //player_state_ = PlayerState::kError;
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

  // 画像の読み込みに失敗
  if (result == -1)
  {
    // エラーログを出力
    printfDx("画像の読み込みに失敗しました\n");
    //TODO: とりあえずkErrorにしておくけど、その後の処理はまだ未定
    //player_state_ = PlayerState::kError;
  }
}

void Player::RemovePlayerImage()
{
  for (int handle : player_handle_array_)
  {
    DeleteGraph(handle);
  }
}

void Player::BeginPlayer()
{
  // 仮実装
  // 画像の読み込み
  //CAUTION: DxLib_Init()が呼ばれていることが前提
  LoadPlayerImage();
}
