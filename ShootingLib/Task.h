#pragma once

#include "TaskManager.h"

/// <summary>
/// �^�X�N����
/// ���ۃN���X
/// </summary>
/// <remarks>
/// �e�I�u�W�F�N�g��Task�N���X����h�����邱�ƂŁA
/// TaskManager�ňꌳ�Ǘ�����݌v�B
/// �K���I�[�o�[���C�h���Ăق����֐��͏������z�֐��ŗp�ӂ��A
/// �e�h����N���X�Ő�p�������������Ă����B
/// </remarks>
class Task
{
public:
	explicit Task();
	virtual ~Task();

  explicit Task(Task &&task) = default;
  Task &operator=(Task &&task) = default;

	void SetTaskId(TaskId task_id);
	TaskId GetTaskId();

	bool IsRelease();
	void SetRelease();

	virtual void Update(float delta_time);

	virtual void Render();

private:
	/// <summary>
	/// �^�X�NID
	/// </summary>
	TaskId task_id_;

	/// <summary>
	/// ������邩�̗L��
	/// </summary>
	bool is_release_;
};
