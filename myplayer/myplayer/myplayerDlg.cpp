/***************************************************************************
* Copyright (c) 2017, AEC, All rights reserved.
*
* 文件名称： 播放器的设置
* 摘 要： 界面
* 作 者： 张育斌
*
* 修改记录：[2018，1，26] [张育斌] [修改注释]
*[日期][作者/修改者] [修改原因]
***************************************************************************/
// myplayerDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "myplayer.h"
#include "myplayerDlg.h"	// 自定义对话框的头文件
#include "afxdialogex.h"	// 引用非标准库的头文件
#include <shlwapi.h>		// 引用标准库的头文件
#include <strsafe.h>		// 引用标准库的头文件



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


// CmyplayerDlg 对话框



CmyplayerDlg::CmyplayerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CmyplayerDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CmyplayerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO, m_CB_Language);
	DDX_Control(pDX, IDC_CH_BOSSKEY, m_BossKey);
	DDX_Text(pDX, IDC_EDIT1, m_stConfig.iStepTime);
	DDV_MinMaxInt(pDX, m_stConfig.iStepTime, 1, 60);
	DDX_Radio(pDX, IDC_RADIO1, m_stConfig.iUpdate);
	DDX_Check(pDX, IDC_CHECK2, m_stConfig.iPS);
	DDX_Check(pDX, IDC_CHECK3, m_stConfig.iOnlyEnable);
	DDX_Check(pDX, IDC_CHECK4, m_stConfig.iAutoStop);
	DDX_Check(pDX, IDC_CHECK5, m_stConfig.iAutoFit);
}

BEGIN_MESSAGE_MAP(CmyplayerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_COMBO, &CmyplayerDlg::OnCbnSelchangeCombo)
	ON_BN_CLICKED(IDC_CH_BOSSKEY, &CmyplayerDlg::OnBnClickedChBosskey)
	/*ON_BN_CLICKED(IDC_CHECK2, &CmyplayerDlg::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK3, &CmyplayerDlg::OnBnClickedCheck3)*/
	ON_EN_CHANGE(IDC_EDIT1, &CmyplayerDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON1, &CmyplayerDlg::OnBnClickedButton1)
	ON_NOTIFY(NM_OUTOFMEMORY, IDC_HOTKEY1, &CmyplayerDlg::OnNMOutofmemoryHotkey1)
	/*ON_BN_CLICKED(IDC_CHECK4, &CmyplayerDlg::OnBnClickedCheck4)
	ON_BN_CLICKED(IDC_CHECK5, &CmyplayerDlg::OnBnClickedCheck5)
	ON_BN_CLICKED(IDC_RADIO1, &CmyplayerDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CmyplayerDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CmyplayerDlg::OnBnClickedRadio3)*/
	ON_CONTROL_RANGE(BN_CLICKED, IDC_CHECK2, IDC_RADIO3, &CmyplayerDlg::OnClickItem)
	ON_BN_CLICKED(IDOK, &CmyplayerDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CmyplayerDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_APPLY, &CmyplayerDlg::OnBnClickedApply)
	ON_EN_CHANGE(IDC_HOTKEY1, &CmyplayerDlg::OnHotkeyChange)
END_MESSAGE_MAP()


// CmyplayerDlg 消息处理程序

BOOL CmyplayerDlg::OnInitDialog()
{
	//配置对话框初始化
	LoadConfig();

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
	//m_CB_Language.AddString(_T("简体中文"));
	//m_CB_Language.AddString(_T("繁体中文"));
	//m_CB_Language.AddString(_T("English"));
	//m_CB_Language.SetCurSel(0);
	//((CButton *)GetDlgItem(IDC_CH_BOSSKEY))->SetCheck(1);
	//((CButton *)GetDlgItem(IDC_CHECK2))->SetCheck(1);//复选框选中状态
	//((CButton *)GetDlgItem(IDC_CHECK3))->SetCheck(1);
	//GetDlgItem(IDC_APPLY)->EnableWindow(FALSE);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CmyplayerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CmyplayerDlg::OnPaint()
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
HCURSOR CmyplayerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

/***************************************************************************
* 函数名称：[OnCbnSelchangeCombo]
* 摘 要： 判断语言栏改变
* 全局影响：语言栏变动激活应用按钮
* 参数： void
* 返回值：
*
* 修改记录：[2018，1，26] [张育斌] [修改注释]
*[日期][作者/修改者] [修改原因]
***************************************************************************/
void CmyplayerDlg::OnCbnSelchangeCombo()
{
	// TODO:  在此添加控件通知处理程序代码
	CComboBox* pctrLanguage = (CComboBox*)GetDlgItem(IDC_COMBO);
	int selLanguage=0;
	//取得下拉语言栏序列号
	selLanguage = pctrLanguage->GetCurSel();
	if (selLanguage != m_stConfig.iLanguage)
	{
		m_stConfig.iLanguage = selLanguage;
			//激活应用
			GetDlgItem(IDC_APPLY)->EnableWindow(TRUE);
		}

}

/***************************************************************************
* 函数名称：[OnBnClickedChBosskey]
* 摘 要： 按下老板键处理函数
* 全局影响：激活应用按钮与热键框
* 参数： void
* 返回值：
*
* 修改记录：[2018，1，26] [张育斌] [修改注释]
*[日期][作者/修改者] [修改原因]
***************************************************************************/
void CmyplayerDlg::OnBnClickedChBosskey()
{
	// TODO:  在此添加控件通知处理程序代码
	CButton* BossKey = (CButton*)GetDlgItem(IDC_CH_BOSSKEY);
	CHotKeyCtrl* HotKey = (CHotKeyCtrl*)GetDlgItem(IDC_HOTKEY1);
	//老板键是否按下
	if (BossKey->GetCheck() == 1)
		HotKey->EnableWindow(TRUE);
	else
		HotKey->EnableWindow(FALSE);
	GetDlgItem(IDC_APPLY)->EnableWindow(TRUE);
}


/***************************************************************************
* 函数名称：[OnEnChangeEdit1]
* 摘 要： 跳跃时长编辑框的处理函数
* 全局影响：激活应用
* 参数： void
* 返回值：
*
* 修改记录：[2018，1，26] [张育斌] [修改注释]
*[日期][作者/修改者] [修改原因]
***************************************************************************/
void CmyplayerDlg::OnEnChangeEdit1()
{
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	int iStepTime = GetDlgItemInt(IDC_EDIT1);
	if (iStepTime < 1)
		SetDlgItemInt(IDC_EDIT1, 1u, FALSE);
	else if (iStepTime > 60)
		SetDlgItemInt(IDC_EDIT1, 60u, FALSE);
	GetDlgItem(IDC_APPLY)->EnableWindow(TRUE);
	
}

/***************************************************************************
* 函数名称：[LoadConfig]
* 摘 要： 加载配置文件
* 全局影响：加载ini初始化
* 参数： void
* 返回值：TRUE
*
* 修改记录：[2018，1，26] [张育斌] [修改注释]
*[日期][作者/修改者] [修改原因]
***************************************************************************/
BOOL CmyplayerDlg::LoadConfig()
{
	// 获取当前程序文件目录
	::GetModuleFileName(NULL, m_strIniPath, MAX_PATH);
	//删除以“\”结尾的文件名
	::PathRemoveFileSpec(m_strIniPath);
	//使字符串以“\”结尾
	::PathAddBackslash(m_strIniPath);
	//连接两字符串，设置配置文件名
	StringCbCat(m_strIniPath, MAX_PATH, _T("config.ini"));
	//是否存在该路径的配置文件 是 加载该配置文件
	if (::PathFileExists(m_strIniPath) == TRUE)
	{
		// 语言  获取有关控件的值
		m_stConfig.iLanguage = (int)::GetPrivateProfileInt(_T("INI"), _T("Language"), 0, m_strIniPath);
		// 老板键
		m_stConfig.iBossKey = (WORD)::GetPrivateProfileInt(_T("INI"), _T("BossKey"), 1, m_strIniPath);
		// 热键
		m_stConfig.iHotKey = ::GetPrivateProfileInt(_T("INI"), _T("HotKey"), 1, m_strIniPath);
		// 播放选项
		m_stConfig.iPS = (int)::GetPrivateProfileInt(_T("INI"), _T("PS"), 1, m_strIniPath);
		m_stConfig.iOnlyEnable = (int)::GetPrivateProfileInt(_T("INI"), _T("OnlyEnable"), 1, m_strIniPath);
		m_stConfig.iAutoStop = (int)::GetPrivateProfileInt(_T("INI"), _T("AutoStop"), 0, m_strIniPath);
		m_stConfig.iAutoFit = (int)::GetPrivateProfileInt(_T("INI"), _T("AutoFit"), 0, m_strIniPath);
		// 步进时长
		m_stConfig.iStepTime = (int)::GetPrivateProfileInt(_T("INI"), _T("StepTime"), 5, m_strIniPath);
		if (m_stConfig.iStepTime < 1)
			m_stConfig.iStepTime = 1;
		else if (m_stConfig.iStepTime > 60)
			m_stConfig.iStepTime = 60;
		// 升级选项
		m_stConfig.iUpdate = (int)::GetPrivateProfileInt(_T("INI"), _T("Update"), 0, m_strIniPath);

		// 应用按钮失效
		GetDlgItem(IDC_APPLY)->EnableWindow(FALSE);
	}
	//加载默认配置文件
	else
	{
		// 语言
		m_stConfig.iLanguage = 0;
		// 老板键
		m_stConfig.iBossKey = 1;
		// 热键
		m_stConfig.iHotKey = MAKEWORD('E', HOTKEYF_ALT);
		// 播放选项
		m_stConfig.iPS = 1;
		m_stConfig.iOnlyEnable = 1;
		m_stConfig.iAutoStop = 0;
		m_stConfig.iAutoFit = 0;
		// 步进时长
		m_stConfig.iStepTime = 5;
		// 升级选项
		m_stConfig.iUpdate = 0;
		
		// 应用按钮激活
		GetDlgItem(IDC_APPLY)->EnableWindow(TRUE);

	}
	//配置初始化
	CComboBox* pctrLanguage = (CComboBox*)GetDlgItem(IDC_COMBO);
	pctrLanguage->AddString(_T("简体中文"));
	pctrLanguage->AddString(_T("繁軆中文"));
	pctrLanguage->AddString(_T("English"));
	pctrLanguage->SetCurSel(m_stConfig.iLanguage);
	CHotKeyCtrl* pctrHotkey = ((CHotKeyCtrl *)GetDlgItem(IDC_HOTKEY1));
	pctrHotkey->SetHotKey(LOBYTE(m_stConfig.iHotKey), HIBYTE(m_stConfig.iHotKey));
	CButton* pctrBossKey = (CButton*)GetDlgItem(IDC_CH_BOSSKEY);
	if (m_stConfig.iBossKey != 0)
	{
		pctrBossKey->SetCheck(BST_CHECKED);
		pctrHotkey->EnableWindow(TRUE);
	}
	else
	{
		pctrBossKey->SetCheck(BST_UNCHECKED);
		pctrHotkey->EnableWindow(FALSE);
	}
	//复选框选中状态
	((CButton *)GetDlgItem(IDC_CHECK2))->SetCheck(1);
	((CButton *)GetDlgItem(IDC_CHECK3))->SetCheck(1);
	//WORD wHotkey = 0;
	//wHotkey = (WORD)pctrHotkey->GetHotKey();
	//if (wHotkey != m_stConfig.iHotKey)
	//{
	//	m_stConfig.iHotKey = wHotkey;
	//	// 激活应用
	//	GetDlgItem(IDC_APPLY)->EnableWindow(TRUE);
	//}

	return TRUE;
}

/***************************************************************************
* 函数名称：[SaveConfig]
* 摘 要： 保存配置文件
* 全局影响：生成ini文件
* 参数： void
* 返回值：TRUE
*
* 修改记录：[2018，1，26] [张育斌] [修改注释]
*[日期][作者/修改者] [修改原因]
***************************************************************************/
BOOL CmyplayerDlg::SaveConfig()
{
	if (UpdateData() == FALSE)
		return FALSE;

	// 语言
	CComboBox* pctrLanguage = (CComboBox*)GetDlgItem(IDC_COMBO);
	int iSel = pctrLanguage->GetCurSel();
	if (iSel >= 0 && iSel < pctrLanguage->GetCount())
		m_stConfig.iLanguage = iSel;
	// 热键
	CHotKeyCtrl* pctrHotkey = (CHotKeyCtrl*)GetDlgItem(IDC_HOTKEY1);
	m_stConfig.iHotKey = (WORD)pctrHotkey->GetHotKey();
	// 老板键
	CButton* pctrEnHot = (CButton*)GetDlgItem(IDC_CH_BOSSKEY);
	if (pctrEnHot->GetCheck() == BST_CHECKED)
		m_stConfig.iBossKey = 1;
	else
		m_stConfig.iBossKey = 0;

	// 写文件
	CString strConfig = _T("");
	// 语言
	strConfig.Format(_T("%u"), (UINT)m_stConfig.iLanguage);
	::WritePrivateProfileString(_T("INI"), _T("Language"), strConfig, m_strIniPath);
	// 老板键
	strConfig.Format(_T("%u"), m_stConfig.iBossKey);
	::WritePrivateProfileString(_T("INI"), _T("BossKey"), strConfig, m_strIniPath);
	// 热键
	strConfig.Format(_T("0x%04x"), m_stConfig.iHotKey);
	::WritePrivateProfileString(_T("INI"), _T("HotKey"), strConfig, m_strIniPath);
	// 播放选项
	strConfig.Format(_T("%u"), (UINT)m_stConfig.iPS);
	::WritePrivateProfileString(_T("INI"), _T("PS"), strConfig, m_strIniPath);
	strConfig.Format(_T("%u"), (UINT)m_stConfig.iOnlyEnable);
	::WritePrivateProfileString(_T("INI"), _T("OnlyEnable"), strConfig, m_strIniPath);
	strConfig.Format(_T("%u"), (UINT)m_stConfig.iAutoStop);
	::WritePrivateProfileString(_T("INI"), _T("AutoStop"), strConfig, m_strIniPath);
	strConfig.Format(_T("%u"), (UINT)m_stConfig.iAutoFit);
	::WritePrivateProfileString(_T("INI"), _T("AutoFit"), strConfig, m_strIniPath);
	// 步进时长
	strConfig.Format(_T("%u"), (UINT)m_stConfig.iStepTime);
	::WritePrivateProfileString(_T("INI"), _T("StepTime"), strConfig, m_strIniPath);
	// 升级选项
	strConfig.Format(_T("%u"), (UINT)m_stConfig.iUpdate);
	::WritePrivateProfileString(_T("INI"), _T("Update"), strConfig, m_strIniPath);

	// 禁止应用按钮
	GetDlgItem(IDC_APPLY)->EnableWindow(FALSE);
	return TRUE;

}

void CmyplayerDlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	CString str = _T("查询版本信息...\r\n当前版本:4.06.11\r\n最新版本:4.07.01\r\n\r\n有可更新的版本！\r\n");
	SetDlgItemText(IDC_EDIT2, str);
	
}


void CmyplayerDlg::OnNMOutofmemoryHotkey1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO:  在此添加控件通知处理程序代码
	GetDlgItem(IDC_APPLY)->EnableWindow(TRUE);
	*pResult = 0;
}

/***************************************************************************
* 函数名称：[OnClickItem]
* 摘 要： 消息范围映射处理
* 全局影响：激活应用按钮
* 参数： UINT nID
* 返回值：
*
* 修改记录：[2018，1，26] [张育斌] [修改注释]
*[日期][作者/修改者] [修改原因]
***************************************************************************/
void CmyplayerDlg::OnClickItem(UINT nID)
{
	// TODO:

	// 播放选项、升级选项 可能发生变化，激活应用
	GetDlgItem(IDC_APPLY)->EnableWindow(TRUE);

}


void CmyplayerDlg::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	if (GetDlgItem(IDC_APPLY)->IsWindowEnabled() == TRUE)
	{
		SaveConfig();
	}
	OnOK();
}


void CmyplayerDlg::OnBnClickedCancel()
{
	// TODO:  在此添加控件通知处理程序代码
	if (GetDlgItem(IDC_APPLY)->IsWindowEnabled() == TRUE)
	{
		if (MessageBox(_T("配置内容已修改，确定不保存？"), _T("是否保存"), MB_ICONMASK | MB_YESNO) == IDYES)
		{
			OnBnClickedApply();
		}
	}
	OnCancel();
	
}


void CmyplayerDlg::OnBnClickedApply()
{
	// TODO:  在此添加控件通知处理程序代码
	SaveConfig();
	
}


void CmyplayerDlg::OnHotkeyChange()
{
		 //激活应用
		GetDlgItem(IDC_APPLY)->EnableWindow(TRUE);
	
}