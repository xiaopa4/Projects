#pragma once


// CPropetypage2 �Ի���

class CPropetypage2 : public CDialogEx
{
	DECLARE_DYNAMIC(CPropetypage2)

public:
	CPropetypage2(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPropetypage2();

// �Ի�������
	enum { IDD = IDD_PROPETYPAGE2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
