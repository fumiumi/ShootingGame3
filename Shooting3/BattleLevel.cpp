#include "DxLib.h"
#include "LevelChanger.h"
#include "BattleLevel.h"
#include "TaskManager.h"

/// <summary>
/// TitleLevel.cpp�݂̂Ŏg�p����萔
/// </summary>
namespace
{
/// <summary>
/// �w�i�摜
/// DX���C�u�����ɓn���̂ŁAconst char*�^���g�p�i�݊����̖��j
/// </summary>
const char *kBattleBgImageFilePath = "E:/�Q�[���J��/�N���A�J/ShootingGame3/Shooting3/Assets/Image/Battle/Background/BaseBgSky01.png";

/// <summary>
/// �E�B���h�E���ɂ�����A�w�i�摜��X���W
/// </summary>
const int kBgPosX = 200;

/// <summary>
/// �E�B���h�E���ɂ�����A�w�i�摜��Y���W
/// </summary>
const int kBgPosY = 0;

/// <summary>
/// ���x���̐؂�ւ�����
/// ��ʑJ�ڂɎ��Ԃ�݂���
/// </summary>
const float kChangeTitleTime = 3.0f;
}

/// <summary>
/// �R���X�g���N�^
/// </summary>
BattleLevel::BattleLevel()
  : battle_level_state_(BattleLevelState::kNone),
    battle_bg_handle_(0),
    player_(nullptr),
    elapsed_time_(0.0f)
{
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
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

/// <summary>
/// �`�揈��
/// </summary>
void BattleLevel::Render()
{
  // �w�i�摜��`��
  //x, y�@�@�@: �O���t�B�b�N��`�悷��̈�̍��㒸�_�̍��W
  //GrHandle�@ : �`�悷��O���t�B�b�N�̃n���h��
  //TransFlag�@ : �摜�̓����x��L���ɂ��邩�ǂ���(TRUE�F�L���ɂ���@FALSE�F�����ɂ���)
  DrawGraph(kBgPosX, kBgPosY, battle_bg_handle_, TRUE);
  //printfDx("handle is %d\n", battle_bg_handle_);
}

/// <summary>
/// ���x���̊J�n
/// </summary>
void BattleLevel::BeginLevel()
{
  // �w�i�摜�̓ǂݍ���
  battle_bg_handle_ = LoadGraph(kBattleBgImageFilePath);

  // �v���C���[�̐���
  player_ = new Player();

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
  DeleteGraph(battle_bg_handle_);
  delete player_;
  player_ = nullptr;
}