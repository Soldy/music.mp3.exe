// Music.mp3.exe.cpp : Idiot collector
//
#include "framework.h"
#include "Music.mp3.exe.h"

#define MAX_LOADSTRING 100


int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    BOOL  bResults = FALSE;
    HINTERNET hSession = NULL,
              hConnect = NULL,
              hRequest = NULL;

    hSession = WinHttpOpen(L"Log query",
        WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
        WINHTTP_NO_PROXY_NAME,
        WINHTTP_NO_PROXY_BYPASS, 0);


    if (hSession)
        hConnect = WinHttpConnect(hSession, L"gidigi.com",
            INTERNET_DEFAULT_HTTPS_PORT, 0);


    if (hConnect)
        hRequest = WinHttpOpenRequest(hConnect, L"GET",
            L"/idiotcollector",
            NULL, WINHTTP_NO_REFERER,
            WINHTTP_DEFAULT_ACCEPT_TYPES,
            WINHTTP_FLAG_REFRESH + WINHTTP_FLAG_SECURE);

    if (hRequest)
        bResults = WinHttpAddRequestHeaders(hRequest,
            L"User-Agent: Idiot collecttor",
            (ULONG)-1L,
            WINHTTP_ADDREQ_FLAG_ADD);

    if (bResults)
        bResults = WinHttpSendRequest(hRequest,
            WINHTTP_NO_ADDITIONAL_HEADERS,
            0, WINHTTP_NO_REQUEST_DATA, 0,
            0, 0);


    MessageBoxA(NULL, "No way, you did it!!!", "LoL", MB_OK | MB_ICONINFORMATION);


    return 0;
}