#pragma once

/// <summary>
/// ゲーム情報管理クラス
/// どのレベルでも必要な共通のゲームの情報を管理する。
/// </summary>
class GameInfo
{
public:
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

	static void Destroy()
	{
		//生成済みなら削除
		if (instance_ != nullptr)
		{
			delete instance_;
			instance_ = nullptr;
		}
	}

	int GetResolutionX();
	int GetResolutionY();

	int GetCenterX();
	int GetCenterY();

  int GetMinPosX();
  int GetMaxPosX();

  int GetPlayerImageWidth();
  int GetPlayerImageHeight();

  int GetTackleEnemyImageWidth();
  int GetTackleEnemyImageHeight();

	int GetColorBit();

	bool IsDebugDisplay();

	/// <summary>
	/// デバッグモードに応じて表示を切り替える
	/// </summary>
	/// <param name="is_debug">trueを渡したらデバッグモード</param>
	void SetDebugDisplay(bool is_debug);

	bool IsEndGame();

	void SetEndGame(bool is_end_game);

private:
	GameInfo();
	~GameInfo() = default;

	static GameInfo *instance_;

	int x_resolution_;
	int y_resolution_;

	int x_center_;
	int y_center_;

	int color_bit_;

	bool is_debug_display_;

	bool is_end_game_;

};
