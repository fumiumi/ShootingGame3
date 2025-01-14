#include <DxLib.h>
#include "Player.h"

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

/// <summary>
/// x�����̕�����
/// </summary>
const int kPlayerImageDivX = 2;
/// <summary>
/// y�����̕�����
/// </summary>
const int kPlayerImageDivY = 2;
/// <summary>
/// ���������摜�̕�
/// </summary>
const int kPlayerImageDivSizeX = 64;
/// <summary>
/// ���������摜�̍���
/// </summary>
const int kPlayerImageDivSizeY = 64;
}

/// <summary>
/// �R���X�g���N�^
/// </summary>
Player::Player()
  : Task(),
  positionX_(640), // �}�W�b�N�i���o�[�͂�߂���
  positionY_(360), // ���}�W�b�N�i���o�[�͂�߂���
  player_state_(PlayerState::kStraight),
  player_handle_array_{0, 0, 0, 0}
{
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
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

  // ������
  // �摜�̓ǂݍ���
  //CAUTION: DxLib_Init()���Ă΂�Ă��邱�Ƃ��O��
  LoadPlayerImage();
  player_state_ = PlayerState::kStraight;
}

void Player::Render()
{
  //��Ԃ��n���h���w��ɕϊ�
  int drawHandleNum = static_cast<int>(player_state_);

  //DEBUG: �n���h���̒��g���m�F
  for (int i = 0; i < kPlayerImageDivNum; i++)
  {
    printfDx("handle[%d] is %d\n", i, player_handle_array_[i]);
  }

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
    player_state_ = PlayerState::kError;
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

  //handle_ = LoadGraph(kPlayerImageFilePath);

  // �摜�̓ǂݍ��݂Ɏ��s
  if (result == -1)
  {
    // �G���[���O���o��
    printfDx("�摜�̓ǂݍ��݂Ɏ��s���܂���\n");
    //TODO: �Ƃ肠����kError�ɂ��Ă������ǁA���̌�̏����͂܂�����
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
