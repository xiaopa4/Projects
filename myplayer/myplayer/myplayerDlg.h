
// myplayerDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
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
	CComboBox m_CB_Language;
	afx_msg void OnCbnSelchangeCombo();
	afx_msg void OnBnClickedChBosskey();
//	afx_msg void OnBnClickedCheck2();
//	afx_msg void OnBnClickedCheck3();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnNMOutofmemoryHotkey1(NMHDR *pNMHDR, LRESULT *pResult);
//	afx_msg void OnBnClickedCheck4();
//	afx_msg void OnBnClickedCheck5();
//	afx_msg void OnBnClickedRadio1();
//	afx_msg void OnBnClickedRadio2();
//	afx_msg void OnBnClickedRadio3();
	// �޸��� ���š�����ѡ���Ӧ�ð�ť
	afx_msg void OnClickItem(UINT nID);
	afx_msg void OnHotkeyChange();
	BOOL LoadConfig();// ��������
	BOOL SaveConfig();// ��������
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedApply();
	CButton m_BossKey;
};
