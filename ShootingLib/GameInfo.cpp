#include "GameInfo.h"

namespace
{
int kWidth = 1280;
int kHeight = 720;
int kColorBit = 32;

const int kSideUiWidth = 200;

const int kPlayerImageWidth = 64;
const int kPlayerImageHeight = 64;
const int kTackleEnemyWidth = 64;
const int kTackleEnemyHeight = 64;

const int kPlayerBulletWidth = 32;
const int kPlayerBulletHeight = 32;
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

int GameInfo::GetMinPosX()
{
  return kSideUiWidth;
}

int GameInfo::GetMaxPosX()
{
  return kWidth - kSideUiWidth;
}

int GameInfo::GetPlayerImageWidth()
{
  return kPlayerImageWidth;
}

int GameInfo::GetPlayerImageHeight()
{
  return kPlayerImageHeight;
}

int GameInfo::GetTackleEnemyImageWidth()
{
  return kTackleEnemyWidth;
}

int GameInfo::GetTackleEnemyImageHeight()
{
  return kTackleEnemyHeight;
}

int GameInfo::GetPlayerBulletImageWidth()
{
  return kPlayerBulletWidth;
}

int GameInfo::GetPlayerBulletImageHeight()
{
  return kPlayerBulletHeight;
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
