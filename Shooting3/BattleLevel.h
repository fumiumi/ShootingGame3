#pragma once

#include "LevelBase.h"

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

  /// <summary>
  /// �R���X�g���N�^
  /// </summary>
  /// 
  BattleLevel();

  /// <summary>
  /// �f�X�g���N�^
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
  // HACK: ������dry�ɂł���̂ł́H
  /// <summary>
  /// �o�g�����x���̏��
  /// </summary>
  BattleLevelState battle_level_state_;

  /// <summary>
  /// �w�i�摜
  /// </summary>
  int battle_bg_handle_;

  /// <summary>
  /// ���݂̌o�ߎ���
  /// </summary>
  float elapsed_time_;
};