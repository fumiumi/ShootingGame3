#include "DxLib.h"
#include "TitleLevel.h"
#include "LevelChanger.h"
#include "TitleUi.h"
#include "InputManager.h"
#include "FadeManager.h"


/// <summary>
/// TitleLevel.cpp�݂̂Ŏg�p����萔
/// </summary>
namespace
{
/// <summary>
/// �w�i�摜
/// DX���C�u�����ɓn���̂ŁAconst char*�^���g�p�i�݊����̖��j
/// </summary>
const char *kTitleBgImageFilePath = "E:/�Q�[���J��/�N���A�J/ShootingGame3/Shooting3/Assets/Image/Title/TitleBg01.png";

/// <summary>
/// �E�B���h�E���ɂ�����A�w�i�摜��X���W
/// </summary>
const int kBgPosX = 200;

const int kBgPosY = 0;
}

/// <summary>
/// �R���X�g���N�^
/// </summary>
TitleLevel::TitleLevel()
  : title_level_state_(TitleLevelState::kNone),
    title_bg_handle_(0),
    title_ui_(new TitleUi)
    // �ŏI�I�ɏ���
    //elapsed_time_(0.0f)
{
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
TitleLevel::~TitleLevel() = default;

/// <summary>
/// ���t���[���̍X�V����
/// </summary>
/// <param name="delta_time">kPlay�ɂȂ��Ă���́A�O����s�t���[������̌o�ߎ��ԁi�b�j</param>
void TitleLevel::Update(float delta_time)
{
  InputManager *input_manager = InputManager::GetInstance();

  //�������Ȃ���ԂȂ���s���Ȃ�
  if (title_level_state_ == TitleLevelState::kNone)
  {
    return;
  }

  //z�L�[�������ꂽ�烌�x���J��
  if (input_manager->IsPushThisFrame(input_manager->GameKeyKind::kPlayerFire))
  {
    ////��Ԃ��������Ȃ���
    //title_level_state_ = TitleLevelState::kNone;

    //���x���`�F���W���[�̏�Ԃ��^�C�g�����x���I����
    LevelChanger::GetInstance()
      ->SetLevelChangerState(LevelChanger::LevelChangerState::kFinTitleLevel);

    // �t�F�[�h�C�������N�G�X�g
    FadeManager::GetInstance()->RequestFadeIO(1000, FadeManager::FadeManagerState::kFadeIn);
  }
}

/// <summary>
/// ���t���[���̕`�揈��
/// </summary>
void TitleLevel::Render()
{
  //�w�i�摜�`��
  //x, y�@�@�@: �O���t�B�b�N��`�悷��̈�̍��㒸�_�̍��W
  //GrHandle�@ : �`�悷��O���t�B�b�N�̃n���h��
  //TransFlag�@ : �摜�̓����x��L���ɂ��邩�ǂ���(TRUE�F�L���ɂ���@FALSE�F�����ɂ���)
  DrawGraph(kBgPosX, kBgPosY, title_bg_handle_, TRUE);

  //UI�̕`��̓^�X�N�}�l�[�W���[�ɔC����
}

/// <summary>
/// ���x���̊J�n����
/// </summary>
void TitleLevel::BeginLevel()
{
  //�w�i�ǂݍ���
  title_bg_handle_ = LoadGraph(kTitleBgImageFilePath);

  //UI���^�X�N�}�l�[�W���[�ɓo�^
  TaskManager::GetInstance()->AddTask(title_ui_);

  //��Ԃ�ʏ��
  title_level_state_ = TitleLevelState::kPlay;

  // �t�F�[�h�A�E�g�����N�G�X�g
  FadeManager::GetInstance()->RequestFadeIO(1000, FadeManager::FadeManagerState::kFadeOut);
}

/// <summary>
/// �^�C�g�����x���̊Ǘ�������̂��^�X�N�}�l�[�W���[����������
/// </summary>
void TitleLevel::ReleaseLevel()
{
  TaskManager::GetInstance()->ReleaseTask(title_ui_->GetTaskId());
}

/// <summary>
/// �^�C�g�����x���̊Ǘ�������̂�j��
/// </summary>
void TitleLevel::DestroyLevel()
{
  //�w�i�摜�j��
  DeleteGraph(title_bg_handle_);
  title_ui_->Destroy();
  delete title_ui_;
  title_ui_ = nullptr;
}