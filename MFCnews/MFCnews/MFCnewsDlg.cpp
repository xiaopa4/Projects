/***************************************************************************
* Copyright (c) 2017, AEC, All rights reserved.
*
* 文件名称： 消息提示器
* 摘 要： 定义文件
* 作 者： 张育斌
*
* 修改记录：
*[日期][作者/修改者] [修改原因]
***************************************************************************/
// MFCnewsDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCnews.h"
#include "MFCnewsDlg.h"
#include "afxdialogex.h"
#include "DialogA.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCnewsDlg 对话框



CMFCnewsDlg::CMFCnewsDlg(CWnd* pParent /*=NULL*/)
: CDialogEx(CMFCnewsDlg::IDD, pParent)
{
	m_T = FALSE;
	m_x = 0;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	
}

void CMFCnewsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK1, m_Stick);
	//  DDX_Control(pDX, IDC_TIPS, m_Tip);
	DDX_Control(pDX, IDC_TIPS, m_Tip);
	DDX_Control(pDX, IDC_MESSAGE, m_Edit);
}

BEGIN_MESSAGE_MAP(CMFCnewsDlg, CDialogEx)

	ON_MESSAGE(WM_MY_TIPMESSAGE, OnMyTIPMessage)

	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_CLOSE()
	//ON_EN_CHANGE(IDC_EDIT1, &CMFCnewsDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCnewsDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_CHECK1, &CMFCnewsDlg::OnBnClickedCheck1)
	ON_EN_CHANGE(IDC_MESSAGE, &CMFCnewsDlg::OnEnChangeMessage)
	ON_BN_CLICKED(IDC_TIPS, &CMFCnewsDlg::OnClickedTips)
	ON_BN_CLICKED(IDC_QUIT, &CMFCnewsDlg::OnBnClickedQuit)
END_MESSAGE_MAP()


// CMFCnewsDlg 消息处理程序

BOOL CMFCnewsDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码
	CTime cTime = CTime::GetCurrentTime();
	//设置时钟
	SetTimer(1, 1000, NULL);
	
		m_Tip.EnableWindow(FALSE);
	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCnewsDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCnewsDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCnewsDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


/***************************************************************************
* 函数名称：[OnTimer]
* 摘 要： 在 SetTimer 成员函数中指定的每个间隔用于安装后计时器
* 全局影响：显示消息
* 参数：INT_PTR nIDEvent
* 返回值：
*
* 修改记录：
*[日期][作者/修改者] [修改原因]
***************************************************************************/
void CMFCnewsDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	//创建一个当前时间   
	CTime cTime = CTime::GetCurrentTime();
	CString strTime;
	//字符串格式化时间   
	strTime.Format(_T("消息提示器    当前时间：%d年%d月%d日  %d时%d分%d秒"), cTime.GetYear(), cTime.GetMonth(), cTime.GetDay(), cTime.GetHour(), cTime.GetMinute(), cTime.GetSecond());
	//设置当前窗口标题   
	SetWindowText(strTime);

	if (m_T == TRUE)
	{
		CString strName, strContent;
		strName = _T("消息名称:\r\n");
		strContent = _T(" \r\n消息内容:\r\n");
		int ShowNums = v_strShowContent.size();
	    vector<int>::size_type i;
		//重复显示
		if ( m_x==ShowNums)
			//全局变量
			m_x = 0;
		//查找显示消息的顺序，以便找到显示的内容
		for (i = 0; i < v_strName.size(); i++)
		{
			if (v_strShowContent[m_x] == v_strName[i])
			{
				break;
			}
			
		}
		//拼接显示的字符
		strName = strName + v_strShowContent[m_x++];
		strName = strName + strContent + v_strContent[i];
		//显示
		m_Edit.SetWindowText(strName);
	}
	CDialogEx::OnTimer(nIDEvent);
}

/***************************************************************************
* 函数名称：[OnMyTIPMessage]
* 摘 要： 自定义消息
* 全局影响：
* 参数：WPARAM wParam, LPARAM lParam
* 返回值：0
*
* 修改记录：
*[日期][作者/修改者] [修改原因]
***************************************************************************/
LRESULT  CMFCnewsDlg::OnMyTIPMessage(WPARAM wParam, LPARAM lParam)
{
	// TODO: 处理用户自定义消息 

	//消息显示间隔时间
	m_nTime = m_DlgA.m_nTime;
	int NameNums, ShowNums;
	//消息总数
	NameNums = m_DlgA.v_strName.size();
	CString str;
	//要显示的消息数
	ShowNums = m_DlgA.v_strShow.size();
	//开始提示按钮是否禁用，要显示的消息为0则禁用，否则启用
	if (ShowNums != 0)
	{
		m_Tip.EnableWindow(TRUE);
	}
	else
	{
		m_Tip.EnableWindow(FALSE);
	}
	//总数为0，不做处理
	if (NameNums == 0)
	{
		return 0;
	}
	//保存传过来的消息
	vector<int>::size_type i;
	for (i = 0; i < NameNums; i++)
	{
		str = m_DlgA.v_strName[i];
		v_strName.push_back(str);
		str = m_DlgA.v_strContent[i];
		v_strContent.push_back(str);
	}

	if ( ShowNums == 0 )
	{
	return 0;
	}
	vector<int>::size_type j;
	for (j = 0; j < ShowNums; j++)
	{
		str = m_DlgA.v_strShow[j];
		v_strShowContent.push_back(str);
	}
	
	/*if (ShowNums != 0)
	{
		m_Tip.EnableWindow(TRUE);
	}
	else
	{
		m_Tip.EnableWindow(FALSE);
	}*/
	
	return 0;
}

void CMFCnewsDlg::OnClose()
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	KillTimer(1);
	CDialogEx::OnClose();
}


//void CMFCnewsDlg::OnEnChangeEdit1()
//{
//	// TODO:  如果该控件是 RICHEDIT 控件，它将不
//	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
//	// 函数并调用 CRichEditCtrl().SetEventMask()，
//	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
//
//	// TODO:  在此添加控件通知处理程序代码
//}

/***************************************************************************
* 函数名称：[OnBnClickedButton]
* 摘 要： 点击消息管理按钮的操作
* 全局影响：
* 参数：
* 返回值：
*
* 修改记录：
*[日期][作者/修改者] [修改原因]
***************************************************************************/
void CMFCnewsDlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	
	vector<int>::size_type i;
	//编辑框中显示的内容
	for (i = 0; i < v_strShowContent.size(); i++)
	{
		CString str;
		str = v_strShowContent[i];
		m_DlgA.v_strShow.push_back(str);
	}
	
	v_strShowContent.clear();
	m_Edit.SetWindowText(_T(""));
	m_DlgA.DoModal();//用来显示一个模式对话框
	
}

/***************************************************************************
* 函数名称：[OnBnClickedCheck1]
* 摘 要： 置顶
* 全局影响：
* 参数：
* 返回值：
*
* 修改记录：
*[日期][作者/修改者] [修改原因]
***************************************************************************/
void CMFCnewsDlg::OnBnClickedCheck1()
{
	// TODO:  在此添加控件通知处理程序代码


	CString str;
	m_Stick.GetWindowTextW(str);
	if (str == _T("置顶"))
	{
		/*::SetWindowPos(this->GetSafeHwnd(), HWND_TOPMOST, 0, 0, 0, 0,
			SWP_HIDEWINDOW | SWP_NOACTIVATE | SWP_NOSIZE);*/
		//置顶窗口，不能移动，不能改变大小
		::SetWindowPos(this->GetSafeHwnd(), HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
		m_Stick.SetWindowTextW(_T("取消置顶"));
	}
	else
	{
		/*::SetWindowPos(this->GetSafeHwnd(), HWND_NOTOPMOST, 0, 0, 0, 0,
			SWP_HIDEWINDOW | SWP_NOACTIVATE | SWP_NOSIZE);*/
		//取消置顶
		::SetWindowPos(this->GetSafeHwnd(), HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
		m_Stick.SetWindowTextW(_T("置顶"));
	}


}

void CMFCnewsDlg::OnEnChangeMessage()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

/***************************************************************************
* 函数名称：[OnClickedTips1]
* 摘 要： 开始提示
* 全局影响：
* 参数：
* 返回值：
*
* 修改记录：
*[日期][作者/修改者] [修改原因]
***************************************************************************/
void CMFCnewsDlg::OnClickedTips()
{
	// TODO:  在此添加控件通知处理程序代码
	CString tip;
	m_Tip.GetWindowTextW(tip);
	if (tip == _T("开始提示"))
	{
		m_T = TRUE;
		//禁用消息管理按钮
		GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
		//GetDlgItem(IDC_MESSAGE)->EnableWindow(TRUE);
		m_Tip.SetWindowTextW(_T("停止提示"));
		//打开定时器，间隔显示消息
		SetTimer(1, m_nTime, NULL);
		m_x = 0;
	}
	else
	{
		m_T = FALSE;
		//启用消息管理按钮
		GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
		//GetDlgItem(IDC_MESSAGE)->EnableWindow(FALSE);
		m_Tip.SetWindowTextW(_T("开始提示"));

	}
	

}


void CMFCnewsDlg::OnBnClickedQuit()
{
	// TODO:  在此添加控件通知处理程序代码

	OnCancel();

}
