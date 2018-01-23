
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
	CImageList m_ImageList;
	afx_msg void OnBnClickedAddsort();
	CAddsortDlg m_clsAddsort;
public:
	CString m_strSortName;
	afx_msg void OnBnClickedDelsort();
	afx_msg void OnBnClickedAddg();
public:
	CEdit m_ctrName;
	CString m_strName;
	CEdit m_ctrIDName;
	CString m_strIDName;
	CDateTimeCtrl m_ctrBirthday;
	CEdit m_ctrTel1;
	CString m_strTel1;
	CEdit m_ctrTel2;
	CString m_strTel2;
	CEdit m_ctrEmail;
	CString m_strEmail;
	CEdit m_ctrAdress;
	CString m_strAdress;
	CEdit m_ctrPropety;
	CString m_strPropety;
	CString m_strMsg[20][8];
	CTime pTime[20];
public:
	CmyTreeCtrl m_clsTree;
	// 树的根节点的句柄
	HTREEITEM hTreeRoot;
	//所选项句柄
	HTREEITEM hHandle;
	//之前选中项的句柄
	HTREEITEM hPreHandle;
public:
	void clearfun();
	CButton m_ctrAddg;
	CButton m_ctrAddSort;
	CButton m_ctrDel;
	CButton m_ctrForm;
	CButton m_ctrDelSort;
	afx_msg void OnNMClickContactTree(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedDel();
	afx_msg void OnBnClickedForm();
};
