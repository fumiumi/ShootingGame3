#include "DxLib.h"
#include "Player.h"

namespace
{
/// <summary>
/// �v���C���[�摜�̃t�@�C���p�X
/// �T�C�Y�F120x120�i60x60 x 4���j
/// ����F�f�t�H���g'
/// �E��F�������͎�
/// �����F�E�����͎�
/// �E���F��
/// </summary>
const char *kPlayerImageFilePath = "E:�Q�[���J��/�N���A�J/ShootingGame3/Shooting3/Assets/Image/Battle/Player/Player.png";

/// <summary>
/// x�����̕�����
/// </summary>
const int kPlayerImageDivX = 2;

/// <summary>
/// y�����̕�����
/// </summary>
const int kPlayerImageDivY = 2;

/// <summary>
/// �����摜�̉���
/// </summary>
const int kPlayerImageDivSizeX = 60;

/// <summary>
/// �����摜�̏c��
/// </summary>
const int kPlayerImageDivSizeY = 60;
}

Player::Player()
  : Task(),
  positionX_(0),
  positionY_(0),
  playerState_(PlayerState::kStraight)
{
  // �摜�̓ǂݍ���
 LoadPlayerImage();
}

Player::~Player()
{
  // �摜�̉��
  RemovePlayerImage();
}

void Player::Update(float delta_time)
{
  // �\������playerImageDivArray������
  if (playerState_ == PlayerState::kError)
  {
    return;
  }

  // ������
  playerState_ = PlayerState::kStraight;

}

void Player::Render()
{
  // �摜�̕`��
  DrawGraph(
    positionX_, 
    positionY_, 
    playerImageHandleArray_[static_cast<int>(playerState_)], 
    TRUE
  );
}

/// <summary>
/// ���@�̍��W��ݒ�
/// </summary>
/// <param name="x">x���W</param>
/// <param name="y">y���W</param>
void Player::SetPosition(int x, int y)
{
  positionX_ = x;
  positionY_ = y;
}

/// <summary>
/// x���W���擾
/// </summary>
/// <returns>x���W</returns>
int Player::GetPositionX() const
{
  return positionX_;
}

/// <summary>
/// y���W���擾
/// </summary>
/// <returns>y���W</returns>
int Player::GetPositionY() const
{
  return positionY_;
}

void Player::LoadPlayerImage()
{
  // LoadDivGraph�֐�
  // FileName:�����ǂݍ��݂���摜�t�@�C��������̃|�C���^
  // AllNum:�摜�̕�������
  // XNum, YNum:�摜�̉������ɑ΂��镪�����Əc�ɑ΂��镪����
  // SizeX, SizeY:�������ꂽ�摜��̑傫��
  // HandleBuf:�����ǂݍ��݂��ē����O���t�B�b�N�n���h����
  // �ۑ�����int�^�̔z��ւ̃|�C���^
  int result = LoadDivGraph(
    kPlayerImageFilePath,
    kPlayerImageDivNum, // �w�b�_��static�錾���Ă���
    kPlayerImageDivX,
    kPlayerImageDivY,
    kPlayerImageDivSizeX,
    kPlayerImageDivSizeY,
    playerImageHandleArray_ // �z��̐擪�A�h���X��n��
  );

  if (result == -1)
  {
    // �摜�̓ǂݍ��݂Ɏ��s
    // �G���[���O���o��
    printfDx("�摜�̓ǂݍ��݂Ɏ��s���܂���");
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


