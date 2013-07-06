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
	void playAudioOfDiary(LPCTSTR path);
	void playAudioOfMemo(LPCTSTR path);
	void playAudioOfTimeRemind(LPCTSTR path);
	void playAudioOfDateRemind(LPCTSTR path);
	void playAudioOfHoliday(LPCTSTR path);
	//实现路径的读写，以保存
	void write(LPCTSTR path);
	void read(LPCTSTR path);
	void transferPath(void);
	CString BootOpenDialog(void);
	
private:
	CString m_strMuPath; //用于传递路径的成员变量
	LPTSTR m_lpMuPath;
};

