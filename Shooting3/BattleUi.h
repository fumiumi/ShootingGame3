#pragma once

#include "Task.h"

class BattleUi : public Task
{
public:
  BattleUi();
  ~BattleUi() = default;

  void Update(float delta_time) override;
  void Render() override;

  void Destroy();

private:
  int side_ui_handle_;
  int clear_ui_handle_;
  int game_over_ui_handle_;
};