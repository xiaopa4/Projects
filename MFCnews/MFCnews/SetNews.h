/***************************************************************************
* Copyright (c) 2017, AEC, All rights reserved.
*
* 文件名称： 消息提示器
* 摘 要： 新建消息对话框头文件
* 作 者： 张育斌
*
* 修改记录：
*[日期][作者/修改者] [修改原因]
***************************************************************************/
#pragma once
#include "afxwin.h"		// 引用非标准库的头文件
#include <vector>		// 引用标准库的头文件
using namespace std;

// CSetNews 对话框

class CSetNews : public CDialogEx
{
	DECLARE_DYNAMIC(CSetNews)

public:
	CSetNews(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSetNews();

// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:   
	//名称
	CEdit m_Name;
	CString m_strName;
	//内容
	CEdit m_Content;
	CString m_strContent;
	//名称编辑框处理函数
	afx_msg void OnEnChangeName();
	//创建
	afx_msg void OnBnClickedSetup();
	//取消创建
	afx_msg void OnBnClickedNosetup();
	//存消息名
	vector<CString> v_Mnamestr;
};
