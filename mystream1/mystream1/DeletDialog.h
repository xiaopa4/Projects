#pragma once


// CDeletDialog �Ի���

class CDeletDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CDeletDialog)

public:
	CDeletDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDeletDialog();

// �Ի�������
	enum { IDD = IDD_DELET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
