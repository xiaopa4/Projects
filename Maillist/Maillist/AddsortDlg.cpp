// AddsortDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Maillist.h"
#include "AddsortDlg.h"
#include "afxdialogex.h"


// CAddsortDlg �Ի���

IMPLEMENT_DYNAMIC(CAddsortDlg, CDialogEx)

CAddsortDlg::CAddsortDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAddsortDlg::IDD, pParent)
	
	, m_strName(_T(""))
{
	
}

CAddsortDlg::~CAddsortDlg()
{
}

void CAddsortDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	  DDX_Text(pDX, IDC_CINNAME, m_strName1);
	  DDV_MaxChars(pDX, m_strName1, 8);
}


BEGIN_MESSAGE_MAP(CAddsortDlg, CDialogEx)
	//ON_EN_CHANGE(IDC_CINNAME, &CAddsortDlg::OnEnChangeCinname)
	ON_BN_CLICKED(IDOK, &CAddsortDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CAddsortDlg ��Ϣ�������


//void CAddsortDlg::OnEnChangeCinname()
//{
//	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
//	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
//	// ���������� CRichEditCtrl().SetEventMask()��
//	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�
//
//	// TODO:  �ڴ���ӿؼ�֪ͨ����������
//	
//	
//
//}


void CAddsortDlg::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(IDC_CINNAME)->GetWindowTextW(m_strName);
	GetDlgItem(IDC_CINNAME)->SetWindowTextW(_T(""));
	if (m_strName == "")
	{
		MessageBox(_T("�������������"));
	}
	else

	CDialogEx::OnOK();
}
