#pragma once
#include "afxwin.h"


// CAddsortDlg �Ի���

class CAddsortDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddsortDlg)

public:
	CAddsortDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddsortDlg();

// �Ի�������
	enum { IDD = IDD_ADDSORT_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	//afx_msg void OnEnChangeCinname();
	CString m_strName1;
	CString m_strName;
	afx_msg void OnBnClickedOk();
};
