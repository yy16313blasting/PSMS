#include "StdAfx.h"
#include "User.h"

CUser::CUser(void)
{
}

CUser::~CUser(void)
{
}

CString CUser::GetUserPassword(CString name)
{   
	CString m_szPassword;
	m_szPassword=usrDA.GetUserPassword(name);
	return m_szPassword;
}

bool CUser::ExistUser(CString name)
{   
	bool m_ExistUser;
	m_ExistUser=usrDA.ExistUser(name);
	return m_ExistUser;
}

void CUser::AddDiary(CDiary diary)
{   
	usrDA.AddDiary(diary);
}

void CUser::AddMemo(CMemo memo)
{
	usrDA.AddMemo(memo);
}

void CUser::AddTimeRemind(CTimeRemind timeRemind)
{
	usrDA.AddTimeRemind(timeRemind);
}

void CUser::AddDateRemind(CDateRemind dateRemind)
{
	usrDA.AddDateRemind(dateRemind);
}


void CUser::RemoveDiary(CDiary diary)
{
	usrDA.RemoveDiary(diary);
}

void CUser::RemoveMemo(CMemo memo)
{
		usrDA.RemoveMemo(memo);
}

void CUser::RemoveTimeRemind(CTimeRemind timeRemind)
{
	usrDA.RemoveTimeRemind(timeRemind);
}

void CUser::RemoveDateRemind(CDateRemind dateRemind)
{
	usrDA.RemoveDateRemind(dateRemind);
}

void CUser::UpdateDiary(CDiary diary)
{
	usrDA.UpdateDiary(diary);
}

void CUser::UpdateMemo(CMemo memo)
{
	usrDA.UpdateMemo(memo);
}

void CUser::UpdateDateRemind(CDateRemind dateRemind)
{
	usrDA.UpdateDateRemind(dateRemind);
}

void CUser::UpdateTimeRemind(CTimeRemind timeRemind)
{
	usrDA.UpdateTimeRemind(timeRemind);
}

void CUser::GetAllDiary(CDiary*& list)
{
	usrDA.GetAllDiary(list);
}

void CUser::GetAllMemo(CMemo*& list)
{
	usrDA.GetAllMemo(list);
}

void CUser::GetAllTimeRemind(CTimeRemind*& list)
{
	usrDA.GetAllTimeRemind(list);
}

void CUser::GetAllDateRemind(CDateRemind*& list)
{
	usrDA.GetAllDateRemind(list);
}

void CUser::GetAllHoliday(CHoliday*& list)
{
	usrDA.GetAllHoliday(list);
}

int CUser::CountAllDiary()
{
		int CountAllDiary;
		CountAllDiary=usrDA.CountAllDiary();
		return CountAllDiary;
}

int CUser::CountAllMemo()
{
		int CountAllMemo;
		CountAllMemo=usrDA.CountAllMemo();
		return CountAllMemo;
}

int CUser::CountAllTimeRemind()
{
		int CountAllTimeRemind;
		CountAllTimeRemind=usrDA.CountAllTimeRemind();
		return CountAllTimeRemind;
}

int CUser::CountAllDateRemind()
{
		int CountAllDateRemind;
		CountAllDateRemind=usrDA.CountAllDateRemind();
		return CountAllDateRemind;
}

int CUser::CountAllHoliday()
{
		int CountAllHoliday;
		CountAllHoliday=usrDA.CountAllHoliday();
		return CountAllHoliday;
}
bool CUser:: ExistDiary(CDiary diary)
{		
	return false;
}

bool CUser:: ExistMemo(CMemo memo)
{		
	return false;
}

bool CUser:: ExistTimeRemind(CTimeRemind timeRemind)
{		
	return false;
}

bool CUser:: ExistDateRemind(CDateRemind dateRemind)
{		
	return false;
}

void CUser::PurgeDiary()
{
	usrDA.PurgeDiary();
}

void CUser::PurgeMemo()
{
	usrDA.PurgeMemo();
}

void CUser::PurgeTimeRemind()
{
	usrDA.PurgeTimeRemind();
}

void CUser::PurgeDateRemind()
{
	usrDA.PurgeDateRemind();
}

void CUser::SetName(CString name)
{
	m_szName = name;
}

CString CUser::GetName()
{
	return m_szName;
}