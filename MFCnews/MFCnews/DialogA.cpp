// DialogA.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCnews.h"
#include "DialogA.h"
#include "DialogB.h"
#include "afxdialogex.h"


// CDialogA �Ի���

IMPLEMENT_DYNAMIC(CDialogA, CDialogEx)

CDialogA::CDialogA(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialogA::IDD, pParent)
	, m_strMlist(_T(""))
	, m_strTiplist(_T(""))
	, m_Edit_Time(666)
{

}

CDialogA::~CDialogA()
{
}

void CDialogA::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MESSAGE_LIST, m_MList);
	DDX_LBString(pDX, IDC_MESSAGE_LIST, m_strMlist);
	DDX_Control(pDX, IDC_TIPS_LIST, m_Tiplist);
	DDX_LBString(pDX, IDC_TIPS_LIST, m_strTiplist);
	//  DDX_Text(pDX, IDC_EDIT1, m_Edit_Time);
	DDX_Text(pDX, IDC_EDIT1, m_Edit_Time);
	DDV_MinMaxInt(pDX, m_Edit_Time, 500, 30000);
}


BEGIN_MESSAGE_MAP(CDialogA, CDialogEx)
	ON_MESSAGE(WM_MY_MESSAGE, OnMyMessage)
	ON_BN_CLICKED(IDC_ADD, &CDialogA::OnClickedAdd)
	ON_LBN_SELCHANGE(IDC_MESSAGE_LIST, &CDialogA::OnLbnSelchangeMessageList)
	ON_BN_CLICKED(IDC_MINUS, &CDialogA::OnBnClickedMinus)
	ON_BN_CLICKED(IDC_RIGHT, &CDialogA::OnBnClickedRight)
	ON_BN_CLICKED(IDC_LEFT, &CDialogA::OnBnClickedLeft)
	ON_BN_CLICKED(IDC_RIGHTSHIFT, &CDialogA::OnBnClickedRightshift)
	ON_BN_CLICKED(IDC_LEFTSHIFT, &CDialogA::OnBnClickedLeftshift)
	ON_BN_CLICKED(IDC_UP, &CDialogA::OnBnClickedUp)
	ON_BN_CLICKED(IDC_DOWN, &CDialogA::OnBnClickedDown)
	ON_BN_CLICKED(IDC_OK, &CDialogA::OnBnClickedOk)
	ON_BN_CLICKED(IDC_Cancel, &CDialogA::OnBnClickedCancel)
	ON_EN_CHANGE(IDC_EDIT1, &CDialogA::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CDialogA ��Ϣ�������

LRESULT  CDialogA::OnMyMessage(WPARAM wParam, LPARAM lParam)
{
	// TODO: �����û��Զ�����Ϣ 

	m_MList.AddString(m_DlgB.m_strName);
	v_strName.push_back(m_DlgB.m_strName);
	v_strContent.push_back(m_DlgB.m_strContent);
	//MessageBox("��Ϣ�������!");  
	return 0;
}

void CDialogA::OnClickedAdd()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	
	m_DlgB.DoModal();//������ʾһ��ģʽ�Ի���

}


void CDialogA::OnLbnSelchangeMessageList()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

}


BOOL CDialogA::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	//�����д洢��Ϣ���Ƶ��ܸ���
	vector<int>::size_type i_NameNum = v_strName.size();
	//�����д洢��ʾ��Ϣ���Ƶĸ���
	vector<int>::size_type i_ShowNum = v_strShow.size();
	CString str;
	if (i_NameNum == 0)
	{
		return 0;
	}
	else
	{
		//��Ϣ�б���г�ʼ��
		if (i_ShowNum == 0)
		{
			static vector<int>::size_type i;
			for (i = 0; i < i_NameNum; i++)
			{
				m_MList.InsertString(i, v_strName[i]);
			}
		}
		else
		{
			//��Ҫ��ʾ�����ݴ�����ʾ�б��н��г�ʼ��
			static vector<int>::size_type j;
			for (j = 0; j < i_ShowNum; j++)
			{
				m_Tiplist.InsertString(j, v_strShow[j]);
				
			
			}
			//��������Ϣ������Ϣ�б��н��г�ʼ��
			static vector<int>::size_type m;
			static vector<int>::size_type n;
			int k = 0;
			for (m = 0; m < i_NameNum; m++)
			{
				//�ж�Ҫ��ʾ����Ϣ����Ϣ�����Ƿ���ͬ������ͬ�����Ϣ������ӵ���Ϣ�б���
				bool flats = true;
				for (n = 0; n < i_ShowNum; n++)
				{
					if (v_strName[m] == v_strShow[n])
					{
						flats = false;
					}
				}
				if (flats == true)
				{
					m_MList.InsertString(k++, v_strName[m]);
				}

			}
		}
	}
	
	//�����ʼ��¼
	
	for (unsigned int m = 0; m < v_strName.size(); m++)
	{
		str = v_strName[m];
		v_strReName.push_back(str);
		str = v_strContent[m];
		v_strReContent.push_back(str);
	}
	//��Ϣ����
	v_nNums = v_strName.size();

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void CDialogA::OnBnClickedMinus()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	if (m_MList.GetCurSel() >= 0)
	{
		m_MList.GetText(m_MList.GetCurSel(), m_strMlist);
		m_MList.DeleteString(m_MList.GetCurSel());
		//ɾ�������´����Ϣ
		vector<int>::size_type i;
		for (i = 0; i < v_strName.size(); i++)
		{
			if (m_strMlist == v_strName[i])
			{
				//�����洢��������Ϣ
				v_strName.erase(v_strName.begin() + i);
				v_strContent.erase(v_strContent.begin() + i);
				//�����½���������Ϣ
				m_DlgB.v_Mnamestr.erase(m_DlgB.v_Mnamestr.begin() + i);
			}
		}

	}
	else
	{
		MessageBox(_T("��ѡ��ɾ���"));
	}
	m_strMlist = _T("");
}


void CDialogA::OnBnClickedRight()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	UpdateData(true);
	if (m_strMlist == _T(""))
	{
		MessageBox(_T("��ѡ��ת���"));
	}
	else
	{
		m_Tiplist.AddString(m_strMlist);
		m_MList.DeleteString(m_MList.GetCurSel());
	}
}


void CDialogA::OnBnClickedLeft()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	UpdateData(true);
	if (m_strTiplist == _T(""))
	{
		MessageBox(_T("��ѡ��ת���"));
	}
	else
	{
		m_MList.AddString(m_strTiplist);
		m_Tiplist.DeleteString(m_Tiplist.GetCurSel());
	}
}


void CDialogA::OnBnClickedRightshift()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	unsigned int m;
	unsigned int n =  m_MList.GetCount();
	for ( m=0; m < n; n--)
	{
		m_MList.GetText(m, m_strMlist);
		m_Tiplist.AddString(m_strMlist);
		m_MList.DeleteString(m);
	}

}

//ȫ������
void CDialogA::OnBnClickedLeftshift()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	unsigned int m;
	unsigned int n = m_Tiplist.GetCount();
	for ( m=0; m < n; n--)
	{
		m_Tiplist.GetText(m, m_strTiplist);
		m_MList.AddString(m_strTiplist);
		m_Tiplist.DeleteString(m);
	}
}


void CDialogA::OnBnClickedUp()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	UpdateData(true);
	int i = m_Tiplist.GetCurSel();
	if (m_strTiplist == _T(""))
	{
		MessageBox(_T("��ѡ�������"));
	}
	else
	{
		if (m_Tiplist.GetCurSel() == 0)
		{
			MessageBox(_T("�Ѿ�����㣡"));
		} 
		else
		{
			//m_Tiplist.GetText(m_Tiplist.GetCurSel() - 1, m_strTiplist);
			m_Tiplist.InsertString(m_Tiplist.GetCurSel() - 1, m_strTiplist);
			m_Tiplist.DeleteString(i+1);
		}
		
	}
	m_strTiplist = _T("");
}


void CDialogA::OnBnClickedDown()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	UpdateData(true);
	int i = m_Tiplist.GetCurSel();
	if (m_strTiplist == _T(""))
	{
		MessageBox(_T("��ѡ�������"));
	}
	else
	{
		if (m_Tiplist.GetCurSel() == m_Tiplist.GetCurSel() - 1)
		{
			MessageBox(_T("�Ѿ�����ײ㣡"));
		}
		else
		{
			m_Tiplist.InsertString(m_Tiplist.GetCurSel() + 2, m_strTiplist);
			m_Tiplist.DeleteString(i);
		}

	}
	m_strTiplist = _T("");
}


void CDialogA::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	v_strShow.clear();
			CString str;
			int ShowNums = m_Tiplist.GetCount();
			for (int i = 0; i < ShowNums; ShowNums--)
			{
				m_Tiplist.GetText(i, str);
				v_strShow.push_back(str);
				m_Tiplist.DeleteString(i);
			}
			UpdateData(true);
			this->GetParent()->SendMessage(WM_MY_TIPMESSAGE, 0, 0);
			v_strReName.clear();
			v_strReContent.clear();
			v_strShow.clear();
		
			OnOK();
}


void CDialogA::OnBnClickedCancel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

		CString str;
		unsigned int i;
		if (v_nNums != v_strName.size())
		{
			bool flats = 0;
			for (i = 0; i < v_strName.size(); i++)
			{
				if (v_strName[i] != v_strReName[i])
				{
					flats = 1;
					break;
				}
			}
			if (flats == 1)
			{
				v_strName.clear();
				v_strContent.clear();
				m_DlgB.v_Mnamestr.clear();
				for (i = 0; i < v_strReName.size(); i++)
				{
					str = v_strReName[i];
					v_strName.push_back(str);
					m_DlgB.v_Mnamestr.push_back(str);
					str = v_strReContent[i];
					v_strContent.push_back(str);
	
				}
			}
		}
		else
		{
	
			v_strName.clear();
			v_strContent.clear();
			m_DlgB.v_Mnamestr.clear();
	
			for (i = 0; i < v_strReName.size(); i++)
			{
				str = v_strReName[i];
				v_strName.push_back(str);
				m_DlgB.v_Mnamestr.push_back(str);
				str = v_strReContent[i];
				v_strContent.push_back(str);
	
			}
			
		}
	
	
	
			UpdateData(true);
			this->GetParent()->SendMessage(WM_MY_TIPMESSAGE, 0, 0);
			v_strReName.clear();
			v_strReContent.clear();
			v_strShow.clear();
	
	
			OnCancel();
}


void CDialogA::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	m_nTime = GetDlgItemInt(IDC_EDIT1);

}
