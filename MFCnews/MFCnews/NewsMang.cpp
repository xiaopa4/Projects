
/***************************************************************************
* Copyright (c) 2017, AEC, All rights reserved.
*
* �ļ����ƣ� ��Ϣ��ʾ��
* ժ Ҫ�� ��Ϣ����Ի������ļ�
* �� �ߣ� ������
*
* �޸ļ�¼��
*[����][����/�޸���] [�޸�ԭ��]
***************************************************************************/
// NewsMang.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCnews.h"
#include "NewsMang.h"
#include "SetNews.h"
#include "afxdialogex.h"


// CNewsMang �Ի���

IMPLEMENT_DYNAMIC(CNewsMang, CDialogEx)

CNewsMang::CNewsMang(CWnd* pParent /*=NULL*/)
	: CDialogEx(CNewsMang::IDD, pParent)
	//��ʼ������
	, m_strMlist(_T(""))
	, m_strTiplist(_T(""))
	, m_Edit_Time(666)
{

}

CNewsMang::~CNewsMang()
{
}

void CNewsMang::DoDataExchange(CDataExchange* pDX)
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


BEGIN_MESSAGE_MAP(CNewsMang, CDialogEx)
	ON_MESSAGE(WM_MY_MESSAGE, OnMyMessage)
	ON_BN_CLICKED(IDC_ADD, &CNewsMang::OnClickedAdd)
	//ON_LBN_SELCHANGE(IDC_MESSAGE_LIST, &CNewsMang::OnLbnSelchangeMessageList)
	ON_BN_CLICKED(IDC_MINUS, &CNewsMang::OnBnClickedMinus)
	ON_BN_CLICKED(IDC_RIGHT, &CNewsMang::OnBnClickedRight)
	ON_BN_CLICKED(IDC_LEFT, &CNewsMang::OnBnClickedLeft)
	ON_BN_CLICKED(IDC_RIGHTSHIFT, &CNewsMang::OnBnClickedRightshift)
	ON_BN_CLICKED(IDC_LEFTSHIFT, &CNewsMang::OnBnClickedLeftshift)
	ON_BN_CLICKED(IDC_UP, &CNewsMang::OnBnClickedUp)
	ON_BN_CLICKED(IDC_DOWN, &CNewsMang::OnBnClickedDown)
	ON_BN_CLICKED(IDC_OK, &CNewsMang::OnBnClickedOk)
	ON_BN_CLICKED(IDC_Cancel, &CNewsMang::OnBnClickedCancel)
	ON_EN_CHANGE(IDC_EDIT1, &CNewsMang::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CNewsMang ��Ϣ�������

/***************************************************************************
* �������ƣ�[OnMyMessage]
* ժ Ҫ�� �Զ�����Ϣ����
* ȫ��Ӱ�죺���ղ������½���Ϣ
* ������ WPARAM wParam, LPARAM lParam��Ϣ�ֶ�
* ����ֵ��0
*
* �޸ļ�¼��
*[����][����/�޸���] [�޸�ԭ��]
***************************************************************************/
LRESULT  CNewsMang::OnMyMessage(WPARAM wParam, LPARAM lParam)
{
	// TODO: �����û��Զ�����Ϣ 
	//�����½���Ϣ
	m_MList.AddString(m_DlgB.m_strName);
	v_strName.push_back(m_DlgB.m_strName);
	v_strContent.push_back(m_DlgB.m_strContent);
	return 0;
}


/***************************************************************************
* �������ƣ�[OnClickedAdd]
* ժ Ҫ�� �����Ϣ
* ȫ��Ӱ�죺���ղ������½���Ϣ
* ������ 
* ����ֵ��
*
* �޸ļ�¼��
*[����][����/�޸���] [�޸�ԭ��]
***************************************************************************/
void CNewsMang::OnClickedAdd()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	//���½���Ϣ�Ի���ģʽ�Ի���
	m_DlgB.DoModal();

}


//void CNewsMang::OnLbnSelchangeMessageList()
//{
//	// TODO:  �ڴ���ӿؼ�֪ͨ����������
//
//}

/***************************************************************************
* �������ƣ�[OnInitDialog]
* ժ Ҫ�� ��д�ĳ�ʼ������
* ȫ��Ӱ�죺
* ������
* ����ֵ��true
*
* �޸ļ�¼��
*[����][����/�޸���] [�޸�ԭ��]
***************************************************************************/
BOOL CNewsMang::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	//�����д洢��Ϣ���Ƶ��ܸ���
	vector<int>::size_type i_NameNum = v_strName.size();
	//�����д洢��ʾ��Ϣ���Ƶĸ���
	vector<int>::size_type i_ShowNum = v_strShow.size();
	CString str;
	//��Ϣ��Ϊ�㲻������
	if (i_NameNum == 0)
	{
		return 0;
	}
	else
	{
		//��Ϣ�б���г�ʼ��
		if (i_ShowNum == 0)
		{
			vector<int>::size_type i;
			for (i = 0 ; i < i_NameNum; i++)
			{
				m_MList.InsertString(i, v_strName[i]);
			}
		}
		else
		{
			//��Ҫ��ʾ�����ݴ�����ʾ�б��н��г�ʼ��
			vector<int>::size_type j;
			for (j = 0; j < i_ShowNum; j++)
			{
				m_Tiplist.InsertString(j, v_strShow[j]);
				
			
			}
			//��������Ϣ������Ϣ�б��н��г�ʼ��
			vector<int>::size_type m;
			vector<int>::size_type n;
			vector<int>::size_type k = 0;
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
		//������ӵ�ԭʼ���ݣ���Ϣ��
		v_strReName.push_back(str);
		str = v_strContent[m];
		//������ӵ�ԭʼ���ݣ�����
		v_strReContent.push_back(str);
	}
	//��Ϣ����
	v_nNums = v_strName.size();

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}

/***************************************************************************
* �������ƣ�[OnBnClickedMinus]
* ժ Ҫ�� ɾ����Ϣ
* ȫ��Ӱ�죺
* ������
* ����ֵ��
*
* �޸ļ�¼��
*[����][����/�޸���] [�޸�ԭ��]
***************************************************************************/
void CNewsMang::OnBnClickedMinus()
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
				//�Ѿ���������forѭ��
				break;
			}
		}

	}
	else
	{
		MessageBox(_T("��ѡ��ɾ���"));
	}
	//v_nNums = v_strName.size();
	m_strMlist = _T("");
}


void CNewsMang::OnBnClickedRight()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	UpdateData(true);
	if (m_strMlist == _T(""))
	{
		MessageBox(_T("��ѡ��ת���"));
	}
	else
	{	//��ʾ�б���Ӹ���Ϣ����Ϣ�б��������Ϣ
		m_Tiplist.AddString(m_strMlist);
		m_MList.DeleteString(m_MList.GetCurSel());
	}
	UpdateData(FALSE);
}


void CNewsMang::OnBnClickedLeft()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	UpdateData(true);
	if (m_strTiplist == _T(""))
	{
		MessageBox(_T("��ѡ��ת���"));
	}
	else 
	{	//��Ϣ�б���Ӹ���Ϣ����ʾ�б��������Ϣ
		m_MList.AddString(m_strTiplist);
		m_Tiplist.DeleteString(m_Tiplist.GetCurSel());
	}
}


void CNewsMang::OnBnClickedRightshift()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	unsigned int m;
	//�б�����Ϣ��Ŀ
	unsigned int n =  m_MList.GetCount();
	for ( m=0; m < n; n--)
	{	//ȡ����Ϣ�б���Ϣ��
		m_MList.GetText(m, m_strMlist);
		//��ӵ���ʾ�б�
		m_Tiplist.AddString(m_strMlist);
		//������Ϣ�б����Ϣ
		m_MList.DeleteString(m);
	}

}

//ȫ������
void CNewsMang::OnBnClickedLeftshift()
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


void CNewsMang::OnBnClickedUp()
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
			UpdateData(FALSE);
		}
		
	}
	m_strTiplist = _T("");
}


void CNewsMang::OnBnClickedDown()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	UpdateData(true);
	int i = m_Tiplist.GetCount();
	if (m_strTiplist == _T(""))
	{
		MessageBox(_T("��ѡ�������"));
	}
	else
	{
		if (m_Tiplist.GetCurSel() == i - 1)
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

/***************************************************************************
* �������ƣ�[OnBnClickedOk]
* ժ Ҫ�� ȷ��
* ȫ��Ӱ�죺
* ������
* ����ֵ��
*
* �޸ļ�¼��
*[����][����/�޸���] [�޸�ԭ��]
***************************************************************************/
void CNewsMang::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	//���������Ԫ��
	v_strShow.clear();
	CString str;
	//�����ʾ�б���Ϣ��Ŀ
	int ShowNums = m_Tiplist.GetCount();
	//����ʾ�б���Ϣ�����浽v_strShow�������ʾ�б�
	for (int i = 0; i < ShowNums; ShowNums--)
		{
			m_Tiplist.GetText(i, str);
			v_strShow.push_back(str);
			m_Tiplist.DeleteString(i);
		}
	UpdateData(true);
	//����Ϣ��ʾ�����ڷ���һ����Ϣ
	this->GetParent()->SendMessage(WM_MY_TIPMESSAGE, 0, 0);
	//��������ԭʼ��Ϣ
	v_strReName.clear();
	v_strReContent.clear();
	v_strShow.clear();
		
	 OnOK();
}

/***************************************************************************
* �������ƣ�[OnBnClickedCancel]
* ժ Ҫ�� ȡ��
* ȫ��Ӱ�죺
* ������
* ����ֵ��
*
* �޸ļ�¼��
*[����][����/�޸���] [�޸�ԭ��]
***************************************************************************/
void CNewsMang::OnBnClickedCancel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

		CString str;
		unsigned int i;
		//�Ƿ�����Ϣɾ����(��Ϣ��Ŀ�Ƿ�ı�)
		if (v_nNums != v_strName.size())
		{
			/*bool flats = FALSE;
			for (i = 0; i < v_strReName.size(); i++)
			{
				if (v_strName[i] != v_strReName[i])
				{
					flats = TRUE;
					break;
				}
			}
			if (flats == TRUE)
			{*/
				//����ı�����Ϣ
				v_strName.clear();
				v_strContent.clear();
				//���v_Mnamestr�б������Ϣ��
				m_DlgB.v_Mnamestr.clear();
				//��ԭʼ��Ϣ����
				for (i = 0; i < v_strReName.size(); i++)
				{
					str = v_strReName[i];
					v_strName.push_back(str);
					m_DlgB.v_Mnamestr.push_back(str);
					str = v_strReContent[i];
					v_strContent.push_back(str);
	
				}
			//}
		}
		else
		{
			bool flats = FALSE;
			//�����Ƚ���Ϣ˳���Ƿ�ı�
			for (i = 0; i < v_strReName.size(); i++)
			{
				//�ı��˾�Ϊtrue
				if (v_strName[i] != v_strReName[i])
				{
					flats = TRUE;
					break;
				}
			}
			//�����Ϣ����������ԭʼ��Ϣ
			if (flats == TRUE)
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
	
			UpdateData(true);
			this->GetParent()->SendMessage(WM_MY_TIPMESSAGE, 0, 0);
			v_strReName.clear();
			v_strReContent.clear();
			v_strShow.clear();
	
	
			OnCancel();
}


void CNewsMang::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	m_nTime = GetDlgItemInt(IDC_EDIT1);

}
