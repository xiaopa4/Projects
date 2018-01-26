
/***************************************************************************
* Copyright (c) 2017, AEC, All rights reserved.
*
* �ļ����ƣ� ��Ϣ��ʾ��
* ժ Ҫ�� �½���Ϣ�Ի������ļ�
* �� �ߣ� ������
*
* �޸ļ�¼��
*[����][����/�޸���] [�޸�ԭ��]
***************************************************************************/
// DialogB.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCnews.h"
#include "DialogB.h"
#include "DialogA.h"
#include "afxdialogex.h"


// CDialogB �Ի���


IMPLEMENT_DYNAMIC(CDialogB, CDialogEx)

CDialogB::CDialogB(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialogB::IDD, pParent)
	, m_strName(_T(""))
	, m_strContent(_T(""))
{
	

}

CDialogB::~CDialogB()
{
}

void CDialogB::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_NAME, m_Name);
	DDX_Text(pDX, IDC_NAME, m_strName);
	DDX_Control(pDX, IDC_CONTENTS, m_Content);
	DDX_Text(pDX, IDC_CONTENTS, m_strContent);
}


BEGIN_MESSAGE_MAP(CDialogB, CDialogEx)
	ON_EN_CHANGE(IDC_NAME, &CDialogB::OnEnChangeName)
	ON_BN_CLICKED(IDC_SETUP, &CDialogB::OnBnClickedSetup)
	ON_BN_CLICKED(IDC_NOSETUP, &CDialogB::OnBnClickedNosetup)
END_MESSAGE_MAP()


// CDialogB ��Ϣ�������


void CDialogB::OnEnChangeName()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������

}

/***************************************************************************
* �������ƣ�[OnBnClickedSetup]
* ժ Ҫ�� ������Ϣ
* ȫ��Ӱ�죺������Ϣ����Ϣ����Ի���
* ������
* ����ֵ��
*
* �޸ļ�¼��
*[����][����/�޸���] [�޸�ԭ��]
***************************************************************************/
void CDialogB::OnBnClickedSetup()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	UpdateData(true);
	bool IsAdd = true;
	//���ֺ������Ƿ�û����
	if (m_strName == _T("") | m_strContent == _T(""))
	{
		MessageBox(_T("�뽫��Ϣ���������"));
	}
	else
	{
		//������Ϣ���Ƿ��ظ�
		for (int i = 0; i < v_Mnamestr.size(); i++)
		{

			if (m_strName == v_Mnamestr[i])
			{
				MessageBox(_T("��Ϣ���ظ���"));
				m_Name.SetWindowText(_T(""));
				IsAdd = false;
			}

		}
		//���ظ�Ϊtrue
		if (IsAdd == true)
		{
			v_Mnamestr.push_back(m_strName);
			UpdateData(true);
			this->GetParent()->SendMessage(WM_MY_MESSAGE, 0, 0);
			m_Name.SetWindowText(_T(""));
			m_Content.SetWindowText(_T(""));
			//��ӳɹ����˳�
			OnOK();
		}
	}
}


void CDialogB::OnBnClickedNosetup()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	OnCancel();
}
