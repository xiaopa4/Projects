/***************************************************************************
* Copyright (c) 2017, AEC, All rights reserved.
*
* �ļ����ƣ� ��Ϣ��ʾ��
* ժ Ҫ�� �½���Ϣ�Ի���ͷ�ļ�
* �� �ߣ� ������
*
* �޸ļ�¼��
*[����][����/�޸���] [�޸�ԭ��]
***************************************************************************/
#pragma once
#include "afxwin.h"		// ���÷Ǳ�׼���ͷ�ļ�
#include <vector>		// ���ñ�׼���ͷ�ļ�
using namespace std;

// CSetNews �Ի���

class CSetNews : public CDialogEx
{
	DECLARE_DYNAMIC(CSetNews)

public:
	CSetNews(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSetNews();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:   
	//����
	CEdit m_Name;
	CString m_strName;
	//����
	CEdit m_Content;
	CString m_strContent;
	//���Ʊ༭������
	afx_msg void OnEnChangeName();
	//����
	afx_msg void OnBnClickedSetup();
	//ȡ������
	afx_msg void OnBnClickedNosetup();
	//����Ϣ��
	vector<CString> v_Mnamestr;
};
