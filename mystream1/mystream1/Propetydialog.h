/***************************************************************************
* Copyright (c) 2017, AEC, All rights reserved.
*
* 文件名称： 流媒体管理器
* 摘 要： 头文件
* 作 者： 张育斌
*
* 修改记录：
*[日期][作者/修改者] [修改原因]
***************************************************************************/
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
	//选项卡变量
	CTabCtrl m_tab;
	virtual BOOL OnInitDialog();
	//常规标签变量
	CPropetypage1 m_clsPage1;
	//网络标签变量
	CPropetypage2 m_clsPage2;
//	Cstring m_strPropety;
//	CString* m_strPropety;
	CString* m_Propety;
	//属性页切换处理函数
	afx_msg void OnTcnSelchangingTab(NMHDR *pNMHDR, LRESULT *pResult);
};
