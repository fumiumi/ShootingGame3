#include "Task.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
Task::Task()
  : task_id_(0)
  , is_release_(false)
{
}

//���ۃN���X�̂��߁A�f�X�g���N�^�͏������z�֐�

/// <summary>
/// �^�X�NID��ݒ�
/// </summary>
/// <param name="task_id">�ݒ肷��^�X�NID</param>
void Task::SetTaskId(TaskId task_id)
{
  task_id_ = task_id;
}

/// <summary>
/// �^�X�NID���擾����
/// </summary>
/// <returns>�^�X�NID</returns>
TaskId Task::GetTaskId()
{
  return task_id_;
}

/// <summary>
/// ����ݒ肳��Ă��邩
/// </summary>
/// <returns>����ݒ肳��Ă���Ȃ�true</returns>
bool Task::IsRelease()
{
  return is_release_;
}

/// <summary>
/// �����ݒ肷��
/// </summary>
void Task::SetRelease()
{
  is_release_ = true;
}

/// <summary>
/// ���t���[���̍X�V����
/// </summary>
/// <param name="delta_time">�O����s�t���[������̌o�ߎ��ԁi�b)</param>
void Task::Update(float delta_time)
{
  // �h���N���X�Ŏ���
}

/// <summary>
/// ���t���[���̕`�揈��
/// </summary>
void Task::Render()
{
  // �h���N���X�Ŏ���
}