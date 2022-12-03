#include "pch.h"
#include "CMyButton.h"

CMyButton::CMyButton(LPCTSTR lpszCaption, DWORD dwStyle, const RECT& rect, int nPointSize, CWnd* pParentWnd, UINT nID)
	: CButton()
{
	Create(lpszCaption, dwStyle, rect, pParentWnd, nID);
	m_cfFont.CreatePointFont(nPointSize, TEXT("Segoe UI"), NULL);
	SetFont(&m_cfFont);
}

CMyButton::~CMyButton()
{
    m_cfFont.DeleteObject();
}

void CMySwitchButton::Switch(LPCWSTR lpTrueStateStr, LPCWSTR lpFalseStateStr)
{
    if (m_bState)
    {
        m_bState = FALSE;
        SetWindowText(lpFalseStateStr);
    }
    else
    {
        m_bState = TRUE;
        SetWindowText(lpTrueStateStr);
    }
}
