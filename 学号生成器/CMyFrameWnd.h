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

    CFont m_Font;

    CMyFrameWnd(class CMyApp* pApp);

    virtual ~CMyFrameWnd();

    DECLARE_MESSAGE_MAP()
        afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
    afx_msg void OnPaint();
};


#endif