#include <DxLib.h>
#include <crtdbg.h>
#include <GameInfo.h>

//メモリリーク検出のために必要
#if defined(_WIN64) || defined(_WIN32)
#include <windows.h>
#endif

/// <summary>
/// メイン処理用の無名名前空間(内部リンケージ)
/// </summary>
namespace
{
	/// <summary>
	/// 1000ミリ秒（1秒）
	/// </summary>
	const int kOneMillisecond = 1000;

	/// <summary>
	/// 目標FPS
	/// </summary>
	const int kTargetFps = 60;

	/// <summary>
	/// 1フレームの時間（秒）
	/// </summary>
	const float kOneFrameTimeSecond = (static_cast<float>(kOneMillisecond) / static_cast<float>(kTargetFps)) / kOneMillisecond;

	/// <summary>
	/// 現在の時間（ミリ秒）
	/// </summary>
	int current_time_millisecond = 0;

	/// <summary>
	/// 前回のフレーム実行時の時間（ミリ秒）
	/// </summary>
	int last_frame_time_millisecond = 0;

	/// <summary>
	/// フレーム数のカウント用
	/// </summary>
	int frame_count = 0;

	/// <summary>
	/// 最後にフレームレートを更新した時間（ミリ秒）
	/// </summary>
	int last_update_frame_rate_time_millisecond = 0;

	/// <summary>
	/// 算出したフレームレート格納用
	/// </summary>
	float frame_rate = 0.0f;
}

/// <summary>
/// フレームレート計算用
/// </summary>
void CalcFrameRate();

/// <summary>
/// フレームレート描画用
/// </summary>
void DrawFrameRate();

/// <summary>
/// プログラムは WinMain から始まります
/// </summary>
/// <param name="hInstance">アプリケーションの現在のインスタンスハンドル</param>
/// <param name="hPrevInstance">Win16 の産物（常にNULL）</param>
/// <param name="lpCmdLine">コマンドライン引数</param>
/// <param name="nCmdShow">ウィンドウの表示状態</param>
/// <returns>アプリケーションの終了コード</returns>
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//メモリリーク検出のために記述
#if defined(_WIN64) || defined(_WIN32)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	//ログファイルは出力しない設定にする
	SetOutApplicationLogValidFlag(FALSE);

	//ウィンドウモードに設定
	ChangeWindowMode(TRUE);

  GameInfo *game_info = GameInfo::GetInstance();

	//ウィンドウサイズとカラービットを設定
	//（値は後ほど定数化します）
  SetGraphMode(game_info->GetResolutionX(), game_info->GetResolutionY(), game_info->GetColorBit());

	//DXライブラリの初期化
	if (DxLib_Init() == -1)
	{

		//初期化失敗は強制終了
		return -1;
	}

	//描画先の画面を裏画面に設定
	SetDrawScreen(DX_SCREEN_BACK);

	//ウィンドウが非アクティブになってもゲームは止めないようにする
	SetAlwaysRunFlag(true);

	//ゲームメインループ
	while (ProcessMessage() != -1)
	{
		//システムに処理を渡す
		Sleep(1);

		//現在の時間更新
		current_time_millisecond = GetNowCount();

		//経過時間が目標フレームレート分の1以上経過しているなら
		//フレームを実行する
		if (current_time_millisecond - last_frame_time_millisecond >= kOneMillisecond / kTargetFps)
		{
			//前回フレーム実行からの経過時間を秒で算出
			float delta_time = static_cast<float>(current_time_millisecond - last_frame_time_millisecond) / kOneMillisecond;

			//最後にフレームを実行した時間を更新
			last_frame_time_millisecond = current_time_millisecond;

			//フレーム実行のたびにFPSをカウントする
			++frame_count;

			//画面の消去
			ClearDrawScreen();

			//ウィンドウがアクティブなら実行する処理
			if (GetWindowActiveFlag() == TRUE)
			{
				//Update関連を呼ぶ
			}

			//描画関連を呼ぶ

			//フレームレートの計算
			CalcFrameRate();

			//フレームレートの描画
			DrawFrameRate();

			//経過時間を描画
			//（必要に応じて定数化してください）
			DrawFormatString(0, 16, GetColor(255, 30, 30), _T("delta_time[%.4f]"), delta_time);

			//表画面への出力
			ScreenFlip();
		}
	}

	//DXライブラリの終了処理
	DxLib_End();

	return 0;
}

/// <summary>
/// フレームレート計算用
/// </summary>
void CalcFrameRate()
{
	//前回のフレームレート更新からの経過時間を求める
	int diff_time = current_time_millisecond - last_update_frame_rate_time_millisecond;

	//前回のフレームレート更新から
	//1秒以上経過していたらフレームレートを更新する
	if (diff_time > kOneMillisecond)
	{
		//フレーム回数をミリ秒に合わせる
		//少数まで出したいのでfloatにキャスト
		float count = (float)(frame_count * kOneMillisecond);

		//フレームレートを求める
		//理想どうりなら 60000 / 1000 で 60 となる
		frame_rate = count / diff_time;

		//フレームカウントをクリア
		frame_count = 0;

		//フレームレート更新時間を更新
		last_update_frame_rate_time_millisecond = current_time_millisecond;
	}

}

/// <summary>
/// フレームレート描画用
/// </summary>
void DrawFrameRate()
{
	//フレームレートの描画
	//（必要に応じて定数化してください）
	DrawFormatString(0, 0, GetColor(255, 30, 30), _T("FPS[%.2f]"), frame_rate);
}