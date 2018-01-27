
/***************************************************************************
* Copyright (c) 2017, AEC, All rights reserved.
*
* �ļ����ƣ� ��Ϣ��ʾ��
* ժ Ҫ�� ͷ�ļ�
* �� �ߣ� ������
*
* �޸ļ�¼��
*[����][����/�޸���] [�޸�ԭ��]
***************************************************************************/
// MFCnewsDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"		// ���÷Ǳ�׼���ͷ�ļ�
#include "NewsMang.h"	// �����Զ����ͷ�ļ�
#include <vector>		// ���ñ�׼���ͷ�ļ�
using namespace std;

// CMFCnewsDlg �Ի���
class CMFCnewsDlg : public CDialogEx
{
// ����
public:
	CMFCnewsDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCNEWS_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	//��ʱ��
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	//�رն�ʱ��
	afx_msg void OnClose();
	//��Ϣ����
	afx_msg void OnBnClickedButton1();
	//�ö�
	afx_msg void OnBnClickedCheck1();
	CButton m_Stick;
	afx_msg void OnEnChangeMessage();
	//��ʼ��ʾ
	afx_msg void OnClickedTips();
	CButton m_Tip;
	//�˳�
	afx_msg void OnBnClickedQuit();
	//��Ϣ����Ի����������
	CNewsMang m_DlgA;
public:
	//�Զ�����Ϣ
	afx_msg LRESULT OnMyTIPMessage(WPARAM wParam, LPARAM lParam);
	//��ʾ������
	vector<CString> v_strShowContent;
	CEdit m_Edit;
	int m_x;
	BOOL m_T;
	vector<CString> v_strContent;
	vector<CString> v_strName;
	//��Ϣ�����ʾ�ļ��ʱ��
	int m_nTime;
};
