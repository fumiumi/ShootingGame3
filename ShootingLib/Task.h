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
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	explicit Task();

	/// <summary>
	/// �f�X�g���N�^
	/// �������z�֐�
	/// </summary>
	virtual ~Task() = 0;

  /// <summary>
  /// ���[�u�R���X�g���N�^
  /// </summary>
  /// <param name="task">���[�u���̉E�Ӓl�Q��</param>
  explicit Task(Task &&task) = default;
  /// <summary>
  /// ���[�u������Z�q
  /// </summary>
  /// <param name="task">���[�u���̉E�Ӓl�Q��</param>
  /// <returns>���[�u���s</returns>
  Task &operator=(Task &&task) = default;

	/// <summary>
	/// �^�X�NID��ݒ�
	/// </summary>
	/// <param name="task_id">�ݒ肷��^�X�NID</param>
	void SetTaskId(TaskId task_id);

	/// <summary>
	/// �^�X�NID���擾����
	/// </summary>
	/// <returns>�^�X�NID</returns>
	TaskId GetTaskId();

	/// <summary>
	/// ����ݒ肳��Ă��邩
	/// </summary>
	/// <returns>����ݒ肳��Ă���Ȃ�true</returns>
	bool IsRelease();

	/// <summary>
	/// �����ݒ肷��
	/// </summary>
	void SetRelease();

	/// <summary>
	/// ���t���[���X�V����
	/// </summary>
	/// <param name="delta_time">�O����s�t���[������̌o�ߎ��ԁi�b�j</param>
	virtual void Update(float delta_time);

	/// <summary>
	/// ���t���[���̕`�揈��
	/// </summary>
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
