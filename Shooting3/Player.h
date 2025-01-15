#pragma once
#include "Task.h"

class Player : public Task
{
public:
  /// <summary>
  /// �v���C���[�̈ړ�����
  /// �`�悷��X�v���C�g�摜��ύX���邽�߂Ɏg�p
  /// </summary>
  enum class PlayerState
  {
    /// <summary>
    /// ���ʌ���
    /// </summary>
    kStraight = 0,
    /// <summary>
    /// ���o���N
    /// </summary>
    kLeftBank = 1,
    /// <summary>
    /// �E�o���N
    /// </summary>
    kRightBank = 2,
    /// <summary>
    /// Load��Draw�����s�����Ƃ�
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
  /// �X�v���C�g�p�摜�̕�����
  /// </summary>
  static constexpr int kPlayerImageDivNum = 4;

  //TIPS: 3D�Q�[����Ԃ̍��W�n�͍���n����ʓI

  int positionX_;
  int positionY_;

  /// <summary>
  /// .���@�̕`����
  /// </summary>
  PlayerState player_state_;

  /// <summary>
  /// ���@�摜
  /// Dx���C�u�����ŉ摜���Ǘ����邽�߂̃n���h��
  /// </summary>
  int player_handle_array_[kPlayerImageDivNum];
};

