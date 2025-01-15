#pragma once

#include "Task.h"

/// <summary>
/// レベルの基本クラス
/// 各レベルはLevelBaseを派生して定義する
/// </summary>
class LevelBase : public Task
{

public:
	explicit LevelBase();
	virtual ~LevelBase();

	void Update(float delta_time) override;

	void Render() override;

	// 以下は各レベルオブジェクト固有の機能
	/// <summary>
	/// レベルの開始処理
	/// </summary>
	virtual void BeginLevel() = 0;

	/// <summary>
	/// レベル関連をタスクマネージャーから解放する
	/// </summary>
	virtual void ReleaseLevel() = 0;

	/// <summary>
	/// レベル関連を破棄
	/// </summary>
	virtual void DestroyLevel() = 0;
};