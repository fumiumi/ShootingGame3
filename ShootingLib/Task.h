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
	/// <summary>
	/// コンストラクタ
	/// </summary>
	explicit Task() = default;

	/// <summary>
	/// デストラクタ
	/// 純粋仮想関数
	/// </summary>
	virtual ~Task() = 0;

  /// <summary>
  /// ムーブコンストラクタ
  /// </summary>
  /// <param name="task">ムーブ元の右辺値参照</param>
  explicit Task(Task &&task) = default;
  /// <summary>
  /// ムーブ代入演算子
  /// </summary>
  /// <param name="task">ムーブ元の右辺値参照</param>
  /// <returns>ムーブ実行</returns>
  Task &operator=(Task &&task) = default;

	/// <summary>
	/// タスクIDを設定
	/// </summary>
	/// <param name="task_id">設定するタスクID</param>
	void SetTaskId(TaskId task_id);

	/// <summary>
	/// タスクIDを取得する
	/// </summary>
	/// <returns>タスクID</returns>
	TaskId GetTaskId();

	/// <summary>
	/// 解放設定されているか
	/// </summary>
	/// <returns>解放設定されているならtrue</returns>
	bool IsRelease();

	/// <summary>
	/// 解放を設定する
	/// </summary>
	void SetRelease();

	/// <summary>
	/// 毎フレーム更新処理
	/// </summary>
	/// <param name="delta_time">前回実行フレームからの経過時間（秒）</param>
	virtual void Update(float delta_time) = 0;

	/// <summary>
	/// 毎フレームの描画処理
	/// </summary>
	virtual void Render() = 0;

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
