		
// ViewView.cpp : CViewView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_MENUSET, &CViewView::OnMenuset)
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_EQUIT, &CViewView::OnEquit)
END_MESSAGE_MAP()

// CViewView 构造/析构

CViewView::CViewView()
{
	// TODO:  在此处添加构造代码
	
	m_nPenw = 8;
	m_cfColor = RGB(0, 0, 255);

}

CViewView::~CViewView()
{
}

BOOL CViewView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CViewView 绘制

void CViewView::OnDraw(CDC* pDC)
{
	CViewDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: 在此处为本机数据添加绘制代码

	CRect rcWnd;
	GetClientRect(&rcWnd);
	//先获取设备环境pDC
	CPen *pOldPen, newPen;
	//创建宽度为m_nPenw的m_cfColor色实线画笔
	newPen.CreatePen(PS_SOLID, m_nPenw, m_cfColor);
	//将newPen画笔对象选入设备环境
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

	//标题
	CFont *oldFont, newFont;
	LOGFONT lf;
	//获取原有字体参数，并进行修改
	pDC->GetCurrentFont()->GetLogFont(&lf);
	lf.lfCharSet = DEFAULT_CHARSET;
	lf.lfHeight = -50;
	lf.lfWidth = 0;
	_tcscpy(lf.lfFaceName, _T("宋体"));
	newFont.CreateFontIndirect(&lf);
	oldFont = pDC->SelectObject(&newFont);

	pDC->SetBkMode(/*OPAQUE*/TRANSPARENT);
	pDC->SetBkColor(RGB(0, 0, 0));
	pDC->DrawText(m_strTitle, &rcWnd, DT_CENTER);

	pDC->SelectObject(oldFont);
	
}


// CViewView 打印

BOOL CViewView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CViewView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void CViewView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// CViewView 诊断

#ifdef _DEBUG
void CViewView::AssertValid() const
{
	CView::AssertValid();
}

void CViewView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CViewDoc* CViewView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CViewDoc)));
	return (CViewDoc*)m_pDocument;
}
#endif //_DEBUG


// CViewView 消息处理程序


void CViewView::OnMenuset()
{
	// TODO:  在此添加命令处理程序代码

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
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	//状态栏坐标
	CString str;
	str.Format(_T("	X:%d Y:%d"), point.x, point.y);
	((CMainFrame*)GetParent())->m_wndStatusBar.SetWindowTextW(str);

	CView::OnMouseMove(nFlags, point);
}


void CViewView::OnEquit()
{
	// TODO:  在此添加命令处理程序代码
	PostQuitMessage(0);
}
