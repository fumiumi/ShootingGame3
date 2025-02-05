#include "TaskManager.h"
#include "Task.h"

//タスクマネージャーのインスタンス初期化
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
  //追加するタスクがnullptrなら失敗
  if (task == nullptr)
  {
    //失敗を示すIDを返す
    return -1;
  }

  //初の追加なら
  if (last_assigned_task_id_ == 0)
  {
    //開始タスクIDを設定
    last_assigned_task_id_ = kStartTaskId;
  }

  //前回割り振ったIDに+1して割り振り
  TaskId assign_id = last_assigned_task_id_ + 1;

  //前回割り振ったIDを更新
  last_assigned_task_id_++;

  //タスクにIDを設定
  task->SetTaskId(assign_id);

  //追加リストに加える
  add_task_list_.emplace_back(task);

  //発行したTaskIdを返す
  return assign_id;
}

Task *TaskManager::ReleaseTask(TaskId task_id)
{
  Task *find_task = nullptr;

  //タスクを見つける
  for (std::vector<Task *>::iterator it = task_list_.begin(); it != task_list_.end(); ++it)
  {
    //該当IDのタスクを発見した
    if (task_id == (*it)->GetTaskId())
    {
      find_task = (*it);
    }
  }

  //見つからなかったら終了
  if (find_task == nullptr)
  {
    return nullptr;
  }

  //タスクに解放フラグを設定する
  //開放自体はUpdateTaskで行う
  find_task->SetRelease();

  //削除リストに追加
  release_task_list_.emplace_back(find_task->GetTaskId());

  //Q: なぜSetRelease()したのにfind_taskを返すのか？
  return find_task;
}

void TaskManager::UpdateTask(float delta_time)
{
  //リスト内のタスクの毎フレーム更新処理
  for (std::vector<Task *>::iterator it = task_list_.begin(); it != task_list_.end(); ++it)
  {
    //解放フラグが立っているなら実行しない
    if ((*it)->IsRelease())
    {
      continue;
    }

    //タスクの更新
    (*it)->Update(delta_time);
  }

  //追加タスクリストにあるタスクを追加
  for (std::vector<Task *>::iterator it = add_task_list_.begin(); it != add_task_list_.end(); ++it)
  {
    //タスクリストに追加
    task_list_.emplace_back((*it));
  }

  //追加タスクリストをクリア
  add_task_list_.clear();

  //解放タスクリストにあるタスクIDのタスクを解放
  for (std::vector<TaskId>::iterator it = release_task_list_.begin(); it != release_task_list_.end(); ++it)
  {
    //タスクを見つける
    for (std::vector<Task *>::iterator it_task = task_list_.begin(); it_task != task_list_.end(); ++it_task)
    {
      //該当IDのタスクを発見した
      if ((*it) == (*it_task)->GetTaskId())
      {
        //タスクを削除
        task_list_.erase(it_task);
        //タスクの解放はTaskManagerの責務ではないのでdeleteしない
        break;
      }
    }
  }

  //解放タスクリストをクリア
  release_task_list_.clear();
}

void TaskManager::RenderTask()
{
  //タスクの毎フレーム描画処理
  for (auto it = task_list_.begin(); it != task_list_.end(); ++it)
  {
    //解放フラグが立っているなら実行しない
    if ((*it)->IsRelease())
    {
      continue;
    }

    //タスクの描画
    //※描画順は登録順
    (*it)->Render();
  }
}