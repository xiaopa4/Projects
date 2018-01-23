
// MFCnewsDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "DialogA.h"
#include <vector>
using namespace std;

// CMFCnewsDlg 对话框
class CMFCnewsDlg : public CDialogEx
{
// 构造
public:
	CMFCnewsDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFCNEWS_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnClose();
	//afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedCheck1();
	CButton m_Stick;
	afx_msg void OnEnChangeMessage();
	afx_msg void OnClickedTips();
//	BOOL m_Tip;
	CButton m_Tip;
	afx_msg void OnBnClickedQuit();
//	CDialogA  m_DialogA;
	CDialogA m_DlgA;
public:
	//自定义消息
	afx_msg LRESULT OnMyTIPMessage(WPARAM wParam, LPARAM lParam);
//	vector<CString> v_strName;
//	vector<CString> v_strContent;
	vector<CString> v_strShowContent;
	CEdit m_Edit;
	int m_x;
	BOOL m_T;
//	vector<CString> v_strContext;
	vector<CString> v_strContent;
//	vector<CString> v_strName1;
//	vector<CString> v_strContent1;
	vector<CString> v_strName;
	int m_nTime;
};
