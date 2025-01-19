#pragma once

/// <summary>
/// ゲームループのどこからでもアクセスできるように
/// シングルトンパターンで実装
/// </summary>
class FadeManager
{
public:
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
  /// インプットマネージャーにフェードインタスクを登録
  /// </summary>
  /// <param name="duration"></param>
  void FadeIn(float duration);

  /// <summary>
  /// インプットマネージャーにフェードアウトタスクを登録
  /// </summary>
  /// <param name="duration"></param>
  void FadeOut(float duration);

  void Update(float delta_time);
  void Render();

private:
  FadeManager();
  ~FadeManager() = default;
  static FadeManager *instance_;

  float fade_alpha_;

};