#include "GameInfo.h"

/// <summary>
/// �萔��ێ����閳�����O���
/// </summary>
namespace
{
  int kWidth = 1280;
  int kHeight = 720;
  int kColorBit = 32;
}

/// <summary>
/// �C���X�^���X��nullptr�ŏ�����
/// </summary>
GameInfo *GameInfo::instance_ = nullptr;

std::mutex GameInfo::mutex_;

/// <summary>
/// GetInstance()����Ăяo���R���X�g���N�^
/// </summary>
GameInfo::GameInfo() :
  x_resolution_(kWidth),
  y_resolution_(kHeight),
  x_center_(kWidth / 2),
  y_center_(kHeight / 2),
  color_bit_(kColorBit),
  is_end_game_(false),
  is_debug_display_(false)
{
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
GameInfo::~GameInfo() = default;

/// <summary>
/// x�����̉�ʉ𑜓x���擾���郁���o�֐�
/// </summary>
/// <returns>x�����̉�ʉ𑜓x�𐮐��ŕԂ�</returns>
int GameInfo::GetResolutionX()
{
  return instance_->x_resolution_;
}

/// <summary>
/// y�����̉�ʉ𑜓x���擾���郁���o�֐�
/// </summary>
/// <returns>y�����̉�ʉ𑜓x�𐮐��ŕԂ�</returns>
int GameInfo::GetResolutionY()
{
  return instance_->y_resolution_;
}

/// <summary>
/// ��ʂ̒��S���W��x�������擾���郁���o�֐�
/// </summary>
/// <returns>���S���W��x����</returns>
int GameInfo::GetCenterX()
{
  return instance_->x_center_;
}

/// <summary>
/// ��ʂ̒��S���W��y�������擾���郁���o�֐�
/// </summary>
/// <returns>���S���W��y����</returns>
int GameInfo::GetCenterY()
{
  return instance_->y_center_;
}

/// <summary>
/// �J���[�r�b�g�����擾���郁���o�֐�
/// </summary>
/// <returns>�J���[�r�b�g��</returns>
int GameInfo::GetColorBit()
{
  return instance_->color_bit_;
}

/// <summary>
/// �f�o�b�O���[�h�̏����擾
/// </summary>
/// <returns>�f�o�b�O�\������Ȃ�true</returns>
bool GameInfo::IsDebugDisplay()
{
  return instance_->is_debug_display_;
}

/// <summary>
/// �f�o�b�O���[�h�ɉ����ĕ\����؂�ւ���
/// </summary>
/// <param name="is_debug">true��n������f�o�b�O���[�h</param>
void GameInfo::SetDebugDisplay(bool is_debug)
{
  instance_->is_debug_display_ = is_debug;
}

/// <summary>
/// �Q�[���I���t���O�̐ݒ�
/// </summary>
/// <returns>true�Ȃ�I��</returns>
bool GameInfo::IsEndGame()
{
  return instance_->is_end_game_;
}

/// <summary>
/// �Q�[���I���t���O���Z�b�g
/// </summary>
/// <param name="is_end_game">�ݒ肷��Q�[���I���t���O</param>
void GameInfo::SetEndGame(bool is_end_game)
{
  instance_->is_end_game_ = is_end_game;
}