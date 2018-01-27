/***************************************************************************
* Copyright (c) 2017, AEC, All rights reserved.
*
* 文件名称： 添加分组
* 摘 要： 头文件
* 作 者： 张育斌
*
* 修改记录：
*[日期][作者/修改者] [修改原因]
***************************************************************************/
#pragma once
#include "afxwin.h"


// CAddsortDlg 对话框

class CAddsortDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CAddsortDlg)

public:
	CAddsortDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAddsortDlg();

// 对话框数据
	enum { IDD = IDD_ADDSORT_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	//afx_msg void OnEnChangeCinname();
	//添加分组的组名
	CString m_strName1;
	CString m_strName;
	//创建
	afx_msg void OnBnClickedOk();
};
