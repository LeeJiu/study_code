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
	InvalidateRect(_hWnd, NULL, false);		//���� ���۸��� �̿��ϸ� ��� ���׷��ش�
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
		GetClientRect(_hWnd, &rt);									//������ ����� �޾ƿ�
		hdc = BeginPaint(_hWnd, &ps);
		memDC = CreateCompatibleDC(hdc);							//���ο� DC���� hdc�� ����
		Bitmap = CreateCompatibleBitmap(hdc, WINSIZEX, WINSIZEY);	//���ο� ���� ����
		OldBitmap = (HBITMAP)SelectObject(memDC, Bitmap);			//���� ��ü
		FillRect(memDC, &rt, (HBRUSH)GetStockObject(WHITE_BRUSH));	//��Ʈ�� ����� ����Ʈ�� �����̱� ������
		//=============================								//������ ������� ä������

		this->render(memDC);
		
		//=============================
		BitBlt(hdc, 0, 0, WINSIZEX, WINSIZEY, memDC, 0, 0, SRCCOPY); //hdc�� memDC�� ���� �׸���
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

	//������ ���ν������� ó������ ���� ������ �޽����� ó�����ش�
	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}