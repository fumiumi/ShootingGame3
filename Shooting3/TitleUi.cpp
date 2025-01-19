#include "TitleUi.h"
#include "DxLib.h"
#include "GameInfo.h"

namespace
{
const char *kTitleLogoFilePath = "E:/ゲーム開発/クリアカ/ShootingGame3/Shooting3/Assets/Image/Ui/TitleUi/TitleLogo01.png";
const char *kTitleGuidanceFilePath = "E:/ゲーム開発/クリアカ/ShootingGame3/Shooting3/Assets/Image/Ui/TitleUi/TitleGuidance01.png";
const char *kSideUiFilePath = "E:/ゲーム開発/クリアカ/ShootingGame3/Shooting3/Assets/Image/Ui/SideUi/SideUiBg01.png";

const int kTitleLogoWidth = 591;
const int kTitleLogoHeight = 195;

const int kTitleGuidanceWidth = 372;
const int kTitleGuidanceHeight = 94;

const int kSideUiWidth = 200;
}

TitleUi::TitleUi() 
  : title_logo_ui_handle_(0), 
    title_guidance_ui_handle_(0),
    title_side_ui_handle_(0)
{
}

void TitleUi::Update(float delta_time)
{
  title_logo_ui_handle_ = LoadGraph(kTitleLogoFilePath);
  title_guidance_ui_handle_ = LoadGraph(kTitleGuidanceFilePath);
  title_side_ui_handle_ = LoadGraph(kSideUiFilePath);
}

void TitleUi::Render()
{
  GameInfo *game_info = GameInfo::GetInstance();

  if (title_logo_ui_handle_ == -1 || title_guidance_ui_handle_ == -1 || title_side_ui_handle_ == -1)
  {
    return;
  }

  DrawGraph(game_info->GetCenterX() - kTitleLogoWidth / 2, 240 - kTitleLogoHeight / 2, title_logo_ui_handle_, TRUE);
  DrawGraph(game_info->GetCenterX() - kTitleGuidanceWidth / 2, 480 - kTitleGuidanceHeight / 2, title_guidance_ui_handle_, TRUE);
  DrawGraph(0, 0, title_side_ui_handle_, TRUE);
  DrawGraph(game_info->GetResolutionX() - kSideUiWidth, 0, title_side_ui_handle_, TRUE);
}

void TitleUi::Destroy()
{
  if (title_logo_ui_handle_ != -1)
  {
    DeleteGraph(title_logo_ui_handle_);
  }
  if (title_guidance_ui_handle_ != -1)
  {
    DeleteGraph(title_guidance_ui_handle_);
  }
  if (title_side_ui_handle_ != -1)
  {
    DeleteGraph(title_side_ui_handle_);
  }
}