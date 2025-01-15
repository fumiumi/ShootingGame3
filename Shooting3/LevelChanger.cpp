#include "DxLib.h"
#include <TaskManager.h>
#include "LevelChanger.h"
#include "TitleLevel.h"
#include "BattleLevel.h"

//���x���`�F���W���[�̃C���X�^���X������
LevelChanger *LevelChanger::instance_ = nullptr;

LevelChanger::LevelChanger()
  : current_level_changer_state_(LevelChangerState::kWait),
    current_level_(nullptr),
    next_level_changer_state_after_destroy_(LevelChangerState::kWait)
{
}

LevelChanger::~LevelChanger() = default;

void LevelChanger::SetLevelChangerState(LevelChanger::LevelChangerState level_changer_state)
{
  //DEBUG
  printfDx("���x���`�F���W\n");
  current_level_changer_state_ = level_changer_state;
}

void LevelChanger::Update(float delta_time) {

  //�V�������x���𐶐������t���O
  bool is_created_level = false;

  //���x������t���O
  bool is_release_level = false;

  //�^�C�g�����x���̏�����
  if (current_level_changer_state_ == LevelChangerState::kInitTitleLevel) {

    //�^�C�g�����x���𐶐�
    current_level_ = new TitleLevel();

    //�V�������x���𐶐������t���O��true
    is_created_level = true;
  }
  //�^�C�g�����x���̌㏈��
  else if (current_level_changer_state_ == LevelChangerState::kFinTitleLevel) {

    //���̓o�g�����x���̏�������
    next_level_changer_state_after_destroy_ = LevelChangerState::kInitBattleLevel;

    //���x������t���O��true
    is_release_level = true;
  }
  //�o�g�����x���̏�����
  else if (current_level_changer_state_ == LevelChangerState::kInitBattleLevel) {

    //�o�g�����x���𐶐�
    current_level_ = new BattleLevel();

    //�V�������x���𐶐������t���O��true
    is_created_level = true;
  }
  //�o�g�����x���̌㏈��
  else if (current_level_changer_state_ == LevelChangerState::kFinBattleLevel) {

    //���̓^�C�g���̏�������
    next_level_changer_state_after_destroy_ = LevelChangerState::kInitTitleLevel;

    //���x������t���O��true
    is_release_level = true;
  }
  //���݃��x���̔j��
  else if (current_level_changer_state_ == LevelChangerState::kDestroyCurrentLevel) {

    //���݃��x���Ɋւ���I�u�W�F�N�g�̔j��
    current_level_->DestroyLevel();

    //���݃��x����j��
    delete current_level_;
    current_level_ = nullptr;

    //���x���j����ɗ\�񂳂ꂽ��Ԃ�
    current_level_changer_state_ = next_level_changer_state_after_destroy_;
  }

  //�V�������x�����������ꂽ�Ȃ�
  if (is_created_level) {

    //�����������x�����^�X�N�ɓo�^
    TaskManager::GetInstance()->AddTask(current_level_);

    //���x���̊J�n����
    current_level_->BeginLevel();

    //���x���`�F���W���[�̏�Ԃ͑ҋ@��
    current_level_changer_state_ = LevelChangerState::kWait;
  }

  //���݂̃��x���͉������Ȃ�
  if (is_release_level) {

    //���݃��x���Ɋ֘A������̂��^�X�N�}�l�[�W���[����������
    current_level_->ReleaseLevel();

    //���݃��x�����^�X�N������
    TaskManager::GetInstance()->ReleaseTask(current_level_->GetTaskId());

    //���x���`�F���W���[�̏�Ԃ͌��݂̃��x���j����
    current_level_changer_state_ = LevelChangerState::kDestroyCurrentLevel;
  }
}

/// <summary>
/// ���݂̃��x���������j��
/// �E�B���h�E�́~�{�^���ŃQ�[�����I�������ꍇ�Ȃǂ̑Ή�
/// </summary>
void LevelChanger::ForceDestroyCurrentLevel()
{
  //���݂̃��x�����j������ĂȂ��Ȃ�
  if (current_level_ != nullptr) {

    //���݂̃��x���Ɋ֌W�̂���I�u�W�F�N�g�̔j��
    current_level_->DestroyLevel();

    //���݂̃��x����j��
    delete current_level_;
    current_level_ = nullptr;
  }
}
