#pragma once
#define WIN32_LEAN_AND_MEAN   

#include <mutex>

/// <summary>
/// �Q�[�����Ǘ��N���X
/// �ǂ̃��x���ł��K�v�ȋ��ʂ̃Q�[���̏����Ǘ�����B
/// </summary>
class GameInfo
{
public:
	/// <summary>
	/// GameInfo�̃C���X�^���X���擾����
	/// �i�V���O���g���f�U�C���p�^�[���j
	/// </summary>
	/// <returns>GameInfo�̃C���X�^���X</returns>
	static GameInfo *GetInstance()
	{
		//��������ĂȂ��Ȃ瓮�I����
		if (instance_ == nullptr)
		{
			instance_ = new GameInfo();
		}

		//GameInfo�̃C���X�^���X��Ԃ�
		return instance_;
	}

	/// <summary>
	/// GameInfo�̃C���X�^���X���폜
	/// �Q�[���I�����ɕK���Ă�
	/// </summary>
	static void Destroy()
	{
		//�����ς݂Ȃ�폜
		if (instance_ != nullptr)
		{
			delete instance_;
			instance_ = nullptr;
		}
	}

	/// <summary>
	/// �𑜓x�̉����̃T�C�Y���擾
	/// </summary>
	/// <returns>�𑜓x�̉����̃T�C�Y</returns>
	int GetResolutionX();

	/// <summary>
	/// �𑜓x�̏c���̃T�C�Y���擾
	/// </summary>
	/// <returns>�𑜓x�̏c���̃T�C�Y</returns>
	int GetResolutionY();

	/// <summary>
	/// ��ʉ����̒��S���W���擾
	/// </summary>
	/// <returns>��ʉ����̒��S���W</returns>
	int GetCenterX();

	/// <summary>
	/// ��ʏc���̒��S���W���擾
	/// </summary>
	/// <returns>��ʏc���̒��S���W</returns>
	int GetCenterY();

	/// <summary>
	/// �J���[�r�b�g�����擾
	/// </summary>
	/// <returns>�J���[�r�b�g��</returns>
	int GetColorBit();

	/// <summary>
	/// �f�o�b�O���[�h�̏����擾
	/// </summary>
	/// <returns>�f�o�b�O�\������Ȃ�true</returns>
	bool IsDebugDisplay();

	/// <summary>
	/// �f�o�b�O���[�h�ɉ����ĕ\����؂�ւ���
	/// </summary>
	/// <param name="is_debug">true��n������f�o�b�O���[�h</param>
	void SetDebugDisplay(bool is_debug);

	/// <summary>
	/// �Q�[���I���t���O�̐ݒ�
	/// </summary>
	/// <returns>true�Ȃ�I��</returns>
	bool IsEndGame();

	/// <summary>
	/// �Q�[���I���t���O���Z�b�g
	/// </summary>
	/// <param name="is_end_game">�ݒ肷��Q�[���I���t���O</param>
	void SetEndGame(bool is_end_game);

private:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	GameInfo();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~GameInfo();

	/// <summary>
	/// �Q�[�����C���X�^���X
	/// �i�V���O���g���p�̐ÓI�C���X�^���X�j
	/// </summary>
	static GameInfo *instance_;

	static std::mutex mutex_;

	/// <summary>
	/// �𑜓x�̉����T�C�Y
	/// </summary>
	int x_resolution_;

	/// <summary>
	/// �𑜓x�̏c���T�C�Y
	/// </summary>
	int y_resolution_;

	/// <summary>
	/// ��ʉ����̒��S���W
	/// </summary>
	int x_center_;

	/// <summary>
	/// ��ʏc���̒��S���W
	/// </summary>
	int y_center_;

	/// <summary>
	/// �J���[�r�b�g��
	/// </summary>
	int color_bit_;

	/// <summary>
	/// �f�o�b�O���[�h�̃t���O
	/// </summary>
	bool is_debug_display_;

	/// <summary>
	/// �Q�[���I���̃t���O
	/// </summary>
	bool is_end_game_;
};
