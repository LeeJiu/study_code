// WinApi.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

HINSTANCE _hInstance;
HWND _hWnd;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void SetWindowSize(int x, int y, int width, int height);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	_hInstance = hInstance;

	WNDCLASS WndClass;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = (WNDPROC)WndProc;
	WndClass.lpszClassName = WINNAME;
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&WndClass);

	_hWnd = CreateWindow(WINNAME, WINNAME, WINSTYLE, WINSTARTX, WINSTARTY, WINSIZEX, WINSIZEY, NULL, (HMENU)NULL, hInstance, NULL);

	ShowWindow(_hWnd, nCmdShow);

	MSG msg;

	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;

	switch (iMessage)
	{
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			PostMessage(hWnd, WM_DESTROY, 0, 0);
			break;
		}
		break;
	case WM_PAINT:
	{
		hdc = BeginPaint(hWnd, &ps);

		//=============구구단을 외우자=============
		TCHAR str[128];
		for (int i = 2; i < 10; ++i)
		{
			for (int j = 1; j < 10; ++j)
			{
				wsprintf(str, TEXT("%d x %d = %d"), i, j, i*j);		//정수나 실수를 서식화하여 문자열에 담는다.
				TextOut(hdc, 100*i-190, 20*j, str, lstrlen(str));
			}
		}

		//==============그림을 그리자==============
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 20; ++j)
			{
				SetPixel(hdc, 100 + i, 250 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 30; ++j)
			{
				SetPixel(hdc, 110 + i, 260 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 20; ++j)
			{
				SetPixel(hdc, 120 + i, 240 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 30; ++j)
			{
				SetPixel(hdc, 120 + i, 290 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 20; ++j)
			{
				SetPixel(hdc, 130 + i, 250 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 20; ++j)
			{
				SetPixel(hdc, 140 + i, 240 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 20; ++j)
			{
				SetPixel(hdc, 150 + i, 250 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 20; ++j)
			{
				SetPixel(hdc, 160 + i, 230 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 20; ++j)
			{
				SetPixel(hdc, 170 + i, 240 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 20; ++j)
			{
				SetPixel(hdc, 180 + i, 230 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 20; ++j)
			{
				SetPixel(hdc, 190 + i, 240 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 20; ++j)
			{
				SetPixel(hdc, 200 + i, 220 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				SetPixel(hdc, 210 + i, 230 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 20; ++j)
			{
				SetPixel(hdc, 220 + i, 220 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				SetPixel(hdc, 230 + i, 230 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 20; ++j)
			{
				SetPixel(hdc, 240 + i, 220 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				SetPixel(hdc, 250 + i, 220 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 50; ++j)
			{
				SetPixel(hdc, 260 + i, 220 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 50; ++j)
			{
				SetPixel(hdc, 270 + i, 270 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 30; ++j)
			{
				SetPixel(hdc, 280 + i, 320 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 60; ++j)
			{
				SetPixel(hdc, 290 + i, 340 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 30; ++j)
			{
				SetPixel(hdc, 130 + i, 320 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 40; ++j)
			{
				SetPixel(hdc, 140 + i, 350 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				SetPixel(hdc, 150 + i, 380 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 20; ++j)
			{
				SetPixel(hdc, 130 + i, 390 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				SetPixel(hdc, 140 + i, 410 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				SetPixel(hdc, 150 + i, 400 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				SetPixel(hdc, 160 + i, 410 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 60; ++j)
			{
				SetPixel(hdc, 150 + i, 420 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				SetPixel(hdc, 140 + i, 470 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				SetPixel(hdc, 130 + i, 480 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				SetPixel(hdc, 120 + i, 490 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 30; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				SetPixel(hdc, 110 + i, 500 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				SetPixel(hdc, 100 + i, 510 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				SetPixel(hdc, 140 + i, 510 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				SetPixel(hdc, 160 + i, 480 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 30; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				SetPixel(hdc, 170 + i, 490 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 30; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				SetPixel(hdc, 200 + i, 480 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				SetPixel(hdc, 220 + i, 470 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 20; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				SetPixel(hdc, 230 + i, 460 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				SetPixel(hdc, 250 + i, 450 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 80; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				SetPixel(hdc, 210 + i, 440 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 30; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				SetPixel(hdc, 180 + i, 430 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				SetPixel(hdc, 190 + i, 420 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 20; ++j)
			{
				SetPixel(hdc, 290 + i, 420 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 20; ++j)
			{
				SetPixel(hdc, 280 + i, 400 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 20; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				SetPixel(hdc, 260 + i, 400 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 40; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				SetPixel(hdc, 200 + i, 400 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				SetPixel(hdc, 190 + i, 390 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				SetPixel(hdc, 240 + i, 390 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 40; ++j)
			{
				SetPixel(hdc, 180 + i, 350 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 30; ++j)
			{
				SetPixel(hdc, 250 + i, 360 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 20; ++j)
			{
				SetPixel(hdc, 240 + i, 340 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 40; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				SetPixel(hdc, 200 + i, 330 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				SetPixel(hdc, 190 + i, 340 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				SetPixel(hdc, 200 + i, 370 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 30; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				SetPixel(hdc, 260 + i, 370 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				SetPixel(hdc, 260 + i, 350 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				SetPixel(hdc, 250 + i, 330 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 20; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				SetPixel(hdc, 260 + i, 320 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				SetPixel(hdc, 230 + i, 490 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 20; ++j)
			{
				SetPixel(hdc, 240 + i, 500 + j, RGB(0, 0, 0));
			}
		}
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				SetPixel(hdc, 250 + i, 510 + j, RGB(0, 0, 0));
			}
		}


		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}


	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}

void SetWindowSize(int x, int y, int width, int height)
{
	RECT rc;
	rc.left = 0;
	rc.top = 0;
	rc.right = width;
	rc.bottom = height;

	AdjustWindowRect(&rc, WINSTYLE, NULL);

	SetWindowPos(_hWnd, NULL, x, y, (rc.right - rc.left), (rc.bottom - rc.top), SWP_NOZORDER | SWP_NOMOVE);
}
