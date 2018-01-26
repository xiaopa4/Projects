
// MaillistDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Maillist.h"
#include "MaillistDlg.h"
#include "afxdialogex.h"
#include "vld.h"
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


// CMaillistDlg 对话框



CMaillistDlg::CMaillistDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMaillistDlg::IDD, pParent)
	, m_strName(_T(""))
	, m_strIDName(_T(""))
	, m_strTel1(_T(""))
	, m_strTel2(_T(""))
	, m_strEmail(_T(""))
	, m_strAdress(_T(""))
	, m_strPropety(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMaillistDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_CONTACT_TREE, m_clsTree);
	DDX_Control(pDX, IDC_CONTACT_TREE, m_clsTree);
	DDX_Control(pDX, IDC_NAME, m_ctrName);
	DDX_Text(pDX, IDC_NAME, m_strName);
	DDV_MaxChars(pDX, m_strName, 16);
	DDX_Control(pDX, IDC_IDNAME, m_ctrIDName);
	DDX_Text(pDX, IDC_IDNAME, m_strIDName);
	DDV_MaxChars(pDX, m_strIDName, 16);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_ctrBirthday);
	DDX_Control(pDX, IDC_TEL1, m_ctrTel1);
	DDX_Text(pDX, IDC_TEL1, m_strTel1);
	DDV_MaxChars(pDX, m_strTel1, 16);
	DDX_Control(pDX, IDC_TEL2, m_ctrTel2);
	DDX_Text(pDX, IDC_TEL2, m_strTel2);
	DDV_MaxChars(pDX, m_strTel2, 16);
	DDX_Control(pDX, IDC_MAIL, m_ctrEmail);
	DDX_Text(pDX, IDC_MAIL, m_strEmail);
	DDV_MaxChars(pDX, m_strEmail, 128);
	//  DDX_Control(pDX, IDC_FORM, m_ctrForm);
	DDX_Control(pDX, IDC_ADRESS, m_ctrAdress);
	DDX_Text(pDX, IDC_ADRESS, m_strAdress);
	DDV_MaxChars(pDX, m_strAdress, 128);
	DDX_Control(pDX, IDC_PROPETY, m_ctrPropety);
	DDX_Text(pDX, IDC_PROPETY, m_strPropety);
	DDV_MaxChars(pDX, m_strPropety, 256);
	DDX_Control(pDX, IDC_ADDG, m_ctrAddg);
	DDX_Control(pDX, IDC_ADDSORT, m_ctrAddSort);
	DDX_Control(pDX, IDC_DEL, m_ctrDel);
	DDX_Control(pDX, IDC_FORM, m_ctrForm);
	DDX_Control(pDX, IDC_DELSORT, m_ctrDelSort);
}

BEGIN_MESSAGE_MAP(CMaillistDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADDSORT, &CMaillistDlg::OnBnClickedAddsort)
	ON_BN_CLICKED(IDC_DELSORT, &CMaillistDlg::OnBnClickedDelsort)
	ON_BN_CLICKED(IDC_ADDG, &CMaillistDlg::OnBnClickedAddg)
	//ON_NOTIFY(TVN_SELCHANGED, IDC_CONTACT_TREE, &CMaillistDlg::OnTvnSelchangedContactTree)
	ON_NOTIFY(NM_CLICK, IDC_CONTACT_TREE, &CMaillistDlg::OnNMClickContactTree)
	ON_BN_CLICKED(IDC_DEL, &CMaillistDlg::OnBnClickedDel)
	ON_BN_CLICKED(IDC_FORM, &CMaillistDlg::OnBnClickedForm)
END_MESSAGE_MAP()


// CMaillistDlg 消息处理程序

BOOL CMaillistDlg::OnInitDialog()
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

	HICON hIcon[5];      // 图标句柄数组     
	

	// 加载三个图标，并将它们的句柄保存到数组     
	hIcon[0] = theApp.LoadIcon(IDI_ICON1);
	hIcon[1] = theApp.LoadIcon(IDI_ICON2);
	hIcon[2] = theApp.LoadIcon(IDI_ICON3);
	hIcon[3] = theApp.LoadIcon(IDI_ICON4);
	hIcon[4] = theApp.LoadIcon(IDI_ICON5);
	// 创建图像序列CImageList对象     
	m_ImageList.Create(32, 32, ILC_COLOR32 , 5, 5);
	// 将三个图标添加到图像序列   
	for (int i = 0; i < 5; i++)
	{
		m_ImageList.Add(hIcon[i]);
	}

	// 为树形控件设置图像序列     
	m_clsTree.SetImageList(&m_ImageList, TVSIL_NORMAL);
	hTreeRoot = m_clsTree.InsertItem(_T("未分组"),1, 3);
	m_clsTree.InsertItem(_T("熊宝"), 0, 2, hTreeRoot, TVI_LAST);
	m_clsTree.InsertItem(_T("马绍文"), 0, 2, hTreeRoot, TVI_LAST);
	HTREEITEM hSubItem = m_clsTree.InsertItem(_T("大学同学"), 1, 3);
	m_clsTree.InsertItem(_T("刘星武"), 0, 2, hSubItem, TVI_LAST);

	m_strMsg[0][0] = _T("熊宝");
	m_strMsg[1][0] = _T("马绍文");
	m_strMsg[2][0] = _T("刘星武");
	m_ctrForm.EnableWindow(FALSE);
	m_ctrDel.EnableWindow(FALSE);


	m_clsTree.SetItemHeight(30);

	m_clsTree.ModifyStyle(NULL, TVS_HASLINES | TVS_HASBUTTONS | TVS_LINESATROOT | TVIF_IMAGE | TVE_EXPAND);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMaillistDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMaillistDlg::OnPaint()
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
HCURSOR CMaillistDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMaillistDlg::OnBnClickedAddsort()
{
	// TODO:  在此添加控件通知处理程序代码

	if (m_clsAddsort.DoModal() == IDOK)
	{
		HTREEITEM hTreeRoot;
		m_strSortName = m_clsAddsort.m_strName;
		m_clsTree.SetImageList(&m_ImageList, TVSIL_NORMAL);
		hTreeRoot = m_clsTree.InsertItem(m_strSortName, 1, 3);
	}
	

}


void CMaillistDlg::OnBnClickedDelsort()
{
	// TODO:  在此添加控件通知处理程序代码

	HTREEITEM  hSelected;
	hSelected = m_clsTree.GetSelectedItem();
	//删除选择的节点,如果节点下面还有子节点也会被一起删掉
	m_clsTree.DeleteItem(hSelected);

}


void CMaillistDlg::OnBnClickedAddg()
{
	// TODO:  在此添加控件通知处理程序代码

	UpdateData(TRUE);
	if (m_strName == _T(""))
	{
		::MessageBox(NULL, _T("请将信息填充完整！"), _T("提示"), MB_OK);
	}
	else
	{
		int i;
		for (i = 0; i < 20; i++)
		{
			if (m_strMsg[i][0] == m_strName)
			{
				MessageBox(_T(" 已存在该人名！"));
				return;
			}
		}
		for (i = 0; m_strMsg[i][0] != _T("");)
		{
			i++;
		}
		UpdateData(TRUE);
		m_ctrName.GetWindowText(m_strMsg[i][0]);
		m_strName = m_strMsg[i][0];
		m_ctrIDName.GetWindowText(m_strMsg[i][1]);
		m_ctrTel1.GetWindowText(m_strMsg[i][2]);
		m_ctrTel2.GetWindowText(m_strMsg[i][3]);
		m_ctrEmail.GetWindowText(m_strMsg[i][4]);
		m_ctrAdress.GetWindowText(m_strMsg[i][5]);
		m_ctrPropety.GetWindowText(m_strMsg[i][6]);

		m_ctrBirthday.GetTime(pTime[i]);

		m_clsTree.InsertItem(m_strMsg[i][0], 1, 3, hTreeRoot);

		clearfun();
		m_clsTree.RedrawWindow();
	}
}
void CMaillistDlg::clearfun()
{
	m_ctrName.SetWindowText(_T(""));
	m_strName = _T("");
	m_ctrIDName.SetWindowText(_T(""));
	CTime time = CTime::GetCurrentTime();
	CString str;
	str.Format(_T("%d-%d-%d"), time.GetYear(), time.GetMonth(), time.GetDay());
	m_ctrBirthday.SetWindowText(str);
	m_ctrTel1.SetWindowText(_T(""));
	m_ctrTel2.SetWindowText(_T(""));
	m_ctrEmail.SetWindowText(_T(""));
	m_ctrAdress.SetWindowText(_T(""));
	m_ctrPropety.SetWindowText(_T(""));

}



void CMaillistDlg::OnNMClickContactTree(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO:  在此添加控件通知处理程序代码
	//获取鼠标消息点击的坐标
	CPoint pt = GetCurrentMessage()->pt;
	m_clsTree.ScreenToClient(&pt);
	UINT uFlags = 0;
	HTREEITEM hItem = m_clsTree.HitTest(pt, &uFlags);



	if (hItem == NULL)
	{
		m_ctrDelSort.EnableWindow(FALSE);
		m_ctrAddg.EnableWindow(TRUE);
		m_ctrForm.EnableWindow(FALSE);
		m_ctrDel.EnableWindow(FALSE);
		clearfun();
		//选择的是父节点
		if (m_clsTree.GetParentItem(hPreHandle) == NULL)
		{
			m_clsTree.SetItemImage(hPreHandle, 1, 1);
			
		}
		else
		{
			m_clsTree.SetItemImage(hPreHandle, 0, 0);
			
		}
		m_clsTree.PostMessage(WM_KILLFOCUS, 0, 0);
		m_clsTree.RedrawWindow();
		//hPreHandle = NULL;
		return;
	}
	if (hItem != NULL && (TVHT_ONITEM & uFlags))
	{
		m_clsTree.SelectItem(hItem);

		hHandle = m_clsTree.GetSelectedItem();
		
		if (m_clsTree.GetParentItem(hPreHandle) == NULL)
		{
			
			m_clsTree.SetItemImage(hPreHandle, 1, 3);
			
		}
		else
		{
			
			m_clsTree.SetItemImage(hPreHandle, 0, 2);
			
		}
		//获取前选中项的句柄为父节点
		hPreHandle = hHandle;

		//设置焦点
		m_clsTree.PostMessage(WM_SETFOCUS, 0, 0);

		CString str = _T("");
		str = m_clsTree.GetItemText(hHandle);
		//选中了父节点
		if (m_clsTree.GetParentItem(hHandle) == NULL)
		{
			m_ctrDelSort.EnableWindow(TRUE);
			m_ctrAddg.EnableWindow(FALSE);
			m_ctrForm.EnableWindow(FALSE);
			m_ctrDel.EnableWindow(FALSE);
			clearfun();
			return;
		}
		else
		{
			m_ctrDelSort.EnableWindow(FALSE);
			m_ctrAddg.EnableWindow(TRUE);
			m_ctrForm.EnableWindow(TRUE);
			m_ctrDel.EnableWindow(TRUE);

			int i;
			for (i = 0; i < 20; i++)
			{
				if (str == m_strMsg[i][0])
				{
					UpdateData(FALSE);
					m_ctrName.SetWindowText(m_strMsg[i][0]);
					m_strName = m_strMsg[i][0];
					m_ctrIDName.SetWindowText(m_strMsg[i][1]);
					m_ctrBirthday.SetTime(&pTime[i]);
					m_ctrTel1.SetWindowText(m_strMsg[i][2]);
					m_ctrTel2.SetWindowText(m_strMsg[i][3]);
					m_ctrEmail.SetWindowText(m_strMsg[i][4]);
					m_ctrAdress.SetWindowText(m_strMsg[i][5]);
					m_ctrPropety.SetWindowText(m_strMsg[i][6]);

					break;
				}
			}
			

		}
	}



}


void CMaillistDlg::OnBnClickedDel()
{
	// TODO:  在此添加控件通知处理程序代码
	if (m_clsTree.GetParentItem(hHandle) == NULL)
	{
		return;
	}
	m_clsTree.DeleteItem(hHandle);
}


void CMaillistDlg::OnBnClickedForm()
{
	// TODO:  在此添加控件通知处理程序代码
	if (m_strName == _T(""))
	{
		::MessageBox(NULL, _T("请选择修改的项！"), _T("提示"), MB_OK);
	}
	else
	{
		int i;
		for (i = 0; i < 30; i++)
		{
			if (m_strName == m_strMsg[i][0])
			{
				UpdateData(TRUE);
				m_ctrName.GetWindowText(m_strMsg[i][0]);
				m_strName = m_strMsg[i][0];
				m_ctrIDName.GetWindowText(m_strMsg[i][1]);
				m_ctrBirthday.GetTime(pTime[i]);
				m_ctrTel1.GetWindowText(m_strMsg[i][2]);
				m_ctrTel2.GetWindowText(m_strMsg[i][3]);
				m_ctrEmail.GetWindowText(m_strMsg[i][4]);
				m_ctrAdress.GetWindowText(m_strMsg[i][5]);
				m_ctrPropety.GetWindowText(m_strMsg[i][6]);

				
			
				clearfun();

				break;
			}
		}
	}
}
