/***************************************************************************
* Copyright (c) 2017, AEC, All rights reserved.
*
* 文件名称： 视图窗口
* 摘 要： 头文件
* 作 者： 张育斌
*
* 修改记录：
*[日期][作者/修改者] [修改原因]
***************************************************************************/
// ViewView.h : CViewView 类的接口
//

#pragma once
#include "MenuDialog.h"

class CViewView : public CView
{
protected: // 仅从序列化创建
	CViewView();
	DECLARE_DYNCREATE(CViewView)

// 特性
public:
	CViewDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CViewView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	//画面属性设置
	afx_msg void OnMenuset();
	//换面属性对话框变量
	CMenuDialog m_clsMenuDlg;
	//处理鼠标消息
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//退出
	afx_msg void OnEquit();
public:
	int m_nPenw;
	COLORREF m_cfColor;
	CString m_strTitle;
	CString filename;
};

#ifndef _DEBUG  // ViewView.cpp 中的调试版本
inline CViewDoc* CViewView::GetDocument() const
   { return reinterpret_cast<CViewDoc*>(m_pDocument); }
#endif

