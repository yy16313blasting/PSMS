#include "StdAfx.h"
#include "UserDA.h"


UserDA::UserDA(void)
{
	m_pRecordset=NULL;
}


UserDA::~UserDA(void)
{
}


bool UserDA::InitConnection()
{
	//初始化COM环境
	::CoInitialize(NULL);
	try
	{
		m_pConnection->Close();
		m_pConnection->Release();
		//创建连接对象实例
		m_pConnection.CreateInstance(__uuidof(Connection));
		
	
		m_pRecordset.CreateInstance(__uuidof(Recordset));
		//设置等待连接打开的时间为20s	
		m_pConnection->ConnectionTimeout=20; 
		//设置连接字符串
		CString szConnection=_T("Provider=Microsoft.Jet.OLEDB.4.0;\
			Data Source=DataBase.mdb;\
		Jet OLEDB:Database Password=");
		//使用Open方法连接数据库
		m_pConnection->Open((_bstr_t)szConnection,"","",adModeUnknown);
	}
	catch(_com_error e)
	{
		CString str;
		str.Format(_T("%s"),e.Description());
		AfxMessageBox(str);
		return false;
	}
	AfxMessageBox(_T("Succeed!"));
	return true;
}

void UserDA::CloseConnection()
{
	AfxMessageBox(_T("start to close..."));
	if(m_pRecordset!=NULL)
	{
		m_pRecordset->Close();
	}
	m_pConnection->Close();
	//释放COM环境
	::CoUninitialize();
}