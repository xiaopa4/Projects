#pragma once
#include "afxwin.h"
#include <vector>
using namespace std;
#include "DialogB.h"
// CDialogA 对话框

class CDialogA : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogA)

public:
	CDialogA(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDialogA();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnClickedAdd();
	afx_msg void OnClickedAdd();
	afx_msg void OnLbnSelchangeMessageList();
	CListBox m_MList;
public:
	//自定义消息
	afx_msg LRESULT OnMyMessage(WPARAM wParam, LPARAM lParam);
public:
	virtual BOOL OnInitDialog();
public:
	CString m_strMlist;
	CListBox m_Tiplist;
	CString m_strTiplist;
//	int m_Edit_Time;
	int m_Edit_Time;
	//存放添加新建消息
	vector<CString> v_strName;
	vector<CString> v_strContent;
	//保存初始记录
	vector<CString> v_strReName;
	vector<CString> v_strReContent;

	vector<int>::size_type v_nNums;
	CDialogB m_DlgB;
	afx_msg void OnBnClickedMinus();
	afx_msg void OnBnClickedRight();
	afx_msg void OnBnClickedLeft();
	afx_msg void OnBnClickedRightshift();
	afx_msg void OnBnClickedLeftshift();
	afx_msg void OnBnClickedUp();
	afx_msg void OnBnClickedDown();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
public:
	vector<CString> v_strShow;
	afx_msg void OnEnChangeEdit1();
	int m_nTime;
};
