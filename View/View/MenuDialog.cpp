// MenuDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "View.h"
#include "MenuDialog.h"
#include "afxdialogex.h"


// CMenuDialog 对话框

IMPLEMENT_DYNAMIC(CMenuDialog, CDialogEx)

CMenuDialog::CMenuDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMenuDialog::IDD, pParent)
	, m_strTitle(_T("画面一"))
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


// CMenuDialog 消息处理程序


BOOL CMenuDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	m_ctrSilder.SetRange(1, 30);//设置滑动范围为1到30
	m_ctrSilder.SetTicFreq(1);//每1个单位画一刻度
	//m_ctrSilder.SetPos(8);//设置滑块初始位置为1 

	//enable use it
	EnableToolTips(TRUE);
	m_ctrTT.Create(this);
	m_ctrTT.Activate(TRUE);
	//font color
	//m_ctrTT.SetTipTextColor(RGB(0, 0,0));
	//delay time
	m_ctrTT.SetDelayTime(150);
	//添加提示的控件
	m_ctrTT.AddTool(GetDlgItem(IDC_TITLE), _T("标题不超过16个字符"));
	m_ctrTT.AddTool(GetDlgItem(IDC_COLOR), _T("点击选择边框颜色"));
	m_ctrTT.AddTool(GetDlgItem(IDC_BROWSE), _T("点击选择背景图片"));

	return TRUE;  
	// 异常:  OCX 属性页应返回 FALSE
}


BOOL CMenuDialog::PreTranslateMessage(MSG* pMsg)
{
	// TODO:  在此添加专用代码和/或调用基类

	m_ctrTT.RelayEvent(pMsg);

	return CDialogEx::PreTranslateMessage(pMsg);
}




void CMenuDialog::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	m_nSilder = m_ctrSilder.GetPos();
	SetDlgItemInt(IDC_WIDTH, m_nSilder, true);
	
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
	
}


void CMenuDialog::OnBnClickedBrowse()
{
	// TODO:  在此添加控件通知处理程序代码

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
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

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

