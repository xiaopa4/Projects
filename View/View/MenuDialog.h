/***************************************************************************
* Copyright (c) 2017, AEC, All rights reserved.
*
* �ļ����ƣ� �������ԶԻ���
* ժ Ҫ�� ͷ�ļ�
* �� �ߣ� ������
*
* �޸ļ�¼��
*[����][����/�޸���] [�޸�ԭ��]
***************************************************************************/
#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "resource.h"
#include "ColorBtn.h"

// CMenuDialog �Ի���

class CMenuDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CMenuDialog)

public:
	CMenuDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMenuDialog();

// �Ի�������
	enum { IDD = IDD_MENUSETTING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	//�������
	CEdit m_ctrTitle;
	CString m_strTitle;
	//������
	CSliderCtrl m_ctrSilder;
	int m_nSilder;
	//���
	CEdit m_ctrWidth;
	int m_nWidth;
	afx_msg void OnEnChangeWidth();
	//ͼƬ��ַ
	CEdit m_ctrPath;
	CString m_strPath;
	virtual BOOL OnInitDialog();
	//��ʾ��
	CToolTipCtrl m_ctrTT;
	//������ʾ��
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//��ť��ɫ
	CColorBtn m_colColor;
	//���û��������ڵ�ˮƽ��������¼ʱ����ܵ��øó�Ա����
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//int m_nX;
	//���
	afx_msg void OnBnClickedBrowse();
	//ͼƬ·��
	CString fileName;
};
