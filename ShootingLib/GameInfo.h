#pragma once

/// <summary>
/// �Q�[�����Ǘ��N���X
/// �ǂ̃��x���ł��K�v�ȋ��ʂ̃Q�[���̏����Ǘ�����B
/// </summary>
class GameInfo
{
public:
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

	static void Destroy()
	{
		//�����ς݂Ȃ�폜
		if (instance_ != nullptr)
		{
			delete instance_;
			instance_ = nullptr;
		}
	}

	int GetResolutionX();
	int GetResolutionY();

	int GetCenterX();
	int GetCenterY();

  int GetMinPosX();
  int GetMaxPosX();

  int GetPlayerImageWidth();
  int GetPlayerImageHeight();

  int GetTackleEnemyImageWidth();
  int GetTackleEnemyImageHeight();

	int GetColorBit();

	bool IsDebugDisplay();

	/// <summary>
	/// �f�o�b�O���[�h�ɉ����ĕ\����؂�ւ���
	/// </summary>
	/// <param name="is_debug">true��n������f�o�b�O���[�h</param>
	void SetDebugDisplay(bool is_debug);

	bool IsEndGame();

	void SetEndGame(bool is_end_game);

private:
	GameInfo();
	~GameInfo() = default;

	static GameInfo *instance_;

	int x_resolution_;
	int y_resolution_;

	int x_center_;
	int y_center_;

	int color_bit_;

	bool is_debug_display_;

	bool is_end_game_;

};
