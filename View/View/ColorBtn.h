
/***************************************************************************
* Copyright (c) 2017, AEC, All rights reserved.
*
* 文件名称： 颜色拾取器
* 摘 要： 头文件
* 作 者： 张育斌
*
* 修改记录：
*[日期][作者/修改者] [修改原因]
***************************************************************************/
#pragma once
#include "afxwin.h"

class CColorBtn :
	public CButton
{
public:
	CColorBtn();
	~CColorBtn();
	DECLARE_MESSAGE_MAP()
	//afx_msg void OnBnClickedColor();
	afx_msg void OnBnClicked();
	//自绘按钮
	virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
	COLORREF GetBGColor();
	bool SetBGColor(COLORREF bgColor);
public:
	COLORREF m_bgColor;
};

