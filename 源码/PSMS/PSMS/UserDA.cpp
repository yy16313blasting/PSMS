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

void CUserDA::CreateTable(CString tableName)
{
	_bstr_t sql="CREATE TABLE "+tableName;
	m_pRecordset.CreateInstance(__uuidof(Recordset));
	try
	{
		m_pConnection->Execute(sql,NULL,adCmdText);
	}
	catch(_com_error e)
	{
		AfxMessageBox(e.Description());
	}
}

void CUserDA::AddDiary(CDiary diary)
{
}

void CUserDA::AddMemo(CMemo memo)
{
}

void CUserDA::AddTimeRemind(CTimeRemind timeRemind)
{
}

void CUserDA::AddDateRemind(CDateRemind dateRemind)
{
}

void CUserDA::RemoveDiary(CDiary diary)
{
}

void CUserDA::RemoveMemo(CMemo memo)
{
}

void CUserDA::RemoveTimeRemind(CTimeRemind timeRemind)
{
}


void CUserDA::RemoveDateRemind(CDateRemind dateRemiind)
{
}


void CUserDA::UpdateDiary(CDiary diary)
{
}

void CUserDA::UpdateMemo(CMemo memo)
{
}

void CUserDA::UpdateDateRemind(CDateRemind dateRemind)
{
}

void CUserDA::UpdateTimeRemind(CTimeRemind timeRemind)
{
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