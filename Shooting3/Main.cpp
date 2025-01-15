#include <DxLib.h>
#include <crtdbg.h>
#include <GameInfo.h>
#include <TaskManager.h>
#include "LevelChanger.h"
#include "Player.h"
#include "inputManager.h"

//メモリリーク検出のために必要
#if defined(_WIN64) || defined(_WIN32)
#include <windows.h>
#endif

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
		float count = static_cast<float>(frame_count * kOneMillisecond);

		//フレームレートを求める
		//理想どうりなら 60000 / 1000 で 60 となる
		frame_rate = count / diff_time;

		//フレームカウントをクリア
		frame_count = 0;

		//フレームレート更新時間を更新
		last_update_frame_rate_time_millisecond = current_time_millisecond;
	}
}

void DrawFrameRate()
{
	//フレームレートの描画
	//（必要に応じて定数化してください）
	DrawFormatString(0, 0, GetColor(255, 30, 30), _T("FPS[%.2f]"), frame_rate);
}

/// <summary>
/// プログラムは WinMain から始まります
/// </summary>
/// <param name="hInstance">アプリケーションの現在のインスタンスハンドル</param>
/// <param name="hPrevInstance">Win16 の産物（常にNULL）</param>
/// <param name="lpCmdLine">コマンドライン引数</param>
/// <param name="nCmdShow">ウィンドウの表示状態</param>
/// <returns>アプリケーションの終了コード</returns>
int WINAPI WinMain(
	_In_ HINSTANCE hInstance, 
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine, 
	_In_ int nCmdShow)
{
	//メモリリーク検出のために記述
#if defined(_WIN64) || defined(_WIN32)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	//ログファイルは出力しない設定にする
	SetOutApplicationLogValidFlag(FALSE);

	//ウィンドウモードに設定
  // これをフルスクリーンにするとデバッグ画面が見えなくなるので注意
	ChangeWindowMode(TRUE);

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

  //HACK: シングルトンが多すぎる。
  //ゲーム情報オブジェクトの初期化
  GameInfo *game_info = GameInfo::GetInstance();
  //タスクマネージャーのインスタンスを取得
  TaskManager *task_manager = TaskManager::GetInstance();
  //レベルチェンジャーのインスタンスを取得
  LevelChanger *level_changer = LevelChanger::GetInstance();
  //入力マネージャのインスタンスを取得
  InputManager *input_manager = InputManager::GetInstance();
	

  //タスクマネージャーにタスクを追加
  task_manager->AddTask(level_changer);

  //初期レベルを設定
  level_changer->SetLevelChangerState(LevelChanger::LevelChangerState::kInitTitleLevel);

	//ウィンドウサイズとカラービットを設定
	SetGraphMode(
		game_info->GetResolutionX(), 
		game_info->GetResolutionY(), 
		game_info->GetColorBit()
	);

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

			//ウィンドウがアクティブなら実行する処理
			if (GetWindowActiveFlag() == TRUE)
			{
        input_manager->UpdateKeyStateAll(delta_time);
				task_manager->UpdateTask(delta_time);
        input_manager->RecordKeyStateAll(delta_time);
			}

			//画面の消去
			ClearDrawScreen();

			//描画関連を呼ぶ
			task_manager->RenderTask();

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

  //メモリの開放
	game_info->Destroy();
  level_changer->ForceDestroyCurrentLevel();
	level_changer->Destory();
  task_manager->Destroy();
  input_manager->Destory();

	DxLib_End();

	return 0;
}
