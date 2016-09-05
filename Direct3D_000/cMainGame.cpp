#include "StdAfx.h"
#include "cMainGame.h"
#include "cImage.h"
#include "cScene_00.h"


cMainGame::cMainGame(void)
{
}

cMainGame::~cMainGame(void)
{
}

//셋팅
HRESULT cMainGame::Init(void)
{
	//매니져 셋팅
	TIME_MGR->Init();
	LOG_MGR->Init( LOG_WINDOW | LOG_FILE, g_hWnd, "Dump" );

	//HDC 얻는다
	m_hdc = GetDC( g_hWnd );

	//백버퍼 이미지를 만든다.
	m_pBackBufferImage = new cImage;
	
	//빈비트맵 만든다.
	m_pBackBufferImage->Init( 800, 800 );

	//씬 생성
	m_pNowScene = new cScene_00;

	//씬 초기화
	m_pNowScene->Init();

	
	//return E_FAIL;
	return S_OK;		
}	

//해제
void cMainGame::Release()
{
	//씬 해제
	m_pNowScene->Release();
	SAFE_DELETE(m_pNowScene);


	//DC 해제
	ReleaseDC( g_hWnd, m_hdc );

	//매니져 해제
	TIME_MGR->Release();
	cTimeMgr::ReleaseInstance();
	KEY_MGR->Release();
	cKeyMgr::ReleaseInstance();
	LOG_MGR->Release();
	cLogMgr::ReleaseInstance();
}

//업데이트
void cMainGame::Update()
{
	//타임매니져 업데이트
	TIME_MGR->UpdateTime( 60.0f );
	
	//한프레임 갱신 시간
	double timeDelta = TIME_MGR->GetFrameDeltaSec();

	//씬 업데이트
	m_pNowScene->Update(static_cast<float>(timeDelta));

	
}

//드로우
void cMainGame::Draw()
{
	//
	// Cpp 캐스팅
	//
	
	//정적 캐스팅 ( 단순 형변환 할때 사용하자 )
	//static_cast<형>( 형변환할 변수 );

	//정적 캐스팅 ( OPP 상속관계 있을때 안전하게 다운캐스팅을 할수 있다 , virtual table 를 가지고 있는 인스턴스에 한해서 ( virtual 함수가 있는애들 ) )
	//dynamic_cast<형>( 형변환할 포인터 );
	//포유류* p = 반장인스턴스주소;
	//돼지* pPig = dynamic_cast<돼지*>( p );	//NULL 이 대입됨
	//사람* pHuman = dynamic_cast<사람*>( p );	//재대로 형변환 되서 주소 대입됨

	//상수 캐스팅 ( 상수포인터를 비상수 포인터로 만들어버린다 )
	//const_cast<비상수포인터>( 상수포인터 );

	//강제성이 아주 강한 그냥 형변환 
	//reinterpret_cast<정수형>( 포인터 );	//( 포인터 주소 값이 정수로 그냥 바뀐다 해쉬 테이블 만들때 쓴다 )


	//백DC 를 얻는다.
	HDC backDC = m_pBackBufferImage->GetBitDC();

	//backDC 의 내용을 흰색으로 클리어
	RECT rcBack = { 0, 0, WINSIZE_X, WINSIZE_Y };
	FillRect( backDC, &rcBack, (HBRUSH)GetStockObject(WHITE_BRUSH) );

	//씬 렌더
	m_pNowScene->Render(backDC);


	//타임 정보를 출력해보자
	TIME_MGR->DrawTimeInfo(backDC );

	//백버퍼의 내용을 hdc 에 고속 전송
	m_pBackBufferImage->Draw( m_hdc, 0, 0 );
}



//////////////////////////////////////////////////////////////////////////

//메인 프로시져 함수
LRESULT cMainGame::MainProc( HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam )
{
	switch( iMessage )
	{	
	case WM_TIMER:
		Update();
		break;

	case WM_KEYDOWN:
		switch( wParam )
		{
		case VK_ESCAPE:
			DestroyWindow( hWnd );
			break;
		}
		break;

	case WM_DESTROY:			//윈도우가 파괴된다면..
		PostQuitMessage( 0 );	//프로그램 종료 요청 ( 메시지 루프를 빠져나가게 된다 )
		break;
	}
	return DefWindowProc( hWnd, iMessage, wParam, lParam );
}

