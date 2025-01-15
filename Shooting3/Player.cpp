#include <DxLib.h>
#include "Player.h"
#include "InputManager.h"
#include "GameInfo.h"

namespace
{
/// <summary>
/// �v���C���[�摜�̃t�@�C���p�X
/// ����F�f�t�H���g
/// �E��F�������͎�
/// �����F�E�����͎�
/// �E���F��
/// </summary>
const char *kPlayerImageFilePath = "E:/�Q�[���J��/�N���A�J/ShootingGame3/Shooting3/Assets/Image/Battle/Player/Player.png";

const int kPlayerImageDivX = 2;
const int kPlayerImageDivY = 2;
const int kPlayerImageDivSizeX = 64;
const int kPlayerImageDivSizeY = 64;

const int kPlayerStraightVelocity = 30;
const int kPlayerBankVelocity = 30;
const int kPlayerBackVelocity = 20;

const int kPlayerInitPosX = 640;
const int kPlayerInitPosY = 360;

const int kBgSizeX = 880; // BattleLevel.cpp���Q��
const int kBgSizeY = 720; // BattleLevel.cpp���Q��

// �v���C���[���ړ��ł���͈�
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
  // �摜�̉��
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
    //TODO: �G���[���̏������l����
  }

  // ���͏���
  InputManager *input_manager = InputManager::GetInstance();
  // �E
  if (input_manager->IsPushThisFrame(InputManager::GameKeyKind::kRight))
  {
    player_state_ = PlayerState::kRightBank;
    
    positionX_ += kPlayerBankVelocity;

    // ��ʊO�ɏo�Ȃ��悤�ɂ���
    // �摜�̃T�C�Y���l��
    if (positionX_ >= kBgEndRight - kPlayerImageDivSizeX)
    {
      positionX_ = kBgEndRight - kPlayerImageDivSizeX;
    }
    else if (positionX_ < kBgEndLeft)
    {
      positionX_ = kBgEndLeft;
    }
  }
  // ��
  else if (input_manager->IsPushThisFrame(InputManager::GameKeyKind::kLeft))
  {
    player_state_ = PlayerState::kLeftBank;
    positionX_ -= kPlayerBankVelocity;

    // ��ʊO�ɏo�Ȃ��悤�ɂ���
    if (positionX_ > kBgEndRight - kPlayerImageDivSizeX)
    {
      positionX_ = kBgEndRight - kPlayerImageDivSizeX;
    }
    else if (positionX_ <= kBgEndLeft)
    {
      positionX_ = kBgEndLeft;
    }
  }
  // ��
  else if (input_manager->IsPushThisFrame(InputManager::GameKeyKind::kUp))
  {
    player_state_ = PlayerState::kStraight;
    positionY_ -= kPlayerStraightVelocity;

    // ��ʊO�ɏo�Ȃ��悤�ɂ���
    if (positionY_ > kBgEndBottom - kPlayerImageDivSizeY)
    {
      positionY_ = kBgEndBottom - kPlayerImageDivSizeY;
    }
    else if (positionY_ <= kBgEndTop)
    {
      positionY_ = kBgEndTop;
    }
  }
  // ��
  else if (input_manager->IsPushThisFrame(InputManager::GameKeyKind::kDown))
  {
    player_state_ = PlayerState::kStraight;
    positionY_ += kPlayerBackVelocity;

    // ��ʊO�ɏo�Ȃ��悤�ɂ���
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
  //��Ԃ��n���h���w��ɕϊ�
  int drawHandleNum = static_cast<int>(player_state_);

  // �摜�̕`��
  int result = DrawGraph(
    positionX_,
    positionY_,
    player_handle_array_[drawHandleNum],
    TRUE
  );

  if (result == -1)
  {
    // �G���[���O���o��
    printfDx("�摜�̏o�͂Ɏ��s���܂���\n");
    //TODO: �Ƃ肠����kError�ɂ��Ă������ǁA���̌�̏����͂܂�����
    //player_state_ = PlayerState::kError;
  }
}


void Player::LoadPlayerImage()
{
  int result = LoadDivGraph(
    kPlayerImageFilePath,
    kPlayerImageDivNum, // �w�b�_��static�錾���Ă���
    kPlayerImageDivX,
    kPlayerImageDivY,
    kPlayerImageDivSizeX,
    kPlayerImageDivSizeY,
    player_handle_array_ // �z��̐擪�A�h���X��n��
  );

  // �摜�̓ǂݍ��݂Ɏ��s
  if (result == -1)
  {
    // �G���[���O���o��
    printfDx("�摜�̓ǂݍ��݂Ɏ��s���܂���\n");
    //TODO: �Ƃ肠����kError�ɂ��Ă������ǁA���̌�̏����͂܂�����
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
  // ������
  // �摜�̓ǂݍ���
  //CAUTION: DxLib_Init()���Ă΂�Ă��邱�Ƃ��O��
  LoadPlayerImage();
}
