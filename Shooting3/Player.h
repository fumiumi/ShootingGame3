#pragma once
#include "Task.h"

class Player : public Task
{
public:
  /// <summary>
  /// プレイヤーの移動向き
  /// 描画するスプライト画像を変更するために使用
  /// </summary>
  enum class PlayerState
  {
    /// <summary>
    /// 正面向き
    /// </summary>
    kStraight = 0,
    /// <summary>
    /// 左バンク
    /// </summary>
    kLeftBank = 1,
    /// <summary>
    /// 右バンク
    /// </summary>
    kRightBank = 2,
    /// <summary>
    /// LoadやDrawが失敗したとき
    /// </summary>
    kError = 3,
  };

  Player();
  ~Player();

  void SetPosition(int x, int y);

  int GetPositionX() const;
  int GetPositionY() const;

  void Update(float delta_time) override;

  void Render() override;

  void LoadPlayerImage();

  void RemovePlayerImage();

  void BeginPlayer();


private:
  /// <summary>
  /// スプライト用画像の分割数
  /// </summary>
  static constexpr int kPlayerImageDivNum = 4;

  //TIPS: 3Dゲーム空間の座標系は左手系が一般的

  int positionX_;
  int positionY_;

  /// <summary>
  /// .自機の描画状態
  /// </summary>
  PlayerState player_state_;

  /// <summary>
  /// 自機画像
  /// Dxライブラリで画像を管理するためのハンドル
  /// </summary>
  int player_handle_array_[kPlayerImageDivNum];
};

