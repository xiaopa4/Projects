
/***************************************************************************
* Copyright (c) 2017, AEC, All rights reserved.
*
* 文件名称： 流媒体管理器
* 摘 要： 定义文件
* 作 者： 张育斌
*
* 修改记录：
*[日期][作者/修改者] [修改原因]
***************************************************************************/
// Propetydialog.cpp : 实现文件
//

#include "stdafx.h"
#include "mystream1.h"
#include "Propetydialog.h"
#include "afxdialogex.h"


// CPropetydialog 对话框

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


// CPropetydialog 消息处理程序

/***************************************************************************
* 函数名称：[OnInitDialog]
* 摘 要： 初始化
* 全局影响：
* 参数：
* 返回值：
*
* 修改记录：
*[日期][作者/修改者] [修改原因]
***************************************************************************/
BOOL CPropetydialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//标签标题
	m_tab.InsertItem(0, _T("常规"));
	m_tab.InsertItem(1, _T("网络"));
	//创建两个对话框
	m_clsPage1.Create(IDD_PROPETYPAGE1, &m_tab);
	m_clsPage2.Create(IDD_PROPETYPAGE2, &m_tab);
	
	//设置属性页显示的范围
	CRect rc;
	m_tab.GetClientRect(rc);
	rc.top += 20;
	rc.bottom -= 0;
	rc.left += 0;
	rc.right -= 0;
	m_clsPage1.MoveWindow(&rc);
	m_clsPage2.MoveWindow(&rc);
	//显示页面
	m_clsPage1.ShowWindow(SW_SHOW);
	m_clsPage2.ShowWindow(SW_HIDE);
	/*m_clsPage1.SetWindowPos(NULL, rc.left, rc.top, rc.Width(), rc.Height(), SWP_SHOWWINDOW);     
	m_clsPage2.SetWindowPos(NULL, rc.left, rc.top, rc.Width(), rc.Height(), SWP_HIDEWINDOW);*/
	//初始化默认页面1并设置页面的值
	m_clsPage1.m_ctrName.SetWindowText(m_Propety[0]);
	m_clsPage1.m_ctrType.SetWindowText(m_Propety[1]);
	m_clsPage1.m_ctrIP.SetWindowText(m_Propety[2]);
	m_clsPage1.m_ctrRemark.SetWindowText(m_Propety[3]);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}

/***************************************************************************
* 函数名称：[OnSize]
* 摘 要： 选项卡标签变化
* 全局影响：
* 参数：NMHDR *pNMHDR, LRESULT *pResult
* 返回值：
*
* 修改记录：
*[日期][作者/修改者] [修改原因]
***************************************************************************/
void CPropetydialog::OnTcnSelchangingTab(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO:  在此添加控件通知处理程序代码
	//获取标签序号
	int m_nCurSelTab = m_tab.GetCurSel();
	//判断显示页面
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
