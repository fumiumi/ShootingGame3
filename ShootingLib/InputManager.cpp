#include "InputManager.h"
#include "DxLib.h"

//タスクマネージャーのインスタンス初期化
InputManager *InputManager::instance_ = nullptr;

/// <summary>
/// InputManager.cppのみで使う定数
/// </summary>
namespace
{
/// <summary>
/// ゲームボタンに対応したDXライブラリ側のキー定数
/// リテラルはDXライブラリに定義されているものを使う
/// </summary>
const int kDxlibKeyKind[static_cast<int>(InputManager::GameKeyKind::kNum)] =
{
	//0x1C
	KEY_INPUT_RETURN,   //Decide：Enterキー (D_DIK_RETURN)
	//0x0E
	KEY_INPUT_BACK,     //Cancel：BackSpaceキー (D_DIK_BACK)
	//0xC8
	KEY_INPUT_UP,       //Up：上キー (D_DIK_UP)
	//0xD0
	KEY_INPUT_DOWN,     //Down：下キー (D_DIK_DOWN)
  //0xCB
	KEY_INPUT_LEFT,     //Left：左キー (D_DIK_LEFT)
  //0xCD
	KEY_INPUT_RIGHT,    //Right：右キー (D_DIK_RIGHT)
	//0x01
	KEY_INPUT_ESCAPE,   //Pause：Escキー (D_DIK_ESCAPE)
	//0x2A
	KEY_INPUT_LSHIFT,   //PlayerMoveSlow：プレイヤー減速 左Shiftキー (D_DIK_LSHIFT)
	//0x2C
	KEY_INPUT_Z,        //PlayerFire：プレイヤー弾発射 Zキー (D_DIK_Z)
};
}

InputManager::InputManager()
	: current_key_buffer_{ 0 },
		pre_key_buffer_{ 0 }
{
}

/// <summary>
/// 現在のフレームのキー情報をすべて更新
/// タスクマネージャーの更新の前に呼ぶ
/// </summary>
/// <param name="delta_time">前回実行フレームからの経過時間（秒）</param>
void InputManager::UpdateKeyStateAll(float delta_time)
{
	// 現在のキー情報を更新する
	// GetHitKeyStateAll 関数を使うにはまず
	// char 型変数 256 個の配列を宣言します。 
	// 必ず char 型で、数は 256 個でないといけません。
	GetHitKeyStateAll(current_key_buffer_);
}

/// <summary>
/// 現在のフレームのキー情報を記録
/// フレームの最後に呼ぶ
/// </summary>
/// <param name="delta_time">前回実行フレームからの経過時間（秒）</param>
void InputManager::RecordKeyStateAll(float delta_time)
{
	//現在のキー情報を記録しておく
	for (int i = 0; i < kKeyBufferSize; ++i) {
		pre_key_buffer_[i] = current_key_buffer_[i];
	}
}

/// <summary>
/// 引数のキーはこのフレームで押されたか
/// </summary>
/// <param name="key_kind">調べるキー</param>
/// <returns>押されているならtrue</returns>
bool InputManager::IsPushThisFrame(GameKeyKind game_key_kind)
{
	int target_key = kDxlibKeyKind[static_cast<int>(game_key_kind)];

	return (current_key_buffer_[target_key] == 1 && pre_key_buffer_[target_key] == 0);
}

/// <summary>
/// 引数のキーは押されているか
/// </summary>
/// <param name="game_key_kind">調べるキー</param>
/// <returns>押されているならtrue</returns>
bool InputManager::IsDown(GameKeyKind game_key_kind)
{
	int target_key = kDxlibKeyKind[static_cast<int>(game_key_kind)];

	//current_key_buffer_の値をチェックし
	//現在キーが押されているなら true を返す
	//そうでないなら false を返す
  if (current_key_buffer_[target_key] == 1)
  {
    return true;
  }
	else
	{
    return false;
	}
}
