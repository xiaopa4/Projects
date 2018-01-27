/***************************************************************************
* Copyright (c) 2017, AEC, All rights reserved.
*
* �ļ����ƣ� ��Ϣ��ʾ��
* ժ Ҫ�� ��Ϣ����Ի���ͷ�ļ�
* �� �ߣ� ������
*
* �޸ļ�¼��
*[����][����/�޸���] [�޸�ԭ��]
***************************************************************************/
#pragma once
#include "afxwin.h"		// ���÷Ǳ�׼���ͷ�ļ�
#include <vector>		// ���ñ�׼���ͷ�ļ�
#include "SetNews.h"	// �����Զ����ͷ�ļ�
using namespace std;
// CNewsMang �Ի���

class CNewsMang : public CDialogEx
{
	DECLARE_DYNAMIC(CNewsMang)

public:
	CNewsMang(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CNewsMang();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	//�����Ϣ
	afx_msg void OnClickedAdd();
	//��Ϣ�б����
public:
	CListBox m_MList;
	CString m_strMlist;
public:
	//�Զ�����Ϣ
	afx_msg LRESULT OnMyMessage(WPARAM wParam, LPARAM lParam);
public:
	//��д
	virtual BOOL OnInitDialog();
public:
	//��ʾ�б����
	CListBox m_Tiplist;
	CString m_strTiplist;
public:
	//���ʱ��
	int m_Edit_Time;
	int m_nTime;
public:
	//�������½���Ϣ
	vector<CString> v_strName;
	vector<CString> v_strContent;
	//�����ʼ��¼
	vector<CString> v_strReName;
	vector<CString> v_strReContent;
	//��¼��ʼ��Ϣ����
	vector<int>::size_type v_nNums;
	//�½���Ϣ�Ի����������
	CSetNews m_DlgB;
public:
	//ɾ����Ϣ�б���Ϣ
	afx_msg void OnBnClickedMinus();
	//��������
	afx_msg void OnBnClickedRight();
	//��������
	afx_msg void OnBnClickedLeft();
	//ȫ������
	afx_msg void OnBnClickedRightshift();
	//ȫ������
	afx_msg void OnBnClickedLeftshift();
	//����
	afx_msg void OnBnClickedUp();
	//����
	afx_msg void OnBnClickedDown();
	//ȷ��
	afx_msg void OnBnClickedOk();
	//ȡ��
	afx_msg void OnBnClickedCancel();
public:
	//������ʾ�б���Ϣ
	vector<CString> v_strShow;
	//���ʱ�䴦����
	afx_msg void OnEnChangeEdit1();
	
};
