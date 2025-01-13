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

  /// <summary>
  /// �R���X�g���N�^
  /// </summary>
  Player();
  /// <summary>
  /// �f�X�g���N�^
  /// </summary>
  ~Player();

 /// <summary>
 /// ���@�̍��W��ݒ�
 /// </summary>
 /// <param name="x">x���W</param>
 /// <param name="y">y���W</param>
  void SetPosition(int x, int y);

  int GetPositionX() const;
  int GetPositionY() const;


  /// <summary>
  /// ���t���[�����s���鏈��
  /// </summary>
  /// <param name="delta_time"></param>
  void Update(float delta_time) override;

  /// <summary>
  /// ���t���[���̕`�揈��
  /// </summary>
  void Render() override;

  /// <summary>
  /// ���@�摜�̓ǂݍ���
  /// </summary>
  void LoadPlayerImage();

  /// <summary>
  /// ���@�摜�̉��
  /// </summary>
  void RemovePlayerImage();


private:
  /// <summary>
  /// �X�v���C�g�p�摜�̕�����
  /// </summary>
  static constexpr int kPlayerImageDivNum = 4;

  //TIPS: 3D�Q�[����Ԃ̍��W�n�͍���n����ʓI
  /// <summary>
  /// �v���C���[��x���W
  /// </summary>
  int positionX_;

  /// <summary>
  /// �v���C���[��y���W
  /// </summary>
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

