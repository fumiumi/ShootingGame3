#pragma once

/// <summary>
/// インプットマネージャー処理
/// </summary>
/// <remarks>
/// キーボードやパッドからの入力を管理する
/// （サンプルなのでパッドは未実装）
/// </remarks>
class InputManager
{
public:
	/// <summary>
	/// 使用するゲームでのキーの種類
	/// </summary>
	enum class GameKeyKind
	{
		/// <summary>
		/// 決定
		/// </summary>
		kDecide,
		/// <summary>
		/// キャンセル
		/// </summary>
		kCancel,
		/// <summary>
		/// 上ボタン
		/// </summary>
		kUp,
		/// <summary>
		/// 下ボタン
		/// </summary>
		kDown,
		/// <summary>
		/// 左ボタン
		/// </summary>
		kLeft,
		/// <summary>
		/// 右ボタン
		/// </summary>
		kRight,
		/// <summary>
		/// ポーズ
		/// </summary>
		kPause,
		/// <summary>
		/// プレイヤー減速
		/// </summary>
		kPlayerMoveSlow,
		/// <summary>
		/// プレイヤーバレット発射
		/// </summary>
		kPlayerFire,
		/// <summary>
		/// 総数
		/// </summary>
		kNum,
	};

	static InputManager *GetInstance()
  {
    //生成されていないなら生成
    if (instance_ == nullptr) {
      instance_ = new InputManager();
    }
    return instance_;
  }

	static void Destory()
	{
		////生成済みなら削除
		//if (instance_ != nullptr) {
		//	delete instance_;
		//	instance_ = nullptr;
		//}
    //自動破棄なので何もしない
	}

	/// <summary>
	/// タスクの更新の前に呼ばれる関数
	/// </summary>
	/// <param name="delta_time">前回実行フレームからの経過時間（秒）</param>
	void UpdateKeyStateAll(float delta_time);

	/// <summary>
	/// タスクの更新の後に呼ばれる関数
	/// </summary>
	/// <param name="delta_time">前回実行フレームからの経過時間（秒）</param>
	void RecordKeyStateAll(float delta_time);

	/// <summary>
	/// 引数のキーはこのフレームで押されたか
	/// </summary>
	/// <param name="key_kind">調べるキー</param>
	/// <returns>押されているならtrue</returns>
	bool IsPushThisFrame(GameKeyKind game_key_kind);

	/// <summary>
	/// 引数のキーは押されているか
	/// </summary>
	/// <param name="game_key_kind">調べるキー</param>
	/// <returns>押されているならtrue</returns>
	bool IsDown(GameKeyKind game_key_kind);


private:
	InputManager();
	virtual ~InputManager() = default;

	static InputManager *instance_;

	/// <summary>
	/// キー状態を格納するバッファのサイズ
	/// </summary>
	static const int kKeyBufferSize = 256;

	/// <summary>
	/// 現在のフレームのキー情報
	/// GetHitKeyStateAll 関数を使うにはまず 
	/// char 型変数 256 個の配列を宣言します。 
	/// 必ず char 型で、数は 256 個でないといけません。
	/// </summary>
	char current_key_buffer_[kKeyBufferSize];

	/// <summary>
	/// 前回フレームのキー情報
	/// GetHitKeyStateAll 関数を使うにはまず 
	/// char 型変数 256 個の配列を宣言します。 
	/// 必ず char 型で、数は 256 個でないといけません。
	/// </summary>
	char pre_key_buffer_[kKeyBufferSize];
};