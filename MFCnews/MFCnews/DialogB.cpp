// DialogB.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCnews.h"
#include "DialogB.h"
#include "DialogA.h"
#include "afxdialogex.h"


// CDialogB 对话框


IMPLEMENT_DYNAMIC(CDialogB, CDialogEx)

CDialogB::CDialogB(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialogB::IDD, pParent)
	, m_strName(_T(""))
	, m_strContent(_T(""))
{
	

}

CDialogB::~CDialogB()
{
}

void CDialogB::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_NAME, m_Name);
	DDX_Text(pDX, IDC_NAME, m_strName);
	DDX_Control(pDX, IDC_CONTENTS, m_Content);
	DDX_Text(pDX, IDC_CONTENTS, m_strContent);
}


BEGIN_MESSAGE_MAP(CDialogB, CDialogEx)
	ON_EN_CHANGE(IDC_NAME, &CDialogB::OnEnChangeName)
	ON_BN_CLICKED(IDC_SETUP, &CDialogB::OnBnClickedSetup)
	ON_BN_CLICKED(IDC_NOSETUP, &CDialogB::OnBnClickedNosetup)
END_MESSAGE_MAP()


// CDialogB 消息处理程序


void CDialogB::OnEnChangeName()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

}


void CDialogB::OnBnClickedSetup()
{
	// TODO:  在此添加控件通知处理程序代码

	UpdateData(true);
	bool IsAdd = true;
	if (m_strName == _T("") | m_strContent == _T(""))
	{
		MessageBox(_T("请将信息填充完整！"));
	}
	else
	{
		//查找消息名是否重复，消息名重复则不会存储
		for (int i = 0; i < v_Mnamestr.size(); i++)
		{

			if (m_strName == v_Mnamestr[i])
			{
				MessageBox(_T("消息名重复！"));
				m_Name.SetWindowText(_T(""));
				IsAdd = false;
			}

		}
		if (IsAdd == true)
		{
			v_Mnamestr.push_back(m_strName);
			this->GetParent()->SendMessage(WM_MY_MESSAGE, 0, 0);
			m_Name.SetWindowText(_T(""));
			m_Content.SetWindowText(_T(""));
			//添加成功后退出
			OnOK();
		}
	}
}


void CDialogB::OnBnClickedNosetup()
{
	// TODO:  在此添加控件通知处理程序代码

	OnCancel();
}
