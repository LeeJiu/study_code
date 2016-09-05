#pragma once

class cImage;			//이런클래스가 있다


class cMainGame
{
private:	
	HDC				m_hdc;		//윈도우 HDC
	cImage*			m_pBackBufferImage;		//백버퍼 이미지

	cScene_00*		m_pNowScene;//현재 씬

public:
	cMainGame(void);
	~cMainGame(void);

	//셋팅
	HRESULT Init(void);

	//해제
	void Release();

	//업데이트
	void Update();

	//드로우
	void Draw();

	
public:

	//프로시져
	LRESULT MainProc( HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam );

};
