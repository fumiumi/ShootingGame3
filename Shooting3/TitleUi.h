#pragma once

//#include "DXLib.h"
#include "Task.h"

class TitleUi : public Task
{
public:
  TitleUi();
  ~TitleUi() = default;

  void Update(float delta_time) override;
  void Render() override;
private:

  int title_logo_handle_;
  int title_guidance_handle_;
};