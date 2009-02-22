// ComponentSelector.cpp : implementation file
//

#include "stdafx.h"
#include "dotNetInstaller.h"
#include "ComponentSelector.h"
#include ".\componentselector.h"


// CComponentSelector dialog

IMPLEMENT_DYNAMIC(CComponentSelector, CDialog)
CComponentSelector::CComponentSelector(installerSetting * p_Setting, CWnd* pParent /*=NULL*/)
	: CDialog(CComponentSelector::IDD, pParent)
{
	m_Settings = p_Setting;
}

CComponentSelector::~CComponentSelector()
{
}

void CComponentSelector::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LISTCOMPONENTS, m_List);
	DDX_Control(pDX, IDOK, m_btnOK);
	DDX_Control(pDX, IDCANCEL, m_btnCancel);
	DDX_Control(pDX, IDC_DESCRIPTIONSELECTOR, m_lblMessage);
}


BEGIN_MESSAGE_MAP(CComponentSelector, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()


// CComponentSelector message handlers


BOOL CComponentSelector::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetWindowText(m_Settings->dialog_selector_caption);
	m_btnCancel.SetWindowText(m_Settings->dialog_selector_cancel);
	m_btnOK.SetWindowText(m_Settings->dialog_selector_ok);
	m_lblMessage.SetWindowText(m_Settings->dialog_selector_message);

	int hScrollWidth = 0;
	CDC *pDC = m_List.GetDC();
	ASSERT(pDC);

	//Populate the list of components
	for (size_t i = 0; i < m_Settings->components.size();i++)
	{
		CString l_descr = m_Settings->components[i]->description;
		if (m_Settings->components[i]->IsInstalled())
		{
			l_descr += " ";
			l_descr += m_Settings->status_installed;
		}
		else
		{
			l_descr += " ";
			l_descr += m_Settings->status_notinstalled;
		}
		m_List.AddString(l_descr);
		 
		CSize size = pDC->GetTextExtent(l_descr);	

		if ((size.cx > 0) && (hScrollWidth < size.cx))
			hScrollWidth = size.cx;

		if (m_Settings->components[i]->selected)
			m_List.SetCheck((int)i, 1);
	}
	
	if (hScrollWidth > 0 )
		m_List.SetHorizontalExtent(hScrollWidth);

	m_List.ReleaseDC(pDC); 

	return TRUE;
}

void CComponentSelector::OnBnClickedOk()
{
	//Populate the list of components
	for (size_t i = 0; i < m_Settings->components.size();i++)
	{
		if (m_List.GetCheck((int)i) == 1)
			m_Settings->components[i]->selected = true;
		else
			m_Settings->components[i]->selected = false;
	}

	OnOK();
}
