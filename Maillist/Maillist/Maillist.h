
// Maillist.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMaillistApp: 
// �йش����ʵ�֣������ Maillist.cpp
//

class CMaillistApp : public CWinApp
{
public:
	CMaillistApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMaillistApp theApp;