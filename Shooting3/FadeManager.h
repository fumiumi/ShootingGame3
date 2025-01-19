#pragma once

/// <summary>
/// ゲームループのどこからでもアクセスできるように
/// シングルトンパターンで実装
/// </summary>
class FadeManager
{
public:
  enum class FadeManagerState
  {
    kFadeIn,
    kFadeOut,
    kNone
  };

  static FadeManager *GetInstance()
  {
    //生成されてないなら動的生成
    if (instance_ == nullptr)
    {
      instance_ = new FadeManager();
    }
    //FadeManagerのインスタンスを返す
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

  /// <summary>
  /// クライアントがFadeManagerにフェードイン/アウトを依頼する関数
  /// </summary>
  /// <param name="duration">ミリ秒</param>
  void RequestFadeIO(float duration, FadeManagerState mode);

  void RenderFade(float delta_time);

  bool IsRequested() const;

private:
  FadeManager();
  ~FadeManager() = default;
  static FadeManager *instance_;

  FadeManagerState fade_manager_state_;
  float duration_;
  float fade_alpha_;

  bool is_requested_;

  int fade_handle_;
};