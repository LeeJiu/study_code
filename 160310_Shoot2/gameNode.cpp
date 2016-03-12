#include "stdafx.h"
#include "gameNode.h"


gameNode::gameNode()
{
}


gameNode::~gameNode()
{
}


HRESULT gameNode::init()
{
	SetTimer(_hWnd, 1, 10, NULL);

	KEYMANAGER->init();

	return S_OK;
}

void gameNode::release()
{
	KillTimer(_hWnd, 1);

	KEYMANAGER->release();
	KEYMANAGER->releaseSingleton();
}

void gameNode::update()
{
	InvalidateRect(_hWnd, NULL, false);
}

void gameNode::render(HDC hdc)
{

}


LRESULT gameNode::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc, MemDC;
	HBITMAP Bitmap, OldBitmap;
	PAINTSTRUCT ps;
	RECT rt;

	switch (iMessage)
	{
	case WM_TIMER:
	{
		this->update();
	}
	break;

	case WM_MOUSEMOVE:
		_ptMouse.x = LOWORD(lParam);
		_ptMouse.y = HIWORD(lParam);
		break;

	case WM_PAINT:
	{
		GetClientRect(_hWnd, &rt);
		hdc = BeginPaint(_hWnd, &ps);
		MemDC = CreateCompatibleDC(hdc);
		Bitmap = (HBITMAP)CreateCompatibleBitmap(hdc, WINSIZEX, WINSIZEY);
		OldBitmap = (HBITMAP)SelectObject(MemDC, Bitmap);
		FillRect(MemDC, &rt, (HBRUSH)GetStockObject(WHITE_BRUSH));
		//=============================

		this->render(MemDC);

		//=============================
		BitBlt(hdc, 0, 0, WINSIZEX, WINSIZEY, MemDC, 0, 0, SRCCOPY);
		DeleteObject(SelectObject(MemDC, OldBitmap));
		DeleteDC(MemDC);
		EndPaint(_hWnd, &ps);
	}
	break;

	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			PostMessage(_hWnd, WM_DESTROY, 0, 0);
			break;
		}
		break;


	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	//윈도우 프로시져에서 처리되지 않은 나머지 메시지를 처리해준다
	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}