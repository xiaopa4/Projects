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
#include "afxwin.h"
#include "afxcmn.h"
#define WM_ADD_OK	(WM_USER+1000)

// CAdddialog 对话框

class CAdddialog : public CDialogEx
{
	DECLARE_DYNAMIC(CAdddialog)

public:
	CAdddialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAdddialog();

// 对话框数据
	enum { IDD = IDD_ADD_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	//流名称
	CEdit m_ctrAddName;
	CString m_strAddName;
	//流类型
	CComboBox m_Typelist;
	CString m_strTypelist;
	//重写的初始化函数
	virtual BOOL OnInitDialog();
	//流地址
	CIPAddressCtrl m_ctrIP;
	DWORD m_nIP;
	CString m_strIP;
	//备注
	CEdit m_ctrRemark;
	CString m_strRemark;
	//添加
	afx_msg void OnBnClickedOk();
	//存放添加的数据
	CString m_pAdd[4];
};
