#include "pch.h"
#include "CMyButton.h"

CMyButton::CMyButton(LPCTSTR lpszCaption, DWORD dwStyle, const RECT& rect, int nFontSize, CWnd* pParentWnd, UINT nID)
	: CButton()
{
	Create(lpszCaption, dwStyle, rect, pParentWnd, nID);
    m_cfFont.CreateFont(nFontSize, 0, 0, 0, 400, FALSE, FALSE, FALSE,
        DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
        PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("Segoe UI"));
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
