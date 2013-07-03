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
											// ʵ�������Ӷ��� 
		hr = m_pConnection.CreateInstance(__uuidof(Connection)); 
		if( SUCCEEDED( hr ) )
		{
			//���õȴ����Ӵ򿪵�ʱ��Ϊ20s	
			m_pConnection->ConnectionTimeout=20; 

			m_pConnection->Open((_bstr_t)"Provider=Microsoft.Jet.OLEDB.4.0;\
				Data Source=DataBase.mdb;\
			Jet OLEDB:Database Password=","","",adModeUnknown);
			
		}
		//AfxMessageBox("���ӳɹ�����");
	}
	catch(_com_error * e)
	{
		CString errormessage;
		errormessage.Format("�������ݿ�ʧ�ܣ�\r\n������Ϣ��%s",e->ErrorMessage());
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
		AfxMessageBox("Holiday��ļ�¼����:"+str);
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