#include "pch.h"
#include "CMyFrameWnd.h"

BEGIN_MESSAGE_MAP(CMyFrameWnd, CFrameWnd)
	ON_WM_KEYDOWN()
	ON_WM_PAINT()
END_MESSAGE_MAP()

CMyFrameWnd::CMyFrameWnd(class CMyApp* pApp)
{
	Create(NULL, TEXT("学号生成器"), (WS_SYSMENU | WS_MINIMIZEBOX),
		CRect(CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT + 510, CW_USEDEFAULT + 250));

	RECT rect;
	GetClientRect(&rect);
	SetWindowPos(
		this, NULL, NULL, 
		510 * 2 - (rect.right - rect.left), 
		250 * 2 - (rect.bottom - rect.top),
		(SWP_NOMOVE | SWP_NOREDRAW | SWP_NOZORDER)
	);


	m_Font.CreateFont(FONT_SIZE, 0, 0, 0, 400, FALSE, FALSE, FALSE,
		DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
		PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("Segoe UI"));

	m_pApp = pApp;
}

CMyFrameWnd::~CMyFrameWnd()
{
	m_Font.DeleteObject();
}

void CMyFrameWnd::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if(m_pApp->m_pButtonOK->m_bState)
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

	CFrameWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CMyFrameWnd::OnPaint()
{
	CPaintDC dc(this);
	dc.SelectObject(m_Font);
	dc.SetBkMode(TRANSPARENT);
	dc.DrawText(TEXT("人数:"), -1, CRect(20, 10, 100, 60),  (DT_SINGLELINE | DT_VCENTER));
	dc.DrawText(TEXT("结果:"), -1, CRect(20, 90, 100, 140), (DT_SINGLELINE | DT_VCENTER));
	dc.DrawText(TEXT("允许重复抽取:"), -1, CRect(20, 170, 180, 220), (DT_SINGLELINE | DT_VCENTER));
}
