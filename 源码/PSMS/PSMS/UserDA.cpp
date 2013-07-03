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
	//countֵΪ-1Ϊ�ɹ�
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

CRecord CUserDA::AddDiary(CDiary diary)
{
	return diary;
}

CRecord CUserDA::AddMemo(CMemo memo)
{
	return memo;
}

CRecord CUserDA::AddTimeRemind(CTimeRemind timeRemind)
{
	return timeRemind;
}

CRecord CUserDA::AddDateRemind(CDateRemind dateRemind)
{
	return dateRemind;
}

CRecord CUserDA::RemoveDiary(CDiary diary)
{
	return diary;
}

CRecord CUserDA::RemoveMemo(CMemo memo)
{
	return memo;
}

CRecord CUserDA::RemoveTimeRemind(CTimeRemind timeRemind)
{
	return timeRemind;
}


CRecord CUserDA::RemoveDateRemind(CDateRemind dateRemiind)
{
	return dateRemiind;
}


CRecord CUserDA::UpdateDiary(CDiary diary)
{
	return diary;
}
