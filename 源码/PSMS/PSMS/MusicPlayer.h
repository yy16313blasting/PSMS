#pragma once
//�˴�����ini�ļ�·��
#define ROAD "..\\PSMS\\res"
class CMusicPlayer
{
public:
	CMusicPlayer(CString p);
	~CMusicPlayer(void);

	//�����Ա����
	void playAudioOfDiary(void);
	void playAudioOfMemo(void);
	void playAudioOfTimeRemind(void);
	void playAudioOfDateRemind(void);
	void playAudioOfHoliday(void);
	//ʵ��·���Ķ�д���Ա���
	void write(void);
	LPTSTR read(void);
	void transferPath(void);
	CString BootOpenDialog(void);
	
private:
	CString m_strMuPath; //���ڴ���·���ĳ�Ա����


};

