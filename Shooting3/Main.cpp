#include <DxLib.h>
#include <crtdbg.h>
#include <GameInfo.h>

//���������[�N���o�̂��߂ɕK�v
#if defined(_WIN64) || defined(_WIN32)
#include <windows.h>
#endif

/// <summary>
/// ���C�������p�̖������O���(���������P�[�W)
/// </summary>
namespace
{
	/// <summary>
	/// 1000�~���b�i1�b�j
	/// </summary>
	const int kOneMillisecond = 1000;

	/// <summary>
	/// �ڕWFPS
	/// </summary>
	const int kTargetFps = 60;

	/// <summary>
	/// 1�t���[���̎��ԁi�b�j
	/// </summary>
	const float kOneFrameTimeSecond = (static_cast<float>(kOneMillisecond) / static_cast<float>(kTargetFps)) / kOneMillisecond;

	/// <summary>
	/// ���݂̎��ԁi�~���b�j
	/// </summary>
	int current_time_millisecond = 0;

	/// <summary>
	/// �O��̃t���[�����s���̎��ԁi�~���b�j
	/// </summary>
	int last_frame_time_millisecond = 0;

	/// <summary>
	/// �t���[�����̃J�E���g�p
	/// </summary>
	int frame_count = 0;

	/// <summary>
	/// �Ō�Ƀt���[�����[�g���X�V�������ԁi�~���b�j
	/// </summary>
	int last_update_frame_rate_time_millisecond = 0;

	/// <summary>
	/// �Z�o�����t���[�����[�g�i�[�p
	/// </summary>
	float frame_rate = 0.0f;
}

/// <summary>
/// �t���[�����[�g�v�Z�p
/// </summary>
void CalcFrameRate();

/// <summary>
/// �t���[�����[�g�`��p
/// </summary>
void DrawFrameRate();

/// <summary>
/// �v���O������ WinMain ����n�܂�܂�
/// </summary>
/// <param name="hInstance">�A�v���P�[�V�����̌��݂̃C���X�^���X�n���h��</param>
/// <param name="hPrevInstance">Win16 �̎Y���i���NULL�j</param>
/// <param name="lpCmdLine">�R�}���h���C������</param>
/// <param name="nCmdShow">�E�B���h�E�̕\�����</param>
/// <returns>�A�v���P�[�V�����̏I���R�[�h</returns>
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//���������[�N���o�̂��߂ɋL�q
#if defined(_WIN64) || defined(_WIN32)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	//���O�t�@�C���͏o�͂��Ȃ��ݒ�ɂ���
	SetOutApplicationLogValidFlag(FALSE);

	//�E�B���h�E���[�h�ɐݒ�
	ChangeWindowMode(TRUE);

  GameInfo *game_info = GameInfo::GetInstance();

	//�E�B���h�E�T�C�Y�ƃJ���[�r�b�g��ݒ�
	//�i�l�͌�قǒ萔�����܂��j
  SetGraphMode(game_info->GetResolutionX(), game_info->GetResolutionY(), game_info->GetColorBit());

	//DX���C�u�����̏�����
	if (DxLib_Init() == -1)
	{

		//���������s�͋����I��
		return -1;
	}

	//�`���̉�ʂ𗠉�ʂɐݒ�
	SetDrawScreen(DX_SCREEN_BACK);

	//�E�B���h�E����A�N�e�B�u�ɂȂ��Ă��Q�[���͎~�߂Ȃ��悤�ɂ���
	SetAlwaysRunFlag(true);

	//�Q�[�����C�����[�v
	while (ProcessMessage() != -1)
	{
		//�V�X�e���ɏ�����n��
		Sleep(1);

		//���݂̎��ԍX�V
		current_time_millisecond = GetNowCount();

		//�o�ߎ��Ԃ��ڕW�t���[�����[�g����1�ȏ�o�߂��Ă���Ȃ�
		//�t���[�������s����
		if (current_time_millisecond - last_frame_time_millisecond >= kOneMillisecond / kTargetFps)
		{
			//�O��t���[�����s����̌o�ߎ��Ԃ�b�ŎZ�o
			float delta_time = static_cast<float>(current_time_millisecond - last_frame_time_millisecond) / kOneMillisecond;

			//�Ō�Ƀt���[�������s�������Ԃ��X�V
			last_frame_time_millisecond = current_time_millisecond;

			//�t���[�����s�̂��т�FPS���J�E���g����
			++frame_count;

			//��ʂ̏���
			ClearDrawScreen();

			//�E�B���h�E���A�N�e�B�u�Ȃ���s���鏈��
			if (GetWindowActiveFlag() == TRUE)
			{
				//Update�֘A���Ă�
			}

			//�`��֘A���Ă�

			//�t���[�����[�g�̌v�Z
			CalcFrameRate();

			//�t���[�����[�g�̕`��
			DrawFrameRate();

			//�o�ߎ��Ԃ�`��
			//�i�K�v�ɉ����Ē萔�����Ă��������j
			DrawFormatString(0, 16, GetColor(255, 30, 30), _T("delta_time[%.4f]"), delta_time);

			//�\��ʂւ̏o��
			ScreenFlip();
		}
	}

	//DX���C�u�����̏I������
	DxLib_End();

	return 0;
}

/// <summary>
/// �t���[�����[�g�v�Z�p
/// </summary>
void CalcFrameRate()
{
	//�O��̃t���[�����[�g�X�V����̌o�ߎ��Ԃ����߂�
	int diff_time = current_time_millisecond - last_update_frame_rate_time_millisecond;

	//�O��̃t���[�����[�g�X�V����
	//1�b�ȏ�o�߂��Ă�����t���[�����[�g���X�V����
	if (diff_time > kOneMillisecond)
	{
		//�t���[���񐔂��~���b�ɍ��킹��
		//�����܂ŏo�������̂�float�ɃL���X�g
		float count = (float)(frame_count * kOneMillisecond);

		//�t���[�����[�g�����߂�
		//���z�ǂ���Ȃ� 60000 / 1000 �� 60 �ƂȂ�
		frame_rate = count / diff_time;

		//�t���[���J�E���g���N���A
		frame_count = 0;

		//�t���[�����[�g�X�V���Ԃ��X�V
		last_update_frame_rate_time_millisecond = current_time_millisecond;
	}

}

/// <summary>
/// �t���[�����[�g�`��p
/// </summary>
void DrawFrameRate()
{
	//�t���[�����[�g�̕`��
	//�i�K�v�ɉ����Ē萔�����Ă��������j
	DrawFormatString(0, 0, GetColor(255, 30, 30), _T("FPS[%.2f]"), frame_rate);
}