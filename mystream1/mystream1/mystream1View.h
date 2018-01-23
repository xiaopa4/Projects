
// mystream1View.h : Cmystream1View 类的接口
//

#pragma once

#include "resource.h"
#include "afxcmn.h"
#include "Adddialog.h"
#include "DeletDialog.h"
#include "Propetydialog.h"

class Cmystream1View : public CFormView
{
protected: // 仅从序列化创建
	Cmystream1View();
	DECLARE_DYNCREATE(Cmystream1View)

public:
	enum{ IDD = IDD_MYSTREAM1_FORM };

	// 特性
public:
	Cmystream1Doc* GetDocument() const;

	// 操作
public:

	// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

	// 实现
public:
	virtual ~Cmystream1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_List;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	BOOL m_initOK;
	afx_msg void OnAdd();
	CAdddialog m_clsAdddlg;
protected:
	afx_msg LRESULT OnAddOk(WPARAM wParam, LPARAM lParam);
public:

	int i;
	CString* m_pAdd;
	afx_msg void OnDelet();
	CDeletDialog m_clsDelet;
	long long  m_nSelmark;
	afx_msg void OnUpdateDelet(CCmdUI *pCmdUI);
	afx_msg void OnEarseall();
	afx_msg void OnUpdateEarseall(CCmdUI *pCmdUI);
	afx_msg void OnPropety();
	afx_msg void OnUpdatePropety(CCmdUI *pCmdUI);
	CPropetydialog m_clsPropetyDlg;
//	CString m_Add[4];
	CString m_Propety[4];
};

#ifndef _DEBUG  // mystream1View.cpp 中的调试版本
inline Cmystream1Doc* Cmystream1View::GetDocument() const
   { return reinterpret_cast<Cmystream1Doc*>(m_pDocument); }
#endif

