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
#include "afxwin.h"
#include "afxcmn.h"
#define WM_ADD_OK	(WM_USER+1000)

// CAdddialog �Ի���

class CAdddialog : public CDialogEx
{
	DECLARE_DYNAMIC(CAdddialog)

public:
	CAdddialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAdddialog();

// �Ի�������
	enum { IDD = IDD_ADD_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	//������
	CEdit m_ctrAddName;
	CString m_strAddName;
	//������
	CComboBox m_Typelist;
	CString m_strTypelist;
	//��д�ĳ�ʼ������
	virtual BOOL OnInitDialog();
	//����ַ
	CIPAddressCtrl m_ctrIP;
	DWORD m_nIP;
	CString m_strIP;
	//��ע
	CEdit m_ctrRemark;
	CString m_strRemark;
	//���
	afx_msg void OnBnClickedOk();
	//�����ӵ�����
	CString m_pAdd[4];
};
