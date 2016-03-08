// winApi.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


HINSTANCE _hInstance;
HWND _hWnd;
POINT _ptEnd = { 0, 0 };
POINT _ptStart = { 0, 0 };
POINT _ptMove = { 0, 0 };

RECT rc;

/* ==== 함수 프로토타입 선언 ===== */
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void setWindowSize(int x, int y, int width, int height);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpszCmdParam, int nCmdShow)
{
	_hInstance = hInstance;

	//MSG : 운영체제에서 발행하는 메시지 정보를 저장하기 위한 구조체
	MSG message;

	//WNDCLASS : 윈도우의 정보를 저장하기 위한 구조체
	WNDCLASS wndClass;
	wndClass.cbClsExtra = 0;
	wndClass.cbWndExtra = 0;
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndClass.hInstance = hInstance;
	wndClass.lpfnWndProc = (WNDPROC)WndProc;
	wndClass.lpszClassName = WINNAME;
	wndClass.lpszMenuName = NULL;
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&wndClass);

	setWindowSize(WINSTARTX, WINSTARTY, WINSIZEX, WINSIZEY);

	_hWnd = CreateWindow(
		WINNAME,
		WINNAME,
		WINSTYLE,
		WINSTARTX,
		WINSTARTY,
		WINSIZEX,
		WINSIZEY,
		NULL,
		(HMENU)NULL,
		hInstance,
		NULL);

	setWindowSize(WINSTARTX, WINSTARTY, WINSIZEX, WINSIZEY);

	ShowWindow(_hWnd, nCmdShow);

	while (GetMessage(&message, 0, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	return message.wParam;

}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	POINT pt;
	int prvWidth, prvHeight;
	static int quadrant;
	static bool isLdown, isRdown;
	

	switch (iMessage)
	{
	case WM_CREATE:
		rc = RectMakeCenter(WINSIZEX/2, WINSIZEY/2, 100, 100);
		break;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			PostMessage(_hWnd, WM_DESTROY, 0, 0);
			break;
		}
		break;

	case WM_PAINT:
	{
		hdc = BeginPaint(_hWnd, &ps);
		//=============================

		char rcPoint[128];
		sprintf_s(rcPoint, "left : %-5d, top : %-5d, right : %-5d, bottom : %-5d", rc.left, rc.top, rc.right, rc.bottom);
		TextOut(hdc, 10, 10, rcPoint, strlen(rcPoint));

		switch (quadrant)
		{
		case 0:
			rc = { rc.left, rc.top, rc.right, rc.bottom };
			Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
			break;
		case 1:
			rc = { rc.left, rc.top - _ptMove.y, rc.right - _ptMove.x, rc.bottom };
			Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
			if (rc.left >= rc.right)
			{
				int temp = rc.left;
				rc.left = rc.right;
				rc.right = temp;
				quadrant = 2;
			}
			if (rc.top >= rc.bottom)
			{
				int temp = rc.top;
				rc.top = rc.bottom;
				rc.bottom = temp;
				quadrant = 3;
			}
			break;
		case 2:
			rc = { rc.left - _ptMove.x, rc.top - _ptMove.y, rc.right, rc.bottom };
			Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
			if (rc.left >= rc.right)
			{
				int temp = rc.left;
				rc.left = rc.right;
				rc.right = temp;
				quadrant = 1;
			}
			if(rc.top >= rc.bottom)
			{
				int temp = rc.top;
				rc.top = rc.bottom;
				rc.bottom = temp;
				quadrant = 4;
			}
			break;
		case 3:
			rc = { rc.left - _ptMove.x, rc.top, rc.right, rc.bottom - _ptMove.y };
			Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
			if (rc.left >= rc.right)
			{
				int temp = rc.left;
				rc.left = rc.right;
				rc.right = temp;
				quadrant = 4;
			}
			if(rc.top >= rc.bottom)
			{
				int temp = rc.top;
				rc.top = rc.bottom;
				rc.bottom = temp;
				quadrant = 1;
			}
			break;
		case 4:
			rc = { rc.left, rc.top, rc.right - _ptMove.x, rc.bottom - _ptMove.y };
			Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
			if (rc.left >= rc.right)
			{
				int temp = rc.left;
				rc.left = rc.right;
				rc.right = temp;
				quadrant = 3;
			}
			if(rc.top >= rc.bottom)
			{
				int temp = rc.top;
				rc.top = rc.bottom;
				rc.bottom = temp;
				quadrant = 2;
			}
			break;
		case 5:
			rc = { rc.left - _ptMove.x, rc.top - _ptMove.y, rc.right - _ptMove.x, rc.bottom - _ptMove.y };
			Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
			break;
		}
		
		//=============================
		EndPaint(_hWnd, &ps);
	}
	break;

	case WM_MOUSEMOVE:
	{
		_ptEnd.x = LOWORD(lParam);
		_ptEnd.y = HIWORD(lParam);

		_ptMove.x = _ptStart.x - _ptEnd.x;
		_ptMove.y = _ptStart.y - _ptEnd.y;

		//이동의 시작점은 계속 변해야함
		_ptStart.x = _ptEnd.x;
		_ptStart.y = _ptEnd.y;

		if(isLdown || isRdown)
			InvalidateRect(hWnd, NULL, true);
	}
	break;

	case WM_LBUTTONDOWN:
	{
		_ptStart.x = LOWORD(lParam);
		_ptStart.y = HIWORD(lParam);

		isLdown = true;

		//1사분면
		if (rc.left + ((rc.right - rc.left) / 2) < _ptStart.x && rc.right > _ptStart.x
			&& rc.top < _ptStart.y && rc.top + ((rc.bottom - rc.top) / 2) > _ptStart.y)
		{
			quadrant = 1;
		}
		//2사분면
		else if (rc.left < _ptStart.x && rc.left + ((rc.right - rc.left) / 2) > _ptStart.x
			&& rc.top < _ptStart.y && rc.top + ((rc.bottom - rc.top) / 2) > _ptStart.y)
		{
			quadrant = 2;
		}
		//3사분면
		else if (rc.left < _ptStart.x && rc.left + ((rc.right - rc.left) / 2) > _ptStart.x
			&& rc.top + ((rc.bottom - rc.top) / 2) < _ptStart.y && rc.bottom > _ptStart.y)
		{
			quadrant = 3;
		}
		//4사분면
		else if (rc.left + ((rc.right - rc.left) / 2) < _ptStart.x && rc.right > _ptStart.x
			&& rc.top + ((rc.bottom - rc.top) / 2) < _ptStart.y && rc.bottom > _ptStart.y)
		{
			quadrant = 4;
		}
		else
			quadrant = 0;
	}
		break;

	case WM_LBUTTONUP:
	{
		_ptEnd.x = LOWORD(lParam);
		_ptEnd.y = HIWORD(lParam);
		
		isLdown = false;
	}
		break;

	case WM_RBUTTONDOWN:
	{
		_ptStart.x = LOWORD(lParam);
		_ptStart.y = HIWORD(lParam);

		if (rc.left < _ptStart.x && rc.top < _ptStart.y && rc.right > _ptStart.x && rc.bottom > _ptStart.y)
		{
			isRdown = true;
			quadrant = 5;
		}
	}
		break;

	case WM_RBUTTONUP:
	{
		_ptEnd.x = LOWORD(lParam);
		_ptEnd.y = HIWORD(lParam);

		isRdown = false;
	}
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}

void setWindowSize(int x, int y, int width, int height)
{
	RECT rc;

	rc.left = 0;
	rc.top = 0;
	rc.right = width;
	rc.bottom = height;

	AdjustWindowRect(&rc, WINSTYLE, false);

	SetWindowPos(_hWnd, NULL, x, y, (rc.right - rc.left),
		(rc.bottom - rc.top), SWP_NOZORDER | SWP_NOMOVE);
}