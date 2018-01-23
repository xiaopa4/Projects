// Propetydialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "mystream1.h"
#include "Propetydialog.h"
#include "afxdialogex.h"


// CPropetydialog �Ի���

IMPLEMENT_DYNAMIC(CPropetydialog, CDialogEx)

CPropetydialog::CPropetydialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPropetydialog::IDD, pParent)
{


}

CPropetydialog::~CPropetydialog()
{
}

void CPropetydialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB, m_tab);
}


BEGIN_MESSAGE_MAP(CPropetydialog, CDialogEx)
	ON_NOTIFY(TCN_SELCHANGING, IDC_TAB, &CPropetydialog::OnTcnSelchangingTab)
END_MESSAGE_MAP()


// CPropetydialog ��Ϣ�������


BOOL CPropetydialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	m_tab.InsertItem(0, _T("����"));
	m_tab.InsertItem(1, _T("����"));
	//���������Ի���
	m_clsPage1.Create(IDD_PROPETYPAGE1, &m_tab);
	m_clsPage2.Create(IDD_PROPETYPAGE2, &m_tab);
	
	//��������ҳ��ʾ�ķ�Χ
	CRect rc;
	m_tab.GetClientRect(rc);
	rc.top += 20;
	rc.bottom -= 0;
	rc.left += 0;
	rc.right -= 0;
	m_clsPage1.MoveWindow(&rc);
	m_clsPage2.MoveWindow(&rc);
	//��ʾҳ��
	m_clsPage1.ShowWindow(SW_SHOW);
	m_clsPage2.ShowWindow(SW_HIDE);
	/*m_clsPage1.SetWindowPos(NULL, rc.left, rc.top, rc.Width(), rc.Height(), SWP_SHOWWINDOW);     
	m_clsPage2.SetWindowPos(NULL, rc.left, rc.top, rc.Width(), rc.Height(), SWP_HIDEWINDOW);*/
	//��ʼ��Ĭ��ҳ��1������ҳ���ֵ
	m_clsPage1.m_ctrName.SetWindowText(m_Propety[0]);
	m_clsPage1.m_ctrType.SetWindowText(m_Propety[1]);
	m_clsPage1.m_ctrIP.SetWindowText(m_Propety[2]);
	m_clsPage1.m_ctrRemark.SetWindowText(m_Propety[3]);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void CPropetydialog::OnTcnSelchangingTab(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	int m_nCurSelTab = m_tab.GetCurSel();
	switch (m_nCurSelTab)
	{
	case 0:
		m_clsPage1.ShowWindow(SW_HIDE);
		m_clsPage2.ShowWindow(SW_SHOW);
		break;
	case 1:
		m_clsPage1.ShowWindow(SW_SHOW);
		m_clsPage2.ShowWindow(SW_HIDE);
		break;
	default:
		break;
	}

	*pResult = 0;
}
