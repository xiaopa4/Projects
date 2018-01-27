/***************************************************************************
* Copyright (c) 2017, AEC, All rights reserved.
*
* 文件名称： 消息提示器
* 摘 要： 消息管理对话框头文件
* 作 者： 张育斌
*
* 修改记录：
*[日期][作者/修改者] [修改原因]
***************************************************************************/
#pragma once
#include "afxwin.h"		// 引用非标准库的头文件
#include <vector>		// 引用标准库的头文件
#include "SetNews.h"	// 引用自定义的头文件
using namespace std;
// CNewsMang 对话框

class CNewsMang : public CDialogEx
{
	DECLARE_DYNAMIC(CNewsMang)

public:
	CNewsMang(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CNewsMang();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	//添加消息
	afx_msg void OnClickedAdd();
	//消息列表变量
public:
	CListBox m_MList;
	CString m_strMlist;
public:
	//自定义消息
	afx_msg LRESULT OnMyMessage(WPARAM wParam, LPARAM lParam);
public:
	//重写
	virtual BOOL OnInitDialog();
public:
	//提示列表变量
	CListBox m_Tiplist;
	CString m_strTiplist;
public:
	//间隔时间
	int m_Edit_Time;
	int m_nTime;
public:
	//存放添加新建消息
	vector<CString> v_strName;
	vector<CString> v_strContent;
	//保存初始记录
	vector<CString> v_strReName;
	vector<CString> v_strReContent;
	//记录初始消息个数
	vector<int>::size_type v_nNums;
	//新建消息对话框关联变量
	CSetNews m_DlgB;
public:
	//删除消息列表消息
	afx_msg void OnBnClickedMinus();
	//单个右移
	afx_msg void OnBnClickedRight();
	//单个左移
	afx_msg void OnBnClickedLeft();
	//全部右移
	afx_msg void OnBnClickedRightshift();
	//全部左移
	afx_msg void OnBnClickedLeftshift();
	//上移
	afx_msg void OnBnClickedUp();
	//下移
	afx_msg void OnBnClickedDown();
	//确定
	afx_msg void OnBnClickedOk();
	//取消
	afx_msg void OnBnClickedCancel();
public:
	//保存提示列表消息
	vector<CString> v_strShow;
	//间隔时间处理函数
	afx_msg void OnEnChangeEdit1();
	
};
