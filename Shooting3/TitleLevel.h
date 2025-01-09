#pragma once

#include "LevelBase.h"

/// <summary>
/// �^�C�g����ʂ̃��x��
/// </summary>
class TitleLevel : public LevelBase
{
public:
  // TODO: �t�F�[�h�A�E�g�E�t�F�[�h�C���Ȃǂ��������ꂽ��A
  // �t�F�[�h�A�E�g�҂��̏�Ԃ�����
  /// <summary>
  /// �^�C�g�����x���̏��
  /// </summary>
  enum class TitleLevelState
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
  explicit TitleLevel();

  /// <summary>
  /// �f�X�g���N�^
  /// </summary>
  virtual ~TitleLevel();

  /// <summary>
  /// ���t���[���̍X�V����
  /// </summary>
  /// <param name="delta_time">�O����s�t���[������̌o�ߎ��ԁi�b�j</param>
  void Update(float delta_time) override;

  /// <summary>
  /// ���t���[���̕`�揈��
  /// </summary>
  void Render() override;

  /// <summary>
  /// ���x���̊J�n����
  /// </summary>
  void BeginLevel() override;

  /// <summary>
  /// �^�C�g�����x���̊Ǘ�������̂��^�X�N�}�l�[�W���[����������
  /// </summary>
  void ReleaseLevel() override;

  /// <summary>
  /// �^�C�g�����x���̊Ǘ�������̂�j��
  /// </summary>
  void DestroyLevel() override;

private:

  /// <summary>
  /// �^�C�g�����x���̏��
  /// </summary>
  TitleLevelState title_level_state_;

  /// <summary>
  /// �w�i�摜
  /// </summary>
  int title_bg_handle_;

  /// <summary>
  /// ���݂̌o�ߎ���
  /// </summary>
  float elapsed_time_;
};
