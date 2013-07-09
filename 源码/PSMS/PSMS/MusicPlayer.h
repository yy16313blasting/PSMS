#pragma once
//此处定义ini文件路径
#define ROAD "..//PSMS//res//road.ini"
#define DIARY "diary"
#define MEMO "memo"
#define TIMER "timeremind"
#define DATER "dateremind"
#define HOLIDAY "holiday"

class CMusicPlayer
{
public:
	CMusicPlayer(void);
	~CMusicPlayer(void);

	//定义成员函数
	void playAudioOfDiary();
	void playAudioOfMemo();
	void playAudioOfTimeRemind();
	void playAudioOfDateRemind();
	void playAudioOfHoliday();
	//实现路径的读写，以保存
	void write(void);
	void read(void);
	void transferPath(void);
	CString BootOpenDialog(void);
	void CloseMusic(void);
	
private:
	CString m_strMuPath; //用于传递路径的成员变量
	LPTSTR m_lpMuPath;
};

