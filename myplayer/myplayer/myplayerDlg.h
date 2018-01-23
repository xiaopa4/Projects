
// myplayerDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#define NM_CHANGE   (WM_USER+100)

// CmyplayerDlg 对话框
class CmyplayerDlg : public CDialogEx
{
	TCHAR m_strIniPath[MAX_PATH];
	struct ST_CONFIG
	{
		int iLanguage;	// 语言
		WORD iBossKey;	// 老板键
		UINT iHotKey;	// 热键

		int iPS;			// 点击播放、暂停
		int iOnlyEnable;		// 只列出可播放的
		int iAutoStop;		// 自动暂停
		int iAutoFit;		// 窗口适应视频
		int iStepTime;		// 步进时长

		int iUpdate;	// 升级选项
	}m_stConfig;
// 构造
public:
	CmyplayerDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MYPLAYER_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
	// 修改了 播放、升级选项激活应用按钮
	afx_msg void OnClickItem(UINT nID);
	afx_msg void OnHotkeyChange();
	BOOL LoadConfig();// 加载配置
	BOOL SaveConfig();// 保存配置
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedApply();
	CButton m_BossKey;
};
