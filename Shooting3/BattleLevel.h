#pragma once

#include "LevelBase.h"
#include "Player.h"
#include "BackGround.h"

class BattleLevel : public LevelBase
{
public:
  // TODO: �t�F�[�h�A�E�g�E�t�F�[�h�C���Ȃǂ��������ꂽ��A
  // �t�F�[�h�A�E�g�҂��̏�Ԃ�����
  /// <summary>
  /// �^�C�g�����x���̏��
  /// </summary>
  enum class BattleLevelState
  {
    /// <summary>
    /// �����Ȃ�
    /// </summary>
    kNone,

    /// <summary>
    /// �ʏ폈��
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
  // HACK: ������dry�ɂł���̂ł́H
  /// <summary>
  /// �o�g�����x���̏��
  /// </summary>
  BattleLevelState battle_level_state_;

  Player *player_;

  /// <summary>
  /// �w�i�`����J�v�Z����
  /// </summary>
  BackGround *back_ground_;

  /// <summary>
  /// ���݂̌o�ߎ���
  /// </summary>
  float elapsed_time_;
};