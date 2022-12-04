#pragma once

#if !defined(__CMYFRAMEWND_H_)
#define __CMYFRAMEWND_H_

#include "pch.h"

#include "CMyApp.h"

class CMyFrameWnd :
    public CFrameWnd
{
public:

    class CMyApp* m_pApp;
    class CMySmallWnd* m_pSmallWnd;

    BOOL m_bVisible = TRUE;

    CFont m_Font;

    CMyFrameWnd(class CMyApp* pApp);

    virtual ~CMyFrameWnd();

    DECLARE_MESSAGE_MAP()
        afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
        afx_msg void OnPaint();
        afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
        afx_msg void OnMove(int x, int y);
        afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

class CMySmallWnd :
    public CFrameWnd
{
public:

    class CMyFrameWnd* m_pFrameWnd;

    BOOL m_bVisible = FALSE;

    CMySmallWnd(class CMyFrameWnd* m_pFrameWnd);

    virtual ~CMySmallWnd() {}

    DECLARE_MESSAGE_MAP()
        afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
        afx_msg void OnMove(int x, int y);
        afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
        afx_msg void OnPaint();
};


#endif