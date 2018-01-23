
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
	afx_msg void OnMenuset();
	CMenuDialog m_clsMenuDlg;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
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

