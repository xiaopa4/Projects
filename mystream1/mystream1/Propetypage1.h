#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CPropetypage1 �Ի���

class CPropetypage1 : public CDialogEx
{
	DECLARE_DYNAMIC(CPropetypage1)

public:
	CPropetypage1(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPropetypage1();

// �Ի�������
	enum { IDD = IDD_PROPETYPAGE1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_ctrName;
	CEdit m_ctrRemark;
	CIPAddressCtrl m_ctrIP;
	CComboBox m_ctrType;
};
