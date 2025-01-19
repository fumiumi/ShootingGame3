#include "FadeManager.h"
#include "DxLib.h"
#include "GameInfo.h"

namespace
{
const char *kFadeImageFilePath = "E:/ゲーム開発/クリアカ/ShootingGame3/Shooting3/Assets/Image/Fade/FadeBlack.png";
}

FadeManager *FadeManager::instance_ = nullptr;

FadeManager::FadeManager()
  : fade_manager_state_(FadeManagerState::kNone),
    duration_(0.0f),
    fade_alpha_(0.0f),
    is_requested_(false)
{
  // いつでも呼び出せるようにあらかじめフェード用の画像を読み込んでおく
  fade_handle_ = LoadGraph(kFadeImageFilePath);
}

void FadeManager::RequestFadeIO(float duration, FadeManagerState mode)
{
  // １度リクエストされたら、フェードイン/アウトが終わるまでリクエストを受け付けない
  if (is_requested_)
  {
    return;
  }

  switch (mode)
  {
  case FadeManagerState::kNone:
    is_requested_ = true;
    return;
  case FadeManagerState::kFadeIn:
    fade_manager_state_ = FadeManagerState::kFadeIn;
    duration_ = duration;
    fade_alpha_ = 1.0f;
    break;
  case FadeManagerState::kFadeOut:
    fade_manager_state_ = FadeManagerState::kFadeOut;
    duration_ = duration;
    fade_alpha_ = 0.0f;
    break;
  }

  is_requested_ = true;
}

void FadeManager::RenderFade(float delta_time)
{
  if (!is_requested_)
  {
    return;
  }

  if (fade_manager_state_ == FadeManagerState::kNone)
  {
    //HACK: 万が一kNoneで指定されても、リクエストがサスペンドしないようにする
    is_requested_ = false;
    return;
  }

  // 指定したdurationとdelta_timeから、実時間でのフェードイン/アウトを行う

  // duration_ はミリ秒指定なので、秒に変換して使用する
  float fade_duration_sec = duration_ / 1000.0f;
  // フェード速度の計算
  float fade_speed_per_sec = 1.0f / fade_duration_sec;
  // 今フレームで変化させるアルファ量
  float delta_alpha = fade_speed_per_sec * delta_time;

  // フェードイン/アウト処理
  if (fade_manager_state_ == FadeManagerState::kFadeIn)
  {
    fade_alpha_ -= delta_alpha;
    if (fade_alpha_ <= 0.0f)
    {
      fade_alpha_ = 0.0f;

      // フェードイン終了
      fade_manager_state_ = FadeManagerState::kNone;
      is_requested_ = false;
    }
  }
  else if (fade_manager_state_ == FadeManagerState::kFadeOut)
  {
    fade_alpha_ += delta_alpha;
    if (fade_alpha_ >= 1.0f)
    {
      fade_alpha_ = 1.0f;

      // フェードアウト終了
      fade_manager_state_ = FadeManagerState::kNone;
      is_requested_ = false;
    }
  }
  // フェード描画
  GameInfo *game_info = GameInfo::GetInstance();

  SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(fade_alpha_ * 255));
  DrawExtendGraph(0, 0,game_info->GetResolutionX(), game_info->GetResolutionY(), fade_handle_, TRUE);

  // 描画終了後は、ブレンドモードを元に戻す
  if (fade_alpha_ == 0.0f || fade_alpha_ == 1.0f)
  {
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
  }
}

bool FadeManager::IsRequested() const
{
  return is_requested_;
}