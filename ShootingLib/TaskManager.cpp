#include "TaskManager.h"
#include "Task.h"

//�^�X�N�}�l�[�W���[�̃C���X�^���X������
TaskManager *TaskManager::instance_ = nullptr;

const TaskId TaskManager::kStartTaskId = 100;

TaskManager::TaskManager()
  : task_list_(),
  add_task_list_(),
  release_task_list_(),
  last_assigned_task_id_(0)
{
}

TaskManager::~TaskManager()
{
}

TaskId TaskManager::AddTask(Task *task)
{
  //�ǉ�����^�X�N��nullptr�Ȃ玸�s
  if (task == nullptr)
  {
    //���s������ID��Ԃ�
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
  last_assigned_task_id_++;

  //�^�X�N��ID��ݒ�
  task->SetTaskId(assign_id);

  //�ǉ����X�g�ɉ�����
  add_task_list_.emplace_back(task);

  //���s����TaskId��Ԃ�
  return assign_id;
}

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
  //�J�����̂�UpdateTask�ōs��
  find_task->SetRelease();

  //�폜���X�g�ɒǉ�
  release_task_list_.emplace_back(find_task->GetTaskId());

  //Q: �Ȃ�SetRelease()�����̂�find_task��Ԃ��̂��H
  return find_task;
}

void TaskManager::UpdateTask(float delta_time)
{
  //���X�g���̃^�X�N�̖��t���[���X�V����
  for (std::vector<Task *>::iterator it = task_list_.begin(); it != task_list_.end(); ++it)
  {
    //����t���O�������Ă���Ȃ���s���Ȃ�
    if ((*it)->IsRelease())
    {
      continue;
    }

    //�^�X�N�̍X�V
    (*it)->Update(delta_time);
  }

  //�ǉ��^�X�N���X�g�ɂ���^�X�N��ǉ�
  for (std::vector<Task *>::iterator it = add_task_list_.begin(); it != add_task_list_.end(); ++it)
  {
    //�^�X�N���X�g�ɒǉ�
    task_list_.emplace_back((*it));
  }

  //�ǉ��^�X�N���X�g���N���A
  add_task_list_.clear();

  //����^�X�N���X�g�ɂ���^�X�NID�̃^�X�N�����
  for (std::vector<TaskId>::iterator it = release_task_list_.begin(); it != release_task_list_.end(); ++it)
  {
    //�^�X�N��������
    for (std::vector<Task *>::iterator it_task = task_list_.begin(); it_task != task_list_.end(); ++it_task)
    {
      //�Y��ID�̃^�X�N�𔭌�����
      if ((*it) == (*it_task)->GetTaskId())
      {
        //�^�X�N���폜
        task_list_.erase(it_task);
        //�^�X�N�̉����TaskManager�̐Ӗ��ł͂Ȃ��̂�delete���Ȃ�
        break;
      }
    }
  }

  //����^�X�N���X�g���N���A
  release_task_list_.clear();
}

void TaskManager::RenderTask()
{
  //�^�X�N�̖��t���[���`�揈��
  for (auto it = task_list_.begin(); it != task_list_.end(); ++it)
  {
    //����t���O�������Ă���Ȃ���s���Ȃ�
    if ((*it)->IsRelease())
    {
      continue;
    }

    //�^�X�N�̕`��
    //���`�揇�͓o�^��
    (*it)->Render();
  }
}