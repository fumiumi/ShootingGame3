#include "Task.h"

/// <summary>
/// コンストラクタ
/// </summary>
Task::Task()
  : task_id_(0)
  , is_release_(false)
{
}

//抽象クラスのため、デストラクタは純粋仮想関数

/// <summary>
/// タスクIDを設定
/// </summary>
/// <param name="task_id">設定するタスクID</param>
void Task::SetTaskId(TaskId task_id)
{
  task_id_ = task_id;
}

/// <summary>
/// タスクIDを取得する
/// </summary>
/// <returns>タスクID</returns>
TaskId Task::GetTaskId()
{
  return task_id_;
}

/// <summary>
/// 解放設定されているか
/// </summary>
/// <returns>解放設定されているならtrue</returns>
bool Task::IsRelease()
{
  return is_release_;
}

/// <summary>
/// 解放を設定する
/// </summary>
void Task::SetRelease()
{
  is_release_ = true;
}

/// <summary>
/// 毎フレームの更新処理
/// </summary>
/// <param name="delta_time">前回実行フレームからの経過時間（秒)</param>
void Task::Update(float delta_time)
{
  // 派生クラスで実装
}

/// <summary>
/// 毎フレームの描画処理
/// </summary>
void Task::Render()
{
  // 派生クラスで実装
}