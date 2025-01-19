#pragma once

/// <summary>
/// �Q�[�����[�v�̂ǂ�����ł��A�N�Z�X�ł���悤��
/// �V���O���g���p�^�[���Ŏ���
/// </summary>
class FadeManager
{
public:
  enum class FadeManagerState
  {
    kFadeIn,
    kFadeOut,
    kNone
  };

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
  /// �N���C�A���g��FadeManager�Ƀt�F�[�h�C��/�A�E�g���˗�����֐�
  /// </summary>
  /// <param name="duration">�~���b</param>
  void RequestFadeIO(float duration, FadeManagerState mode);

  void RenderFade(float delta_time);

  bool IsRequested() const;

private:
  FadeManager();
  ~FadeManager() = default;
  static FadeManager *instance_;

  FadeManagerState fade_manager_state_;
  float duration_;
  float fade_alpha_;

  bool is_requested_;

  int fade_handle_;
};