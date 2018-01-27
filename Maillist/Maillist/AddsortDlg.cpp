/***************************************************************************
* Copyright (c) 2017, AEC, All rights reserved.
*
* 文件名称： 添加分组窗口
* 摘 要： 定义文件
* 作 者： 张育斌
*
* 修改记录：
*[日期][作者/修改者] [修改原因]
***************************************************************************/
// AddsortDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Maillist.h"
#include "AddsortDlg.h"
#include "afxdialogex.h"


// CAddsortDlg 对话框

IMPLEMENT_DYNAMIC(CAddsortDlg, CDialogEx)

CAddsortDlg::CAddsortDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAddsortDlg::IDD, pParent)
	//变量初始化
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


// CAddsortDlg 消息处理程序


//void CAddsortDlg::OnEnChangeCinname()
//{
//	// TODO:  如果该控件是 RICHEDIT 控件，它将不
//	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
//	// 函数并调用 CRichEditCtrl().SetEventMask()，
//	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
//
//	// TODO:  在此添加控件通知处理程序代码
//	
//	
//
//}

//确定添加分组
void CAddsortDlg::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	GetDlgItem(IDC_CINNAME)->GetWindowTextW(m_strName);
	GetDlgItem(IDC_CINNAME)->SetWindowTextW(_T(""));
	if (m_strName == "")
	{
		MessageBox(_T("请输入分组名！"));
	}
	else

	CDialogEx::OnOK();
}
