/***************************************************************************
* Copyright (c) 2017, AEC, All rights reserved.
*
* �ļ����ƣ� ������������
* ժ Ҫ�� ͷ�ļ�
* �� �ߣ� ������
*
* �޸ļ�¼��
*[����][����/�޸���] [�޸�ԭ��]
***************************************************************************/
// myplayerDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"		// ���ñ�׼���ͷ�ļ�
//	�Զ�����Ϣ
#define NM_CHANGE   (WM_USER+100)

// CmyplayerDlg �Ի���
class CmyplayerDlg : public CDialogEx
{
	TCHAR m_strIniPath[MAX_PATH];
	struct ST_CONFIG
	{
		int iLanguage;	// ����
		WORD iBossKey;	// �ϰ��
		UINT iHotKey;	// �ȼ�

		int iPS;			// ������š���ͣ
		int iOnlyEnable;		// ֻ�г��ɲ��ŵ�
		int iAutoStop;		// �Զ���ͣ
		int iAutoFit;		// ������Ӧ��Ƶ
		int iStepTime;		// ����ʱ��

		int iUpdate;	// ����ѡ��
	}m_stConfig;
// ����
public:
	CmyplayerDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MYPLAYER_DIALOG };

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
	//������
	CComboBox m_CB_Language;
	//�ж�������ʱ��ı�
	afx_msg void OnCbnSelchangeCombo();
	//�ж��ϰ��ʱ����
	afx_msg void OnBnClickedChBosskey();
	//ʱ���༭���Ƿ�ı�
	afx_msg void OnEnChangeEdit1();
	//�������
	afx_msg void OnBnClickedButton1();
	//�ڴ����������
	afx_msg void OnNMOutofmemoryHotkey1(NMHDR *pNMHDR, LRESULT *pResult);
	// �޸��� ���š�����ѡ���Ӧ�ð�ť
	afx_msg void OnClickItem(UINT nID);
	//�Զ����ȼ�������
	afx_msg void OnHotkeyChange();
	// ��������
	BOOL LoadConfig();
	// ��������
	BOOL SaveConfig();
	//ȷ��
	afx_msg void OnBnClickedOk();
	//ȡ��
	afx_msg void OnBnClickedCancel();
	//Ӧ��
	afx_msg void OnBnClickedApply();
	//�ϰ��
	CButton m_BossKey;
};
