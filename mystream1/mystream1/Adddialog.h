#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CAdddialog �Ի���

class CAdddialog : public CDialogEx
{
	DECLARE_DYNAMIC(CAdddialog)

public:
	CAdddialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAdddialog();

// �Ի�������
	enum { IDD = IDD_ADD_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_ctrAddName;
	CString m_strAddName;
	CComboBox m_Typelist;
	virtual BOOL OnInitDialog();
	CIPAddressCtrl m_ctrIP;
	CEdit m_ctrRemark;
	CString m_strTypelist;
	DWORD m_nIP;
	CString m_strRemark;
	afx_msg void OnBnClickedOk();
	CString m_strIP;

//	CString* m_pAdd;
	CString m_pAdd[4];
};
