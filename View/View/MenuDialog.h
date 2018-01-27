/***************************************************************************
* Copyright (c) 2017, AEC, All rights reserved.
*
* 文件名称： 画面属性对话框
* 摘 要： 头文件
* 作 者： 张育斌
*
* 修改记录：
*[日期][作者/修改者] [修改原因]
***************************************************************************/
#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "resource.h"
#include "ColorBtn.h"

// CMenuDialog 对话框

class CMenuDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CMenuDialog)

public:
	CMenuDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMenuDialog();

// 对话框数据
	enum { IDD = IDD_MENUSETTING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	//画面标题
	CEdit m_ctrTitle;
	CString m_strTitle;
	//滚动条
	CSliderCtrl m_ctrSilder;
	int m_nSilder;
	//宽度
	CEdit m_ctrWidth;
	int m_nWidth;
	afx_msg void OnEnChangeWidth();
	//图片地址
	CEdit m_ctrPath;
	CString m_strPath;
	virtual BOOL OnInitDialog();
	//提示条
	CToolTipCtrl m_ctrTT;
	//处理提示条
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//按钮颜色
	CColorBtn m_colColor;
	//当用户单击窗口的水平滚动条记录时，框架调用该成员函数
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//int m_nX;
	//浏览
	afx_msg void OnBnClickedBrowse();
	//图片路径
	CString fileName;
};
