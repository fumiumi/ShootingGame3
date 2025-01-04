#include "pch.h"
#include "gtest/gtest.h"

// なぜかgmockが入っていないので使わない方針で
//#include "gmock/gmock.h"

#include "TaskManager.h"
#include "Task.h"

/*
* TaskManagerクラスのテスト
* 要件
* 概要：タスクを一括管理、ゲームループで処理
* シングルトンパターンで実装
* タスクの追加、削除ができる
* 各タスクオブジェクトへのポインタを保持するコンテナ
* Update()メソッドで各タスクの処理を行う
* Render()メソッドで各タスクの描画を行う
*/

class TaskManagerTest : public ::testing::Test {
protected:
  TaskManager *task_manager = nullptr;

  void SetUp() override {
    task_manager = TaskManager::GetInstance();
  }

  void TearDown() override {
    // シングルトンの場合、通常はインスタンスを削除しません
    TaskManager::Destroy();
    task_manager = nullptr;
  }
};


