
// mystream1View.cpp : Cmystream1View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "mystream1.h"
#endif

#include "mystream1Doc.h"
#include "mystream1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cmystream1View

IMPLEMENT_DYNCREATE(Cmystream1View, CFormView)

BEGIN_MESSAGE_MAP(Cmystream1View, CFormView)
	ON_WM_SIZE()
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_Add, &Cmystream1View::OnAdd)
	ON_MESSAGE(WM_ADD_OK, &Cmystream1View::OnAddOk)
	ON_COMMAND(ID_DELET, &Cmystream1View::OnDelet)
	ON_UPDATE_COMMAND_UI(ID_DELET, &Cmystream1View::OnUpdateDelet)
	ON_COMMAND(ID_EARSEALL, &Cmystream1View::OnEarseall)
	ON_UPDATE_COMMAND_UI(ID_EARSEALL, &Cmystream1View::OnUpdateEarseall)
	ON_COMMAND(ID_PROPETY, &Cmystream1View::OnPropety)
	ON_UPDATE_COMMAND_UI(ID_PROPETY, &Cmystream1View::OnUpdatePropety)
END_MESSAGE_MAP()

// Cmystream1View 构造/析构

Cmystream1View::Cmystream1View()
	: CFormView(Cmystream1View::IDD)
	, m_initOK(false)
	, i(0)
	, m_nSelmark(-1)
{
	// TODO:  在此处添加构造代码

}

Cmystream1View::~Cmystream1View()
{
}

void Cmystream1View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_List);
}

BOOL Cmystream1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CFormView::PreCreateWindow(cs);
}

/****************************************!
*@brief  
*@author Administrator
*@date   2017年11月10日
*@param[out] 
*@return     void  
****************************************/
void Cmystream1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	//this->SetActiveWindow();
	m_initOK = TRUE;
	//在CListCtrl中添加列，设置流的属性
	CRect rect;
	GetClientRect(&rect);
	m_List.InsertColumn(0, _T("序号"), LVCFMT_LEFT, rect.Width() / 8, 0);
	m_List.InsertColumn(1, _T("流名称"), LVCFMT_LEFT, rect.Width() / 8, 1);
	m_List.InsertColumn(2, _T("流类型"), LVCFMT_LEFT, rect.Width() / 8, 2);
	m_List.InsertColumn(3, _T("流地址"), LVCFMT_LEFT, 2 * rect.Width() / 8, 3);
	m_List.InsertColumn(4, _T("备注"), LVCFMT_LEFT, 3 * rect.Width() / 8, 4);
	//设置行数和列数(制表格)       使选中的行点亮  
	m_List.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);

}


// Cmystream1View 诊断

#ifdef _DEBUG
void Cmystream1View::AssertValid() const
{
	CFormView::AssertValid();
}

void Cmystream1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

Cmystream1Doc* Cmystream1View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cmystream1Doc)));
	return (Cmystream1Doc*)m_pDocument;
}
#endif //_DEBUG


// Cmystream1View 消息处理程序


void Cmystream1View::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);

	// TODO:  在此处添加消息处理程序代码
	CRect rect;
	if (true == m_initOK)
	{
		CWnd* pWnd = GetDlgItem(IDC_LIST1);
		if (pWnd->GetSafeHwnd())
		{
			pWnd->MoveWindow(0, 0, cx, cy);
			this->GetClientRect(&rect);
			m_List.SetColumnWidth(0, rect.Width() / 8);
			m_List.SetColumnWidth(1, rect.Width() / 8);
			m_List.SetColumnWidth(2, rect.Width() / 8);
			m_List.SetColumnWidth(3, 2 * rect.Width() / 8);
			m_List.SetColumnWidth(4, 3 * rect.Width() / 8);
		}
	}
	

}


void Cmystream1View::OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/)
{
	// TODO:  在此处添加消息处理程序代码

	CPoint pt;
	::GetCursorPos(&pt);	//获取鼠标坐标
	CMenu	menu;
	//加载菜单
	if (!menu.LoadMenuW(IDR_MENU1))
	{
		return;
	}

	//获得子菜单
	CMenu *pPopupMenu = menu.GetSubMenu(0);		//编号为0的子菜单
	//弹出菜单
	pPopupMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, pt.x, pt.y, GetParent());


}


void Cmystream1View::OnAdd()
{
	// TODO:  在此添加命令处理程序代码
	m_clsAdddlg.DoModal();
}


 LRESULT Cmystream1View::OnAddOk(WPARAM wParam, LPARAM lParam)
{
	CString str;
	//CString str1;
	//static int i= 0;
	//显示序号
	//CString* m_pAdd = new CString[4];
	m_pAdd =  m_clsAdddlg.m_pAdd;
	str.Format(_T("%d"), i + 1);
	m_List.InsertItem(i, str);
	/*m_List.SetItemText(i, 1, str1);
	str1 = m_clsAdddlg.m_strTypelist;
	m_List.SetItemText(i, 2, str1);*/
	m_List.SetItemText(i, 1, m_pAdd[0]);
	m_List.SetItemText(i, 2, m_pAdd[1]);
	m_List.SetItemText(i, 3, m_pAdd[2]);
	m_List.SetItemText(i, 4, m_pAdd[3]);
	////记录流媒体数量
	i++;

	return 0;
}






 void Cmystream1View::OnDelet()
 {
	 // TODO:  在此添加命令处理程序代码
	/* if (i>0)
	 {*/
		 m_nSelmark = m_List.GetSelectionMark();
		 if (m_nSelmark==-1)
		 {
			 MessageBox(_T("请选择一项"));
		 }
		 else
		 {
			 if (m_clsDelet.DoModal() == IDOK)
			 {
				m_List. DeleteItem(m_nSelmark);
				for (int j = m_nSelmark; j < i; j++)
				{
				CString str;
				str.Format(_T("%d"), j+1);
				m_List.SetItemText(j, 0, str);
				}
			 }
		 }
		 //MessageBox(_T("请选择一项")
		 //m_clsDelet.DoModal();
	/* } 
	 else
	 {
	 }*/
	 m_nSelmark = -1;
	 i--;
 }


 void Cmystream1View::OnUpdateDelet(CCmdUI *pCmdUI)
 {
	 // TODO:  在此添加命令更新用户界面处理程序代码
	 m_nSelmark = -1;
	 m_nSelmark = m_List.GetSelectionMark();
	 if (m_nSelmark == -1)
	 { 
		 pCmdUI->Enable(FALSE);
	
	 }
	 else
	 {
		 pCmdUI->Enable(TRUE);
	 }
	 m_nSelmark = -1;
 }




 void Cmystream1View::OnEarseall()
 {
	 // TODO:  在此添加命令处理程序代码

	 m_List.DeleteAllItems();
	i = 0;
	 m_nSelmark = -1;

 }


 void Cmystream1View::OnUpdateEarseall(CCmdUI *pCmdUI)
 {
	 // TODO:  在此添加命令更新用户界面处理程序代码
	 m_nSelmark = -1;
	 m_nSelmark = m_List.GetSelectionMark();
	 if (m_nSelmark == -1)
	 {
		 pCmdUI->Enable(FALSE);

	 }
	 else
	 {
		 pCmdUI->Enable(TRUE);
	 }
	 m_nSelmark = -1;

 }



 void Cmystream1View::OnPropety()
 {
	 // TODO:  在此添加命令处理程序代码
	 m_nSelmark = m_List.GetSelectionMark();
	 m_Propety[0] = m_List.GetItemText(m_nSelmark, 1);
	 m_Propety[1] = m_List.GetItemText(m_nSelmark, 2);
	 m_Propety[2] = m_List.GetItemText(m_nSelmark, 3);
	 m_Propety[3] = m_List.GetItemText(m_nSelmark, 4);
	 m_clsPropetyDlg.m_Propety = m_Propety;
	 m_clsPropetyDlg.DoModal();


 }


 void Cmystream1View::OnUpdatePropety(CCmdUI *pCmdUI)
 {
	 // TODO:  在此添加命令更新用户界面处理程序代码

	 m_nSelmark = -1;
	 m_nSelmark = m_List.GetSelectionMark();
	 if (m_nSelmark == -1)
	 {
		 pCmdUI->Enable(FALSE);

	 }
	 else
	 {
		 pCmdUI->Enable(TRUE);
	 }
	 m_nSelmark = -1;

 }


 
