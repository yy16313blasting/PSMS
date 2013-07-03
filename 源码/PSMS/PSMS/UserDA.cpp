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
	//��ʼ��COM����
	::CoInitialize(NULL);
	try
	{
		m_pConnection->Close();
		m_pConnection->Release();
		//�������Ӷ���ʵ��
		m_pConnection.CreateInstance(__uuidof(Connection));
		
	
		m_pRecordset.CreateInstance(__uuidof(Recordset));
		//���õȴ����Ӵ򿪵�ʱ��Ϊ20s	
		m_pConnection->ConnectionTimeout=20; 
		//���������ַ���
		CString szConnection=_T("Provider=Microsoft.Jet.OLEDB.4.0;\
			Data Source=DataBase.mdb;\
		Jet OLEDB:Database Password=");
		//ʹ��Open�����������ݿ�
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
	//�ͷ�COM����
	::CoUninitialize();
}