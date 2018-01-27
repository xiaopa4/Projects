
/***************************************************************************
* Copyright (c) 2017, AEC, All rights reserved.
*
* 文件名称： 消息提示器
* 摘 要： 头文件
* 作 者： 张育斌
*
* 修改记录：
*[日期][作者/修改者] [修改原因]
***************************************************************************/
// MFCnewsDlg.h : 头文件
//

#pragma once
#include "afxwin.h"		// 引用非标准库的头文件
#include "NewsMang.h"	// 引用自定义的头文件
#include <vector>		// 引用标准库的头文件
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
	//定时器
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	//关闭定时器
	afx_msg void OnClose();
	//消息管理
	afx_msg void OnBnClickedButton1();
	//置顶
	afx_msg void OnBnClickedCheck1();
	CButton m_Stick;
	afx_msg void OnEnChangeMessage();
	//开始提示
	afx_msg void OnClickedTips();
	CButton m_Tip;
	//退出
	afx_msg void OnBnClickedQuit();
	//消息管理对话框关联变量
	CNewsMang m_DlgA;
public:
	//自定义消息
	afx_msg LRESULT OnMyTIPMessage(WPARAM wParam, LPARAM lParam);
	//显示的内容
	vector<CString> v_strShowContent;
	CEdit m_Edit;
	int m_x;
	BOOL m_T;
	vector<CString> v_strContent;
	vector<CString> v_strName;
	//消息间隔显示的间隔时间
	int m_nTime;
};
