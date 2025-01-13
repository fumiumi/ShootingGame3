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

  /// <summary>
  /// コンストラクタ
  /// </summary>
  Player();
  /// <summary>
  /// デストラクタ
  /// </summary>
  ~Player();

 /// <summary>
 /// 自機の座標を設定
 /// </summary>
 /// <param name="x">x座標</param>
 /// <param name="y">y座標</param>
  void SetPosition(int x, int y);

  int GetPositionX() const;
  int GetPositionY() const;


  /// <summary>
  /// 毎フレーム実行する処理
  /// </summary>
  /// <param name="delta_time"></param>
  void Update(float delta_time) override;

  /// <summary>
  /// 毎フレームの描画処理
  /// </summary>
  void Render() override;

  /// <summary>
  /// 自機画像の読み込み
  /// </summary>
  void LoadPlayerImage();

  /// <summary>
  /// 自機画像の解放
  /// </summary>
  void RemovePlayerImage();


private:
  /// <summary>
  /// スプライト用画像の分割数
  /// </summary>
  static constexpr int kPlayerImageDivNum = 4;

  //TIPS: 3Dゲーム空間の座標系は左手系が一般的
  /// <summary>
  /// プレイヤーのx座標
  /// </summary>
  int positionX_;

  /// <summary>
  /// プレイヤーのy座標
  /// </summary>
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

