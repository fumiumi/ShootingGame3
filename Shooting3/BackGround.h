#pragma once

#include <vector>

namespace
{
const char *kBgImgFilePath = "E:/ゲーム開発/クリアカ/ShootingGame3/Shooting3/Assets/Image/Battle/Background/BaseBgSky01.png";
const char *kScrollBgImgFilePath01 = "E:/ゲーム開発/クリアカ/ShootingGame3/Shooting3/Assets/Image/Battle/Background/ScrollBgSky01.png";
const char *kScrollBgImgFilePath02 = "E:/ゲーム開発/クリアカ/ShootingGame3/Shooting3/Assets/Image/Battle/Background/ScrollBgSky02.png";
const char *kScrollBgImgFilePath03 = "E:/ゲーム開発/クリアカ/ShootingGame3/Shooting3/Assets/Image/Battle/Background/ScrollBgSky03.png";

const int kScrollBgImageNum = 3;

const int kBgPositionX = 200;
const int kBgPositionY = 0;

const std::vector<int> kScrollVelocity = {2, 4, 8};

const int kBgSizeX = 880;
const int kBgSizeY = 720;
}

class BackGround
{
public:
  BackGround();
  ~BackGround();

  void Render();

  void LoadImages();

  void RemoveImages();

private:

  int scroll_position_y_[kScrollBgImageNum];

  int base_bg_handle_;

  int scroll_bg_handle_[kScrollBgImageNum];

};