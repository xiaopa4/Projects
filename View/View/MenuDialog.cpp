// MenuDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "View.h"
#include "MenuDialog.h"
#include "afxdialogex.h"


// CMenuDialog �Ի���

IMPLEMENT_DYNAMIC(CMenuDialog, CDialogEx)

CMenuDialog::CMenuDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMenuDialog::IDD, pParent)
	, m_strTitle(_T("����һ"))
	, m_nSilder(8)
	, m_nWidth(8)
	, m_strPath(_T(""))
{

}

CMenuDialog::~CMenuDialog()
{
}

void CMenuDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TITLE, m_ctrTitle);
	DDX_Text(pDX, IDC_TITLE, m_strTitle);
	DDX_Control(pDX, IDC_SLIDER, m_ctrSilder);
	DDX_Slider(pDX, IDC_SLIDER, m_nSilder);
	//DDV_MinMaxInt(pDX, m_nSilder, 1, 30);
	DDX_Control(pDX, IDC_WIDTH, m_ctrWidth);
	  DDX_Text(pDX, IDC_WIDTH, m_nWidth);
	  //DDV_MinMaxInt(pDX, m_nWidth, 1, 30);
	DDX_Control(pDX, IDC_PICTUREPATH, m_ctrPath);
	//  DDX_Control(pDX, IDC_COLOR, m_ctrColor);
	DDX_Text(pDX, IDC_PICTUREPATH, m_strPath);
	DDX_Control(pDX, IDC_COLOR, m_colColor);
}


BEGIN_MESSAGE_MAP(CMenuDialog, CDialogEx)
	//ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER, &CMenuDialog::OnNMCustomdrawSlider)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_BROWSE, &CMenuDialog::OnBnClickedBrowse)
	ON_EN_CHANGE(IDC_WIDTH, &CMenuDialog::OnEnChangeWidth)
END_MESSAGE_MAP()


// CMenuDialog ��Ϣ�������


BOOL CMenuDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	m_ctrSilder.SetRange(1, 30);//���û�����ΧΪ1��30
	m_ctrSilder.SetTicFreq(1);//ÿ1����λ��һ�̶�
	//m_ctrSilder.SetPos(8);//���û����ʼλ��Ϊ1 

	//enable use it
	EnableToolTips(TRUE);
	m_ctrTT.Create(this);
	m_ctrTT.Activate(TRUE);
	//font color
	//m_ctrTT.SetTipTextColor(RGB(0, 0,0));
	//delay time
	m_ctrTT.SetDelayTime(150);
	//�����ʾ�Ŀؼ�
	m_ctrTT.AddTool(GetDlgItem(IDC_TITLE), _T("���ⲻ����16���ַ�"));
	m_ctrTT.AddTool(GetDlgItem(IDC_COLOR), _T("���ѡ��߿���ɫ"));
	m_ctrTT.AddTool(GetDlgItem(IDC_BROWSE), _T("���ѡ�񱳾�ͼƬ"));

	return TRUE;  
	// �쳣:  OCX ����ҳӦ���� FALSE
}


BOOL CMenuDialog::PreTranslateMessage(MSG* pMsg)
{
	// TODO:  �ڴ����ר�ô����/����û���

	m_ctrTT.RelayEvent(pMsg);

	return CDialogEx::PreTranslateMessage(pMsg);
}




void CMenuDialog::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_nSilder = m_ctrSilder.GetPos();
	SetDlgItemInt(IDC_WIDTH, m_nSilder, true);
	
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	
}


void CMenuDialog::OnBnClickedBrowse()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	CFileDialog dlg(TRUE,NULL, NULL, 
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		_T("(*.bmp)|*.bmp|(*.jpg)|*.jpg|(*.png)|*.png|"));
	if (dlg.DoModal() == IDOK)
	{
		fileName = dlg.GetPathName();
		m_ctrPath.SetWindowTextW(fileName);
	
	}

}


void CMenuDialog::OnEnChangeWidth()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	//UpdateData(TRUE);
	m_nWidth = GetDlgItemInt(IDC_WIDTH);
	if (m_nWidth > 30)
	{
		m_nWidth = 30;
		SetDlgItemInt(IDC_WIDTH, m_nWidth, true);
		m_ctrSilder.SetPos(m_nWidth);
		
	}
	if (m_nWidth < 1)
	{
		m_nWidth = 1;
		SetDlgItemInt(IDC_WIDTH, m_nWidth, true);
		m_ctrSilder.SetPos(m_nWidth);

	}

	m_ctrSilder.SetPos(m_nWidth);
	//UpdateData(FALSE);



}

