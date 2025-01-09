#pragma once

#include "LevelBase.h"

/// <summary>
/// タイトル画面のレベル
/// </summary>
class TitleLevel : public LevelBase
{
public:
  // TODO: フェードアウト・フェードインなどが実装されたら、
  // フェードアウト待ちの状態を実装
  /// <summary>
  /// タイトルレベルの状態
  /// </summary>
  enum class TitleLevelState
  {
    /// <summary>
    /// 処理なし
    /// </summary>
    kNone,

    /// <summary>
    /// 通常処理
    /// </summary>
    kPlay,
  };

  /// <summary>
  /// コンストラクタ
  /// </summary>
  explicit TitleLevel();

  /// <summary>
  /// デストラクタ
  /// </summary>
  virtual ~TitleLevel();

  /// <summary>
  /// 毎フレームの更新処理
  /// </summary>
  /// <param name="delta_time">前回実行フレームからの経過時間（秒）</param>
  void Update(float delta_time) override;

  /// <summary>
  /// 毎フレームの描画処理
  /// </summary>
  void Render() override;

  /// <summary>
  /// レベルの開始処理
  /// </summary>
  void BeginLevel() override;

  /// <summary>
  /// タイトルレベルの管理するものをタスクマネージャーから解放する
  /// </summary>
  void ReleaseLevel() override;

  /// <summary>
  /// タイトルレベルの管理するものを破棄
  /// </summary>
  void DestroyLevel() override;

private:

  /// <summary>
  /// タイトルレベルの状態
  /// </summary>
  TitleLevelState title_level_state_;

  /// <summary>
  /// 背景画像
  /// </summary>
  int title_bg_handle_;

  /// <summary>
  /// 現在の経過時間
  /// </summary>
  float elapsed_time_;
};
