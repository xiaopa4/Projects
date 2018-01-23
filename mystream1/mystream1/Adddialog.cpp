// Adddialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "mystream1.h"
#include "Adddialog.h"
#include "afxdialogex.h"


// CAdddialog �Ի���

IMPLEMENT_DYNAMIC(CAdddialog, CDialogEx)

CAdddialog::CAdddialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAdddialog::IDD, pParent)
	, m_strAddName(_T(""))
	, m_strTypelist(_T(""))
	, m_nIP(0)
	, m_strRemark(_T(""))
{

	m_strIP = _T("");
}

CAdddialog::~CAdddialog()
{
}

void CAdddialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ADDNAME, m_ctrAddName);
	DDX_Text(pDX, IDC_ADDNAME, m_strAddName);
	DDV_MaxChars(pDX, m_strAddName, 16);
	DDX_Control(pDX, IDC_ADDTYPE, m_Typelist);
	DDX_Control(pDX, IDC_IPADDRESS, m_ctrIP);
	DDX_Control(pDX, IDC_REMARK, m_ctrRemark);
	DDX_CBString(pDX, IDC_ADDTYPE, m_strTypelist);
	DDX_IPAddress(pDX, IDC_IPADDRESS, m_nIP);
	DDX_Text(pDX, IDC_REMARK, m_strRemark);
	DDV_MaxChars(pDX, m_strRemark, 128);
}


BEGIN_MESSAGE_MAP(CAdddialog, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAdddialog::OnBnClickedOk)
END_MESSAGE_MAP()


// CAdddialog ��Ϣ�������


BOOL CAdddialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	m_Typelist.AddString(_T("RTSP"));
	m_Typelist.AddString(_T("MMS"));
	m_Typelist.AddString(_T("HTTP"));
	m_Typelist.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void CAdddialog::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	UpdateData(TRUE);
	if (m_strAddName == _T("") || m_strTypelist == _T("") || m_nIP == 0)
	{
		MessageBox(_T("����������Ϣ���ߵ����ȡ�������������ý��"));
	}
	else
	{
		/*m_ctrAddName.GetWindowTextW(m_strAddName);
		m_Typelist.GetWindowTextW(m_strTypelist);
		m_ctrIP.GetWindowTextW(m_strIP);
		m_ctrRemark.GetWindowTextW(m_strRemark);*/
		/*CString* m_pAdd = new CString[4];*/
		m_ctrAddName.GetWindowTextW(m_pAdd[0]);
		m_Typelist.GetWindowTextW(m_pAdd[1]);
		m_ctrIP.GetWindowTextW(m_pAdd[2]);
		m_ctrRemark.GetWindowTextW(m_pAdd[3]);
		CView *pView = ((CFrameWnd*)AfxGetMainWnd())->GetActiveView();
		pView->SendMessage(WM_ADD_OK, 0, 0);
		//��ӳɹ��������ӶԻ���ļ�¼
		//delete[]m_pAdd;
		m_ctrAddName.SetWindowText(_T(""));
		m_Typelist.SetWindowText(_T(""));
		m_ctrIP.SetWindowText(_T(""));
		m_ctrRemark.SetWindowText(_T(""));


		CDialogEx::OnOK();
	}

	
}
