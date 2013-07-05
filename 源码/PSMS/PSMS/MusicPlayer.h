#pragma once
//此处定义ini文件路径
#define ROAD "..\\PSMS\\res"
class CMusicPlayer
{
public:
	CMusicPlayer(CString p);
	~CMusicPlayer(void);

	//定义成员函数
	void playAudioOfDiary(void);
	void playAudioOfMemo(void);
	void playAudioOfTimeRemind(void);
	void playAudioOfDateRemind(void);
	void playAudioOfHoliday(void);
	//实现路径的读写，以保存
	void write(void);
	LPTSTR read(void);
	void transferPath(void);
	CString BootOpenDialog(void);
	
private:
	CString m_strMuPath; //用于传递路径的成员变量


};

