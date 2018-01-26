
// MaillistDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Maillist.h"
#include "MaillistDlg.h"
#include "afxdialogex.h"
#include "vld.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CMaillistDlg �Ի���



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


// CMaillistDlg ��Ϣ�������

BOOL CMaillistDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	HICON hIcon[5];      // ͼ��������     
	

	// ��������ͼ�꣬�������ǵľ�����浽����     
	hIcon[0] = theApp.LoadIcon(IDI_ICON1);
	hIcon[1] = theApp.LoadIcon(IDI_ICON2);
	hIcon[2] = theApp.LoadIcon(IDI_ICON3);
	hIcon[3] = theApp.LoadIcon(IDI_ICON4);
	hIcon[4] = theApp.LoadIcon(IDI_ICON5);
	// ����ͼ������CImageList����     
	m_ImageList.Create(32, 32, ILC_COLOR32 , 5, 5);
	// ������ͼ����ӵ�ͼ������   
	for (int i = 0; i < 5; i++)
	{
		m_ImageList.Add(hIcon[i]);
	}

	// Ϊ���οؼ�����ͼ������     
	m_clsTree.SetImageList(&m_ImageList, TVSIL_NORMAL);
	hTreeRoot = m_clsTree.InsertItem(_T("δ����"),1, 3);
	m_clsTree.InsertItem(_T("�ܱ�"), 0, 2, hTreeRoot, TVI_LAST);
	m_clsTree.InsertItem(_T("������"), 0, 2, hTreeRoot, TVI_LAST);
	HTREEITEM hSubItem = m_clsTree.InsertItem(_T("��ѧͬѧ"), 1, 3);
	m_clsTree.InsertItem(_T("������"), 0, 2, hSubItem, TVI_LAST);

	m_strMsg[0][0] = _T("�ܱ�");
	m_strMsg[1][0] = _T("������");
	m_strMsg[2][0] = _T("������");
	m_ctrForm.EnableWindow(FALSE);
	m_ctrDel.EnableWindow(FALSE);


	m_clsTree.SetItemHeight(30);

	m_clsTree.ModifyStyle(NULL, TVS_HASLINES | TVS_HASBUTTONS | TVS_LINESATROOT | TVIF_IMAGE | TVE_EXPAND);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMaillistDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMaillistDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMaillistDlg::OnBnClickedAddsort()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	HTREEITEM  hSelected;
	hSelected = m_clsTree.GetSelectedItem();
	//ɾ��ѡ��Ľڵ�,����ڵ����滹���ӽڵ�Ҳ�ᱻһ��ɾ��
	m_clsTree.DeleteItem(hSelected);

}


void CMaillistDlg::OnBnClickedAddg()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	UpdateData(TRUE);
	if (m_strName == _T(""))
	{
		::MessageBox(NULL, _T("�뽫��Ϣ���������"), _T("��ʾ"), MB_OK);
	}
	else
	{
		int i;
		for (i = 0; i < 20; i++)
		{
			if (m_strMsg[i][0] == m_strName)
			{
				MessageBox(_T(" �Ѵ��ڸ�������"));
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//��ȡ�����Ϣ���������
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
		//ѡ����Ǹ��ڵ�
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
		//��ȡǰѡ����ľ��Ϊ���ڵ�
		hPreHandle = hHandle;

		//���ý���
		m_clsTree.PostMessage(WM_SETFOCUS, 0, 0);

		CString str = _T("");
		str = m_clsTree.GetItemText(hHandle);
		//ѡ���˸��ڵ�
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (m_clsTree.GetParentItem(hHandle) == NULL)
	{
		return;
	}
	m_clsTree.DeleteItem(hHandle);
}


void CMaillistDlg::OnBnClickedForm()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (m_strName == _T(""))
	{
		::MessageBox(NULL, _T("��ѡ���޸ĵ��"), _T("��ʾ"), MB_OK);
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
