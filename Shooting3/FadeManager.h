#pragma once

/// <summary>
/// �Q�[�����[�v�̂ǂ�����ł��A�N�Z�X�ł���悤��
/// �V���O���g���p�^�[���Ŏ���
/// </summary>
class FadeManager
{
public:
  static FadeManager *GetInstance()
  {
    //��������ĂȂ��Ȃ瓮�I����
    if (instance_ == nullptr)
    {
      instance_ = new FadeManager();
    }
    //FadeManager�̃C���X�^���X��Ԃ�
    return instance_;
  }

  static void Destroy()
  {
    //�����ς݂Ȃ�폜
    if (instance_ != nullptr)
    {
      delete instance_;
      instance_ = nullptr;
    }
  }

  /// <summary>
  /// �C���v�b�g�}�l�[�W���[�Ƀt�F�[�h�C���^�X�N��o�^
  /// </summary>
  /// <param name="duration"></param>
  void FadeIn(float duration);

  /// <summary>
  /// �C���v�b�g�}�l�[�W���[�Ƀt�F�[�h�A�E�g�^�X�N��o�^
  /// </summary>
  /// <param name="duration"></param>
  void FadeOut(float duration);

  void Update(float delta_time);
  void Render();

private:
  FadeManager();
  ~FadeManager() = default;
  static FadeManager *instance_;

  float fade_alpha_;

};