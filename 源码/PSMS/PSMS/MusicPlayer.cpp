#include "StdAfx.h"
#include "MusicPlayer.h"
#include <MMSystem.h>
#pragma comment(lib,"winmm.lib")

//使用初始化列表的方式初始化
CMusicPlayer::CMusicPlayer(CString p):m_strMuPath("")
{
};


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

//打开文件以及返回文件的成员方法的实现
CString CMusicPlayer::BootOpenDialog(void)
{
	CString strFile = _T("");

    CFileDialog    dlgFile(TRUE, NULL, NULL, OFN_HIDEREADONLY, _T("Describe Files (*.wav)|*.wav|All Files (*.*)|*.*||"), NULL);
    if (dlgFile.DoModal())
    {
        strFile = dlgFile.GetPathName();//获取文件路径getpathname（）
    }
    return strFile;
}
void CMusicPlayer::transferPath(void)
{
	m_strMuPath = "";
	//打开文件对话框，返回文件路径
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

//传出路径
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
	//此函数内部自动进行赋值操作
    GetPrivateProfileString(
						   lpAppName,        // INI文件中的一个字段名[节名]可以有很多个节名
						   lpKeyName,        // lpAppName 下的一个键名，也就是里面具体的变量名
						   lpDefault,        // 如果lpReturnedString为空,则把个变量赋给lpReturnedString
						   lpReturnedString,  // 存放键值的指针变量,用于接收INI文件中键值(数据)的接收缓冲区
						   nSize,            // lpReturnedString的缓冲区大小
						   lpPath        // INI文件的路径
							);
	return lpReturnedString;
	delete [] lpPath;
}