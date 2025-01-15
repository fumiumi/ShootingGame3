#pragma once

/// <summary>
/// �C���v�b�g�}�l�[�W���[����
/// </summary>
/// <remarks>
/// �L�[�{�[�h��p�b�h����̓��͂��Ǘ�����
/// �i�T���v���Ȃ̂Ńp�b�h�͖������j
/// </remarks>
class InputManager
{
public:
	/// <summary>
	/// �g�p����Q�[���ł̃L�[�̎��
	/// </summary>
	enum class GameKeyKind
	{
		/// <summary>
		/// ����
		/// </summary>
		kDecide,
		/// <summary>
		/// �L�����Z��
		/// </summary>
		kCancel,
		/// <summary>
		/// ��{�^��
		/// </summary>
		kUp,
		/// <summary>
		/// ���{�^��
		/// </summary>
		kDown,
		/// <summary>
		/// ���{�^��
		/// </summary>
		kLeft,
		/// <summary>
		/// �E�{�^��
		/// </summary>
		kRight,
		/// <summary>
		/// �|�[�Y
		/// </summary>
		kPause,
		/// <summary>
		/// �v���C���[����
		/// </summary>
		kPlayerMoveSlow,
		/// <summary>
		/// �v���C���[�o���b�g����
		/// </summary>
		kPlayerFire,
		/// <summary>
		/// ����
		/// </summary>
		kNum,
	};

	static InputManager *GetInstance()
  {
    //��������Ă��Ȃ��Ȃ琶��
    if (instance_ == nullptr) {
      instance_ = new InputManager();
    }
    return instance_;
  }

	static void Destory()
	{
		////�����ς݂Ȃ�폜
		//if (instance_ != nullptr) {
		//	delete instance_;
		//	instance_ = nullptr;
		//}
    //�����j���Ȃ̂ŉ������Ȃ�
	}

	/// <summary>
	/// �^�X�N�̍X�V�̑O�ɌĂ΂��֐�
	/// </summary>
	/// <param name="delta_time">�O����s�t���[������̌o�ߎ��ԁi�b�j</param>
	void UpdateKeyStateAll(float delta_time);

	/// <summary>
	/// �^�X�N�̍X�V�̌�ɌĂ΂��֐�
	/// </summary>
	/// <param name="delta_time">�O����s�t���[������̌o�ߎ��ԁi�b�j</param>
	void RecordKeyStateAll(float delta_time);

	/// <summary>
	/// �����̃L�[�͂��̃t���[���ŉ����ꂽ��
	/// </summary>
	/// <param name="key_kind">���ׂ�L�[</param>
	/// <returns>������Ă���Ȃ�true</returns>
	bool IsPushThisFrame(GameKeyKind game_key_kind);

	/// <summary>
	/// �����̃L�[�͉�����Ă��邩
	/// </summary>
	/// <param name="game_key_kind">���ׂ�L�[</param>
	/// <returns>������Ă���Ȃ�true</returns>
	bool IsDown(GameKeyKind game_key_kind);


private:
	InputManager();
	virtual ~InputManager() = default;

	static InputManager *instance_;

	/// <summary>
	/// �L�[��Ԃ��i�[����o�b�t�@�̃T�C�Y
	/// </summary>
	static const int kKeyBufferSize = 256;

	/// <summary>
	/// ���݂̃t���[���̃L�[���
	/// GetHitKeyStateAll �֐����g���ɂ͂܂� 
	/// char �^�ϐ� 256 �̔z���錾���܂��B 
	/// �K�� char �^�ŁA���� 256 �łȂ��Ƃ����܂���B
	/// </summary>
	char current_key_buffer_[kKeyBufferSize];

	/// <summary>
	/// �O��t���[���̃L�[���
	/// GetHitKeyStateAll �֐����g���ɂ͂܂� 
	/// char �^�ϐ� 256 �̔z���錾���܂��B 
	/// �K�� char �^�ŁA���� 256 �łȂ��Ƃ����܂���B
	/// </summary>
	char pre_key_buffer_[kKeyBufferSize];
};