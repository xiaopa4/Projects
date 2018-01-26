/***************************************************************************
* Copyright (c) 2017, AEC, All rights reserved.
*
* �ļ����ƣ� ��Ϣ��ʾ��
* ժ Ҫ�� �����ļ�
* �� �ߣ� ������
*
* �޸ļ�¼��
*[����][����/�޸���] [�޸�ԭ��]
***************************************************************************/
// MFCnewsDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCnews.h"
#include "MFCnewsDlg.h"
#include "afxdialogex.h"
#include "DialogA.h"


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


// CMFCnewsDlg �Ի���



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


// CMFCnewsDlg ��Ϣ�������

BOOL CMFCnewsDlg::OnInitDialog()
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
	CTime cTime = CTime::GetCurrentTime();
	//����ʱ��
	SetTimer(1, 1000, NULL);
	
		m_Tip.EnableWindow(FALSE);
	
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCnewsDlg::OnPaint()
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
HCURSOR CMFCnewsDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


/***************************************************************************
* �������ƣ�[OnTimer]
* ժ Ҫ�� �� SetTimer ��Ա������ָ����ÿ��������ڰ�װ���ʱ��
* ȫ��Ӱ�죺��ʾ��Ϣ
* ������INT_PTR nIDEvent
* ����ֵ��
*
* �޸ļ�¼��
*[����][����/�޸���] [�޸�ԭ��]
***************************************************************************/
void CMFCnewsDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	//����һ����ǰʱ��   
	CTime cTime = CTime::GetCurrentTime();
	CString strTime;
	//�ַ�����ʽ��ʱ��   
	strTime.Format(_T("��Ϣ��ʾ��    ��ǰʱ�䣺%d��%d��%d��  %dʱ%d��%d��"), cTime.GetYear(), cTime.GetMonth(), cTime.GetDay(), cTime.GetHour(), cTime.GetMinute(), cTime.GetSecond());
	//���õ�ǰ���ڱ���   
	SetWindowText(strTime);

	if (m_T == TRUE)
	{
		CString strName, strContent;
		strName = _T("��Ϣ����:\r\n");
		strContent = _T(" \r\n��Ϣ����:\r\n");
		int ShowNums = v_strShowContent.size();
	    vector<int>::size_type i;
		//�ظ���ʾ
		if ( m_x==ShowNums)
			//ȫ�ֱ���
			m_x = 0;
		//������ʾ��Ϣ��˳���Ա��ҵ���ʾ������
		for (i = 0; i < v_strName.size(); i++)
		{
			if (v_strShowContent[m_x] == v_strName[i])
			{
				break;
			}
			
		}
		//ƴ����ʾ���ַ�
		strName = strName + v_strShowContent[m_x++];
		strName = strName + strContent + v_strContent[i];
		//��ʾ
		m_Edit.SetWindowText(strName);
	}
	CDialogEx::OnTimer(nIDEvent);
}

/***************************************************************************
* �������ƣ�[OnMyTIPMessage]
* ժ Ҫ�� �Զ�����Ϣ
* ȫ��Ӱ�죺
* ������WPARAM wParam, LPARAM lParam
* ����ֵ��0
*
* �޸ļ�¼��
*[����][����/�޸���] [�޸�ԭ��]
***************************************************************************/
LRESULT  CMFCnewsDlg::OnMyTIPMessage(WPARAM wParam, LPARAM lParam)
{
	// TODO: �����û��Զ�����Ϣ 

	//��Ϣ��ʾ���ʱ��
	m_nTime = m_DlgA.m_nTime;
	int NameNums, ShowNums;
	//��Ϣ����
	NameNums = m_DlgA.v_strName.size();
	CString str;
	//Ҫ��ʾ����Ϣ��
	ShowNums = m_DlgA.v_strShow.size();
	//��ʼ��ʾ��ť�Ƿ���ã�Ҫ��ʾ����ϢΪ0����ã���������
	if (ShowNums != 0)
	{
		m_Tip.EnableWindow(TRUE);
	}
	else
	{
		m_Tip.EnableWindow(FALSE);
	}
	//����Ϊ0����������
	if (NameNums == 0)
	{
		return 0;
	}
	//���洫��������Ϣ
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
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	KillTimer(1);
	CDialogEx::OnClose();
}


//void CMFCnewsDlg::OnEnChangeEdit1()
//{
//	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
//	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
//	// ���������� CRichEditCtrl().SetEventMask()��
//	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�
//
//	// TODO:  �ڴ���ӿؼ�֪ͨ����������
//}

/***************************************************************************
* �������ƣ�[OnBnClickedButton]
* ժ Ҫ�� �����Ϣ����ť�Ĳ���
* ȫ��Ӱ�죺
* ������
* ����ֵ��
*
* �޸ļ�¼��
*[����][����/�޸���] [�޸�ԭ��]
***************************************************************************/
void CMFCnewsDlg::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	
	vector<int>::size_type i;
	//�༭������ʾ������
	for (i = 0; i < v_strShowContent.size(); i++)
	{
		CString str;
		str = v_strShowContent[i];
		m_DlgA.v_strShow.push_back(str);
	}
	
	v_strShowContent.clear();
	m_Edit.SetWindowText(_T(""));
	m_DlgA.DoModal();//������ʾһ��ģʽ�Ի���
	
}

/***************************************************************************
* �������ƣ�[OnBnClickedCheck1]
* ժ Ҫ�� �ö�
* ȫ��Ӱ�죺
* ������
* ����ֵ��
*
* �޸ļ�¼��
*[����][����/�޸���] [�޸�ԭ��]
***************************************************************************/
void CMFCnewsDlg::OnBnClickedCheck1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������


	CString str;
	m_Stick.GetWindowTextW(str);
	if (str == _T("�ö�"))
	{
		/*::SetWindowPos(this->GetSafeHwnd(), HWND_TOPMOST, 0, 0, 0, 0,
			SWP_HIDEWINDOW | SWP_NOACTIVATE | SWP_NOSIZE);*/
		//�ö����ڣ������ƶ������ܸı��С
		::SetWindowPos(this->GetSafeHwnd(), HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
		m_Stick.SetWindowTextW(_T("ȡ���ö�"));
	}
	else
	{
		/*::SetWindowPos(this->GetSafeHwnd(), HWND_NOTOPMOST, 0, 0, 0, 0,
			SWP_HIDEWINDOW | SWP_NOACTIVATE | SWP_NOSIZE);*/
		//ȡ���ö�
		::SetWindowPos(this->GetSafeHwnd(), HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
		m_Stick.SetWindowTextW(_T("�ö�"));
	}


}

void CMFCnewsDlg::OnEnChangeMessage()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

/***************************************************************************
* �������ƣ�[OnClickedTips1]
* ժ Ҫ�� ��ʼ��ʾ
* ȫ��Ӱ�죺
* ������
* ����ֵ��
*
* �޸ļ�¼��
*[����][����/�޸���] [�޸�ԭ��]
***************************************************************************/
void CMFCnewsDlg::OnClickedTips()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString tip;
	m_Tip.GetWindowTextW(tip);
	if (tip == _T("��ʼ��ʾ"))
	{
		m_T = TRUE;
		//������Ϣ����ť
		GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
		//GetDlgItem(IDC_MESSAGE)->EnableWindow(TRUE);
		m_Tip.SetWindowTextW(_T("ֹͣ��ʾ"));
		//�򿪶�ʱ���������ʾ��Ϣ
		SetTimer(1, m_nTime, NULL);
		m_x = 0;
	}
	else
	{
		m_T = FALSE;
		//������Ϣ����ť
		GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
		//GetDlgItem(IDC_MESSAGE)->EnableWindow(FALSE);
		m_Tip.SetWindowTextW(_T("��ʼ��ʾ"));

	}
	

}


void CMFCnewsDlg::OnBnClickedQuit()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	OnCancel();

}
