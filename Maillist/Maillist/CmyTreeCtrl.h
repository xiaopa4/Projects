/***************************************************************************
* Copyright (c) 2017, AEC, All rights reserved.
*
* 文件名称： 树形控件
* 摘 要： 头文件
* 作 者： 张育斌
*
* 修改记录：
*[日期][作者/修改者] [修改原因]
***************************************************************************/
#pragma once


// CmyTreeCtrl

class CmyTreeCtrl : public CTreeCtrl
{
	DECLARE_DYNAMIC(CmyTreeCtrl)

public:
	CmyTreeCtrl();
	virtual ~CmyTreeCtrl();

protected:
	UINT          m_TimerTicks;      //处理滚动的定时器所经过的时间
	UINT          m_nScrollTimerID;  //处理滚动的定时器
	CPoint        m_HoverPoint;      //鼠标位置
	UINT          m_nHoverTimerID;   //鼠标敏感定时器
	DWORD         m_dwDragStart;     //按下鼠标左键那一刻的时间
	BOOL          m_bDragging;       //标识是否正在拖动过程中
	CImageList*   m_pDragImage;      //拖动时显示的图象列表
	HTREEITEM     m_hItemDragS;      //被拖动的标签
	HTREEITEM     m_hItemDragD;      //接受拖动的标签
	//开始拖拽
	afx_msg void OnBegindrag(NMHDR* pNMHDR, LRESULT* pResult);
	//拖动
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//放下
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	DECLARE_MESSAGE_MAP()
private:
	HTREEITEM CopyBranch(HTREEITEM htiBranch, HTREEITEM htiNewParent, HTREEITEM htiAfter);
	HTREEITEM CopyItem(HTREEITEM hItem, HTREEITEM htiNewParent, HTREEITEM htiAfter);



	
};


