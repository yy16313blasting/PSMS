#include "StdAfx.h"
#include "MusicPlayer.h"
#include <MMSystem.h>
#pragma comment(lib,"winmm.lib")


CMusicPlayer::CMusicPlayer(void)
{
}


CMusicPlayer::~CMusicPlayer(void)
{
}

//ʵ�ֳ�Ա����
void CMusicPlayer::playAudioOfDiary(void)
{
	 PlaySound("..\\PSMS\\res\\001.wav", NULL, SND_FILENAME | SND_ASYNC);//ʹ�þֲ�����
}
void CMusicPlayer::playAudioOfMemo(void)
{
	PlaySound("..\\PSMS\\res\\002", NULL, SND_FILENAME | SND_ASYNC);//ʹ�þֲ�����
}
void CMusicPlayer::playAudioOfTimeRemind(void)
{
	PlaySound("..\\PSMS\\res\\003", NULL, SND_FILENAME | SND_ASYNC);//ʹ�þֲ�����
}
void CMusicPlayer::playAudioOfDateRemind(void)
{
	PlaySound("..\\PSMS\\res\\004", NULL, SND_FILENAME | SND_ASYNC);//ʹ�þֲ�����
}
void CMusicPlayer::playAudioOfHoliday(void)
{
	PlaySound("..\\PSMS\\res\\005", NULL, SND_FILENAME | SND_ASYNC);//ʹ�þֲ�����
}