#pragma once
#include "afxwin.h"


// CAddsortDlg 对话框

class CAddsortDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddsortDlg)

public:
	CAddsortDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAddsortDlg();

// 对话框数据
	enum { IDD = IDD_ADDSORT_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	//afx_msg void OnEnChangeCinname();
	CString m_strName1;
	CString m_strName;
	afx_msg void OnBnClickedOk();
};
