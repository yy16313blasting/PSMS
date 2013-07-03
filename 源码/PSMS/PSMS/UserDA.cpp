#include "StdAfx.h"
#include "UserDA.h"


CUserDA::CUserDA(void)
{
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
	if(m_pConnection==NULL)
		InitConnection();
	_bstr_t sql="select * from Holiday";
	m_pRecordset.CreateInstance(__uuidof(Recordset));
	m_pRecordset->Open(sql,m_pConnection.GetInterfacePtr(),adOpenDynamic,adLockOptimistic,adCmdText);
	int count=m_pRecordset->GetRecordCount();
	if(count<=0)
	{
		CString str;
		str.Format("%d",count);
		AfxMessageBox("Holiday里的记录个数:"+str);
		return;
	}
	while(!m_pRecordset->adoEOF)
	{
		CString info;
		try
		{
			info=(char*)(_bstr_t)m_pRecordset->GetCollect("Title");
		}
		catch(_com_error e)
		{
			AfxMessageBox(e.Description());
		}
		AfxMessageBox(info);
	}
}