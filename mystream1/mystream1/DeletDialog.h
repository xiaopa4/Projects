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
