#pragma once

#include "LevelBase.h"
#include "Player.h"
#include "BackGround.h"
#include "BulletManager.h"
#include "BattleUi.h"
#include "EnemyManager.h"

class BattleLevel : public LevelBase
{
  friend class Player;

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
  /// プレイヤー用のバレットマネージャー
  /// </summary>
  BulletManager *bullet_manager_;

  EnemyManager *enemy_manager_;

  /// <summary>
  /// 背景描画をカプセル化
  /// </summary>
  BackGround *back_ground_;

  BattleUi *battle_ui_;
};