//------------------------------------------------------------------------------
// Project Name: [プロジェクト名]
// File Name: [ファイル名]
// Description: [ファイルの簡単な説明]
// Author: [開発者名またはチーム名]
// Copyright [年] [著作者名または組織名]
// Created Date: [作成日]
// Last Updated: [最終更新日]
//------------------------------------------------------------------------------
#pragma once

#include <vector>

/// <summary>
/// int型のTaskIdのエイリアス宣言
/// </summary>
typedef unsigned int TaskId;

/// <summary>
/// Taskクラスの前方宣言
/// この.h内でTask*は扱えるようになる
/// </summary>
class Task;

/// <summary>
/// タスクマネージャー処理
/// </summary>
/// <remarks>
/// 各オブジェクトはタスクから派生してインスタンス化し、
/// タスクマネージャーではインスタンスを一元管理する
/// </remarks>
class TaskManager
{
public:
	/// <summary>
	/// TaskManagerのインスタンスを取得する
	/// （シングルトンデザインパターン）
	/// </summary>
	/// <returns>TaskManagerのインスタンス</returns>
	static TaskManager *GetInstance()
	{
    if (instance_ == nullptr)
    {
      instance_ = new TaskManager();
    }
    return instance_;
	}

	/// <summary>
	/// TaskManagerのインスタンスを削除
	/// ゲーム終了時に必ず呼ぶ
	/// </summary>
	static void Destroy()
	{
    if (instance_ != nullptr)
    {
      delete instance_;
      instance_ = nullptr;
    }
	}

	/// <summary>
	/// タスクを追加する
	/// </summary>
	/// <param name="task">追加するタスク</param>
	/// <returns>発行したTaskId</returns>
	TaskId AddTask(Task *task);

	/// <summary>
	/// タスクを解放する
	/// </summary>
	/// <param name="task_id">タスクID</param>
	/// <returns>成功：解放したタスク、失敗：nullptr</returns>
	Task *ReleaseTask(TaskId task_id);

	/// <summary>
	/// タスクの毎フレーム更新処理を実行する
	/// </summary>
	/// <param name="delta_time">最後のフレームを完了するのに要した時間 (秒) </param>
	void UpdateTask(float delta_time);

	/// <summary>
	/// タスクの毎フレームの描画理を実行する
	/// </summary>
	void RenderTask();

private:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	TaskManager();

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~TaskManager();

	/// <summary>
	/// TaskIDの開始番号
	/// </summary>
	static const TaskId kStartTaskId;

	/// <summary>
	/// TaskManagerのインスタンス
	/// </summary>
	static TaskManager *instance_;

	/// <summary>
	/// タスクリスト
	/// </summary>
	std::vector<Task *> task_list_;

	/// <summary>
	/// 追加タスクリスト
  /// Update中のリソースの確保・解放を防ぐ役割
	/// </summary>
	std::vector<Task *> add_task_list_;

	/// <summary>
	/// 解放タスクリスト
  /// 開放すべきタスクがわかれば良いのでIDだけを保持
	/// Update中のリソースの確保・解放を防ぐ役割
	/// </summary>
	std::vector<TaskId> release_task_list_;

	/// <summary>
	/// 最後に割り振ったタスクID
	/// </summary>
	int last_assigned_task_id_;
};