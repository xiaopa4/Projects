#pragma once


// CPropetypage2 对话框

class CPropetypage2 : public CDialogEx
{
	DECLARE_DYNAMIC(CPropetypage2)

public:
	CPropetypage2(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPropetypage2();

// 对话框数据
	enum { IDD = IDD_PROPETYPAGE2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
