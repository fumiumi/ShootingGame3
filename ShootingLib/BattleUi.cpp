#include "BattleUi.h"
#include "DxLib.h"
#include "GameInfo.h"

namespace
{
const char *kSideUiFilePath = "E:/�Q�[���J��/�N���A�J/ShootingGame3/Shooting3/Assets/Image/Ui/SideUi/SideUiBg01.png";
const char *kClearUiFilePath = "E:/�Q�[���J��/�N���A�J/ShootingGame3/Shooting3/Assets/Image/Ui/BattleUi/GameClearImage.png";
const char *kGameOverUiFilePath = "E:/�Q�[���J��/�N���A�J/ShootingGame3/Shooting3/Assets/Image/Ui/BattleUi/GameOverImage.png";

const int kSideUiWidth = 200;
const int kSideUiHeight = 720;

const int kClearUiWidth = 420;
const int kClearUiHeight = 150;

const int kGameOverUiWidth = 372;
const int kGameOverUiHeight = 94;
}

BattleUi::BattleUi() 
  : side_ui_handle_(0), 
    clear_ui_handle_(0), 
    game_over_ui_handle_(0)
{
}

void BattleUi::Update(float delta_time)
{
  side_ui_handle_ = LoadGraph(kSideUiFilePath);
  clear_ui_handle_ = LoadGraph(kClearUiFilePath);
  game_over_ui_handle_ = LoadGraph(kGameOverUiFilePath);
}

void BattleUi::Render()
{
  GameInfo *game_info = GameInfo::GetInstance();

  if (side_ui_handle_ == -1 || clear_ui_handle_ == -1 || game_over_ui_handle_ == -1)
  {
    return;
  }
  // �T�C�h�͗��[�ɕ\��
  DrawGraph(0, 0, side_ui_handle_, TRUE);
  DrawGraph(game_info->GetResolutionX() - kSideUiWidth, 0, side_ui_handle_, TRUE);

  ////NOTE: �Ƃ肠�����\�����Ȃ��i�N���A�A�Q�[���I�[�o�[�t���O�͌�Ŏ����j
  //DrawGraph(game_info->GetCenterX() - kClearUiWidth / 2, 240 - kClearUiHeight / 2, clear_ui_handle_, TRUE);
  //DrawGraph(game_info->GetCenterX() - kGameOverUiWidth / 2, 240 - kGameOverUiHeight / 2, game_over_ui_handle_, TRUE);
}
