#pragma once

#if !defined(__CMYBUTTON_H_)
#define __CMYBUTTON_H_

#include "pch.h"

class CMyButton :
    public CButton
{
public:

    CFont m_cfFont;

    CMyButton(LPCTSTR lpszCaption, DWORD dwStyle, const RECT& rect, int nPointSize, CWnd* pParentWnd, UINT nID);

    virtual ~CMyButton();
};

class CMySwitchButton
    : public CMyButton
{
public:

    BOOL m_bState = TRUE;

    CMySwitchButton(LPCTSTR lpszCaption, DWORD dwStyle, const RECT& rect, int nPointSize, CWnd* pParentWnd, UINT nID)
        : CMyButton(lpszCaption, dwStyle, rect, nPointSize, pParentWnd, nID) {}

    virtual void Switch(LPCWSTR lpTrueStateStr, LPCWSTR lpFalseStateStr);

    virtual ~CMySwitchButton() {}
};

#endif