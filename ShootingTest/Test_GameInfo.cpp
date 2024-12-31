#include "pch.h"
#include "gtest/gtest.h"
#include "GameInfo.h"

class GameInfoTest : public ::testing::Test {
protected:
  GameInfo *game_info = nullptr;

  // �e�e�X�g�P�[�X�̑O�ɌĂ΂��Z�b�g�A�b�v�֐�
  void SetUp() override {
    game_info = GameInfo::GetInstance();
  }

  // �e�e�X�g�P�[�X�̌�ɌĂ΂��e�B�A�_�E���֐�
  void TearDown() override {
    game_info->Destroy();
    game_info = nullptr;
  }
};

// �e�X�g�P�[�X

// ���������̃f�t�H���g�l�̃e�X�g
TEST_F(GameInfoTest, DefaultValueIsValid)
{
  // game_info���C���X�^���X������Ă��邱�Ƃ��m�F
  EXPECT_NE(game_info, nullptr);

  // �f�t�H���g�l�̊m�F
  // ��ʉ𑜓x�̉���
  EXPECT_EQ(game_info->GetResolutionX(), 1280);
  // ��ʉ𑜓x�̏c��
  EXPECT_EQ(game_info->GetResolutionY(), 720);
  // ��ʂ̒��S���W��x����  
  EXPECT_EQ(game_info->GetCenterX(), 640);
  // ��ʂ̒��S���W��y����
  EXPECT_EQ(game_info->GetCenterY(), 360);
  // �J���[�r�b�g��
  EXPECT_EQ(game_info->GetColorBit(), 32);
  // �f�o�b�O���[�h
  EXPECT_FALSE(game_info->IsDebugDisplay());
  // �Q�[���I���t���O
  EXPECT_FALSE(game_info->IsEndGame());
}

// �f�o�b�O���[�h�̃e�X�g
TEST_F(GameInfoTest, SetEndGame)
{
  game_info->SetDebugDisplay(true);
  EXPECT_TRUE(game_info->IsDebugDisplay());
}

// �Q�[���I���t���O�̃e�X�g
TEST_F(GameInfoTest, SetDebugDisplay)
{
  game_info->SetDebugDisplay(true);
  EXPECT_TRUE(game_info->IsDebugDisplay());
}