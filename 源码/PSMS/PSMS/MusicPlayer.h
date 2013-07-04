#pragma once
class CMusicPlayer
{
public:
	CMusicPlayer(void);
	~CMusicPlayer(void);

	//定义成员函数
	void playAudioOfDiary(void);
	void playAudioOfMemo(void);
	void playAudioOfTimeRemind(void);
	void playAudioOfDateRemind(void);
	void playAudioOfHoliday(void);
};

