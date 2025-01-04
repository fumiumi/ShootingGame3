#include "TaskManager.h"
#include "Task.h"

//�^�X�N�}�l�[�W���[�̃C���X�^���X������
TaskManager *TaskManager::instance_ = nullptr;

/// <summary>
/// ���蓖�Ă�^�X�NID�̍ŏ��̐��l
/// </summary>
const TaskId TaskManager::kStartTaskId = 100;

/// <summary>
/// �R���X�g���N�^
/// </summary>
TaskManager::TaskManager()
  : task_list_()
    ,add_task_list_()
    ,release_task_list_()
    ,last_assigned_task_id_(0)
{
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
TaskManager::~TaskManager()
{
}

/// <summary>
/// �^�X�N��ǉ�����
/// </summary>
/// <param name="task">�ǉ�����^�X�N</param>
/// <returns>���s����TaskId</returns>
TaskId TaskManager::AddTask(Task *task)
{
  //�ǉ�����^�X�N��nullptr�Ȃ玸�s
  if (task == nullptr)
  {
    return -1;
  }

  //���̒ǉ��Ȃ�
  if (last_assigned_task_id_ == 0)
  {
    //�J�n�^�X�NID��ݒ�
    last_assigned_task_id_ = kStartTaskId;
  }

  //�O�񊄂�U����ID��+1���Ċ���U��
  TaskId assign_id = last_assigned_task_id_ + 1;

  //�O�񊄂�U����ID���X�V

  //�^�X�N��ID��ݒ�

  //�ǉ����X�g�ɉ�����

  //���s����TaskId��Ԃ�
  return assign_id;
}

/// <summary>
/// �^�X�N���������
/// </summary>
/// <param name="task_id">�^�X�NID</param>
/// <returns>�����F��������^�X�N�A���s�Fnullptr</returns>
Task *TaskManager::ReleaseTask(TaskId task_id)
{
  Task *find_task = nullptr;

  //�^�X�N��������
  for (std::vector<Task *>::iterator it = task_list_.begin(); it != task_list_.end(); ++it)
  {
    //�Y��ID�̃^�X�N�𔭌�����
    if (task_id == (*it)->GetTaskId())
    {
      find_task = (*it);
    }
  }

  //������Ȃ�������I��
  if (find_task == nullptr)
  {
    return nullptr;
  }

  //�^�X�N�ɉ���t���O��ݒ肷��

  //�폜���X�g�ɒǉ�

  return find_task;
}

/// <summary>
/// �^�X�N�̖��t���[���X�V���������s����
/// </summary>
/// <param name="delta_time">�Ō�̃t���[������������̂ɗv�������� (�b) </param>
void TaskManager::UpdateTask(float delta_time)
{
  //�^�X�N�̖��t���[���X�V����
  for (std::vector<Task *>::iterator it = task_list_.begin(); it != task_list_.end(); ++it)
  {
    //����t���O�������Ă���Ȃ���s���Ȃ�

    //�^�X�N�̍X�V
  }

  //�ǉ��^�X�N���X�g�ɂ���^�X�N��ǉ�

  //�ǉ��^�X�N���X�g���N���A
  add_task_list_.clear();

  //����^�X�N���X�g�ɂ���^�X�NID�̃^�X�N�����

  //����^�X�N���X�g���N���A
  release_task_list_.clear();
}

/// <summary>
/// �^�X�N�̖��t���[���̕`�旝�����s����
/// </summary>
void TaskManager::RenderTask()
{
  //�^�X�N�̖��t���[���`�揈��
  for (std::vector<Task *>::iterator it = task_list_.begin(); it != task_list_.end(); ++it)
  {
    //����t���O�������Ă���Ȃ���s���Ȃ�

    //�^�X�N�̕`��
  }
}