#pragma once


// CSingUp 对话框

class CSingUp : public CDialog
{
	DECLARE_DYNAMIC(CSingUp)

public:
	CSingUp(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSingUp();

// 对话框数据
	enum { IDD = IDD_SINGUP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
