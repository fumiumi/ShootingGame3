#include "pch.h"
#include "gtest/gtest.h"

#include "TaskManager.h"

/*
* TaskManager�N���X�̃e�X�g
* �v��
* �T�v�F�^�X�N���ꊇ�Ǘ��A�Q�[�����[�v�ŏ���
* �V���O���g���p�^�[���Ŏ���
* �^�X�N�̒ǉ��A�폜���ł���
* �e�^�X�N�I�u�W�F�N�g�ւ̃|�C���^��ێ�����R���e�i
* Update()���\�b�h�Ŋe�^�X�N�̏������s��
* Render()���\�b�h�Ŋe�^�X�N�̕`����s��
*/

class TaskManagerTest : public ::testing::Test {
protected:
  TaskManager *task_manager = nullptr;

  void SetUp() override {
    task_manager = &TaskManager::GetInstance();
  }

  void TearDown() override {
    // �V���O���g���̏ꍇ�A�ʏ�̓C���X�^���X���폜���܂���
    task_manager = nullptr;
  }
};

// �e�X�g�P�[�X

