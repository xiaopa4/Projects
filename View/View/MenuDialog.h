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
	CEdit m_ctrTitle;
	CString m_strTitle;
	CSliderCtrl m_ctrSilder;
	int m_nSilder;
	CEdit m_ctrWidth;
	int m_nWidth;
	CEdit m_ctrPath;
//	CButton m_ctrColor;
//	CString m_strPath;
	CString m_strPath;
	virtual BOOL OnInitDialog();
	//��ʾ��
	CToolTipCtrl m_ctrTT;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CColorBtn m_colColor;
	//afx_msg void OnNMCustomdrawSlider(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	int m_nX;
	afx_msg void OnBnClickedBrowse();
	afx_msg void OnEnChangeWidth();
	CString fileName;
};
