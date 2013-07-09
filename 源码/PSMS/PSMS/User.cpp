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
	m_szPassword=userDA.GetUserPassword(name);
	return m_szPassword;
}

CString CUser::GetMotto()
{
	return userDA.GetUserMotto(m_szName);
}

int CUser::GetTimeFrequency()
{
	return userDA.GetUserTimeFrequency(m_szName);
}

bool CUser::ExistUser(CString name)
{   
	bool m_ExistUser;
	m_ExistUser=userDA.ExistUser(name);
	return m_ExistUser;
}

void CUser::AddDiary(CDiary diary)
{   
	userDA.AddDiary(diary);
}

void CUser::AddMemo(CMemo memo)
{
	userDA.AddMemo(memo);
}

void CUser::AddTimeRemind(CTimeRemind timeRemind)
{
	userDA.AddTimeRemind(timeRemind);
}

void CUser::AddDateRemind(CDateRemind dateRemind)
{
	userDA.AddDateRemind(dateRemind);
}


void CUser::RemoveDiary(CDiary diary)
{
	userDA.RemoveDiary(diary);
}

void CUser::RemoveMemo(CMemo memo)
{
		userDA.RemoveMemo(memo);
}

void CUser::RemoveTimeRemind(CTimeRemind timeRemind)
{
	userDA.RemoveTimeRemind(timeRemind);
}

void CUser::RemoveDateRemind(CDateRemind dateRemind)
{
	userDA.RemoveDateRemind(dateRemind);
}

void CUser::UpdateDiary(CDiary diary)
{
	userDA.UpdateDiary(diary);
}

void CUser::UpdateMemo(CMemo memo)
{
	userDA.UpdateMemo(memo);
}

void CUser::UpdateDateRemind(CDateRemind dateRemind)
{
	userDA.UpdateDateRemind(dateRemind);
}

void CUser::UpdateTimeRemind(CTimeRemind timeRemind)
{
	userDA.UpdateTimeRemind(timeRemind);
}

void CUser::GetAllDiary(CDiary*& list)
{
	userDA.GetAllDiary(list,m_szName);
}

void CUser::GetAllMemo(CMemo*& list)
{
	userDA.GetAllMemo(list,m_szName);
}

void CUser::GetAllTimeRemind(CTimeRemind*& list)
{
	userDA.GetAllTimeRemind(list,m_szName);
}

void CUser::GetAllDateRemind(CDateRemind*& list)
{
	userDA.GetAllDateRemind(list,m_szName);
}

void CUser::GetAllHoliday(CHoliday*& list)
{
	userDA.GetAllHoliday(list);
}

int CUser::CountAllDiary()
{
		int CountAllDiary;
		CountAllDiary=userDA.CountAllDiary(m_szName);
		return CountAllDiary;
}

int CUser::CountAllMemo()
{
		int CountAllMemo;
		CountAllMemo=userDA.CountAllMemo(m_szName);
		return CountAllMemo;
}

int CUser::CountAllTimeRemind()
{
		int CountAllTimeRemind;
		CountAllTimeRemind=userDA.CountAllTimeRemind(m_szName);
		return CountAllTimeRemind;
}

int CUser::CountAllDateRemind()
{
		int CountAllDateRemind;
		CountAllDateRemind=userDA.CountAllDateRemind(m_szName);
		return CountAllDateRemind;
}

int CUser::CountAllHoliday()
{
		int CountAllHoliday;
		CountAllHoliday=userDA.CountAllHoliday();
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
	userDA.PurgeDiary(m_szName);
}

void CUser::PurgeMemo()
{
	userDA.PurgeMemo(m_szName);
}

void CUser::PurgeTimeRemind()
{
	userDA.PurgeTimeRemind(m_szName);
}

void CUser::PurgeDateRemind()
{
	userDA.PurgeDateRemind(m_szName);
}

void CUser::SetName(CString name)
{
	m_szName = name;
}

CString CUser::GetName()
{
	return m_szName;
}
void CUser::UpdatePassword(CString password)
{
	userDA.UpdatePassword(m_szName,password);
 }

void CUser::UpdateMotto(CString motto)
{
	userDA.UpdateMotto(m_szName,motto);
}

void CUser::UpdateTimeFrequency(int timefrequency)
{
	userDA.UpdateTimeFrequency(m_szName,timefrequency);
}