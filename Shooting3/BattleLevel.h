#pragma once

#include "LevelBase.h"
#include "Player.h"
#include "BackGround.h"

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

  BattleLevel();
  ~BattleLevel();

  void Update(float delta_time) override;

  void Render() override;

  void BeginLevel() override;

  void ReleaseLevel() override;

  void DestroyLevel() override;

private:
  // HACK: ここはdryにできるのでは？
  /// <summary>
  /// バトルレベルの状態
  /// </summary>
  BattleLevelState battle_level_state_;

  Player *player_;

  /// <summary>
  /// 背景描画をカプセル化
  /// </summary>
  BackGround *back_ground_;

  /// <summary>
  /// 現在の経過時間
  /// </summary>
  float elapsed_time_;
};