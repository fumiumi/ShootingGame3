#include "FadeManager.h"
#include "DxLib.h"
#include "GameInfo.h"

namespace
{
const char *kFadeImageFilePath = "E:/�Q�[���J��/�N���A�J/ShootingGame3/Shooting3/Assets/Image/Fade/FadeBlack.png";
}

FadeManager *FadeManager::instance_ = nullptr;

FadeManager::FadeManager()
  : fade_manager_state_(FadeManagerState::kNone),
    duration_(0.0f),
    fade_alpha_(0.0f),
    is_requested_(false)
{
  // ���ł��Ăяo����悤�ɂ��炩���߃t�F�[�h�p�̉摜��ǂݍ���ł���
  fade_handle_ = LoadGraph(kFadeImageFilePath);
}

void FadeManager::RequestFadeIO(float duration, FadeManagerState mode)
{
  // �P�x���N�G�X�g���ꂽ��A�t�F�[�h�C��/�A�E�g���I���܂Ń��N�G�X�g���󂯕t���Ȃ�
  if (is_requested_)
  {
    return;
  }

  switch (mode)
  {
  case FadeManagerState::kNone:
    is_requested_ = true;
    return;
  case FadeManagerState::kFadeIn:
    fade_manager_state_ = FadeManagerState::kFadeIn;
    duration_ = duration;
    fade_alpha_ = 1.0f;
    break;
  case FadeManagerState::kFadeOut:
    fade_manager_state_ = FadeManagerState::kFadeOut;
    duration_ = duration;
    fade_alpha_ = 0.0f;
    break;
  }

  is_requested_ = true;
}

void FadeManager::RenderFade(float delta_time)
{
  if (!is_requested_)
  {
    return;
  }

  if (fade_manager_state_ == FadeManagerState::kNone)
  {
    //HACK: ������kNone�Ŏw�肳��Ă��A���N�G�X�g���T�X�y���h���Ȃ��悤�ɂ���
    is_requested_ = false;
    return;
  }

  // �w�肵��duration��delta_time����A�����Ԃł̃t�F�[�h�C��/�A�E�g���s��

  // duration_ �̓~���b�w��Ȃ̂ŁA�b�ɕϊ����Ďg�p����
  float fade_duration_sec = duration_ / 1000.0f;
  // �t�F�[�h���x�̌v�Z
  float fade_speed_per_sec = 1.0f / fade_duration_sec;
  // ���t���[���ŕω�������A���t�@��
  float delta_alpha = fade_speed_per_sec * delta_time;

  // �t�F�[�h�C��/�A�E�g����
  if (fade_manager_state_ == FadeManagerState::kFadeIn)
  {
    fade_alpha_ -= delta_alpha;
    if (fade_alpha_ <= 0.0f)
    {
      fade_alpha_ = 0.0f;

      // �t�F�[�h�C���I��
      fade_manager_state_ = FadeManagerState::kNone;
      is_requested_ = false;
    }
  }
  else if (fade_manager_state_ == FadeManagerState::kFadeOut)
  {
    fade_alpha_ += delta_alpha;
    if (fade_alpha_ >= 1.0f)
    {
      fade_alpha_ = 1.0f;

      // �t�F�[�h�A�E�g�I��
      fade_manager_state_ = FadeManagerState::kNone;
      is_requested_ = false;
    }
  }
  // �t�F�[�h�`��
  GameInfo *game_info = GameInfo::GetInstance();

  SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(fade_alpha_ * 255));
  DrawExtendGraph(0, 0,game_info->GetResolutionX(), game_info->GetResolutionY(), fade_handle_, TRUE);

  // �`��I����́A�u�����h���[�h�����ɖ߂�
  if (fade_alpha_ == 0.0f || fade_alpha_ == 1.0f)
  {
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
  }
}

bool FadeManager::IsRequested() const
{
  return is_requested_;
}