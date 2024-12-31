#include "pch.h"
#include "gtest/gtest.h"
#include "GameInfo.h"

class GameInfoTest : public ::testing::Test {
protected:
  GameInfo *game_info = nullptr;

  // 各テストケースの前に呼ばれるセットアップ関数
  void SetUp() override {
    game_info = GameInfo::GetInstance();
  }

  // 各テストケースの後に呼ばれるティアダウン関数
  void TearDown() override {
    game_info->Destroy();
    game_info = nullptr;
  }
};

// テストケース

// 初期化時のデフォルト値のテスト
TEST_F(GameInfoTest, DefaultValueIsValid)
{
  // game_infoがインスタンス化されていることを確認
  EXPECT_NE(game_info, nullptr);

  // デフォルト値の確認
  // 画面解像度の横幅
  EXPECT_EQ(game_info->GetResolutionX(), 1280);
  // 画面解像度の縦幅
  EXPECT_EQ(game_info->GetResolutionY(), 720);
  // 画面の中心座標のx成分  
  EXPECT_EQ(game_info->GetCenterX(), 640);
  // 画面の中心座標のy成分
  EXPECT_EQ(game_info->GetCenterY(), 360);
  // カラービット数
  EXPECT_EQ(game_info->GetColorBit(), 32);
  // デバッグモード
  EXPECT_FALSE(game_info->IsDebugDisplay());
  // ゲーム終了フラグ
  EXPECT_FALSE(game_info->IsEndGame());
}

// デバッグモードのテスト
TEST_F(GameInfoTest, SetEndGame)
{
  game_info->SetDebugDisplay(true);
  EXPECT_TRUE(game_info->IsDebugDisplay());
}

// ゲーム終了フラグのテスト
TEST_F(GameInfoTest, SetDebugDisplay)
{
  game_info->SetDebugDisplay(true);
  EXPECT_TRUE(game_info->IsDebugDisplay());
}