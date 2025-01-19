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

  void Destroy();

private:
  int title_logo_ui_handle_;
  int title_guidance_ui_handle_;
  int title_side_ui_handle_;
};