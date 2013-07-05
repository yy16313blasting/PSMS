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

//实现成员函数
void CMusicPlayer::playAudioOfDiary(void)
{
	 PlaySound("..\\PSMS\\res\\001.wav", NULL, SND_FILENAME | SND_ASYNC);//使用局部变量
}
void CMusicPlayer::playAudioOfMemo(void)
{
	PlaySound("..\\PSMS\\res\\002", NULL, SND_FILENAME | SND_ASYNC);//使用局部变量
}
void CMusicPlayer::playAudioOfTimeRemind(void)
{
	PlaySound("..\\PSMS\\res\\003", NULL, SND_FILENAME | SND_ASYNC);//使用局部变量
}
void CMusicPlayer::playAudioOfDateRemind(void)
{
	PlaySound("..\\PSMS\\res\\004", NULL, SND_FILENAME | SND_ASYNC);//使用局部变量
}
void CMusicPlayer::playAudioOfHoliday(void)
{
	PlaySound("..\\PSMS\\res\\005", NULL, SND_FILENAME | SND_ASYNC);//使用局部变量
}