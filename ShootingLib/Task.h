#pragma once

#include "TaskManager.h"

/// <summary>
/// タスク処理
/// 抽象クラス
/// </summary>
/// <remarks>
/// 各オブジェクトをTaskクラスから派生することで、
/// TaskManagerで一元管理する設計。
/// 必ずオーバーライドしてほしい関数は純粋仮想関数で用意し、
/// 各派生先クラスで専用処理を実装していく。
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
	/// タスクID
	/// </summary>
	TaskId task_id_;

	/// <summary>
	/// 解放するかの有無
	/// </summary>
	bool is_release_;
};
