#pragma once

#if !defined(__CMYEDIT_H_)
#define __CMYEDIT_H_

#include "pch.h"

#include "CMyFrameWnd.h"

class CMyEdit :
    public CEdit
{
public:

    CFont m_Font;
    class CMyApp* m_pApp;

    CMyEdit(DWORD dwStyle, const RECT& rect, class CMyFrameWnd* pParentWnd, UINT nID);

    virtual ~CMyEdit();
    DECLARE_MESSAGE_MAP()
        afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#endif