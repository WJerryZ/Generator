#include "pch.h"
#include "CMyFrameWnd.h"



//// class CMyFrameWnd : public CFrameWnd

BEGIN_MESSAGE_MAP(CMyFrameWnd, CFrameWnd)
	ON_WM_KEYDOWN()
	ON_WM_PAINT()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	ON_WM_NCLBUTTONDBLCLK()
END_MESSAGE_MAP()

CMyFrameWnd::CMyFrameWnd(class CMyApp* pApp) 
	: m_pApp(pApp)
{
	Create(NULL, TEXT("学号生成器"), WS_SYSMENU, 

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

	m_pSmallWnd = new CMySmallWnd(this);
	m_pSmallWnd->SetIcon(GetIcon(FALSE), FALSE);
}

CMyFrameWnd::~CMyFrameWnd()
{
	m_Font.DeleteObject();
	delete m_pSmallWnd;
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
	dc.DrawText(TEXT("人数:"), -1, CRect(20, 10, 110, 60),  (DT_SINGLELINE | DT_VCENTER));
	dc.DrawText(TEXT("结果:"), -1, CRect(20, 90, 110, 140), (DT_SINGLELINE | DT_VCENTER));
	dc.DrawText(TEXT("允许重复抽取:"), -1, CRect(20, 170, 230, 220), (DT_SINGLELINE | DT_VCENTER));
}

void CMyFrameWnd::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	m_bVisible = FALSE;
	m_pSmallWnd->m_bVisible = TRUE;

	ShowWindow(SW_HIDE);
	UpdateWindow();

	RECT rect;
	GetWindowRect(&rect);
	m_pSmallWnd->SetWindowPos(m_pSmallWnd, rect.left, rect.top, 0, 0, (SWP_NOSIZE | SWP_NOZORDER | SWP_NOREDRAW));

	m_pSmallWnd->ShowWindow(SW_NORMAL);
	m_pSmallWnd->UpdateWindow();

	CFrameWnd::OnLButtonDblClk(nFlags, point);
}


void CMyFrameWnd::OnLButtonDown(UINT nFlags, CPoint point)
{
	CFrameWnd::OnLButtonDown(nFlags, point);
	PostMessage(WM_NCLBUTTONDOWN, HTCAPTION, MAKELPARAM(point.x, point.y));
}


void CMyFrameWnd::OnNcLButtonDblClk(UINT nHitTest, CPoint point)
{
	CFrameWnd::OnNcLButtonDblClk(nHitTest, point);
	PostMessage(WM_LBUTTONDBLCLK, HTCLIENT, MAKELPARAM(point.x, point.y));
}




//// class CMySmallWnd : public CFrameWnd

BEGIN_MESSAGE_MAP(CMySmallWnd, CFrameWnd)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
END_MESSAGE_MAP()

CMySmallWnd::CMySmallWnd(CMyFrameWnd* pFrameWnd)
	: m_pFrameWnd(pFrameWnd)
{
	Create(NULL, TEXT("悬浮窗"), WS_POPUP, CRect(0, 0, 64, 64));
	ModifyStyleEx(WS_EX_APPWINDOW, WS_EX_TOOLWINDOW);

	::SetWindowPos(
		m_hWnd, HWND_TOPMOST, 0, 0, 0, 0,
		(SWP_NOMOVE | SWP_NOSIZE | SWP_NOREDRAW)
	);

	::SetWindowLong(GetSafeHwnd(), GWL_EXSTYLE, ::GetWindowLongPtr(GetSafeHwnd(), GWL_EXSTYLE) | WS_EX_LAYERED);
	SetLayeredWindowAttributes(0, (255 * 60) / 100, LWA_ALPHA);
}

void CMySmallWnd::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	m_bVisible = FALSE;
	m_pFrameWnd->m_bVisible = TRUE;

	ShowWindow(SW_HIDE);
	UpdateWindow();

	RECT rect;
	GetWindowRect(&rect);
	m_pFrameWnd->SetWindowPos(m_pFrameWnd, rect.left, rect.top, 0, 0, (SWP_NOSIZE | SWP_NOZORDER | SWP_NOREDRAW));

	m_pFrameWnd->ShowWindow(SW_NORMAL);
	m_pFrameWnd->UpdateWindow();

	CFrameWnd::OnLButtonDblClk(nFlags, point);
}

void CMySmallWnd::OnLButtonDown(UINT nFlags, CPoint point)
{
	CFrameWnd::OnLButtonDown(nFlags, point);
	PostMessage(WM_NCLBUTTONDOWN, HTCAPTION, MAKELPARAM(point.x, point.y));
}


void CMySmallWnd::OnPaint()
{
	CPaintDC dc(this);
	dc.SetBkMode(TRANSPARENT);
	::DrawIconEx(dc.GetSafeHdc(), 5, 5, m_pFrameWnd->m_pApp->m_hIcon, 52, 52, 0, NULL, DI_NORMAL | DI_COMPAT);
}
