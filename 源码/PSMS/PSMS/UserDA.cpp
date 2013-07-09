#include "StdAfx.h"
#include "UserDA.h"
#include "MD5.h"


CUserDA::CUserDA(void)
{
	m_pRecordset = NULL;
	InitConnection();
}

CUserDA::~CUserDA(void)
{
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
			m_pConnection->ConnectionTimeout = WAITOPENTIME; 

			m_pConnection->Open((_bstr_t)"Provider=Microsoft.Jet.OLEDB.4.0;\
								Data Source=DataBase.mdb;\
								Jet OLEDB:Database Password=","","",adModeUnknown);
		}
	}
	catch(_com_error e)
	{
		CString errorMessage;
		errorMessage.Format("连接数据库失败！\r\n错误信息：%s", e.Description());
		//AfxMessageBox(errorMessage);
		return  false;
	}
	return true;
}

void CUserDA::test()
{
	CString sql = "SELECT * FROM [User]";
	
	try
	{
		m_pRecordset.CreateInstance(__uuidof(Recordset));
		m_pRecordset->Open( _variant_t(sql), m_pConnection.GetInterfacePtr(), adOpenDynamic, adLockOptimistic, adCmdText);
	}
	catch(_com_error e)
	{
		//AfxMessageBox(e.Description());
	}
	int count = m_pRecordset->GetRecordCount();

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
			info=(char*)(_bstr_t)m_pRecordset->GetCollect("szName");
		}
		catch(_com_error e)
		{
			//AfxMessageBox(e.Description());
		}
		//AfxMessageBox(info);
		m_pRecordset->MoveNext();
	}
}

void CUserDA::ExcuteSql(CString sql)
{
	m_pRecordset.CreateInstance(__uuidof(Recordset));
	try
	{
		m_pConnection->Execute((_bstr_t)sql, NULL, adCmdText);
	}
	catch(_com_error e)
	{
		//AfxMessageBox(e.Description());
	}
}

void CUserDA::CreateTable(CString tableName)
{
	CString sql = "CREATE TABLE " + tableName;
	ExcuteSql(sql);
}

void CUserDA::AddDiary(CDiary diary)
{
	CString sql;
	sql.Format("insert into Diary (szTitle,szContent,[DateTime],szUser) values ('%s','%s','%s','%s')",
		diary.GetTitle(), diary.GetContent(), diary.GetDate(), diary.GetUser());
	ExcuteSql(sql);
}

void CUserDA::AddMemo(CMemo memo)
{
	CString sql;
	sql.Format("insert into [Memo] (szTitle,szContent,[DateTime],szUser) values ('%s', '%s', '%s', '%s')",
		memo.GetTitle(), memo.GetContent(), memo.GetDate(), memo.GetUser());
	ExcuteSql(sql);
}

void CUserDA::AddTimeRemind(CTimeRemind timeRemind)
{
	CString sql;
	sql.Format("insert into TimeRemind (szTitle,szContent,[DateTime],nRemindFrequency,szUser) values ('%s','%s','%s',%d,'%s')",
		timeRemind.GetTitle(), timeRemind.GetContent(), timeRemind.GetDate(), timeRemind.GetRemindFrequency(), timeRemind.GetUser());
	ExcuteSql(sql);
}

void CUserDA::AddDateRemind(CDateRemind dateRemind)
{
	CString sql;
	sql.Format("insert into DateRemind (szTitle,szContent,[DateTime],nRemindFrequency,szUser) values ('%s','%s','%s',%d,'%s')",
		dateRemind.GetTitle(), dateRemind.GetContent(), dateRemind.GetDate(), dateRemind.GetRemindFrequency(), dateRemind.GetUser());
	ExcuteSql(sql);
}

void CUserDA::AddUser(CString name,CString password)
{
	CString sql;
	CMD5 md5;
	md5.GenerateCMD5((unsigned char*)(LPCTSTR)password, password.GetLength());
	password = md5.ToString();
	sql.Format("insert into [User] ( szName,szPassword) values ('%s','%s')", name, password);
	ExcuteSql(sql);
}

void CUserDA::RemoveDiary(CDiary diary)
{
	CString sql;
	sql.Format("delete * from Diary where ID = %d", diary.GetID());
	ExcuteSql(sql);
}

void CUserDA::RemoveMemo(CMemo memo)
{
	CString sql;
	sql.Format("delete * from [Memo] where ID = %d", memo.GetID());
	ExcuteSql(sql);
}

void CUserDA::RemoveTimeRemind(CTimeRemind timeRemind)
{
	CString sql;
	sql.Format("delete * from TimeRemind where ID = %d", timeRemind.GetID());
	ExcuteSql(sql);
}

void CUserDA::RemoveDateRemind(CDateRemind dateRemind)
{
	CString sql;
	sql.Format("delete * from DateRemind where ID = %d", dateRemind.GetID());
	ExcuteSql(sql);
}

void CUserDA::UpdateDiary(CDiary diary)
{
	CString sql;
	sql.Format("update Diary set szTitle = '%s' szContent = '%s',[DateTime] = '%s' where ID = %d",
		diary.GetTitle(),diary.GetContent(), diary.GetDate(), diary.GetID());
	ExcuteSql(sql);
}

void CUserDA::UpdateMemo(CMemo memo)
{
	CString sql;
	sql.Format("update [Memo] setszTitle = '%s' szContent = '%s',[DateTime] = '%s' where ID = %d",
		memo.GetTitle(),memo.GetContent(), memo.GetDate(), memo.GetID());
	ExcuteSql(sql);
}

void CUserDA::UpdateDateRemind(CDateRemind dateRemind)
{
	CString sql;
	sql.Format("update DateRemind set szTitle = '%s' szContent = '%s',[DateTime] = '%s',nRemindFrequency = %d where ID = %d",
		dateRemind.GetTitle(),dateRemind.GetTitle(),dateRemind.GetContent(), dateRemind.GetDate(), dateRemind.GetRemindFrequency(), dateRemind.GetID());
	ExcuteSql(sql);
}

void CUserDA::UpdateTimeRemind(CTimeRemind timeRemind)
{
	CString sql;
	sql.Format("update TimeRemind setszTitle = '%s' szContent = '%s',[DateTime] = '%s',nRemindFrequency = %d where ID = %d",
		timeRemind.GetContent(), timeRemind.GetDate(), timeRemind.GetRemindFrequency(), timeRemind.GetID());
	ExcuteSql(sql);
}

//将数据库中所有记录传进list数组
void CUserDA::GetAllDiary(CDiary*& list,CString user)
{
	CString sql;
	sql.Format("SELECT * FROM Diary where szUser = '%s'",user);
	
	try
	{
		m_pRecordset.CreateInstance(__uuidof(Recordset));
		m_pRecordset->Open( _variant_t(sql), m_pConnection.GetInterfacePtr(), adOpenDynamic, adLockOptimistic, adCmdText);
	}
	catch(_com_error e)
	{
		////AfxMessageBox(e.Description());
	}
	int count = m_pRecordset->GetRecordCount();

	//count值为-1为成功
	if(0 == count)
	{
		return;
	}
	m_pRecordset->MoveLast();
	m_pRecordset->MoveFirst();
	int i = 0;
	while(!m_pRecordset->adoEOF)
	{
		try
		{
			list[i].SetTitle((char*)(_bstr_t)m_pRecordset->GetCollect("szTitle"));
			list[i].SetContent((char*)(_bstr_t)m_pRecordset->GetCollect("szContent"));
			list[i].SetUser((char*)(_bstr_t)m_pRecordset->GetCollect("szUser"));
			list[i].SetDate((char*)(_bstr_t)m_pRecordset->GetCollect("DateTime"));
			list[i].SetID(atoi((char*)(_bstr_t)m_pRecordset->GetCollect("ID")));
		}
		catch(_com_error e)
		{
			//AfxMessageBox(e.Description());
		}
		m_pRecordset->MoveNext();
		i++;
	}
}

void CUserDA::GetAllMemo(CMemo*& list,CString user)
{
	CString sql;
	sql.Format("SELECT * FROM [Memo] where szUser = '%s'", user);

	try
	{
		m_pRecordset.CreateInstance(__uuidof(Recordset));
		m_pRecordset->Open(_variant_t(sql), m_pConnection.GetInterfacePtr(), adOpenDynamic, adLockOptimistic, adCmdText);
	}
	catch(_com_error e)
	{
		////AfxMessageBox(e.Description());
	}
	int count = m_pRecordset->GetRecordCount();

	if(0 == count)
	{
		return;
	}
	m_pRecordset->MoveLast();
	m_pRecordset->MoveFirst();
	int i = 0;
	while(!m_pRecordset->adoEOF)
	{
		try
		{
			list[i].SetTitle((char*)(_bstr_t)m_pRecordset->GetCollect("szTitle"));
			list[i].SetContent((char*)(_bstr_t)m_pRecordset->GetCollect("szContent"));
			list[i].SetUser((char*)(_bstr_t)m_pRecordset->GetCollect("szUser"));
			list[i].SetDate((char*)(_bstr_t)m_pRecordset->GetCollect("DateTime"));
			list[i].SetID(atoi((char*)(_bstr_t)m_pRecordset->GetCollect("ID")));
		}
		catch(_com_error e)
		{
			//AfxMessageBox(e.Description());
		}
		m_pRecordset->MoveNext();
		i++;
	}
}

void CUserDA::GetAllTimeRemind(CTimeRemind*& list,CString user)
{
	CString sql;
	sql.Format("SELECT * FROM TimeRemind where szUser = '%s'", user);
	
	try
	{
		m_pRecordset.CreateInstance(__uuidof(Recordset));
		m_pRecordset->Open( _variant_t(sql), m_pConnection.GetInterfacePtr(), adOpenDynamic, adLockOptimistic, adCmdText);
	}
	catch(_com_error e)
	{
		//AfxMessageBox(e.Description());
	}
	int count = m_pRecordset->GetRecordCount();
	//count值为-1为成功
	if(0 == count)
	{
		return;
	}
	if(m_pRecordset->adoEOF)
	{
		return;
	}
	m_pRecordset->MoveLast();
	m_pRecordset->MoveFirst();
	int i = 0;
	while(!m_pRecordset->adoEOF)
	{
		try
		{
			list[i].SetTitle((char*)(_bstr_t)m_pRecordset->GetCollect("szTitle"));
			list[i].SetContent((char*)(_bstr_t)m_pRecordset->GetCollect("szContent"));
			list[i].SetUser((char*)(_bstr_t)m_pRecordset->GetCollect("szUser"));
			list[i].SetDate((char*)(_bstr_t)m_pRecordset->GetCollect("DateTime"));
			list[i].SetRemindFrequency(atoi((char*)(_bstr_t)m_pRecordset->GetCollect("nRemindFrequency")));
			list[i].SetID(atoi((char*)(_bstr_t)m_pRecordset->GetCollect("ID")));
		}
		catch(_com_error e)
		{
		}
		m_pRecordset->MoveNext();
		i++;
	}
}

void CUserDA::GetAllDateRemind(CDateRemind*& list,CString user)
{
	CString sql;
	sql.Format("SELECT * FROM DateRemind where szUser = '%s'", user);
	
	try
	{
		m_pRecordset.CreateInstance(__uuidof(Recordset));
		m_pRecordset->Open( _variant_t(sql), m_pConnection.GetInterfacePtr(), adOpenDynamic, adLockOptimistic, adCmdText);
	}
	catch(_com_error e)
	{
		//AfxMessageBox(e.Description());
	}
	int count = m_pRecordset->GetRecordCount();
	//count值为-1为成功
	if(0 == count)
	{
		return;
	}
	m_pRecordset->MoveLast();
	m_pRecordset->MoveFirst();
	int i = 0;
	while(!m_pRecordset->adoEOF)
	{
		try
		{
			list[i].SetTitle((char*)(_bstr_t)m_pRecordset->GetCollect("szTitle"));
			list[i].SetContent((char*)(_bstr_t)m_pRecordset->GetCollect("szContent"));
			list[i].SetUser((char*)(_bstr_t)m_pRecordset->GetCollect("szUser"));
			list[i].SetDate((char*)(_bstr_t)m_pRecordset->GetCollect("DateTime"));
			list[i].SetRemindFrequency(atoi((char*)(_bstr_t)m_pRecordset->GetCollect("nRemindFrequency")));
			list[i].SetID(atoi((char*)(_bstr_t)m_pRecordset->GetCollect("ID")));
		}
		catch(_com_error e)
		{
			//AfxMessageBox(e.Description());
		}
		m_pRecordset->MoveNext();
		i++;
	}
}

void CUserDA::GetAllHoliday(CHoliday*& list)
{
	CString sql;
	sql.Format("SELECT * FROM Holiday");
	
	try
	{
		m_pRecordset.CreateInstance(__uuidof(Recordset));
		m_pRecordset->Open( _variant_t(sql),m_pConnection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
	}
	catch(_com_error e)
	{
		//AfxMessageBox(e.Description());
	}
	int count = m_pRecordset->GetRecordCount();
	//count值为-1为成功
	if(0 == count)
	{
		return;
	}
	m_pRecordset->MoveLast();
	m_pRecordset->MoveFirst();
	int i = 0;
	while(!m_pRecordset->adoEOF)
	{
		try
		{
			list[i].SetTitle((char*)(_bstr_t)m_pRecordset->GetCollect("szTitle"));
			list[i].SetContent((char*)(_bstr_t)m_pRecordset->GetCollect("Message"));
			list[i].SetDate((char*)(_bstr_t)m_pRecordset->GetCollect("DateTime"));
			list[i].SetID(atoi((char*)(_bstr_t)m_pRecordset->GetCollect("ID")));
		}
		catch(_com_error e)
		{
			//AfxMessageBox(e.Description());
		}
		m_pRecordset->MoveNext();
		i++;
	}
}

//获取表中记录的个数
int CUserDA::CountAllDiary(CString user)
{
	CString sql;
	sql.Format("SELECT * FROM Diary where szUser = '%s'", user);
	
	try
	{
		m_pRecordset.CreateInstance(__uuidof(Recordset));
		m_pRecordset->Open( _variant_t(sql), m_pConnection.GetInterfacePtr(), adOpenDynamic, adLockOptimistic, adCmdText);
	}
	catch(_com_error e)
	{
		//AfxMessageBox(e.Description());
	}
	int count = m_pRecordset->GetRecordCount();
	//count值为-1为成功
	if(0 == count)
	{
		return 0;
	}
	if(m_pRecordset->adoEOF)
	{
		return 0;
	}
	m_pRecordset->MoveLast();
	m_pRecordset->MoveFirst();
	int i = 0;
	while(!m_pRecordset->adoEOF)
	{
		m_pRecordset->MoveNext();
		i++;
	}
	return i;
}

int CUserDA::CountAllMemo(CString user)
{
	CString sql;
	sql.Format("SELECT * FROM [Memo] where szUser = '%s'",user);
	
	try
	{
		m_pRecordset.CreateInstance(__uuidof(Recordset));
		m_pRecordset->Open( _variant_t(sql), m_pConnection.GetInterfacePtr(), adOpenDynamic, adLockOptimistic, adCmdText);
	}
	catch(_com_error e)
	{
		//AfxMessageBox(e.Description());
	}
	int count = m_pRecordset->GetRecordCount();
	//count值为-1为成功
	if(0 == count)
	{
		return 0;
	}
	if(m_pRecordset->adoEOF)
	{
		return 0;
	}
	m_pRecordset->MoveLast();
	m_pRecordset->MoveFirst();
	int i = 0;
	while(!m_pRecordset->adoEOF)
	{
		m_pRecordset->MoveNext();
		i++;
	}
	return i;
}

int CUserDA::CountAllTimeRemind(CString user)
{
	CString sql;
	sql.Format("SELECT * FROM TimeRemind where szUser = '%s'", user);
	
	try
	{
		m_pRecordset.CreateInstance(__uuidof(Recordset));
		m_pRecordset->Open( _variant_t(sql), m_pConnection.GetInterfacePtr(), adOpenDynamic, adLockOptimistic, adCmdText);
	}
	catch(_com_error e)
	{
		//AfxMessageBox(e.Description());
	}
	int count = m_pRecordset->GetRecordCount();
	//count值为-1为成功
	if(0 == count)
	{
		return 0;
	}
	if(m_pRecordset->adoEOF)
	{
		return 0;
	}
	m_pRecordset->MoveLast();
	m_pRecordset->MoveFirst();
	int i = 0;
	while(!m_pRecordset->adoEOF)
	{
		m_pRecordset->MoveNext();
		i++;
	}
	return i;
}

int CUserDA::CountAllDateRemind(CString user)
{
	CString sql;
	sql.Format("SELECT * FROM DateRemind where szUser = '%s'",user);
	
	try
	{
		m_pRecordset.CreateInstance(__uuidof(Recordset));
		m_pRecordset->Open( _variant_t(sql),m_pConnection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
	}
	catch(_com_error e)
	{
		//AfxMessageBox(e.Description());
	}
	int count = m_pRecordset->GetRecordCount();
	//count值为-1为成功
	if(0 == count)
	{
		return 0;
	}
	if(m_pRecordset->adoEOF)
	{
		return 0;
	}
	m_pRecordset->MoveLast();
	m_pRecordset->MoveFirst();
	int i = 0;
	while(!m_pRecordset->adoEOF)
	{
		m_pRecordset->MoveNext();
		i++;
	}
	return i;
}

int CUserDA::CountAllHoliday()
{
	CString sql;
	sql.Format("SELECT * FROM Holiday");
	
	try
	{
		m_pRecordset.CreateInstance(__uuidof(Recordset));
		m_pRecordset->Open( _variant_t(sql), m_pConnection.GetInterfacePtr(), adOpenDynamic, adLockOptimistic, adCmdText);
	}
	catch(_com_error e)
	{
		//AfxMessageBox(e.Description());
	}
	int count = m_pRecordset->GetRecordCount();
	//count值为-1为成功
	if(0 == count)
	{
		return 0;
	}
	if(m_pRecordset->adoEOF)
	{
		return 0;
	}
	m_pRecordset->MoveLast();
	m_pRecordset->MoveFirst();
	int i = 0;
	while(!m_pRecordset->adoEOF)
	{
		m_pRecordset->MoveNext();
		i++;
	}
	return i;
}

void CUserDA::PurgeDiary(CString user)
{
	CString sql;
	sql.Format("delete * from Diary where szUser = '%s'", user);
	ExcuteSql(sql);
}

void CUserDA::PurgeMemo(CString user)
{
	CString sql;
	sql.Format("delete * from [Memo] where szUser = '%s'", user);
	ExcuteSql(sql);
}

void CUserDA::PurgeTimeRemind(CString user)
{
	CString sql;
	sql.Format("delete * from TimeRemind where szUser = '%s'", user);
	ExcuteSql(sql);
}

void CUserDA::PurgeDateRemind(CString user)
{
	CString sql;
	sql.Format("delete * from DateRemind where szUser = '%s'", user);
	ExcuteSql(sql);
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
	CString sql;
	sql.Format("SELECT * FROM [User]");
	
	try
	{
		m_pRecordset.CreateInstance(__uuidof(Recordset));
		m_pRecordset->Open( _variant_t(sql), m_pConnection.GetInterfacePtr(), adOpenDynamic, adLockOptimistic, adCmdText);
	}
	catch(_com_error e)
	{
		//AfxMessageBox(e.Description());
	}
	int count = m_pRecordset->GetRecordCount();
	//count值为-1为成功
	if(0 == count)
	{
		return "";
	}
	m_pRecordset->MoveFirst();
	while(!m_pRecordset->adoEOF)
	{
		CString password;
		CString tmp_name;
		try
		{
			tmp_name = (char*)(_bstr_t)m_pRecordset->GetCollect("szName");
			if(tmp_name == name)
			{
				password = (char*)(_bstr_t)m_pRecordset->GetCollect("szPassword");
				return password;
			}
		}
		catch(_com_error e)
		{
			//AfxMessageBox(e.Description());
		}
		m_pRecordset->MoveNext();
	}
	return password;
}

bool CUserDA::ExistUser(CString name)
{
	CString sql;
	sql.Format("SELECT * FROM [User]");
	
	try
	{
		m_pRecordset.CreateInstance(__uuidof(Recordset));
		m_pRecordset->Open( _variant_t(sql), m_pConnection.GetInterfacePtr(), adOpenDynamic, adLockOptimistic, adCmdText);
	}
	catch(_com_error e)
	{
		//AfxMessageBox(e.Description());
	}
	int count = m_pRecordset->GetRecordCount();
	//count值为-1为成功
	if(0 == count)
	{
		return false;
	}
	if(m_pRecordset->adoEOF)
	{
		return false;
	}
	m_pRecordset->MoveFirst();
	while(!m_pRecordset->adoEOF)
	{
	
		CString tmp_name;
		try
		{
			tmp_name = (char*)(_bstr_t)m_pRecordset->GetCollect("szName");
			if(tmp_name == name)
			{
				return true;
			}
		}
		catch(_com_error e)
		{
			//AfxMessageBox(e.Description());
		}
		m_pRecordset->MoveNext();
	}
	return false;
}

void CUserDA::UpdatePassword(CString name,CString password)
{
	CMD5 md5;
	md5.GenerateCMD5((unsigned char*)(LPCTSTR)password, password.GetLength());
	password = md5.ToString();
	CString sql;
	sql.Format("update [User] set szPassword = '%s' where szName = '%s' ", password, name);
	ExcuteSql(sql);
}