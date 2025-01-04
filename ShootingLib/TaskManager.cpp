#include "TaskManager.h"
#include "Task.h"

//タスクマネージャーのインスタンス初期化
TaskManager *TaskManager::instance_ = nullptr;

/// <summary>
/// 割り当てるタスクIDの最初の数値
/// </summary>
const TaskId TaskManager::kStartTaskId = 100;

/// <summary>
/// コンストラクタ
/// </summary>
TaskManager::TaskManager()
  : task_list_()
    ,add_task_list_()
    ,release_task_list_()
    ,last_assigned_task_id_(0)
{
}

/// <summary>
/// デストラクタ
/// </summary>
TaskManager::~TaskManager()
{
}

/// <summary>
/// タスクを追加する
/// </summary>
/// <param name="task">追加するタスク</param>
/// <returns>発行したTaskId</returns>
TaskId TaskManager::AddTask(Task *task)
{
  //追加するタスクがnullptrなら失敗
  if (task == nullptr)
  {
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

  //タスクにIDを設定

  //追加リストに加える

  //発行したTaskIdを返す
  return assign_id;
}

/// <summary>
/// タスクを解放する
/// </summary>
/// <param name="task_id">タスクID</param>
/// <returns>成功：解放したタスク、失敗：nullptr</returns>
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

  //削除リストに追加

  return find_task;
}

/// <summary>
/// タスクの毎フレーム更新処理を実行する
/// </summary>
/// <param name="delta_time">最後のフレームを完了するのに要した時間 (秒) </param>
void TaskManager::UpdateTask(float delta_time)
{
  //タスクの毎フレーム更新処理
  for (std::vector<Task *>::iterator it = task_list_.begin(); it != task_list_.end(); ++it)
  {
    //解放フラグが立っているなら実行しない

    //タスクの更新
  }

  //追加タスクリストにあるタスクを追加

  //追加タスクリストをクリア
  add_task_list_.clear();

  //解放タスクリストにあるタスクIDのタスクを解放

  //解放タスクリストをクリア
  release_task_list_.clear();
}

/// <summary>
/// タスクの毎フレームの描画理を実行する
/// </summary>
void TaskManager::RenderTask()
{
  //タスクの毎フレーム描画処理
  for (std::vector<Task *>::iterator it = task_list_.begin(); it != task_list_.end(); ++it)
  {
    //解放フラグが立っているなら実行しない

    //タスクの描画
  }
}