//------------------------------------------------------------------------------
// Project Name: [�v���W�F�N�g��]
// File Name: [�t�@�C����]
// Description: [�t�@�C���̊ȒP�Ȑ���]
// Author: [�J���Җ��܂��̓`�[����]
// Copyright [�N] [����Җ��܂��͑g�D��]
// Created Date: [�쐬��]
// Last Updated: [�ŏI�X�V��]
//------------------------------------------------------------------------------
#pragma once

#include <vector>

/// <summary>
/// int�^��TaskId�̃G�C���A�X�錾
/// </summary>
typedef unsigned int TaskId;

/// <summary>
/// Task�N���X�̑O���錾
/// ����.h����Task*�͈�����悤�ɂȂ�
/// </summary>
class Task;

/// <summary>
/// �^�X�N�}�l�[�W���[����
/// </summary>
/// <remarks>
/// �e�I�u�W�F�N�g�̓^�X�N����h�����ăC���X�^���X�����A
/// �^�X�N�}�l�[�W���[�ł̓C���X�^���X���ꌳ�Ǘ�����
/// </remarks>
class TaskManager
{
public:
	/// <summary>
	/// TaskManager�̃C���X�^���X���擾����
	/// �i�V���O���g���f�U�C���p�^�[���j
	/// </summary>
	/// <returns>TaskManager�̃C���X�^���X</returns>
	static TaskManager *GetInstance()
	{
    if (instance_ == nullptr)
    {
      instance_ = new TaskManager();
    }
    return instance_;
	}

	/// <summary>
	/// TaskManager�̃C���X�^���X���폜
	/// �Q�[���I�����ɕK���Ă�
	/// </summary>
	static void Destroy()
	{
    if (instance_ != nullptr)
    {
      delete instance_;
      instance_ = nullptr;
    }
	}

	/// <summary>
	/// �^�X�N��ǉ�����
	/// </summary>
	/// <param name="task">�ǉ�����^�X�N</param>
	/// <returns>���s����TaskId</returns>
	TaskId AddTask(Task *task);

	/// <summary>
	/// �^�X�N���������
	/// </summary>
	/// <param name="task_id">�^�X�NID</param>
	/// <returns>�����F��������^�X�N�A���s�Fnullptr</returns>
	Task *ReleaseTask(TaskId task_id);

	/// <summary>
	/// �^�X�N�̖��t���[���X�V���������s����
	/// </summary>
	/// <param name="delta_time">�Ō�̃t���[������������̂ɗv�������� (�b) </param>
	void UpdateTask(float delta_time);

	/// <summary>
	/// �^�X�N�̖��t���[���̕`�旝�����s����
	/// </summary>
	void RenderTask();

private:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	TaskManager();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~TaskManager();

	/// <summary>
	/// TaskID�̊J�n�ԍ�
	/// </summary>
	static const TaskId kStartTaskId;

	/// <summary>
	/// TaskManager�̃C���X�^���X
	/// </summary>
	static TaskManager *instance_;

	/// <summary>
	/// �^�X�N���X�g
	/// </summary>
	std::vector<Task *> task_list_;

	/// <summary>
	/// �ǉ��^�X�N���X�g
  /// Update���̃��\�[�X�̊m�ہE�����h������
	/// </summary>
	std::vector<Task *> add_task_list_;

	/// <summary>
	/// ����^�X�N���X�g
  /// �J�����ׂ��^�X�N���킩��Ηǂ��̂�ID������ێ�
	/// Update���̃��\�[�X�̊m�ہE�����h������
	/// </summary>
	std::vector<TaskId> release_task_list_;

	/// <summary>
	/// �Ō�Ɋ���U�����^�X�NID
	/// </summary>
	int last_assigned_task_id_;
};