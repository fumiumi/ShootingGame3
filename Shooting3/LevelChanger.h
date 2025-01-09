#pragma once

#include "Task.h"

//�O���錾
class LevelBase;

/// <summary>
/// ���x���̐؂�ւ����Ǘ�����N���X
/// </summary>
class LevelChanger : public Task
{
public:
	/// <summary>
	/// ���x���`�F���W���[�̏��
	/// </summary>
	enum class LevelChangerState
	{
		/// <summary>
		/// �ҋ@
		/// </summary>
		kWait,

		/// <summary>
		/// �^�C�g�����x���̏�����
		/// </summary>
		kInitTitleLevel,

		/// <summary>
		/// �^�C�g�����x���̌㏈��
		/// </summary>
		kFinTitleLevel,

		/// <summary>
		/// �o�g�����x���̏�����
		/// </summary>
		kInitBattleLevel,

		/// <summary>
		/// �o�g�����x���̌㏈��
		/// </summary>
		kFinBattleLevel,

		/// <summary>
		/// ���݃��x���Ɋ֘A����I�u�W�F�N�g�̔j��
		/// </summary>
		kDestroyCurrentLevel,
	};

	/// <summary>
	/// LevelChanger�̃C���X�^���X���擾����
	/// �i�V���O���g���f�U�C���p�^�[���j
	/// </summary>
	/// <returns></returns>
	static LevelChanger *GetInstance()
	{
		//��������ĂȂ��Ȃ瓮�I����
		if (instance_ == nullptr)
		{
			instance_ = new LevelChanger();
		}

		//LevelChanger�̃C���X�^���X��Ԃ�
		return instance_;
	}

	/// <summary>
	/// LevelChanger�̃C���X�^���X���폜
	/// �Q�[���I�����ɕK���Ă�
	/// </summary>
	static void Destory()
	{
		//�����ς݂Ȃ�폜
		if (instance_ != nullptr)
		{
			delete instance_;
			instance_ = nullptr;
		}
	}

	/// <summary>
	/// ���x���`�F���W���[�̏�Ԃ�ݒ肷��
	/// </summary>
	/// <param name="level_changer_state">�ݒ肷����</param>
	void SetLevelChangerState(LevelChangerState level_changer_state);

	/// <summary>
	/// ���t���[���̍X�V����
	/// </summary>
	/// <param name="delta_time">�O����s�t���[������̌o�ߎ��ԁi�b�j</param>
	void Update(float delta_time) override;

	/// <summary>
	/// ���݂̃��x���������j��
	/// �E�B���h�E�́~�{�^���ŃQ�[�����I�������ꍇ�Ȃǂ̑Ή�
  /// �^�X�N�}�l�[�W���[�����������
	/// </summary>
	void ForceDestroyCurrentLevel();

private:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	explicit LevelChanger();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~LevelChanger() override;

	/// <summary>
	/// LevelChanger�̃C���X�^���X
	/// </summary>
	static LevelChanger *instance_;

	/// <summary>	
	/// ���x���`�F���W���[�̏��
	/// </summary>
	LevelChangerState current_level_changer_state_;

	/// <summary>
	/// ���݂̃��x��
	/// ���x���F
	/// TitleLevel
	/// BattleLevel
	/// </summary>
	LevelBase *current_level_;

	/// <summary>
	/// ���݂̃��x���j����̃��x���`�F���W���[�̏��
	/// </summary>
	LevelChangerState next_level_changer_state_after_destroy_;

};