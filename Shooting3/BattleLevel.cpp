#include "DxLib.h"
#include "LevelChanger.h"
#include "BattleLevel.h"
#include "TaskManager.h"


namespace
{
/// <summary>
/// DX���C�u�����ɓn���̂ŁAconst char*�^���g�p�i�݊����̖��j
/// </summary>
const char *kBattleBgImageFilePath = "E:/�Q�[���J��/�N���A�J/ShootingGame3/Shooting3/Assets/Image/Battle/Background/BaseBgSky01.png";

const int kBgPosX = 200;
const int kBgPosY = 0;

/// <summary>
/// ���x���̐؂�ւ�����
/// ��ʑJ�ڂɎ��Ԃ�݂���
/// </summary>
const float kChangeTitleTime = 3.0f;
}

BattleLevel::BattleLevel()
  : battle_level_state_(BattleLevelState::kNone),
    player_(nullptr),
    elapsed_time_(0.0f),
    back_ground_(new BackGround)
{
}

BattleLevel::~BattleLevel() = default;

void BattleLevel::Update(float delta_time)
{
  // �������Ȃ���ԂȂ���s���Ȃ�
  if (battle_level_state_ == BattleLevelState::kNone)
  {
    return;
  }
  // �o�ߎ��Ԃ��v�Z
  // ���t���[�����Z
  elapsed_time_ += delta_time;

  // ��莞�Ԍo�߂�����A���̏�Ԃ֑J��
  if (elapsed_time_ >= kChangeTitleTime)
  {
    // �o�ߎ��Ԃ����Z�b�g
    elapsed_time_ = 0.0f;

    // �o�g�����x���̏�Ԃ����Z�b�g
    battle_level_state_ = BattleLevelState::kNone;

    //���x���`�F���W���[�̏�Ԃ��^�C�g�����x���I����
    LevelChanger::GetInstance()
      ->SetLevelChangerState(LevelChanger::LevelChangerState::kFinBattleLevel);
  }
}

void BattleLevel::Render()
{
  // �w�i�摜��`��
  //x, y�@�@�@: �O���t�B�b�N��`�悷��̈�̍��㒸�_�̍��W
  //GrHandle�@ : �`�悷��O���t�B�b�N�̃n���h��
  //TransFlag�@ : �摜�̓����x��L���ɂ��邩�ǂ���(TRUE�F�L���ɂ���@FALSE�F�����ɂ���)
  back_ground_->Render();
}

void BattleLevel::BeginLevel()
{
  // �w�i�摜�̓ǂݍ���
  back_ground_->LoadImages();

  // �v���C���[
  player_ = new Player();
  player_->BeginPlayer();

  //�^�X�N�}�l�[�W���[�ɕ��荞��
  TaskManager::GetInstance()->AddTask(player_);

  // �o�g�����x���̏�Ԃ��v���C�ɐݒ�
  battle_level_state_ = BattleLevelState::kPlay;
  //=> Update�������悤�ɂȂ�
}

void BattleLevel::ReleaseLevel()
{
  // �v���C���[�̉��
  TaskManager::GetInstance()->ReleaseTask(player_->GetTaskId());
}

void BattleLevel::DestroyLevel()
{
  // �w�i�摜�̔j��
  back_ground_->RemoveImages();
  delete back_ground_;
  back_ground_ = nullptr;

  delete player_;
  player_ = nullptr;
}
