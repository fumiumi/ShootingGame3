#pragma once
#define WIN32_LEAN_AND_MEAN   

#include <mutex>

/// <summary>
/// ゲーム情報管理クラス
/// どのレベルでも必要な共通のゲームの情報を管理する。
/// </summary>
class GameInfo
{
public:
	/// <summary>
	/// GameInfoのインスタンスを取得する
	/// （シングルトンデザインパターン）
	/// </summary>
	/// <returns>GameInfoのインスタンス</returns>
	static GameInfo *GetInstance()
	{
		//生成されてないなら動的生成
		if (instance_ == nullptr)
		{
			instance_ = new GameInfo();
		}

		//GameInfoのインスタンスを返す
		return instance_;
	}

	/// <summary>
	/// GameInfoのインスタンスを削除
	/// ゲーム終了時に必ず呼ぶ
	/// </summary>
	static void Destroy()
	{
		//生成済みなら削除
		if (instance_ != nullptr)
		{
			delete instance_;
			instance_ = nullptr;
		}
	}

	/// <summary>
	/// 解像度の横幅のサイズを取得
	/// </summary>
	/// <returns>解像度の横幅のサイズ</returns>
	int GetResolutionX();

	/// <summary>
	/// 解像度の縦幅のサイズを取得
	/// </summary>
	/// <returns>解像度の縦幅のサイズ</returns>
	int GetResolutionY();

	/// <summary>
	/// 画面横幅の中心座標を取得
	/// </summary>
	/// <returns>画面横幅の中心座標</returns>
	int GetCenterX();

	/// <summary>
	/// 画面縦幅の中心座標を取得
	/// </summary>
	/// <returns>画面縦幅の中心座標</returns>
	int GetCenterY();

	/// <summary>
	/// カラービット数を取得
	/// </summary>
	/// <returns>カラービット数</returns>
	int GetColorBit();

	/// <summary>
	/// デバッグモードの情報を取得
	/// </summary>
	/// <returns>デバッグ表示するならtrue</returns>
	bool IsDebugDisplay();

	/// <summary>
	/// デバッグモードに応じて表示を切り替える
	/// </summary>
	/// <param name="is_debug">trueを渡したらデバッグモード</param>
	void SetDebugDisplay(bool is_debug);

	/// <summary>
	/// ゲーム終了フラグの設定
	/// </summary>
	/// <returns>trueなら終了</returns>
	bool IsEndGame();

	/// <summary>
	/// ゲーム終了フラグをセット
	/// </summary>
	/// <param name="is_end_game">設定するゲーム終了フラグ</param>
	void SetEndGame(bool is_end_game);

private:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	GameInfo();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameInfo();

	/// <summary>
	/// ゲーム情報インスタンス
	/// （シングルトン用の静的インスタンス）
	/// </summary>
	static GameInfo *instance_;

	static std::mutex mutex_;

	/// <summary>
	/// 解像度の横幅サイズ
	/// </summary>
	int x_resolution_;

	/// <summary>
	/// 解像度の縦幅サイズ
	/// </summary>
	int y_resolution_;

	/// <summary>
	/// 画面横幅の中心座標
	/// </summary>
	int x_center_;

	/// <summary>
	/// 画面縦幅の中心座標
	/// </summary>
	int y_center_;

	/// <summary>
	/// カラービット数
	/// </summary>
	int color_bit_;

	/// <summary>
	/// デバッグモードのフラグ
	/// </summary>
	bool is_debug_display_;

	/// <summary>
	/// ゲーム終了のフラグ
	/// </summary>
	bool is_end_game_;
};
