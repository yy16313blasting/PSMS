#pragma once
//�˴�����ini�ļ�·��
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

	//�����Ա����
	void playAudioOfDiary();
	void playAudioOfMemo();
	void playAudioOfTimeRemind();
	void playAudioOfDateRemind();
	void playAudioOfHoliday();
	//ʵ��·���Ķ�д���Ա���
	void write(void);
	void read(void);
	void transferPath(void);
	CString BootOpenDialog(void);
	void CloseMusic(void);
	
private:
	CString m_strMuPath; //���ڴ���·���ĳ�Ա����
	LPTSTR m_lpMuPath;
};

