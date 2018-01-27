/***************************************************************************
* Copyright (c) 2017, AEC, All rights reserved.
*
* 文件名称： 通讯薄对话框
* 摘 要： 头文件
* 作 者： 张育斌
*
* 修改记录：
*[日期][作者/修改者] [修改原因]
***************************************************************************/
// MaillistDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "AddsortDlg.h"
#include "CmyTreeCtrl.h"
#include "afxwin.h"
#include "afxdtctl.h"

// CMaillistDlg 对话框
class CMaillistDlg : public CDialogEx
{
// 构造
public:
	CMaillistDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MAILLIST_DIALOG };

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
//	CTreeCtrl m_ctrTree;
public:
	//图标变量
	CImageList m_ImageList;
	//添加分组
	afx_msg void OnBnClickedAddsort();
	CAddsortDlg m_clsAddsort;
public:
	CString m_strSortName;
	//删除分组
	afx_msg void OnBnClickedDelsort();
	//添加
	afx_msg void OnBnClickedAddg();
public:
	//姓名
	CEdit m_ctrName;
	CString m_strName;
	//昵称
	CEdit m_ctrIDName;
	CString m_strIDName;
	//生日
	CDateTimeCtrl m_ctrBirthday;
	CTime pTime[20];
	//电话1
	CEdit m_ctrTel1;
	CString m_strTel1;
	//电话2
	CEdit m_ctrTel2;
	CString m_strTel2;
	//邮箱
	CEdit m_ctrEmail;
	CString m_strEmail;
	//地址
	CEdit m_ctrAdress;
	CString m_strAdress;
	//备注
	CEdit m_ctrPropety;
	CString m_strPropety;
	//存数据
	CString m_strMsg[20][8];
	
public:
	CmyTreeCtrl m_clsTree;
	// 树的根节点的句柄
	HTREEITEM hTreeRoot;
	//所选项句柄
	HTREEITEM hHandle;
	//之前选中项的句柄
	HTREEITEM hPreHandle;
public:
	//自定义函数
	void clearfun();
	//添加
	CButton m_ctrAddg;
	//添加分组
	CButton m_ctrAddSort;
	//删除
	CButton m_ctrDel;
	//修改
	CButton m_ctrForm;
	//删除分组
	CButton m_ctrDelSort;
	//点击树形控件区域响应函数
	afx_msg void OnNMClickContactTree(NMHDR *pNMHDR, LRESULT *pResult);
	//删除响应函数
	afx_msg void OnBnClickedDel();
	//修改响应函数
	afx_msg void OnBnClickedForm();
};
