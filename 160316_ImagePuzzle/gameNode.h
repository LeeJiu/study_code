#pragma once

#include "image.h"

class gameNode
{
private:
	image* _backBuffer;
	void setBackBuffer();

public:
	gameNode();
	virtual ~gameNode();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);

	image* getBackBuffer() { return _backBuffer; }

	LRESULT MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
};

