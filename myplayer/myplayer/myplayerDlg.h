/***************************************************************************
* Copyright (c) 2017, AEC, All rights reserved.
*
* 文件名称： 播放器的设置
* 摘 要： 头文件
* 作 者： 张育斌
*
* 修改记录：
*[日期][作者/修改者] [修改原因]
***************************************************************************/
// myplayerDlg.h : 头文件
//

#pragma once
#include "afxwin.h"		// 引用标准库的头文件
//	自定义消息
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
	//语言栏
	CComboBox m_CB_Language;
	//判断语言栏时候改变
	afx_msg void OnCbnSelchangeCombo();
	//判断老板键时候按下
	afx_msg void OnBnClickedChBosskey();
	//时长编辑框是否改变
	afx_msg void OnEnChangeEdit1();
	//立即检测
	afx_msg void OnBnClickedButton1();
	//内存溢出处理函数
	afx_msg void OnNMOutofmemoryHotkey1(NMHDR *pNMHDR, LRESULT *pResult);
	// 修改了 播放、升级选项激活应用按钮
	afx_msg void OnClickItem(UINT nID);
	//自定义热键框处理函数
	afx_msg void OnHotkeyChange();
	// 加载配置
	BOOL LoadConfig();
	// 保存配置
	BOOL SaveConfig();
	//确定
	afx_msg void OnBnClickedOk();
	//取消
	afx_msg void OnBnClickedCancel();
	//应用
	afx_msg void OnBnClickedApply();
	//老板键
	CButton m_BossKey;
};
