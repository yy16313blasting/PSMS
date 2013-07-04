#include "StdAfx.h"
#include "UserDA.h"


CUserDA::CUserDA(void)
{
	m_pConnection=NULL;
	m_pRecordset=NULL;
	InitConnection();
}


CUserDA::~CUserDA(void)
{
	m_pConnection->Close();
	if(m_pRecordset==NULL)
		m_pRecordset->Close();
	::CoUninitialize();
}

bool CUserDA::InitConnection()
{
	::CoInitialize(NULL);
	HRESULT hr; 
	try
	{
											// 实例化连接对象 
		hr = m_pConnection.CreateInstance(__uuidof(Connection)); 
		if( SUCCEEDED( hr ) )
		{
			//设置等待连接打开的时间为20s	
			m_pConnection->ConnectionTimeout=20; 

			m_pConnection->Open((_bstr_t)"Provider=Microsoft.Jet.OLEDB.4.0;\
				Data Source=DataBase.mdb;\
			Jet OLEDB:Database Password=","","",adModeUnknown);
			
		}
		//AfxMessageBox("连接成功！！");
	}
	catch(_com_error * e)
	{
		CString errormessage;
		errormessage.Format("连接数据库失败！\r\n错误信息：%s",e->ErrorMessage());
		AfxMessageBox(errormessage);
		return  false;
	}
	return true;
}

void CUserDA::test()
{
	CString sql="SELECT * FROM Holiday";
	
	try
	{
		m_pRecordset.CreateInstance(__uuidof(Recordset));
		m_pRecordset->Open( _variant_t(sql),m_pConnection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
	}
	catch(_com_error e)
	{
		AfxMessageBox(e.Description());
	}
	int count=m_pRecordset->GetRecordCount();
	//count值为-1为成功
	if(0 == count)
	{
		return;
	}
	m_pRecordset->MoveLast();
	m_pRecordset->MoveFirst();
	while(!m_pRecordset->adoEOF)
	{
		CString info;
		try
		{
			info=(char*)(_bstr_t)m_pRecordset->GetCollect("szTitle");
		}
		catch(_com_error e)
		{
			AfxMessageBox(e.Description());
		}
		AfxMessageBox(info);
		m_pRecordset->MoveNext();
	}
}

void CUserDA::ExcuteSql(CString sql)
{
	m_pRecordset.CreateInstance(__uuidof(Recordset));
	try
	{
		m_pConnection->Execute((_bstr_t)sql,NULL,adCmdText);
	}
	catch(_com_error e)
	{
		AfxMessageBox(e.Description());
	}
}

void CUserDA::CreateTable(CString tableName)
{
	CString sql="CREATE TABLE "+tableName;
	ExcuteSql(sql);
}

void CUserDA::AddDiary(CDiary diary)
{
	CString sql;
	sql.Format("insert into Diary (szTitle,szContent,[DateTime],szUser) values ('%s','%s','%s','%s')",
		diary.GetTitle(),diary.GetContent(),diary.GetDate(),diary.GetUser());
	ExcuteSql(sql);
}

void CUserDA::AddMemo(CMemo memo)
{
	CString sql;
	sql.Format("insert into Memo (szTitle,szContent,[DateTime],szUser) values ('%s','%s','%s','%s')",
		memo.GetTitle(),memo.GetContent(),memo.GetDate(),memo.GetUser());
	ExcuteSql(sql);
}

void CUserDA::AddTimeRemind(CTimeRemind timeRemind)
{
	CString sql;
	sql.Format("insert into Memo (szTitle,szContent,[DateTime],nRemindFrequency,szUser) values ('%s','%s','%s',%d,'%s')",
		timeRemind.GetTitle(),timeRemind.GetContent(),timeRemind.GetDate(),timeRemind.GetRemindFrequency(),timeRemind.GetUser());
	ExcuteSql(sql);
}

void CUserDA::AddDateRemind(CDateRemind dateRemind)
{
	CString sql;
	sql.Format("insert into Memo (szTitle,szContent,[DateTime],nRemindFrequency,szUser) values ('%s','%s','%s',%d,'%s')",
		dateRemind.GetTitle(),dateRemind.GetContent(),dateRemind.GetDate(),dateRemind.GetRemindFrequency(),dateRemind.GetUser());
	ExcuteSql(sql);
}

void CUserDA::RemoveDiary(CDiary diary)
{
	CString sql;
	sql.Format("delete * from Diary where szTitle='%s'",diary.GetTitle());
	ExcuteSql(sql);
}

void CUserDA::RemoveMemo(CMemo memo)
{
	CString sql;
	sql.Format("delete * from Memo where szTitle = '%s'",memo.GetTitle());
	ExcuteSql(sql);
}

void CUserDA::RemoveTimeRemind(CTimeRemind timeRemind)
{
	CString sql;
	sql.Format("delete * from TimeRemind where szTitle = '%s'",timeRemind.GetTitle());
	ExcuteSql(sql);
}


void CUserDA::RemoveDateRemind(CDateRemind dateRemind)
{
	CString sql;
	sql.Format("delete * from DateRemind where szTitle = '%s'",dateRemind.GetTitle());
	ExcuteSql(sql);
}


void CUserDA::UpdateDiary(CDiary diary)
{
	CString sql;
	sql.Format("update Diary set szContent = '%s',[DateTime] = '%s' where szTitle = '%s'",
		diary.GetContent(),diary.GetDate(),diary.GetTitle());
	ExcuteSql(sql);
}

void CUserDA::UpdateMemo(CMemo memo)
{
	CString sql;
	sql.Format("update Memo set szContent = '%s',[DateTime] = '%s' where szTitle = '%s'",
		memo.GetContent(),memo.GetDate(),memo.GetTitle());
	ExcuteSql(sql);
}

void CUserDA::UpdateDateRemind(CDateRemind dateRemind)
{
	CString sql;
	sql.Format("update DateRemind set szContent = '%s',[DateTime] = '%s',nRemindFrequency = %d where szTitle = '%s'",
		dateRemind.GetContent(),dateRemind.GetDate(),dateRemind.GetRemindFrequency(),dateRemind.GetTitle());
	ExcuteSql(sql);
}

void CUserDA::UpdateTimeRemind(CTimeRemind timeRemind)
{
	CString sql;
	sql.Format("update TimeRemind set szContent = '%s',[DateTime] = '%s',nRemindFrequency = %d where szTitle = '%s'",
		timeRemind.GetContent(),timeRemind.GetDate(),timeRemind.GetRemindFrequency(),timeRemind.GetTitle());
	ExcuteSql(sql);
}

CRecordList CUserDA::GetAllDiary()
{
	return list;
}

CRecordList CUserDA::GetAllMemo()
{
	return list;
}

CRecordList CUserDA::GetAllTimeRemind()
{
	return list;
}

CRecordList CUserDA::GetAllDateRemind()
{
	return list;
}

CRecordList CUserDA::GetAllHoliday()
{
	return list;
}

void CUserDA::PurgeDiary()
{
}

void CUserDA::PurgeMemo()
{
}

void CUserDA::PurgeTimeRemind()
{
}

void CUserDA::PurgeDateRemind()
{
}

bool ExistDiary(CDiary diary)
{
	return false;
}

bool ExistMemo(CMemo memo)
{
	return false;
}

bool ExistTimeRemind(CTimeRemind timeRemind)
{
	return false;
}

bool ExistDateRemind(CDateRemind dateRemind)
{
	return false;
}

CString CUserDA::GetUserPassword(CString name)
{
	CString password;
	return password;
}