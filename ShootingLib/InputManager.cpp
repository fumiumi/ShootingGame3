#include "InputManager.h"
#include "DxLib.h"

//�^�X�N�}�l�[�W���[�̃C���X�^���X������
InputManager *InputManager::instance_ = nullptr;

/// <summary>
/// InputManager.cpp�݂̂Ŏg���萔
/// </summary>
namespace
{
/// <summary>
/// �Q�[���{�^���ɑΉ�����DX���C�u�������̃L�[�萔
/// ���e������DX���C�u�����ɒ�`����Ă�����̂��g��
/// </summary>
const int kDxlibKeyKind[static_cast<int>(InputManager::GameKeyKind::kNum)] =
{
	//0x1C
	KEY_INPUT_RETURN,   //Decide�FEnter�L�[ (D_DIK_RETURN)
	//0x0E
	KEY_INPUT_BACK,     //Cancel�FBackSpace�L�[ (D_DIK_BACK)
	//0xC8
	KEY_INPUT_UP,       //Up�F��L�[ (D_DIK_UP)
	//0xD0
	KEY_INPUT_DOWN,     //Down�F���L�[ (D_DIK_DOWN)
  //0xCB
	KEY_INPUT_LEFT,     //Left�F���L�[ (D_DIK_LEFT)
  //0xCD
	KEY_INPUT_RIGHT,    //Right�F�E�L�[ (D_DIK_RIGHT)
	//0x01
	KEY_INPUT_ESCAPE,   //Pause�FEsc�L�[ (D_DIK_ESCAPE)
	//0x2A
	KEY_INPUT_LSHIFT,   //PlayerMoveSlow�F�v���C���[���� ��Shift�L�[ (D_DIK_LSHIFT)
	//0x2C
	KEY_INPUT_Z,        //PlayerFire�F�v���C���[�e���� Z�L�[ (D_DIK_Z)
};
}

InputManager::InputManager()
	: current_key_buffer_{ 0 },
		pre_key_buffer_{ 0 }
{
}

/// <summary>
/// ���݂̃t���[���̃L�[�������ׂčX�V
/// �^�X�N�}�l�[�W���[�̍X�V�̑O�ɌĂ�
/// </summary>
/// <param name="delta_time">�O����s�t���[������̌o�ߎ��ԁi�b�j</param>
void InputManager::UpdateKeyStateAll(float delta_time)
{
	// ���݂̃L�[�����X�V����
	// GetHitKeyStateAll �֐����g���ɂ͂܂�
	// char �^�ϐ� 256 �̔z���錾���܂��B 
	// �K�� char �^�ŁA���� 256 �łȂ��Ƃ����܂���B
	GetHitKeyStateAll(current_key_buffer_);
}

/// <summary>
/// ���݂̃t���[���̃L�[�����L�^
/// �t���[���̍Ō�ɌĂ�
/// </summary>
/// <param name="delta_time">�O����s�t���[������̌o�ߎ��ԁi�b�j</param>
void InputManager::RecordKeyStateAll(float delta_time)
{
	//���݂̃L�[�����L�^���Ă���
	for (int i = 0; i < kKeyBufferSize; ++i) {
		pre_key_buffer_[i] = current_key_buffer_[i];
	}
}

/// <summary>
/// �����̃L�[�͂��̃t���[���ŉ����ꂽ��
/// </summary>
/// <param name="key_kind">���ׂ�L�[</param>
/// <returns>������Ă���Ȃ�true</returns>
bool InputManager::IsPushThisFrame(GameKeyKind game_key_kind)
{
	int target_key = kDxlibKeyKind[static_cast<int>(game_key_kind)];

	return (current_key_buffer_[target_key] == 1 && pre_key_buffer_[target_key] == 0);
}

/// <summary>
/// �����̃L�[�͉�����Ă��邩
/// </summary>
/// <param name="game_key_kind">���ׂ�L�[</param>
/// <returns>������Ă���Ȃ�true</returns>
bool InputManager::IsDown(GameKeyKind game_key_kind)
{
	int target_key = kDxlibKeyKind[static_cast<int>(game_key_kind)];

	//current_key_buffer_�̒l���`�F�b�N��
	//���݃L�[��������Ă���Ȃ� true ��Ԃ�
	//�����łȂ��Ȃ� false ��Ԃ�
  if (current_key_buffer_[target_key] == 1)
  {
    return true;
  }
	else
	{
    return false;
	}
}
