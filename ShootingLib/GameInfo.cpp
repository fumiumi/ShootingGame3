#include "GameInfo.h"

namespace
{
int kWidth = 1280;
int kHeight = 720;
int kColorBit = 32;

int kPlayerImageWidth = 64;
int kPlayerImageHeight = 64;
}

GameInfo *GameInfo::instance_ = nullptr;

GameInfo::GameInfo() 
  : x_resolution_(kWidth),
    y_resolution_(kHeight),
    x_center_(kWidth / 2),
    y_center_(kHeight / 2),
    color_bit_(kColorBit),
    is_end_game_(false),
    is_debug_display_(false)
{
}

int GameInfo::GetResolutionX()
{
  return x_resolution_;
}

int GameInfo::GetResolutionY()
{
  return y_resolution_;
}

int GameInfo::GetCenterX()
{
  return x_center_;
}

int GameInfo::GetCenterY()
{
  return y_center_;
}

int GameInfo::GetPlayerImageWidth()
{
  return kPlayerImageWidth;
}

int GameInfo::GetPlayerImageHeight()
{
  return kPlayerImageHeight;
}

int GameInfo::GetColorBit()
{
  return color_bit_;
}

bool GameInfo::IsDebugDisplay()
{
  return is_debug_display_;
}

void GameInfo::SetDebugDisplay(bool is_debug)
{
  is_debug_display_ = is_debug;
}

bool GameInfo::IsEndGame()
{
  return is_end_game_;
}

void GameInfo::SetEndGame(bool is_end_game)
{
  is_end_game_ = is_end_game;
}
