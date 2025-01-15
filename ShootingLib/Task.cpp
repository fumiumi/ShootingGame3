#include "Task.h"

Task::Task()
  : task_id_(0)
  , is_release_(false)
{
}

Task::~Task() = default;

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
  // ”h¶ƒNƒ‰ƒX‚ÅÀ‘•
}

void Task::Render()
{
  // ”h¶ƒNƒ‰ƒX‚ÅÀ‘•
}