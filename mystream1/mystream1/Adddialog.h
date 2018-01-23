#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CAdddialog 对话框

class CAdddialog : public CDialogEx
{
	DECLARE_DYNAMIC(CAdddialog)

public:
	CAdddialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAdddialog();

// 对话框数据
	enum { IDD = IDD_ADD_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
