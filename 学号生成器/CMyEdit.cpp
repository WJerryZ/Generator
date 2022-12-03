#include "pch.h"
#include "CMyEdit.h"

BEGIN_MESSAGE_MAP(CMyEdit, CEdit)
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

CMyEdit::CMyEdit(DWORD dwStyle, const RECT& rect, class CMyFrameWnd* pParentWnd, UINT nID)
{
	Create(dwStyle, rect, pParentWnd, nID);
	m_Font.CreatePointFont(120, TEXT("Segoe UI"), NULL);
	SetFont(&m_Font);
	m_pApp = pParentWnd->m_pApp;
}

CMyEdit::~CMyEdit()
{
	m_Font.DeleteObject();
}

void CMyEdit::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (m_pApp->m_pButtonOK->m_bState)
		if (nChar >= '0' && nChar <= '9')
		{
			if (m_pApp->iData < 1000)
			{
				m_pApp->iData = m_pApp->iData * 10 + (nChar - '0');
				m_pApp->strData.Format(TEXT("%d"), m_pApp->iData);
				m_pApp->m_pInputEdit->SetWindowText(m_pApp->strData);
			}
		}
		else if (nChar == VK_BACK)
		{
			if (m_pApp->iData < 10)
			{
				m_pApp->iData = 0;
				m_pApp->strData.Empty();
			}
			else
			{
				m_pApp->iData /= 10;
				m_pApp->strData.Format(TEXT("%d"), m_pApp->iData);
			}
			m_pApp->m_pInputEdit->SetWindowText(m_pApp->strData);
		}

	CEdit::OnKeyDown(nChar, nRepCnt, nFlags);
}
