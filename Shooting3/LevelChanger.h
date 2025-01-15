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

	void Update(float delta_time) override;

	/// <summary>
	/// ���݂̃��x���������j��
	/// �E�B���h�E�́~�{�^���ŃQ�[�����I�������ꍇ�Ȃǂ̑Ή�
  /// �^�X�N�}�l�[�W���[�����������
	/// </summary>
	void ForceDestroyCurrentLevel();

private:
	explicit LevelChanger();

	virtual ~LevelChanger() override;

	static LevelChanger *instance_;

	/// <summary>	
	/// ���x���`�F���W���[�̏��
	/// </summary>
	LevelChangerState current_level_changer_state_;

	LevelBase *current_level_;

	/// <summary>
	/// ���݂̃��x���j����̃��x���`�F���W���[�̏��
	/// </summary>
	LevelChangerState next_level_changer_state_after_destroy_;

};