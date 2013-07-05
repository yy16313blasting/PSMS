#include "StdAfx.h"
#include "MusicPlayer.h"
#include <MMSystem.h>
#pragma comment(lib,"winmm.lib")

//ʹ�ó�ʼ���б�ķ�ʽ��ʼ��
CMusicPlayer::CMusicPlayer(CString p):m_strMuPath("")
{
};


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

//���ļ��Լ������ļ��ĳ�Ա������ʵ��
CString CMusicPlayer::BootOpenDialog(void)
{
	CString strFile = _T("");

    CFileDialog    dlgFile(TRUE, NULL, NULL, OFN_HIDEREADONLY, _T("Describe Files (*.wav)|*.wav|All Files (*.*)|*.*||"), NULL);
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
}

void CMusicPlayer::write(void)
{
	LPCTSTR lpAppName = "Path";
	LPCTSTR lpKeyName = "path";
	//lpString = m_strMuPath;
	LPTSTR lpPath = new char[MAX_PATH];
	strcpy(lpPath, ROAD);
	WritePrivateProfileString(lpAppName,lpKeyName,m_strMuPath,lpPath);
	delete [] lpPath;

}

//����·��
LPTSTR CMusicPlayer::read()
{
	LPTSTR	ReturnedString = new char[MAX_PATH];
	LPCTSTR lpAppName = "Path";
	LPCTSTR lpKeyName = "path";
	LPCTSTR lpDefault = "";
	LPTSTR lpReturnedString = new char[MAX_PATH];
	DWORD nSize = MAX_PATH;
	LPTSTR lpPath = new char[MAX_PATH];
	strcpy(lpPath, "");
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
}