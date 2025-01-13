#include "DxLib.h"
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
    positionX_(0),
    positionY_(0),
    playerState_(PlayerState::kStraight)
{
  // �摜�̓ǂݍ���
  //CAUTION: DxLib_Init()���Ă΂�Ă��邱�Ƃ��O��
 LoadPlayerImage();
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
  if (playerState_ == PlayerState::kError)
  {
    return;
  }

  // ������
  playerState_ = PlayerState::kStraight;
}

void Player::Render()
{
  //��Ԃ��n���h���w��ɕϊ�
  int drawHandleNum_ = static_cast<int>(playerState_);

  if (drawHandleNum_ < 0 || drawHandleNum_ >= kPlayerImageDivNum)
  {
    printfDx("�����ȃn���h���ԍ��ł�: %d", drawHandleNum_);
    playerState_ = PlayerState::kError;
    return;
  }

  // �摜�̕`��
  int result = DrawGraph(
    positionX_, 
    positionY_, 
    playerImageHandleArray_[drawHandleNum_],
    TRUE
  );

  if (result == -1)
  {
    // �G���[���O���o��
    printfDx("�摜�̏o�͂Ɏ��s���܂���");
    playerState_ = PlayerState::kError;
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
    playerImageHandleArray_ // �z��̐擪�A�h���X��n��
  );

  // �摜�̓ǂݍ��݂Ɏ��s
  if (result == -1)
  {
    // �G���[���O���o��
    printfDx("�摜�̓ǂݍ��݂Ɏ��s���܂���");
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
