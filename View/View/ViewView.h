
// ViewView.h : CViewView ��Ľӿ�
//

#pragma once
#include "MenuDialog.h"

class CViewView : public CView
{
protected: // �������л�����
	CViewView();
	DECLARE_DYNCREATE(CViewView)

// ����
public:
	CViewDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CViewView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
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

#ifndef _DEBUG  // ViewView.cpp �еĵ��԰汾
inline CViewDoc* CViewView::GetDocument() const
   { return reinterpret_cast<CViewDoc*>(m_pDocument); }
#endif

