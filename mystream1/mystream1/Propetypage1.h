#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CPropetypage1 对话框

class CPropetypage1 : public CDialogEx
{
	DECLARE_DYNAMIC(CPropetypage1)

public:
	CPropetypage1(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPropetypage1();

// 对话框数据
	enum { IDD = IDD_PROPETYPAGE1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_ctrName;
	CEdit m_ctrRemark;
	CIPAddressCtrl m_ctrIP;
	CComboBox m_ctrType;
};
