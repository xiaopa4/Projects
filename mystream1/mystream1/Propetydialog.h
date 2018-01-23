#pragma once
#include "afxcmn.h"
#include "Propetypage1.h"
#include "Propetypage2.h"

// CPropetydialog 对话框

class CPropetydialog : public CDialogEx
{
	DECLARE_DYNAMIC(CPropetydialog)

public:
	CPropetydialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPropetydialog();

// 对话框数据
	enum { IDD = IDD_PROPETYDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tab;
	virtual BOOL OnInitDialog();
	CPropetypage1 m_clsPage1;
	CPropetypage2 m_clsPage2;
//	Cstring m_strPropety;
//	CString* m_strPropety;
	CString* m_Propety;
	afx_msg void OnTcnSelchangingTab(NMHDR *pNMHDR, LRESULT *pResult);
};
