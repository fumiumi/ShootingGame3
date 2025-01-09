#pragma once

#include "Task.h"

/// <summary>
/// ���x���̊�{�N���X
/// �e���x����LevelBase��h�����Ē�`����
/// </summary>
class LevelBase : public Task
{

public:

	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	explicit LevelBase();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~LevelBase();

	/// <summary>
	/// ���t���[���̍X�V����
	/// �h����̃��x���ŃI�[�o�[���C�h����
	/// </summary>
	/// <param name="delta_time">�O����s�t���[������̌o�ߎ��ԁi�b�j</param>
	void Update(float delta_time) override;

	/// <summary>
	/// ���t���[���̕`�揈��
	/// �h����̃��x���ŃI�[�o�[���C�h����
	/// </summary>
	void Render() override;

	// �ȉ��͊e���x���I�u�W�F�N�g�ŗL�̋@�\
	/// <summary>
	/// ���x���̊J�n����
	/// </summary>
	virtual void BeginLevel() = 0;

	/// <summary>
	/// ���x���֘A���^�X�N�}�l�[�W���[����������
	/// </summary>
	virtual void ReleaseLevel() = 0;

	/// <summary>
	/// ���x���֘A��j��
	/// </summary>
	virtual void DestroyLevel() = 0;
};