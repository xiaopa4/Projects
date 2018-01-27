
/***************************************************************************
* Copyright (c) 2017, AEC, All rights reserved.
*
* 文件名称： 消息提示器
* 摘 要： 新建消息对话框定义文件
* 作 者： 张育斌
*
* 修改记录：
*[日期][作者/修改者] [修改原因]
***************************************************************************/
// SetNews.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCnews.h"
#include "SetNews.h"
#include "NewsMang.h"
#include "afxdialogex.h"


// CSetNews 对话框


IMPLEMENT_DYNAMIC(CSetNews, CDialogEx)

CSetNews::CSetNews(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSetNews::IDD, pParent)
	, m_strName(_T(""))
	, m_strContent(_T(""))
{
	

}

CSetNews::~CSetNews()
{
}

void CSetNews::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_NAME, m_Name);
	DDX_Text(pDX, IDC_NAME, m_strName);
	DDX_Control(pDX, IDC_CONTENTS, m_Content);
	DDX_Text(pDX, IDC_CONTENTS, m_strContent);
}


BEGIN_MESSAGE_MAP(CSetNews, CDialogEx)
	ON_EN_CHANGE(IDC_NAME, &CSetNews::OnEnChangeName)
	ON_BN_CLICKED(IDC_SETUP, &CSetNews::OnBnClickedSetup)
	ON_BN_CLICKED(IDC_NOSETUP, &CSetNews::OnBnClickedNosetup)
END_MESSAGE_MAP()


// CSetNews 消息处理程序


void CSetNews::OnEnChangeName()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

}

/***************************************************************************
* 函数名称：[OnBnClickedSetup]
* 摘 要： 创建消息
* 全局影响：发送消息给消息管理对话框
* 参数：
* 返回值：
*
* 修改记录：
*[日期][作者/修改者] [修改原因]
***************************************************************************/
void CSetNews::OnBnClickedSetup()
{
	// TODO:  在此添加控件通知处理程序代码

	UpdateData(true);
	bool IsAdd = true;
	//名字和内容是否没输入
	if (m_strName == _T("") | m_strContent == _T(""))
	{
		MessageBox(_T("请将信息填充完整！"));
	}
	else
	{
		//查找消息名是否重复
		for (int i = 0; i < v_Mnamestr.size(); i++)
		{

			if (m_strName == v_Mnamestr[i])
			{
				MessageBox(_T("消息名重复！"));
				m_Name.SetWindowText(_T(""));
				IsAdd = false;
			}

		}
		//不重复为true
		if (IsAdd == true)
		{
			v_Mnamestr.push_back(m_strName);
			UpdateData(true);
			this->GetParent()->SendMessage(WM_MY_MESSAGE, 0, 0);
			m_Name.SetWindowText(_T(""));
			m_Content.SetWindowText(_T(""));
			//添加成功后退出
			OnOK();
		}
	}
}


void CSetNews::OnBnClickedNosetup()
{
	// TODO:  在此添加控件通知处理程序代码

	OnCancel();
}
