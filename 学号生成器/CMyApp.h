#pragma once

#if !defined(__CMYAPP_H_)
#define __CMYAPP_H_

#include "pch.h"

#include "CMyFrameWnd.h"
#include "CMyButton.h"
#include "CMyEdit.h"

#define IDC_BUTTON1 1U
#define IDC_BUTTON2 2U
#define IDC_BUTTON3 3U
#define IDC_BUTTON4 4U
#define IDC_BUTTON5 5U
#define IDC_BUTTON6 6U
#define IDC_BUTTON7 7U
#define IDC_BUTTON8 8U
#define IDC_BUTTON9 9U
#define IDC_BUTTON0 10U
#define IDC_BUTTONBACK 11U
#define IDC_BUTTONOK   12U
#define IDC_BUTTONGEN  13U
#define IDC_BUTTONSET  14U

#define IDC_INPUTEDIT  20U
#define IDC_OUTPUTEDIT 21U



class CMyApp :
    public CWinApp
{
public:
    class CMyButton* m_pButton1;
    class CMyButton* m_pButton2;
    class CMyButton* m_pButton3;
    class CMyButton* m_pButton4;
    class CMyButton* m_pButton5;
    class CMyButton* m_pButton6;
    class CMyButton* m_pButton7;
    class CMyButton* m_pButton8;
    class CMyButton* m_pButton9;
    class CMyButton* m_pButton0;
    class CMyButton* m_pButtonBack;
    class CMyButton* m_pButtonGen;

    class CMySwitchButton* m_pButtonOK;
    class CMySwitchButton* m_pButtonSet;

    class CMyEdit* m_pInputEdit;
    class CMyEdit* m_pOutputEdit;

    HICON m_hIcon;

    int iData = 0;
    CString strData;

    int iRes = 0;
    CString strRes;

    std::default_random_engine random_engine;
    std::vector<bool> vSet;

    virtual BOOL InitInstance(void);

    virtual ~CMyApp();


    DECLARE_MESSAGE_MAP()
        afx_msg void OnButton1Clicked(void);
        afx_msg void OnButton2Clicked(void);
        afx_msg void OnButton3Clicked(void);
        afx_msg void OnButton4Clicked(void);
        afx_msg void OnButton5Clicked(void);
        afx_msg void OnButton6Clicked(void);
        afx_msg void OnButton7Clicked(void);
        afx_msg void OnButton8Clicked(void);
        afx_msg void OnButton9Clicked(void);
        afx_msg void OnButton0Clicked(void);
        afx_msg void OnButtonBackClicked(void);
        afx_msg void OnButtonGenClicked(void);
        afx_msg void OnButtonOKClicked(void);
        afx_msg void OnButtonSetClicked(void);
};



#endif