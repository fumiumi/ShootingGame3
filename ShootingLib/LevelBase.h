#pragma once

#include "Task.h"

/// <summary>
/// ���x���̊�{�N���X
/// �e���x����LevelBase��h�����Ē�`����
/// </summary>
class LevelBase : public Task
{

public:
	explicit LevelBase();
	virtual ~LevelBase();

	void Update(float delta_time) override;

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