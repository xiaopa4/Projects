#pragma once
#include "afxwin.h"
#include <vector>
using namespace std;

// CDialogB �Ի���

class CDialogB : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogB)

public:
	CDialogB(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDialogB();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeName();
	CEdit m_Name;
	afx_msg void OnBnClickedSetup();
	afx_msg void OnBnClickedNosetup();
	CString m_strName;
	CEdit m_Content;
	CString m_strContent;
//	vector<Cstring> v_Mnamestr;
	vector<CString> v_Mnamestr;
};
