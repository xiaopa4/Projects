/***************************************************************************
* Copyright (c) 2017, AEC, All rights reserved.
*
* �ļ����ƣ� ��ý�������
* ժ Ҫ�� ͷ�ļ�
* �� �ߣ� ������
*
* �޸ļ�¼��
*[����][����/�޸���] [�޸�ԭ��]
***************************************************************************/
#pragma once
#include "afxcmn.h"
#include "Propetypage1.h"
#include "Propetypage2.h"

// CPropetydialog �Ի���

class CPropetydialog : public CDialogEx
{
	DECLARE_DYNAMIC(CPropetydialog)

public:
	CPropetydialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPropetydialog();

// �Ի�������
	enum { IDD = IDD_PROPETYDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	//ѡ�����
	CTabCtrl m_tab;
	virtual BOOL OnInitDialog();
	//�����ǩ����
	CPropetypage1 m_clsPage1;
	//�����ǩ����
	CPropetypage2 m_clsPage2;
//	Cstring m_strPropety;
//	CString* m_strPropety;
	CString* m_Propety;
	//����ҳ�л�������
	afx_msg void OnTcnSelchangingTab(NMHDR *pNMHDR, LRESULT *pResult);
};
