
/***************************************************************************
* Copyright (c) 2017, AEC, All rights reserved.
*
* �ļ����ƣ� ��ɫʰȡ��
* ժ Ҫ�� ͷ�ļ�
* �� �ߣ� ������
*
* �޸ļ�¼��
*[����][����/�޸���] [�޸�ԭ��]
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
	//�Ի水ť
	virtual void DrawItem(LPDRAWITEMSTRUCT /*lpDrawItemStruct*/);
	COLORREF GetBGColor();
	bool SetBGColor(COLORREF bgColor);
public:
	COLORREF m_bgColor;
};

