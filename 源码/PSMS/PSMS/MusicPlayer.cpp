#include "StdAfx.h"
#include "MusicPlayer.h"
#include <MMSystem.h>
#pragma comment(lib,"winmm.lib")

//ʹ�ó�ʼ���б�ķ�ʽ��ʼ��
CMusicPlayer::CMusicPlayer():m_strMuPath(""),m_lpMuPath("")
{
};


CMusicPlayer::~CMusicPlayer(void)
{
}

//ʵ�ֳ�Ա����
//���ļ��Լ������ļ��ĳ�Ա������ʵ��
CString CMusicPlayer::BootOpenDialog(void)
{
	CString strFile = _T("");

    CFileDialog    dlgFile(TRUE, NULL, NULL, OFN_HIDEREADONLY, _T("Music Files (*.wav)|*.wav|All Files (*.*)|*.*||"), NULL);
    if (dlgFile.DoModal())
    {
        strFile = dlgFile.GetPathName();//��ȡ�ļ�·��getpathname����
    }
    return strFile;
}
void CMusicPlayer::transferPath(void)
{
	m_strMuPath = "";
	//���ļ��Ի��򣬷����ļ�·��
	m_strMuPath = BootOpenDialog();
	//���ַ������в�����ɾȥ".wav��
	m_strMuPath.TrimRight(".wav");
}

//�޸������Ľӿں�ʵ��
void CMusicPlayer::write(LPCTSTR path)
{
	WritePrivateProfileString("Path",path,m_strMuPath,ROAD);
}



//����·��
void CMusicPlayer::read(LPCTSTR path)
{
	m_lpMuPath = new char[MAX_PATH];//new
	GetPrivateProfileString("Path",path,"",m_lpMuPath,MAX_PATH,ROAD);

	
	/*
	//�˺����ڲ��Զ����и�ֵ����
    GetPrivateProfileString(
						   lpAppName,        // INI�ļ��е�һ���ֶ���[����]�����кܶ������
						   lpKeyName,        // lpAppName �µ�һ��������Ҳ�����������ı�����
						   lpDefault,        // ���lpReturnedStringΪ��,��Ѹ���������lpReturnedString
						   lpReturnedString,  // ��ż�ֵ��ָ�����,���ڽ���INI�ļ��м�ֵ(����)�Ľ��ջ�����
						   nSize,            // lpReturnedString�Ļ�������С
						   lpPath        // INI�ļ���·��
							);
	return lpReturnedString;
	delete [] lpPath;
	*/
}

//�������õĽӿڣ�ʵ��
void CMusicPlayer::playAudioOfDiary(LPCTSTR path)
{
	read(path);
	PlaySound(m_lpMuPath, NULL, SND_FILENAME | SND_ASYNC);//ʹ�þֲ�����
	delete [] m_lpMuPath;//delete
}
void CMusicPlayer::playAudioOfMemo(LPCTSTR path)
{
	read(path);
	PlaySound("..\\PSMS\\res\\002", NULL, SND_FILENAME | SND_ASYNC);//ʹ�þֲ�����
	delete [] m_lpMuPath;//delete
}
void CMusicPlayer::playAudioOfTimeRemind(LPCTSTR path)
{
	read(path);
	PlaySound("..\\PSMS\\res\\003", NULL, SND_FILENAME | SND_ASYNC);//ʹ�þֲ�����
	delete [] m_lpMuPath;//delete
}
void CMusicPlayer::playAudioOfDateRemind(LPCTSTR path)
{
	read(path);
	PlaySound("..\\PSMS\\res\\004", NULL, SND_FILENAME | SND_ASYNC);//ʹ�þֲ�����
	delete [] m_lpMuPath;//delete
}
void CMusicPlayer::playAudioOfHoliday(LPCTSTR path)
{
	read(path);
	PlaySound("..\\PSMS\\res\\005", NULL, SND_FILENAME | SND_ASYNC);//ʹ�þֲ�����
	delete [] m_lpMuPath;//delete
}
