
// MFCnews.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCnewsApp: 
// �йش����ʵ�֣������ MFCnews.cpp
//

class CMFCnewsApp : public CWinApp
{
public:
	CMFCnewsApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCnewsApp theApp;