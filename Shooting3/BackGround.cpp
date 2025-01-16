#include "DxLib.h"
#include "BackGround.h"

BackGround::BackGround() 
  : scroll_position_y_{ kBgPositionY },
    base_bg_handle_(0),
    scroll_bg_handle_{ 0, 0, 0 }
{
}

BackGround::~BackGround() = default;

void BackGround::Render()
{
  // ”wŒi‰æ‘œ‚Ì•`‰æ
  DrawGraph(kBgPositionX, kBgPositionY, base_bg_handle_, TRUE);
  //ƒXƒNƒ[ƒ‹”wŒi‚Í2–‡•`‰æ
  for (int i = 0; i < kScrollBgImageNum; i++)
  {
    scroll_position_y_[i] += kScrollVelocity[i];
    if(scroll_position_y_[i] >= kBgSizeY)
    {
      scroll_position_y_[i] = kBgPositionY;
    }

    DrawGraph(kBgPositionX, scroll_position_y_[i], scroll_bg_handle_[i], TRUE);
    DrawGraph(kBgPositionX, scroll_position_y_[i] - kBgSizeY, scroll_bg_handle_[i], TRUE);
  }
}

void BackGround::LoadImages()
{
  // ‰æ‘œ‚Ì“Ç‚İ‚İ
  base_bg_handle_ = LoadGraph(kBgImgFilePath);
  scroll_bg_handle_[0] = LoadGraph(kScrollBgImgFilePath01);
  scroll_bg_handle_[1] = LoadGraph(kScrollBgImgFilePath02);
  scroll_bg_handle_[2] = LoadGraph(kScrollBgImgFilePath03);
}

void BackGround::RemoveImages()
{
  // ‰æ‘œ‚Ì‰ğ•ú
  DeleteGraph(base_bg_handle_);
  for (int i = 0; i < kScrollBgImageNum; i++)
  {
    DeleteGraph(scroll_bg_handle_[i]);
  }
}
