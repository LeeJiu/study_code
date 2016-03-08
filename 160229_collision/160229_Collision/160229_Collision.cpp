// 160229_Collision.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"


HINSTANCE _hInstance;
HWND _hWnd;

POINT pt1;
POINT pt2;
POINT pt3;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void SetWindowSize(int x, int y, int width, int height);
bool Collision(RECT, RECT, int);
bool innerCollision(RECT, RECT, int);
void SwapPoint(POINT&, POINT&);

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

	static RECT rc1;
	static RECT rc2;
	static RECT ltRc;

	static bool hasltRc;

	switch (iMessage)
	{
	case WM_CREATE:
		pt1.x = 200; pt1.y = 200;
		pt2.x = WINSIZEX/2; pt2.y = WINSIZEY/2;
		pt3.x = pt1.x; pt3.y = pt1.y;				//pt1이 움직일거임
		break;
	case WM_KEYDOWN:
	{
		switch (wParam)
		{
		case VK_ESCAPE:
			PostMessage(hWnd, WM_DESTROY, 0, 0);
			break;
		case VK_LEFT:
			if(innerCollision(rc1, ltRc, 3))		//움직이기 전에 충돌 체크하자
				pt3.x = rc1.right - 15;
			if (Collision(rc1, rc2, 3))				//움직이기 전에 충돌 체크하자
			{
				pt1.x += rc2.right - rc1.left;
				SwapPoint(pt1, pt2);				//움직이는 애의 좌표로 바꿀거임
			}
			else pt1.x -= 5;						//충돌하지 않았다면 그냥 움직여
			InvalidateRect(hWnd, NULL, true);
			break;
		case VK_RIGHT:
			if (innerCollision(rc1, ltRc, 4))
				pt3.x = rc1.left + 15;
			if (Collision(rc1, rc2, 4))
			{
				pt1.x -= rc1.right - rc2.left;
				SwapPoint(pt1, pt2);
			}
			else pt1.x += 5;
			InvalidateRect(hWnd, NULL, true);
			break;
		case VK_UP:
			if (innerCollision(rc1, ltRc, 1))
				pt3.y = rc1.bottom - 15;
			if (Collision(rc1, rc2, 1))
			{
				pt1.y += rc2.bottom - rc1.top;
				SwapPoint(pt1, pt2);
			}
			else pt1.y -= 5;
			InvalidateRect(hWnd, NULL, true);
			break;
		case VK_DOWN:
			if (innerCollision(rc1, ltRc, 2))
				pt3.y = rc1.top + 15;
			if (Collision(rc1, rc2, 2))
			{
				pt1.y -= rc1.bottom - rc2.top;
				SwapPoint(pt1, pt2);
			}
			else pt1.y += 5;
			InvalidateRect(hWnd, NULL, true);
			break;
		}
	}
		break;
	case WM_PAINT:
	{
		hdc = BeginPaint(hWnd, &ps);

		rc1 = RectMakeCenter(pt1.x, pt1.y, 100, 100);
		rc2 = RectMakeCenter(pt2.x, pt2.y, 100, 100);
		ltRc = RectMakeCenter(pt3.x, pt3.y, 20, 20);

		Rectangle(hdc, rc1.left, rc1.top, rc1.right, rc1.bottom);
		Rectangle(hdc, rc2.left, rc2.top, rc2.right, rc2.bottom);
		Rectangle(hdc, ltRc.left, ltRc.top, ltRc.right, ltRc.bottom);

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

bool Collision(RECT rc1, RECT rc2, int dir)
{
	switch (dir)
	{
	case 1:		//상
		rc1.top -= 5;
		rc1.bottom -= 5;
		break;
	case 2:		//하
		rc1.top += 5;
		rc1.bottom += 5;
		break;
	case 3:		//좌
		rc1.left -= 5;
		rc1.right -= 5;
		break;
	case 4:		//우
		rc1.left += 5;
		rc1.right += 5;
		break;
	}

	if (rc1.left <= rc2.right && rc1.top <= rc2.bottom && rc1.right >= rc2.left && rc1.bottom >= rc2.top) return true;
	else return false;
}

bool innerCollision(RECT rc, RECT ltRc, int dir)
{
	switch (dir)
	{
	case 1:		//상
		rc.top -= 5;
		rc.bottom -= 5;
		break;
	case 2:		//하
		rc.top += 5;
		rc.bottom += 5;
		break;
	case 3:		//좌
		rc.left -= 5;
		rc.right -= 5;
		break;
	case 4:		//우
		rc.left += 5;
		rc.right += 5;
		break;
	}

	if (rc.left > ltRc.left || rc.right < ltRc.right || rc.top > ltRc.top || rc.bottom < ltRc.bottom)
		return true;
	else return false;
}

void SwapPoint(POINT& pt1, POINT& pt2)
{
	POINT temp;

	temp.x = pt1.x;
	pt1.x = pt2.x;
	pt2.x = temp.x;
	
	temp.y = pt1.y;
	pt1.y = pt2.y;
	pt2.y = temp.y;

	pt3.x = pt1.x;
	pt3.y = pt1.y;
}
