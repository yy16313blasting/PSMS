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
	void playAudioOfDiary(LPCTSTR path);
	void playAudioOfMemo(LPCTSTR path);
	void playAudioOfTimeRemind(LPCTSTR path);
	void playAudioOfDateRemind(LPCTSTR path);
	void playAudioOfHoliday(LPCTSTR path);
	//ʵ��·���Ķ�д���Ա���
	void write(LPCTSTR path);
	void read(LPCTSTR path);
	void transferPath(void);
	CString BootOpenDialog(void);
	
private:
	CString m_strMuPath; //���ڴ���·���ĳ�Ա����
	LPTSTR m_lpMuPath;
};

