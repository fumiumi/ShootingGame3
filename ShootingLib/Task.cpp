#include "Task.h"

void Task::SetTaskId(TaskId task_id)
{
  task_id_ = task_id;
}

TaskId Task::GetTaskId()
{
  return task_id_;
}


bool Task::IsRelease()
{
  return is_release_;
}

void Task::SetRelease()
{
  is_release_ = true;
}

void Task::Update(float delta_time)
{
  // �h���N���X�Ŏ���
}

void Task::Render()
{
  // �h���N���X�Ŏ���
}