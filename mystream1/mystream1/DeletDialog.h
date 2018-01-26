/***************************************************************************
* Copyright (c) 2017, AEC, All rights reserved.
*
* 文件名称： 流媒体管理器
* 摘 要： 头文件
* 作 者： 张育斌
*
* 修改记录：
*[日期][作者/修改者] [修改原因]
***************************************************************************/
#pragma once


// CDeletDialog 对话框

class CDeletDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CDeletDialog)

public:
	CDeletDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDeletDialog();

// 对话框数据
	enum { IDD = IDD_DELET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
