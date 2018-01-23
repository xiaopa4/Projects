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
//	// TODO:  �ڴ���ӿؼ�֪ͨ����������
//
//
//}


void CColorBtn::OnBnClicked()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	 CColorDialog  m_setClrDlg;
	// CC_RGBINIT�������ϴ�ѡ�����ɫ��Ϊ��ʼ��ɫ��ʾ����
	 m_setClrDlg.m_cc.Flags |= CC_FULLOPEN | CC_RGBINIT;
	//��¼�ϴ�ѡ�����ɫ
	 m_setClrDlg.m_cc.rgbResult = m_bgColor;        
	 if (IDOK == m_setClrDlg.DoModal())
		 {
		 // �����û�ѡ�����ɫ
			 m_bgColor = m_setClrDlg.m_cc.rgbResult;          
		 }
	 SetBGColor(m_bgColor);

}


void CColorBtn::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{

	// TODO:  ������Ĵ����Ի���ָ����

	CDC *pDC = CDC::FromHandle(lpDrawItemStruct->hDC);
	// ����ť����ɫ
	CBrush cb;
	cb.CreateSolidBrush(GetBGColor());
	CRect rc = lpDrawItemStruct->rcItem;
	pDC->FillRect(&rc, &cb);

	// ����ť�߿�
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