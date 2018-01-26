/***************************************************************************
* Copyright (c) 2017, AEC, All rights reserved.
*
* 文件名称： 流媒体管理器
* 摘 要： 定义文件
* 作 者： 张育斌
*
* 修改记录：
*[日期][作者/修改者] [修改原因]
***************************************************************************/
#include "stdafx.h"
#include "ColorBtn.h"
#include "MenuDialog.h"

CColorBtn::CColorBtn()
{
	m_bgColor = RGB(0, 0, 255);
}


CColorBtn::~CColorBtn()
{
}
BEGIN_MESSAGE_MAP(CColorBtn, CButton)
	//ON_BN_CLICKED(IDC_COLOR, &CColorBtn::OnBnClickedColor)
	ON_CONTROL_REFLECT(BN_CLICKED, &CColorBtn::OnBnClicked)
END_MESSAGE_MAP()


//void CColorBtn::OnBnClickedColor()
//{
//	// TODO:  在此添加控件通知处理程序代码
//
//
//}

/***************************************************************************
* 函数名称：[OnSize]
* 摘 要： 选项卡标签变化
* 全局影响：
* 参数：NMHDR *pNMHDR, LRESULT *pResult
* 返回值：
*
* 修改记录：
*[日期][作者/修改者] [修改原因]
***************************************************************************/
void CColorBtn::OnBnClicked()
{
	// TODO:  在此添加控件通知处理程序代码

	 CColorDialog  m_setClrDlg;
	// CC_RGBINIT可以让上次选择的颜色作为初始颜色显示出来
	 m_setClrDlg.m_cc.Flags |= CC_FULLOPEN | CC_RGBINIT;
	//记录上次选择的颜色
	 m_setClrDlg.m_cc.rgbResult = m_bgColor;        
	 if (IDOK == m_setClrDlg.DoModal())
		 {
		 // 保存用户选择的颜色
			 m_bgColor = m_setClrDlg.m_cc.rgbResult;          
		 }
	 SetBGColor(m_bgColor);

}


void CColorBtn::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{

	// TODO:  添加您的代码以绘制指定项

	CDC *pDC = CDC::FromHandle(lpDrawItemStruct->hDC);
	// 画按钮背景色
	CBrush cb;
	cb.CreateSolidBrush(GetBGColor());
	CRect rc = lpDrawItemStruct->rcItem;
	pDC->FillRect(&rc, &cb);

	// 画按钮边框
	CBrush cbFrame;
	cbFrame.CreateSolidBrush(RGB(255, 255, 255));
	pDC->FrameRect(&rc, &cbFrame);



}


COLORREF CColorBtn::GetBGColor()
{
	return m_bgColor;
}


bool CColorBtn::SetBGColor(COLORREF bgColor)
{
	m_bgColor = bgColor;
	InvalidateRect(NULL);
	return TRUE;
}