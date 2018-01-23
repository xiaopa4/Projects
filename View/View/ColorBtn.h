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
	//COLORREF m_nColor;
	virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
	COLORREF GetBGColor();
	bool SetBGColor(COLORREF bgColor);
public:
	COLORREF m_bgColor;
};

