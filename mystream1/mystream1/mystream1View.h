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
	//表格控件变量
	CListCtrl m_List;
	//调整大小
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//右键菜单栏
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	//初始化完成标识符
	BOOL m_initOK;
	//添加流媒体
	afx_msg void OnAdd();
	//添加流媒体对话框相关联变量
	CAdddialog m_clsAdddlg;
protected:
	//自定义消息
	afx_msg LRESULT OnAddOk(WPARAM wParam, LPARAM lParam);
public:

	int i;
	CString* m_pAdd;
	//删除
	afx_msg void OnDelet();
	CDeletDialog m_clsDelet;
	//序号
	long long  m_nSelmark;
	//禁用或启用删除
	afx_msg void OnUpdateDelet(CCmdUI *pCmdUI);
	//全部删除
	afx_msg void OnEarseall();
	//禁用或启用全部删除
	afx_msg void OnUpdateEarseall(CCmdUI *pCmdUI);
	//属性
	afx_msg void OnPropety();
	//禁用或启用属性菜单栏
	afx_msg void OnUpdatePropety(CCmdUI *pCmdUI);
	CPropetydialog m_clsPropetyDlg;
//	CString m_Add[4];
	CString m_Propety[4];
};

#ifndef _DEBUG  // mystream1View.cpp 中的调试版本
inline Cmystream1Doc* Cmystream1View::GetDocument() const
   { return reinterpret_cast<Cmystream1Doc*>(m_pDocument); }
#endif

