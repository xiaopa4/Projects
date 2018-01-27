/***************************************************************************
* Copyright (c) 2017, AEC, All rights reserved.
*
* �ļ����ƣ� ͨѶ���Ի���
* ժ Ҫ�� ͷ�ļ�
* �� �ߣ� ������
*
* �޸ļ�¼��
*[����][����/�޸���] [�޸�ԭ��]
***************************************************************************/
// MaillistDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "AddsortDlg.h"
#include "CmyTreeCtrl.h"
#include "afxwin.h"
#include "afxdtctl.h"

// CMaillistDlg �Ի���
class CMaillistDlg : public CDialogEx
{
// ����
public:
	CMaillistDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MAILLIST_DIALOG };

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
//	CTreeCtrl m_ctrTree;
public:
	//ͼ�����
	CImageList m_ImageList;
	//��ӷ���
	afx_msg void OnBnClickedAddsort();
	CAddsortDlg m_clsAddsort;
public:
	CString m_strSortName;
	//ɾ������
	afx_msg void OnBnClickedDelsort();
	//���
	afx_msg void OnBnClickedAddg();
public:
	//����
	CEdit m_ctrName;
	CString m_strName;
	//�ǳ�
	CEdit m_ctrIDName;
	CString m_strIDName;
	//����
	CDateTimeCtrl m_ctrBirthday;
	CTime pTime[20];
	//�绰1
	CEdit m_ctrTel1;
	CString m_strTel1;
	//�绰2
	CEdit m_ctrTel2;
	CString m_strTel2;
	//����
	CEdit m_ctrEmail;
	CString m_strEmail;
	//��ַ
	CEdit m_ctrAdress;
	CString m_strAdress;
	//��ע
	CEdit m_ctrPropety;
	CString m_strPropety;
	//������
	CString m_strMsg[20][8];
	
public:
	CmyTreeCtrl m_clsTree;
	// ���ĸ��ڵ�ľ��
	HTREEITEM hTreeRoot;
	//��ѡ����
	HTREEITEM hHandle;
	//֮ǰѡ����ľ��
	HTREEITEM hPreHandle;
public:
	//�Զ��庯��
	void clearfun();
	//���
	CButton m_ctrAddg;
	//��ӷ���
	CButton m_ctrAddSort;
	//ɾ��
	CButton m_ctrDel;
	//�޸�
	CButton m_ctrForm;
	//ɾ������
	CButton m_ctrDelSort;
	//������οؼ�������Ӧ����
	afx_msg void OnNMClickContactTree(NMHDR *pNMHDR, LRESULT *pResult);
	//ɾ����Ӧ����
	afx_msg void OnBnClickedDel();
	//�޸���Ӧ����
	afx_msg void OnBnClickedForm();
};
