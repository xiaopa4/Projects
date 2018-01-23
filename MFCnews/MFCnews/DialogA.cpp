// DialogA.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCnews.h"
#include "DialogA.h"
#include "DialogB.h"
#include "afxdialogex.h"


// CDialogA 对话框

IMPLEMENT_DYNAMIC(CDialogA, CDialogEx)

CDialogA::CDialogA(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialogA::IDD, pParent)
	, m_strMlist(_T(""))
	, m_strTiplist(_T(""))
	, m_Edit_Time(666)
{

}

CDialogA::~CDialogA()
{
}

void CDialogA::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MESSAGE_LIST, m_MList);
	DDX_LBString(pDX, IDC_MESSAGE_LIST, m_strMlist);
	DDX_Control(pDX, IDC_TIPS_LIST, m_Tiplist);
	DDX_LBString(pDX, IDC_TIPS_LIST, m_strTiplist);
	//  DDX_Text(pDX, IDC_EDIT1, m_Edit_Time);
	DDX_Text(pDX, IDC_EDIT1, m_Edit_Time);
	DDV_MinMaxInt(pDX, m_Edit_Time, 500, 30000);
}


BEGIN_MESSAGE_MAP(CDialogA, CDialogEx)
	ON_MESSAGE(WM_MY_MESSAGE, OnMyMessage)
	ON_BN_CLICKED(IDC_ADD, &CDialogA::OnClickedAdd)
	ON_LBN_SELCHANGE(IDC_MESSAGE_LIST, &CDialogA::OnLbnSelchangeMessageList)
	ON_BN_CLICKED(IDC_MINUS, &CDialogA::OnBnClickedMinus)
	ON_BN_CLICKED(IDC_RIGHT, &CDialogA::OnBnClickedRight)
	ON_BN_CLICKED(IDC_LEFT, &CDialogA::OnBnClickedLeft)
	ON_BN_CLICKED(IDC_RIGHTSHIFT, &CDialogA::OnBnClickedRightshift)
	ON_BN_CLICKED(IDC_LEFTSHIFT, &CDialogA::OnBnClickedLeftshift)
	ON_BN_CLICKED(IDC_UP, &CDialogA::OnBnClickedUp)
	ON_BN_CLICKED(IDC_DOWN, &CDialogA::OnBnClickedDown)
	ON_BN_CLICKED(IDC_OK, &CDialogA::OnBnClickedOk)
	ON_BN_CLICKED(IDC_Cancel, &CDialogA::OnBnClickedCancel)
	ON_EN_CHANGE(IDC_EDIT1, &CDialogA::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CDialogA 消息处理程序

LRESULT  CDialogA::OnMyMessage(WPARAM wParam, LPARAM lParam)
{
	// TODO: 处理用户自定义消息 

	m_MList.AddString(m_DlgB.m_strName);
	v_strName.push_back(m_DlgB.m_strName);
	v_strContent.push_back(m_DlgB.m_strContent);
	//MessageBox("消息传递完成!");  
	return 0;
}

void CDialogA::OnClickedAdd()
{
	// TODO:  在此添加控件通知处理程序代码

	
	m_DlgB.DoModal();//用来显示一个模式对话框

}


void CDialogA::OnLbnSelchangeMessageList()
{
	// TODO:  在此添加控件通知处理程序代码

}


BOOL CDialogA::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	//容器中存储信息名称的总个数
	vector<int>::size_type i_NameNum = v_strName.size();
	//容器中存储显示信息名称的个数
	vector<int>::size_type i_ShowNum = v_strShow.size();
	CString str;
	if (i_NameNum == 0)
	{
		return 0;
	}
	else
	{
		//消息列表框中初始化
		if (i_ShowNum == 0)
		{
			static vector<int>::size_type i;
			for (i = 0; i < i_NameNum; i++)
			{
				m_MList.InsertString(i, v_strName[i]);
			}
		}
		else
		{
			//把要显示的数据传入提示列表中进行初始化
			static vector<int>::size_type j;
			for (j = 0; j < i_ShowNum; j++)
			{
				m_Tiplist.InsertString(j, v_strShow[j]);
				
			
			}
			//把其他消息传入消息列表中进行初始化
			static vector<int>::size_type m;
			static vector<int>::size_type n;
			int k = 0;
			for (m = 0; m < i_NameNum; m++)
			{
				//判断要显示的消息与消息名称是否相同，若不同则把消息名称添加到消息列表中
				bool flats = true;
				for (n = 0; n < i_ShowNum; n++)
				{
					if (v_strName[m] == v_strShow[n])
					{
						flats = false;
					}
				}
				if (flats == true)
				{
					m_MList.InsertString(k++, v_strName[m]);
				}

			}
		}
	}
	
	//保存初始记录
	
	for (unsigned int m = 0; m < v_strName.size(); m++)
	{
		str = v_strName[m];
		v_strReName.push_back(str);
		str = v_strContent[m];
		v_strReContent.push_back(str);
	}
	//消息总数
	v_nNums = v_strName.size();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void CDialogA::OnBnClickedMinus()
{
	// TODO:  在此添加控件通知处理程序代码

	if (m_MList.GetCurSel() >= 0)
	{
		m_MList.GetText(m_MList.GetCurSel(), m_strMlist);
		m_MList.DeleteString(m_MList.GetCurSel());
		//删除后重新存放消息
		vector<int>::size_type i;
		for (i = 0; i < v_strName.size(); i++)
		{
			if (m_strMlist == v_strName[i])
			{
				//擦除存储容器的消息
				v_strName.erase(v_strName.begin() + i);
				v_strContent.erase(v_strContent.begin() + i);
				//擦除新建容器的消息
				m_DlgB.v_Mnamestr.erase(m_DlgB.v_Mnamestr.begin() + i);
			}
		}

	}
	else
	{
		MessageBox(_T("请选择删除项！"));
	}
	m_strMlist = _T("");
}


void CDialogA::OnBnClickedRight()
{
	// TODO:  在此添加控件通知处理程序代码

	UpdateData(true);
	if (m_strMlist == _T(""))
	{
		MessageBox(_T("请选择转移项！"));
	}
	else
	{
		m_Tiplist.AddString(m_strMlist);
		m_MList.DeleteString(m_MList.GetCurSel());
	}
}


void CDialogA::OnBnClickedLeft()
{
	// TODO:  在此添加控件通知处理程序代码

	UpdateData(true);
	if (m_strTiplist == _T(""))
	{
		MessageBox(_T("请选择转移项！"));
	}
	else
	{
		m_MList.AddString(m_strTiplist);
		m_Tiplist.DeleteString(m_Tiplist.GetCurSel());
	}
}


void CDialogA::OnBnClickedRightshift()
{
	// TODO:  在此添加控件通知处理程序代码

	unsigned int m;
	unsigned int n =  m_MList.GetCount();
	for ( m=0; m < n; n--)
	{
		m_MList.GetText(m, m_strMlist);
		m_Tiplist.AddString(m_strMlist);
		m_MList.DeleteString(m);
	}

}

//全部左移
void CDialogA::OnBnClickedLeftshift()
{
	// TODO:  在此添加控件通知处理程序代码

	unsigned int m;
	unsigned int n = m_Tiplist.GetCount();
	for ( m=0; m < n; n--)
	{
		m_Tiplist.GetText(m, m_strTiplist);
		m_MList.AddString(m_strTiplist);
		m_Tiplist.DeleteString(m);
	}
}


void CDialogA::OnBnClickedUp()
{
	// TODO:  在此添加控件通知处理程序代码

	UpdateData(true);
	int i = m_Tiplist.GetCurSel();
	if (m_strTiplist == _T(""))
	{
		MessageBox(_T("请选择上移项！"));
	}
	else
	{
		if (m_Tiplist.GetCurSel() == 0)
		{
			MessageBox(_T("已经是最顶层！"));
		} 
		else
		{
			//m_Tiplist.GetText(m_Tiplist.GetCurSel() - 1, m_strTiplist);
			m_Tiplist.InsertString(m_Tiplist.GetCurSel() - 1, m_strTiplist);
			m_Tiplist.DeleteString(i+1);
		}
		
	}
	m_strTiplist = _T("");
}


void CDialogA::OnBnClickedDown()
{
	// TODO:  在此添加控件通知处理程序代码

	UpdateData(true);
	int i = m_Tiplist.GetCurSel();
	if (m_strTiplist == _T(""))
	{
		MessageBox(_T("请选择下移项！"));
	}
	else
	{
		if (m_Tiplist.GetCurSel() == m_Tiplist.GetCurSel() - 1)
		{
			MessageBox(_T("已经是最底层！"));
		}
		else
		{
			m_Tiplist.InsertString(m_Tiplist.GetCurSel() + 2, m_strTiplist);
			m_Tiplist.DeleteString(i);
		}

	}
	m_strTiplist = _T("");
}


void CDialogA::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码

	v_strShow.clear();
			CString str;
			int ShowNums = m_Tiplist.GetCount();
			for (int i = 0; i < ShowNums; ShowNums--)
			{
				m_Tiplist.GetText(i, str);
				v_strShow.push_back(str);
				m_Tiplist.DeleteString(i);
			}
			UpdateData(true);
			this->GetParent()->SendMessage(WM_MY_TIPMESSAGE, 0, 0);
			v_strReName.clear();
			v_strReContent.clear();
			v_strShow.clear();
		
			OnOK();
}


void CDialogA::OnBnClickedCancel()
{
	// TODO:  在此添加控件通知处理程序代码

		CString str;
		unsigned int i;
		if (v_nNums != v_strName.size())
		{
			bool flats = 0;
			for (i = 0; i < v_strName.size(); i++)
			{
				if (v_strName[i] != v_strReName[i])
				{
					flats = 1;
					break;
				}
			}
			if (flats == 1)
			{
				v_strName.clear();
				v_strContent.clear();
				m_DlgB.v_Mnamestr.clear();
				for (i = 0; i < v_strReName.size(); i++)
				{
					str = v_strReName[i];
					v_strName.push_back(str);
					m_DlgB.v_Mnamestr.push_back(str);
					str = v_strReContent[i];
					v_strContent.push_back(str);
	
				}
			}
		}
		else
		{
	
			v_strName.clear();
			v_strContent.clear();
			m_DlgB.v_Mnamestr.clear();
	
			for (i = 0; i < v_strReName.size(); i++)
			{
				str = v_strReName[i];
				v_strName.push_back(str);
				m_DlgB.v_Mnamestr.push_back(str);
				str = v_strReContent[i];
				v_strContent.push_back(str);
	
			}
			
		}
	
	
	
			UpdateData(true);
			this->GetParent()->SendMessage(WM_MY_TIPMESSAGE, 0, 0);
			v_strReName.clear();
			v_strReContent.clear();
			v_strShow.clear();
	
	
			OnCancel();
}


void CDialogA::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	m_nTime = GetDlgItemInt(IDC_EDIT1);

}
