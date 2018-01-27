/***************************************************************************
* Copyright (c) 2017, AEC, All rights reserved.
*
* �ļ����ƣ� ������������
* ժ Ҫ�� ����
* �� �ߣ� ������
*
* �޸ļ�¼��[2018��1��26] [������] [�޸�ע��]
*[����][����/�޸���] [�޸�ԭ��]
***************************************************************************/
// myplayerDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "myplayer.h"
#include "myplayerDlg.h"	// �Զ���Ի����ͷ�ļ�
#include "afxdialogex.h"	// ���÷Ǳ�׼���ͷ�ļ�
#include <shlwapi.h>		// ���ñ�׼���ͷ�ļ�
#include <strsafe.h>		// ���ñ�׼���ͷ�ļ�



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


// CmyplayerDlg �Ի���



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


// CmyplayerDlg ��Ϣ�������

BOOL CmyplayerDlg::OnInitDialog()
{
	//���öԻ����ʼ��
	LoadConfig();

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
	//m_CB_Language.AddString(_T("��������"));
	//m_CB_Language.AddString(_T("��������"));
	//m_CB_Language.AddString(_T("English"));
	//m_CB_Language.SetCurSel(0);
	//((CButton *)GetDlgItem(IDC_CH_BOSSKEY))->SetCheck(1);
	//((CButton *)GetDlgItem(IDC_CHECK2))->SetCheck(1);//��ѡ��ѡ��״̬
	//((CButton *)GetDlgItem(IDC_CHECK3))->SetCheck(1);
	//GetDlgItem(IDC_APPLY)->EnableWindow(FALSE);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CmyplayerDlg::OnPaint()
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
HCURSOR CmyplayerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

/***************************************************************************
* �������ƣ�[OnCbnSelchangeCombo]
* ժ Ҫ�� �ж��������ı�
* ȫ��Ӱ�죺�������䶯����Ӧ�ð�ť
* ������ void
* ����ֵ��
*
* �޸ļ�¼��[2018��1��26] [������] [�޸�ע��]
*[����][����/�޸���] [�޸�ԭ��]
***************************************************************************/
void CmyplayerDlg::OnCbnSelchangeCombo()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CComboBox* pctrLanguage = (CComboBox*)GetDlgItem(IDC_COMBO);
	int selLanguage=0;
	//ȡ���������������к�
	selLanguage = pctrLanguage->GetCurSel();
	if (selLanguage != m_stConfig.iLanguage)
	{
		m_stConfig.iLanguage = selLanguage;
			//����Ӧ��
			GetDlgItem(IDC_APPLY)->EnableWindow(TRUE);
		}

}

/***************************************************************************
* �������ƣ�[OnBnClickedChBosskey]
* ժ Ҫ�� �����ϰ��������
* ȫ��Ӱ�죺����Ӧ�ð�ť���ȼ���
* ������ void
* ����ֵ��
*
* �޸ļ�¼��[2018��1��26] [������] [�޸�ע��]
*[����][����/�޸���] [�޸�ԭ��]
***************************************************************************/
void CmyplayerDlg::OnBnClickedChBosskey()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CButton* BossKey = (CButton*)GetDlgItem(IDC_CH_BOSSKEY);
	CHotKeyCtrl* HotKey = (CHotKeyCtrl*)GetDlgItem(IDC_HOTKEY1);
	//�ϰ���Ƿ���
	if (BossKey->GetCheck() == 1)
		HotKey->EnableWindow(TRUE);
	else
		HotKey->EnableWindow(FALSE);
	GetDlgItem(IDC_APPLY)->EnableWindow(TRUE);
}


/***************************************************************************
* �������ƣ�[OnEnChangeEdit1]
* ժ Ҫ�� ��Ծʱ���༭��Ĵ�����
* ȫ��Ӱ�죺����Ӧ��
* ������ void
* ����ֵ��
*
* �޸ļ�¼��[2018��1��26] [������] [�޸�ע��]
*[����][����/�޸���] [�޸�ԭ��]
***************************************************************************/
void CmyplayerDlg::OnEnChangeEdit1()
{
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	int iStepTime = GetDlgItemInt(IDC_EDIT1);
	if (iStepTime < 1)
		SetDlgItemInt(IDC_EDIT1, 1u, FALSE);
	else if (iStepTime > 60)
		SetDlgItemInt(IDC_EDIT1, 60u, FALSE);
	GetDlgItem(IDC_APPLY)->EnableWindow(TRUE);
	
}

/***************************************************************************
* �������ƣ�[LoadConfig]
* ժ Ҫ�� ���������ļ�
* ȫ��Ӱ�죺����ini��ʼ��
* ������ void
* ����ֵ��TRUE
*
* �޸ļ�¼��[2018��1��26] [������] [�޸�ע��]
*[����][����/�޸���] [�޸�ԭ��]
***************************************************************************/
BOOL CmyplayerDlg::LoadConfig()
{
	// ��ȡ��ǰ�����ļ�Ŀ¼
	::GetModuleFileName(NULL, m_strIniPath, MAX_PATH);
	//ɾ���ԡ�\����β���ļ���
	::PathRemoveFileSpec(m_strIniPath);
	//ʹ�ַ����ԡ�\����β
	::PathAddBackslash(m_strIniPath);
	//�������ַ��������������ļ���
	StringCbCat(m_strIniPath, MAX_PATH, _T("config.ini"));
	//�Ƿ���ڸ�·���������ļ� �� ���ظ������ļ�
	if (::PathFileExists(m_strIniPath) == TRUE)
	{
		// ����  ��ȡ�йؿؼ���ֵ
		m_stConfig.iLanguage = (int)::GetPrivateProfileInt(_T("INI"), _T("Language"), 0, m_strIniPath);
		// �ϰ��
		m_stConfig.iBossKey = (WORD)::GetPrivateProfileInt(_T("INI"), _T("BossKey"), 1, m_strIniPath);
		// �ȼ�
		m_stConfig.iHotKey = ::GetPrivateProfileInt(_T("INI"), _T("HotKey"), 1, m_strIniPath);
		// ����ѡ��
		m_stConfig.iPS = (int)::GetPrivateProfileInt(_T("INI"), _T("PS"), 1, m_strIniPath);
		m_stConfig.iOnlyEnable = (int)::GetPrivateProfileInt(_T("INI"), _T("OnlyEnable"), 1, m_strIniPath);
		m_stConfig.iAutoStop = (int)::GetPrivateProfileInt(_T("INI"), _T("AutoStop"), 0, m_strIniPath);
		m_stConfig.iAutoFit = (int)::GetPrivateProfileInt(_T("INI"), _T("AutoFit"), 0, m_strIniPath);
		// ����ʱ��
		m_stConfig.iStepTime = (int)::GetPrivateProfileInt(_T("INI"), _T("StepTime"), 5, m_strIniPath);
		if (m_stConfig.iStepTime < 1)
			m_stConfig.iStepTime = 1;
		else if (m_stConfig.iStepTime > 60)
			m_stConfig.iStepTime = 60;
		// ����ѡ��
		m_stConfig.iUpdate = (int)::GetPrivateProfileInt(_T("INI"), _T("Update"), 0, m_strIniPath);

		// Ӧ�ð�ťʧЧ
		GetDlgItem(IDC_APPLY)->EnableWindow(FALSE);
	}
	//����Ĭ�������ļ�
	else
	{
		// ����
		m_stConfig.iLanguage = 0;
		// �ϰ��
		m_stConfig.iBossKey = 1;
		// �ȼ�
		m_stConfig.iHotKey = MAKEWORD('E', HOTKEYF_ALT);
		// ����ѡ��
		m_stConfig.iPS = 1;
		m_stConfig.iOnlyEnable = 1;
		m_stConfig.iAutoStop = 0;
		m_stConfig.iAutoFit = 0;
		// ����ʱ��
		m_stConfig.iStepTime = 5;
		// ����ѡ��
		m_stConfig.iUpdate = 0;
		
		// Ӧ�ð�ť����
		GetDlgItem(IDC_APPLY)->EnableWindow(TRUE);

	}
	//���ó�ʼ��
	CComboBox* pctrLanguage = (CComboBox*)GetDlgItem(IDC_COMBO);
	pctrLanguage->AddString(_T("��������"));
	pctrLanguage->AddString(_T("��܃����"));
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
	//��ѡ��ѡ��״̬
	((CButton *)GetDlgItem(IDC_CHECK2))->SetCheck(1);
	((CButton *)GetDlgItem(IDC_CHECK3))->SetCheck(1);
	//WORD wHotkey = 0;
	//wHotkey = (WORD)pctrHotkey->GetHotKey();
	//if (wHotkey != m_stConfig.iHotKey)
	//{
	//	m_stConfig.iHotKey = wHotkey;
	//	// ����Ӧ��
	//	GetDlgItem(IDC_APPLY)->EnableWindow(TRUE);
	//}

	return TRUE;
}

/***************************************************************************
* �������ƣ�[SaveConfig]
* ժ Ҫ�� ���������ļ�
* ȫ��Ӱ�죺����ini�ļ�
* ������ void
* ����ֵ��TRUE
*
* �޸ļ�¼��[2018��1��26] [������] [�޸�ע��]
*[����][����/�޸���] [�޸�ԭ��]
***************************************************************************/
BOOL CmyplayerDlg::SaveConfig()
{
	if (UpdateData() == FALSE)
		return FALSE;

	// ����
	CComboBox* pctrLanguage = (CComboBox*)GetDlgItem(IDC_COMBO);
	int iSel = pctrLanguage->GetCurSel();
	if (iSel >= 0 && iSel < pctrLanguage->GetCount())
		m_stConfig.iLanguage = iSel;
	// �ȼ�
	CHotKeyCtrl* pctrHotkey = (CHotKeyCtrl*)GetDlgItem(IDC_HOTKEY1);
	m_stConfig.iHotKey = (WORD)pctrHotkey->GetHotKey();
	// �ϰ��
	CButton* pctrEnHot = (CButton*)GetDlgItem(IDC_CH_BOSSKEY);
	if (pctrEnHot->GetCheck() == BST_CHECKED)
		m_stConfig.iBossKey = 1;
	else
		m_stConfig.iBossKey = 0;

	// д�ļ�
	CString strConfig = _T("");
	// ����
	strConfig.Format(_T("%u"), (UINT)m_stConfig.iLanguage);
	::WritePrivateProfileString(_T("INI"), _T("Language"), strConfig, m_strIniPath);
	// �ϰ��
	strConfig.Format(_T("%u"), m_stConfig.iBossKey);
	::WritePrivateProfileString(_T("INI"), _T("BossKey"), strConfig, m_strIniPath);
	// �ȼ�
	strConfig.Format(_T("0x%04x"), m_stConfig.iHotKey);
	::WritePrivateProfileString(_T("INI"), _T("HotKey"), strConfig, m_strIniPath);
	// ����ѡ��
	strConfig.Format(_T("%u"), (UINT)m_stConfig.iPS);
	::WritePrivateProfileString(_T("INI"), _T("PS"), strConfig, m_strIniPath);
	strConfig.Format(_T("%u"), (UINT)m_stConfig.iOnlyEnable);
	::WritePrivateProfileString(_T("INI"), _T("OnlyEnable"), strConfig, m_strIniPath);
	strConfig.Format(_T("%u"), (UINT)m_stConfig.iAutoStop);
	::WritePrivateProfileString(_T("INI"), _T("AutoStop"), strConfig, m_strIniPath);
	strConfig.Format(_T("%u"), (UINT)m_stConfig.iAutoFit);
	::WritePrivateProfileString(_T("INI"), _T("AutoFit"), strConfig, m_strIniPath);
	// ����ʱ��
	strConfig.Format(_T("%u"), (UINT)m_stConfig.iStepTime);
	::WritePrivateProfileString(_T("INI"), _T("StepTime"), strConfig, m_strIniPath);
	// ����ѡ��
	strConfig.Format(_T("%u"), (UINT)m_stConfig.iUpdate);
	::WritePrivateProfileString(_T("INI"), _T("Update"), strConfig, m_strIniPath);

	// ��ֹӦ�ð�ť
	GetDlgItem(IDC_APPLY)->EnableWindow(FALSE);
	return TRUE;

}

void CmyplayerDlg::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString str = _T("��ѯ�汾��Ϣ...\r\n��ǰ�汾:4.06.11\r\n���°汾:4.07.01\r\n\r\n�пɸ��µİ汾��\r\n");
	SetDlgItemText(IDC_EDIT2, str);
	
}


void CmyplayerDlg::OnNMOutofmemoryHotkey1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	GetDlgItem(IDC_APPLY)->EnableWindow(TRUE);
	*pResult = 0;
}

/***************************************************************************
* �������ƣ�[OnClickItem]
* ժ Ҫ�� ��Ϣ��Χӳ�䴦��
* ȫ��Ӱ�죺����Ӧ�ð�ť
* ������ UINT nID
* ����ֵ��
*
* �޸ļ�¼��[2018��1��26] [������] [�޸�ע��]
*[����][����/�޸���] [�޸�ԭ��]
***************************************************************************/
void CmyplayerDlg::OnClickItem(UINT nID)
{
	// TODO:

	// ����ѡ�����ѡ�� ���ܷ����仯������Ӧ��
	GetDlgItem(IDC_APPLY)->EnableWindow(TRUE);

}


void CmyplayerDlg::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (GetDlgItem(IDC_APPLY)->IsWindowEnabled() == TRUE)
	{
		SaveConfig();
	}
	OnOK();
}


void CmyplayerDlg::OnBnClickedCancel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	if (GetDlgItem(IDC_APPLY)->IsWindowEnabled() == TRUE)
	{
		if (MessageBox(_T("�����������޸ģ�ȷ�������棿"), _T("�Ƿ񱣴�"), MB_ICONMASK | MB_YESNO) == IDYES)
		{
			OnBnClickedApply();
		}
	}
	OnCancel();
	
}


void CmyplayerDlg::OnBnClickedApply()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	SaveConfig();
	
}


void CmyplayerDlg::OnHotkeyChange()
{
		 //����Ӧ��
		GetDlgItem(IDC_APPLY)->EnableWindow(TRUE);
	
}