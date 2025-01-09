#pragma once

#include "LevelBase.h"

class BattleLevel : public LevelBase
{
public:
  // TODO: フェードアウト・フェードインなどが実装されたら、
  // フェードアウト待ちの状態を実装
  /// <summary>
  /// タイトルレベルの状態
  /// </summary>
  enum class BattleLevelState
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
  /// 
  BattleLevel();

  /// <summary>
  /// デストラクタ
  /// </summary>
  ~BattleLevel();

  /// <summary>
  /// 
  /// </summary>
  /// <param name="delta_time"></param>
  void Update(float delta_time) override;

  /// <summary>
  /// 
  /// </summary>
  void Render() override;

  /// <summary>
  /// 
  /// </summary>
  void BeginLevel() override;

  /// <summary>
  /// 
  /// </summary>
  void ReleaseLevel() override;

  /// <summary>
  /// 
  /// </summary>
  void DestroyLevel() override;

private:
  // HACK: ここはdryにできるのでは？
  /// <summary>
  /// バトルレベルの状態
  /// </summary>
  BattleLevelState battle_level_state_;

  /// <summary>
  /// 背景画像
  /// </summary>
  int battle_bg_handle_;

  /// <summary>
  /// 現在の経過時間
  /// </summary>
  float elapsed_time_;
};