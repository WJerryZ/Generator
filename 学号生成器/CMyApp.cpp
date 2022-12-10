#include "pch.h"
#include "CMyApp.h"

#define WS_MYBUTTON (WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON)

constexpr int X[3] = { 320, 380, 440 };
constexpr int Y[4] = { 10, 70, 130, 190 };
constexpr int W = 50;
constexpr int H = 50;

BEGIN_MESSAGE_MAP(CMyApp, CWinApp)
    ON_BN_CLICKED(IDC_BUTTON1, OnButton1Clicked)
    ON_BN_CLICKED(IDC_BUTTON2, OnButton2Clicked)
    ON_BN_CLICKED(IDC_BUTTON3, OnButton3Clicked)
    ON_BN_CLICKED(IDC_BUTTON4, OnButton4Clicked)
    ON_BN_CLICKED(IDC_BUTTON5, OnButton5Clicked)
    ON_BN_CLICKED(IDC_BUTTON6, OnButton6Clicked)
    ON_BN_CLICKED(IDC_BUTTON7, OnButton7Clicked)
    ON_BN_CLICKED(IDC_BUTTON8, OnButton8Clicked)
    ON_BN_CLICKED(IDC_BUTTON9, OnButton9Clicked)
    ON_BN_CLICKED(IDC_BUTTON0, OnButton0Clicked)
    ON_BN_CLICKED(IDC_BUTTONBACK, OnButtonBackClicked)
    ON_BN_CLICKED(IDC_BUTTONGEN, OnButtonGenClicked)
    ON_BN_CLICKED(IDC_BUTTONOK, OnButtonOKClicked)
    ON_BN_CLICKED(IDC_BUTTONSET, OnButtonSetClicked)
END_MESSAGE_MAP()

BOOL CMyApp::InitInstance(void)
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    m_hIcon = LoadIcon(IDI_ICON1);
    CMyFrameWnd* pWnd = new CMyFrameWnd(this);
    m_pMainWnd = pWnd;
    m_pMainWnd->SetIcon(m_hIcon, FALSE);
    m_pMainWnd->SetIcon(m_hIcon, TRUE);
    m_pMainWnd->ShowWindow(SW_NORMAL);
    m_pMainWnd->UpdateWindow();

    RECT rect;
    int iHeight = GetSystemMetrics(SM_CYFULLSCREEN);
    m_pMainWnd->GetWindowRect(&rect);
    m_pMainWnd->SetWindowPos(
        m_pMainWnd, rect.left, iHeight - rect.top - (rect.bottom - rect.top),
        NULL, NULL, (SWP_NOSIZE | SWP_NOREDRAW | SWP_NOZORDER)
    );

    // 文本框
    {
        m_pInputEdit = new CMyEdit((WS_CHILD | WS_BORDER | WS_VISIBLE | ES_CENTER | ES_NUMBER | ES_READONLY),
            CRect(90, 10, 90 + 100, 10 + 50), pWnd, IDC_INPUTEDIT);

        m_pOutputEdit = new CMyEdit((WS_CHILD | WS_BORDER | WS_VISIBLE | ES_CENTER| ES_NUMBER | ES_READONLY),
            CRect(90, 90, 90 + 100, 90 + 50), pWnd, IDC_OUTPUTEDIT);
    }


    // 数字键
    {
        m_pButton1 = new CMyButton(TEXT("1"), WS_MYBUTTON,
            CRect(X[0], Y[0], X[0] + W, Y[0] + H), FONT_SIZE, m_pMainWnd, IDC_BUTTON1);

        m_pButton2 = new CMyButton(TEXT("2"), WS_MYBUTTON,
            CRect(X[1], Y[0], X[1] + W, Y[0] + H), FONT_SIZE, m_pMainWnd, IDC_BUTTON2);

        m_pButton3 = new CMyButton(TEXT("3"), WS_MYBUTTON,
            CRect(X[2], Y[0], X[2] + W, Y[0] + H), FONT_SIZE, m_pMainWnd, IDC_BUTTON3);

        m_pButton4 = new CMyButton(TEXT("4"), WS_MYBUTTON,
            CRect(X[0], Y[1], X[0] + W, Y[1] + H), FONT_SIZE, m_pMainWnd, IDC_BUTTON4);

        m_pButton5 = new CMyButton(TEXT("5"), WS_MYBUTTON,
            CRect(X[1], Y[1], X[1] + W, Y[1] + H), FONT_SIZE, m_pMainWnd, IDC_BUTTON5);

        m_pButton6 = new CMyButton(TEXT("6"), WS_MYBUTTON,
            CRect(X[2], Y[1], X[2] + W, Y[1] + H), FONT_SIZE, m_pMainWnd, IDC_BUTTON6);

        m_pButton7 = new CMyButton(TEXT("7"), WS_MYBUTTON,
            CRect(X[0], Y[2], X[0] + W, Y[2] + H), FONT_SIZE, m_pMainWnd, IDC_BUTTON7);

        m_pButton8 = new CMyButton(TEXT("8"), WS_MYBUTTON,
            CRect(X[1], Y[2], X[1] + W, Y[2] + H), FONT_SIZE, m_pMainWnd, IDC_BUTTON8);

        m_pButton9 = new CMyButton(TEXT("9"), WS_MYBUTTON,
            CRect(X[2], Y[2], X[2] + W, Y[2] + H), FONT_SIZE, m_pMainWnd, IDC_BUTTON9);

        m_pButton0 = new CMyButton(TEXT("0"), WS_MYBUTTON,
            CRect(X[0], Y[3], X[0] + W, Y[3] + H), FONT_SIZE, m_pMainWnd, IDC_BUTTON0);

        m_pButtonBack = new CMyButton(TEXT("←"), WS_MYBUTTON,
            CRect(X[1], Y[3], X[1] + 110, Y[3] + H), FONT_SIZE, m_pMainWnd, IDC_BUTTONBACK);

        m_pButtonGen = new CMyButton(TEXT("生成"), WS_MYBUTTON | WS_DISABLED,
            CRect(210, 90, 210 + 90, 90 + 50), FONT_SIZE, m_pMainWnd, IDC_BUTTONGEN);

        m_pButtonOK = new CMySwitchButton(TEXT("确定"), WS_MYBUTTON,
            CRect(210, 10, 210 + 90, 10 + 50), FONT_SIZE, m_pMainWnd, IDC_BUTTONOK);

        m_pButtonSet = new CMySwitchButton(TEXT("是"), WS_MYBUTTON,
            CRect(210, 170, 210 + 90, 170 + 50), FONT_SIZE, m_pMainWnd, IDC_BUTTONSET);
    }


    return TRUE;
}

CMyApp::~CMyApp()
{
    delete m_pMainWnd;

    delete m_pButton1;
    delete m_pButton2;
    delete m_pButton3;
    delete m_pButton4;
    delete m_pButton5;
    delete m_pButton6;
    delete m_pButton7;
    delete m_pButton8;
    delete m_pButton9;
    delete m_pButton0;
    delete m_pButtonBack;
    delete m_pButtonGen;

    delete m_pButtonOK;
    delete m_pButtonSet;

    delete m_pInputEdit;
    delete m_pOutputEdit;

    delete m_pDist;
}

void CMyApp::OnButton1Clicked(void)
{
    if (iData < 1000 && m_pButtonOK->m_bState)
    {
        iData = iData * 10 + 1;
        strData.Format(TEXT("%d"), iData);
        m_pInputEdit->SetWindowText(strData);
    }
}

void CMyApp::OnButton2Clicked(void)
{
    if (iData < 1000 && m_pButtonOK->m_bState)
    {
        iData = iData * 10 + 2;
        strData.Format(TEXT("%d"), iData);
        m_pInputEdit->SetWindowText(strData);
    }
}

void CMyApp::OnButton3Clicked(void)
{
    if (iData < 1000 && m_pButtonOK->m_bState)
    {
        iData = iData * 10 + 3;
        strData.Format(TEXT("%d"), iData);
        m_pInputEdit->SetWindowText(strData);
    }
}

void CMyApp::OnButton4Clicked(void)
{
    if (iData < 1000 && m_pButtonOK->m_bState)
    {
        iData = iData * 10 + 4;
        strData.Format(TEXT("%d"), iData);
        m_pInputEdit->SetWindowText(strData);
    }
}

void CMyApp::OnButton5Clicked(void)
{
    if (iData < 1000 && m_pButtonOK->m_bState)
    {
        iData = iData * 10 + 5;
        strData.Format(TEXT("%d"), iData);
        m_pInputEdit->SetWindowText(strData);
    }
}

void CMyApp::OnButton6Clicked(void)
{
    if (iData < 1000 && m_pButtonOK->m_bState)
    {
        iData = iData * 10 + 6;
        strData.Format(TEXT("%d"), iData);
        m_pInputEdit->SetWindowText(strData);
    }
}

void CMyApp::OnButton7Clicked(void)
{
    if (iData < 1000 && m_pButtonOK->m_bState)
    {
        iData = iData * 10 + 7;
        strData.Format(TEXT("%d"), iData);
        m_pInputEdit->SetWindowText(strData);
    }
}

void CMyApp::OnButton8Clicked(void)
{
    if (iData < 1000 && m_pButtonOK->m_bState)
    {
        iData = iData * 10 + 8;
        strData.Format(TEXT("%d"), iData);
        m_pInputEdit->SetWindowText(strData);
    }
}

void CMyApp::OnButton9Clicked(void)
{
    if (iData < 1000 && m_pButtonOK->m_bState)
    {
        iData = iData * 10 + 9;
        strData.Format(TEXT("%d"), iData);
        m_pInputEdit->SetWindowText(strData);
    }
}

void CMyApp::OnButton0Clicked(void)
{
    if (iData < 1000 && m_pButtonOK->m_bState)
    {
        iData = iData * 10 + 0;
        strData.Format(TEXT("%d"), iData);
        m_pInputEdit->SetWindowText(strData);
    }
}

void CMyApp::OnButtonBackClicked(void)
{
    if (m_pButtonOK->m_bState)
    {
        if (iData < 10)
        {
            iData = 0;
            strData.Empty();
        }
        else
        {
            iData /= 10;
            strData.Format(TEXT("%d"), iData);
        }
        m_pInputEdit->SetWindowText(strData);

    }
}

void CMyApp::OnButtonGenClicked(void)
{
    if (iData != 0)
    {
        iRes = m_pDist->operator()(m_rdRand);

        if(m_pButtonSet->m_bState != TRUE)
        {
            int tmp = iRes;
            while (vSet[iRes] == true)
            {
                iRes = iRes % iData + 1;
                if (tmp == iRes)
                {
                    vSet.resize(0);
                    vSet.resize(iData + 1, false);
                    break;
                }
            }
            vSet[iRes] = true;
        }
    }
    else
    {
        iRes = 0;
    }

    strRes.Format(TEXT("%d"), iRes);
    m_pOutputEdit->SetWindowText(strRes);
}

void CMyApp::OnButtonOKClicked(void)
{
    m_pButtonOK->Switch(TEXT("确定"), TEXT("修改"));

    if (m_pButtonOK->m_bState)
    {
        m_pButtonGen->EnableWindow(FALSE);
        m_pButtonSet->EnableWindow(TRUE);

        RECT rect;
        m_pMainWnd->GetClientRect(&rect);
        m_pMainWnd->SetWindowPos(
            m_pMainWnd, NULL, NULL,
            510,
            250,
            (SWP_NOMOVE | SWP_NOZORDER)
        );
        m_pMainWnd->GetClientRect(&rect);
        m_pMainWnd->SetWindowPos(
            m_pMainWnd, NULL, NULL,
            510 * 2 - (rect.right - rect.left),
            250 * 2 - (rect.bottom - rect.top),
            (SWP_NOMOVE | SWP_NOZORDER)
        );

        ::SetWindowPos(m_pMainWnd->m_hWnd, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
    }
    else
    {
        m_pButtonGen->EnableWindow(TRUE);
        m_pButtonSet->EnableWindow(FALSE);

        RECT rect;
        m_pMainWnd->GetClientRect(&rect);
        m_pMainWnd->SetWindowPos(
            m_pMainWnd, NULL, NULL,
            320,
            150,
            (SWP_NOMOVE | SWP_NOZORDER)
        );
        m_pMainWnd->GetClientRect(&rect);
        m_pMainWnd->SetWindowPos(
            m_pMainWnd, NULL, NULL,
            320 * 2 - (rect.right - rect.left),
            150 * 2 - (rect.bottom - rect.top),
            (SWP_NOMOVE | SWP_NOZORDER)
        );
        
        ::SetWindowPos(m_pMainWnd->m_hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);

        delete m_pDist;
        m_pDist = new std::uniform_int_distribution<>(iData > 0, iData);

        vSet.resize(0);
        vSet.resize(iData + 1, false);
    }
}

void CMyApp::OnButtonSetClicked(void)
{
    m_pButtonSet->Switch(TEXT("是"), TEXT("否"));
}

CMyApp waMyApp;
