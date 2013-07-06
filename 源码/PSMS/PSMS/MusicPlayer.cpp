#include "StdAfx.h"
#include "MusicPlayer.h"
#include <MMSystem.h>
#pragma comment(lib,"winmm.lib")

//使用初始化列表的方式初始化
CMusicPlayer::CMusicPlayer():m_strMuPath(""),m_lpMuPath("")
{
};


CMusicPlayer::~CMusicPlayer(void)
{
}

//实现成员函数
//打开文件以及返回文件的成员方法的实现
CString CMusicPlayer::BootOpenDialog(void)
{
	CString strFile = _T("");

    CFileDialog    dlgFile(TRUE, NULL, NULL, OFN_HIDEREADONLY, _T("Music Files (*.wav)|*.wav|All Files (*.*)|*.*||"), NULL);
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
	//对字符串进行操作，删去".wav”
	m_strMuPath.TrimRight(".wav");
}

//修改声音的接口和实现
void CMusicPlayer::write(LPCTSTR path)
{
	WritePrivateProfileString("Path",path,m_strMuPath,ROAD);
}



//传出路径
void CMusicPlayer::read(LPCTSTR path)
{
	m_lpMuPath = new char[MAX_PATH];//new
	GetPrivateProfileString("Path",path,"",m_lpMuPath,MAX_PATH,ROAD);

	
	/*
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
	*/
}

//声音调用的接口，实现
void CMusicPlayer::playAudioOfDiary(LPCTSTR path)
{
	read(path);
	PlaySound(m_lpMuPath, NULL, SND_FILENAME | SND_ASYNC);//使用局部变量
	delete [] m_lpMuPath;//delete
}
void CMusicPlayer::playAudioOfMemo(LPCTSTR path)
{
	read(path);
	PlaySound("..\\PSMS\\res\\002", NULL, SND_FILENAME | SND_ASYNC);//使用局部变量
	delete [] m_lpMuPath;//delete
}
void CMusicPlayer::playAudioOfTimeRemind(LPCTSTR path)
{
	read(path);
	PlaySound("..\\PSMS\\res\\003", NULL, SND_FILENAME | SND_ASYNC);//使用局部变量
	delete [] m_lpMuPath;//delete
}
void CMusicPlayer::playAudioOfDateRemind(LPCTSTR path)
{
	read(path);
	PlaySound("..\\PSMS\\res\\004", NULL, SND_FILENAME | SND_ASYNC);//使用局部变量
	delete [] m_lpMuPath;//delete
}
void CMusicPlayer::playAudioOfHoliday(LPCTSTR path)
{
	read(path);
	PlaySound("..\\PSMS\\res\\005", NULL, SND_FILENAME | SND_ASYNC);//使用局部变量
	delete [] m_lpMuPath;//delete
}
