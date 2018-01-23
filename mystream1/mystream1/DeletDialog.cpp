// DeletDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "mystream1.h"
#include "DeletDialog.h"
#include "afxdialogex.h"


// CDeletDialog 对话框

IMPLEMENT_DYNAMIC(CDeletDialog, CDialogEx)

CDeletDialog::CDeletDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDeletDialog::IDD, pParent)
{

}

CDeletDialog::~CDeletDialog()
{
}

void CDeletDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDeletDialog, CDialogEx)
END_MESSAGE_MAP()


// CDeletDialog 消息处理程序
