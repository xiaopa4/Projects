
/***************************************************************************
* Copyright (c) 2017, AEC, All rights reserved.
*
* �ļ����ƣ� ��ý�������
* ժ Ҫ�� �����ļ�
* �� �ߣ� ������
*
* �޸ļ�¼��
*[����][����/�޸���] [�޸�ԭ��]
***************************************************************************/
// mystream1View.cpp : Cmystream1View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// Cmystream1View ����/����

Cmystream1View::Cmystream1View()
	: CFormView(Cmystream1View::IDD)
	//������ʼ��
	, m_initOK(false)
	, i(0)
	, m_nSelmark(-1)
{
	// TODO:  �ڴ˴���ӹ������

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
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CFormView::PreCreateWindow(cs);
}

/****************************************!
*@brief  
*@author Administrator
*@date   2017��11��10��
*@param[out] 
*@return     void  
****************************************/
void Cmystream1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	// ������ͼ�ĳߴ����µ��������ڵĴ�С.
	ResizeParentToFit();
	//this->SetActiveWindow();
	m_initOK = TRUE;
	//��CListCtrl������У�������������
	CRect rect;
	GetClientRect(&rect);
	m_List.InsertColumn(0, _T("���"), LVCFMT_LEFT, rect.Width() / 8, 0);
	m_List.InsertColumn(1, _T("������"), LVCFMT_LEFT, rect.Width() / 8, 1);
	m_List.InsertColumn(2, _T("������"), LVCFMT_LEFT, rect.Width() / 8, 2);
	m_List.InsertColumn(3, _T("����ַ"), LVCFMT_LEFT, 2 * rect.Width() / 8, 3);
	m_List.InsertColumn(4, _T("��ע"), LVCFMT_LEFT, 3 * rect.Width() / 8, 4);
	//��������������ʹѡ�е��е���  
	m_List.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);

}


// Cmystream1View ���

#ifdef _DEBUG
void Cmystream1View::AssertValid() const
{
	CFormView::AssertValid();
}

void Cmystream1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

Cmystream1Doc* Cmystream1View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cmystream1Doc)));
	return (Cmystream1Doc*)m_pDocument;
}
#endif //_DEBUG


// Cmystream1View ��Ϣ�������

/***************************************************************************
* �������ƣ�[OnSize]
* ժ Ҫ�� �������ڴ�С
* ȫ��Ӱ�죺
* ������UINT nType, int cx, int cy
* ����ֵ��
*
* �޸ļ�¼��
*[����][����/�޸���] [�޸�ԭ��]
***************************************************************************/
void Cmystream1View::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);

	// TODO:  �ڴ˴������Ϣ����������
	
	CRect rect;
	if (true == m_initOK)
	{
		CWnd* pWnd = GetDlgItem(IDC_LIST1);
		if (pWnd->GetSafeHwnd())
		{
			pWnd->MoveWindow(0, 0, cx, cy);
			//��ȡ�ͷ�����С
			this->GetClientRect(&rect);
			m_List.SetColumnWidth(0, rect.Width() / 8);
			m_List.SetColumnWidth(1, rect.Width() / 8);
			m_List.SetColumnWidth(2, rect.Width() / 8);
			m_List.SetColumnWidth(3, 2 * rect.Width() / 8);
			m_List.SetColumnWidth(4, 3 * rect.Width() / 8);
		}
	}
	

}

/***************************************************************************
* �������ƣ�[OnContextMenu]
* ժ Ҫ�� �Ҽ������˵�
* ȫ��Ӱ�죺
* ������
* ����ֵ��
*
* �޸ļ�¼��
*[����][����/�޸���] [�޸�ԭ��]
***************************************************************************/
void Cmystream1View::OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/)
{
	// TODO:  �ڴ˴������Ϣ����������

	CPoint pt;
	::GetCursorPos(&pt);	//��ȡ�������
	CMenu	menu;
	//���ز˵�
	if (!menu.LoadMenuW(IDR_MENU1))
	{
		return;
	}

	//����Ӳ˵�
	CMenu *pPopupMenu = menu.GetSubMenu(0);		//���Ϊ0���Ӳ˵�
	//�����˵�	��ָ����λ����ʾһ�������ĵ����˵��͸�����Ŀ��ѡ���ڵ����˵��е�
	pPopupMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, pt.x, pt.y, GetParent());


}


void Cmystream1View::OnAdd()
{
	// TODO:  �ڴ���������������
	m_clsAdddlg.DoModal();
}

/***************************************************************************
* �������ƣ�[OnAddOk]
* ժ Ҫ�� �Զ�����Ϣ
* ȫ��Ӱ�죺
* ������WPARAM wParam, LPARAM lParam
* ����ֵ��0
*
* �޸ļ�¼��
*[����][����/�޸���] [�޸�ԭ��]
***************************************************************************/
 LRESULT Cmystream1View::OnAddOk(WPARAM wParam, LPARAM lParam)
{
	CString str;
	//��ʾ���
	//CString* m_pAdd = new CString[4];
	m_pAdd =  m_clsAdddlg.m_pAdd;
	str.Format(_T("%d"), i + 1);
	m_List.InsertItem(i, str);
	/*m_List.SetItemText(i, 1, str1);
	str1 = m_clsAdddlg.m_strTypelist;
	m_List.SetItemText(i, 2, str1);*/
	//���ݲ����Ӧ������λ��
	m_List.SetItemText(i, 1, m_pAdd[0]);
	m_List.SetItemText(i, 2, m_pAdd[1]);
	m_List.SetItemText(i, 3, m_pAdd[2]);
	m_List.SetItemText(i, 4, m_pAdd[3]);
	////��¼��ý������
	i++;

	return 0;
}






 /***************************************************************************
 * �������ƣ�[OnDelet]
 * ժ Ҫ�� ɾ��
 * ȫ��Ӱ�죺
 * ������
 * ����ֵ��
 *
 * �޸ļ�¼��
 *[����][����/�޸���] [�޸�ԭ��]
 ***************************************************************************/
 void Cmystream1View::OnDelet()
 {
	 // TODO:  �ڴ���������������
	/* if (i>0)
	 {*/
		//�����б���ͼ�ؼ���ѡ����
		 m_nSelmark = m_List.GetSelectionMark();
		 if (m_nSelmark==-1)
		 {
			 MessageBox(_T("��ѡ��һ��"));
		 }
		 else
		 {
			 if (m_clsDelet.DoModal() == IDOK)
			 {
				 //ɾ������
				m_List. DeleteItem(m_nSelmark);
				//ˢ���б�
				for (int j = m_nSelmark; j < i; j++)
				{
				CString str;
				str.Format(_T("%d"), j+1);
				m_List.SetItemText(j, 0, str);
				}
			 }
		 }
		 //MessageBox(_T("��ѡ��һ��")
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
	 // TODO:  �ڴ������������û����洦��������
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
	 // TODO:  �ڴ���������������

	 m_List.DeleteAllItems();
	i = 0;
	 m_nSelmark = -1;

 }


 void Cmystream1View::OnUpdateEarseall(CCmdUI *pCmdUI)
 {
	 // TODO:  �ڴ������������û����洦��������
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


 /***************************************************************************
 * �������ƣ�[OnPropety]
 * ժ Ҫ�� ������Ϣ
 * ȫ��Ӱ�죺
 * ������
 * ����ֵ��
 *
 * �޸ļ�¼��
 *[����][����/�޸���] [�޸�ԭ��]
 ***************************************************************************/
 void Cmystream1View::OnPropety()
 {
	 // TODO:  �ڴ���������������
	 //ѡ�������
	 m_nSelmark = m_List.GetSelectionMark();
	 //�������ݵ�����
	 m_Propety[0] = m_List.GetItemText(m_nSelmark, 1);
	 m_Propety[1] = m_List.GetItemText(m_nSelmark, 2);
	 m_Propety[2] = m_List.GetItemText(m_nSelmark, 3);
	 m_Propety[3] = m_List.GetItemText(m_nSelmark, 4);
	 //ת��
	 m_clsPropetyDlg.m_Propety = m_Propety;
	 m_clsPropetyDlg.DoModal();


 }


 void Cmystream1View::OnUpdatePropety(CCmdUI *pCmdUI)
 {
	 // TODO:  �ڴ������������û����洦��������

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


 
