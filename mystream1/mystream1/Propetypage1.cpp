// Propetypage1.cpp : 实现文件
//

#include "stdafx.h"
#include "mystream1.h"
#include "Propetypage1.h"
#include "afxdialogex.h"


// CPropetypage1 对话框

IMPLEMENT_DYNAMIC(CPropetypage1, CDialogEx)

CPropetypage1::CPropetypage1(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPropetypage1::IDD, pParent)
{

}

CPropetypage1::~CPropetypage1()
{
}

void CPropetypage1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_ctrName);
	DDX_Control(pDX, IDC_EDIT2, m_ctrRemark);
	DDX_Control(pDX, IDC_IPADDRESS1, m_ctrIP);
	DDX_Control(pDX, IDC_COMBO1, m_ctrType);
}


BEGIN_MESSAGE_MAP(CPropetypage1, CDialogEx)
END_MESSAGE_MAP()


// CPropetypage1 消息处理程序
