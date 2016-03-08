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
	InvalidateRect(_hWnd, NULL, false);		//더블 버퍼링을 이용하면 계속 덧그려준다
}

void gameNode::render(HDC hdc)
{

}


LRESULT gameNode::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc, memDC;
	PAINTSTRUCT ps;
	HBITMAP Bitmap, OldBitmap;
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
		GetClientRect(_hWnd, &rt);									//윈도우 사이즈를 받아옴
		hdc = BeginPaint(_hWnd, &ps);
		memDC = CreateCompatibleDC(hdc);							//새로운 DC생성 hdc랑 같게
		Bitmap = CreateCompatibleBitmap(hdc, WINSIZEX, WINSIZEY);	//새로운 종이 생성
		OldBitmap = (HBITMAP)SelectObject(memDC, Bitmap);			//종이 교체
		FillRect(memDC, &rt, (HBRUSH)GetStockObject(WHITE_BRUSH));	//비트맵 배경은 디폴트가 검정이기 때문에
		//=============================								//배경색을 흰색으로 채워주자

		this->render(memDC);
		
		//=============================
		BitBlt(hdc, 0, 0, WINSIZEX, WINSIZEY, memDC, 0, 0, SRCCOPY); //hdc에 memDC를 베껴 그리자
		DeleteObject(SelectObject(memDC, OldBitmap));
		DeleteDC(memDC);
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