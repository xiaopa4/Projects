		
// ViewView.cpp : CViewView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "View.h"
#include "MainFrm.h"
#endif

#include "ViewDoc.h"
#include "ViewView.h"
#include <atlimage.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CViewView

IMPLEMENT_DYNCREATE(CViewView, CView)

BEGIN_MESSAGE_MAP(CViewView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_MENUSET, &CViewView::OnMenuset)
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_EQUIT, &CViewView::OnEquit)
END_MESSAGE_MAP()

// CViewView ����/����

CViewView::CViewView()
{
	// TODO:  �ڴ˴���ӹ������
	
	m_nPenw = 8;
	m_cfColor = RGB(0, 0, 255);

}

CViewView::~CViewView()
{
}

BOOL CViewView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CViewView ����

void CViewView::OnDraw(CDC* pDC)
{
	CViewDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���

	CRect rcWnd;
	GetClientRect(&rcWnd);
	//�Ȼ�ȡ�豸����pDC
	CPen *pOldPen, newPen;
	//�������Ϊm_nPenw��m_cfColorɫʵ�߻���
	newPen.CreatePen(PS_SOLID, m_nPenw, m_cfColor);
	//��newPen���ʶ���ѡ���豸����
	pOldPen = pDC->SelectObject(&newPen);
	pDC->MoveTo(0, 0);
	pDC->LineTo(rcWnd.right, 0);
	pDC->LineTo(rcWnd.right, rcWnd.bottom);
	pDC->LineTo(0, rcWnd.bottom);
	pDC->LineTo(0, 0);
	pDC->SelectObject(pOldPen);
	newPen.DeleteObject();

	if (filename != _T(""))
	{
		CImage Image;
		Image.Load(filename);
		CRect rcBk = rcWnd;
		rcBk.DeflateRect(m_nPenw/2, m_nPenw/2);
		Image.Draw(pDC->m_hDC, rcBk);
	}

	//����
	CFont *oldFont, newFont;
	LOGFONT lf;
	//��ȡԭ������������������޸�
	pDC->GetCurrentFont()->GetLogFont(&lf);
	lf.lfCharSet = DEFAULT_CHARSET;
	lf.lfHeight = -50;
	lf.lfWidth = 0;
	_tcscpy(lf.lfFaceName, _T("����"));
	newFont.CreateFontIndirect(&lf);
	oldFont = pDC->SelectObject(&newFont);

	pDC->SetBkMode(/*OPAQUE*/TRANSPARENT);
	pDC->SetBkColor(RGB(0, 0, 0));
	pDC->DrawText(m_strTitle, &rcWnd, DT_CENTER);

	pDC->SelectObject(oldFont);
	
}


// CViewView ��ӡ

BOOL CViewView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CViewView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CViewView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CViewView ���

#ifdef _DEBUG
void CViewView::AssertValid() const
{
	CView::AssertValid();
}

void CViewView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CViewDoc* CViewView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CViewDoc)));
	return (CViewDoc*)m_pDocument;
}
#endif //_DEBUG


// CViewView ��Ϣ�������


void CViewView::OnMenuset()
{
	// TODO:  �ڴ���������������

	if (m_clsMenuDlg.DoModal() == IDOK)
	{
		m_strTitle = m_clsMenuDlg.m_strTitle;
		m_nPenw = m_clsMenuDlg.m_nSilder;
		m_cfColor = m_clsMenuDlg.m_colColor.m_bgColor;
		filename = m_clsMenuDlg.fileName;
		Invalidate(true);
	}
}


void CViewView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//״̬������
	CString str;
	str.Format(_T("	X:%d Y:%d"), point.x, point.y);
	((CMainFrame*)GetParent())->m_wndStatusBar.SetWindowTextW(str);

	CView::OnMouseMove(nFlags, point);
}


void CViewView::OnEquit()
{
	// TODO:  �ڴ���������������
	PostQuitMessage(0);
}
