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
  // �w�i�摜�̕`��
  DrawGraph(kBgPositionX, kBgPositionY, base_bg_handle_, TRUE);
  //�X�N���[���w�i��2���`��
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
  // �摜�̓ǂݍ���
  base_bg_handle_ = LoadGraph(kBgImgFilePath);
  scroll_bg_handle_[0] = LoadGraph(kScrollBgImgFilePath01);
  scroll_bg_handle_[1] = LoadGraph(kScrollBgImgFilePath02);
  scroll_bg_handle_[2] = LoadGraph(kScrollBgImgFilePath03);
}

void BackGround::RemoveImages()
{
  // �摜�̉��
  DeleteGraph(base_bg_handle_);
  for (int i = 0; i < kScrollBgImageNum; i++)
  {
    DeleteGraph(scroll_bg_handle_[i]);
  }
}
