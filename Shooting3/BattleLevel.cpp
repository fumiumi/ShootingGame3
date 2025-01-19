#include "BattleLevel.h"
#include "DxLib.h"
#include "LevelChanger.h"
#include "TaskManager.h"
#include "InputManager.h"
#include "FadeManager.h"

namespace
{
/// <summary>
/// DX���C�u�����ɓn���̂ŁAconst char*�^���g�p�i�݊����̖��j
/// </summary>
const char *kBattleBgImageFilePath = "E:/�Q�[���J��/�N���A�J/ShootingGame3/Shooting3/Assets/Image/Battle/Background/BaseBgSky01.png";

const int kBgPosX = 200;
const int kBgPosY = 0;
}

BattleLevel::BattleLevel()
  : battle_level_state_(BattleLevelState::kNone),
    back_ground_(new BackGround),
    bullet_manager_(new BulletManager),
    battle_ui_(new BattleUi)
{
  player_ = new Player(this);
}

BattleLevel::~BattleLevel() = default;

void BattleLevel::Update(float delta_time)
{
  InputManager *input_manager = InputManager::GetInstance();

  // �������Ȃ���ԂȂ���s���Ȃ�
  if (battle_level_state_ == BattleLevelState::kNone)
  {
    return;
  }

  //DEBUG: KEY_INPUT_ESCAPE����������^�C�g�����x���ɖ߂�
  if (input_manager->IsPushThisFrame(input_manager->GameKeyKind::kPause))
  {

    //���x���`�F���W���[�̏�Ԃ��^�C�g�����x���I����
    LevelChanger::GetInstance()
      ->SetLevelChangerState(LevelChanger::LevelChangerState::kFinBattleLevel);

    // �t�F�[�h�C�������N�G�X�g
    FadeManager::GetInstance()->RequestFadeIO(2000, FadeManager::FadeManagerState::kFadeIn);
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
  player_->BeginPlayer();

  // �e
  bullet_manager_->LoadBulletImageHandle();

  //�^�X�N�}�l�[�W���[�ɕ��荞��
  TaskManager::GetInstance()->AddTask(player_);
  TaskManager::GetInstance()->AddTask(bullet_manager_);
  // �`�揇���l�����āAUI�͍Ō�ɓo�^
  TaskManager::GetInstance()->AddTask(battle_ui_);

  // �o�g�����x���̏�Ԃ��v���C�ɐݒ�
  battle_level_state_ = BattleLevelState::kPlay;
  //=> Update�������悤�ɂȂ�

  // �t�F�[�h�A�E�g�����N�G�X�g
  FadeManager::GetInstance()->RequestFadeIO(300, FadeManager::FadeManagerState::kFadeOut);
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
