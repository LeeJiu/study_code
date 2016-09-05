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

//����
HRESULT cMainGame::Init(void)
{
	//�Ŵ��� ����
	TIME_MGR->Init();
	LOG_MGR->Init( LOG_WINDOW | LOG_FILE, g_hWnd, "Dump" );

	//HDC ��´�
	m_hdc = GetDC( g_hWnd );

	//����� �̹����� �����.
	m_pBackBufferImage = new cImage;
	
	//���Ʈ�� �����.
	m_pBackBufferImage->Init( 800, 800 );

	//�� ����
	m_pNowScene = new cScene_00;

	//�� �ʱ�ȭ
	m_pNowScene->Init();

	
	//return E_FAIL;
	return S_OK;		
}	

//����
void cMainGame::Release()
{
	//�� ����
	m_pNowScene->Release();
	SAFE_DELETE(m_pNowScene);


	//DC ����
	ReleaseDC( g_hWnd, m_hdc );

	//�Ŵ��� ����
	TIME_MGR->Release();
	cTimeMgr::ReleaseInstance();
	KEY_MGR->Release();
	cKeyMgr::ReleaseInstance();
	LOG_MGR->Release();
	cLogMgr::ReleaseInstance();
}

//������Ʈ
void cMainGame::Update()
{
	//Ÿ�ӸŴ��� ������Ʈ
	TIME_MGR->UpdateTime( 60.0f );
	
	//�������� ���� �ð�
	double timeDelta = TIME_MGR->GetFrameDeltaSec();

	//�� ������Ʈ
	m_pNowScene->Update(static_cast<float>(timeDelta));

	
}

//��ο�
void cMainGame::Draw()
{
	//
	// Cpp ĳ����
	//
	
	//���� ĳ���� ( �ܼ� ����ȯ �Ҷ� ������� )
	//static_cast<��>( ����ȯ�� ���� );

	//���� ĳ���� ( OPP ��Ӱ��� ������ �����ϰ� �ٿ�ĳ������ �Ҽ� �ִ� , virtual table �� ������ �ִ� �ν��Ͻ��� ���ؼ� ( virtual �Լ��� �ִ¾ֵ� ) )
	//dynamic_cast<��>( ����ȯ�� ������ );
	//������* p = �����ν��Ͻ��ּ�;
	//����* pPig = dynamic_cast<����*>( p );	//NULL �� ���Ե�
	//���* pHuman = dynamic_cast<���*>( p );	//���� ����ȯ �Ǽ� �ּ� ���Ե�

	//��� ĳ���� ( ��������͸� ���� �����ͷ� ���������� )
	//const_cast<����������>( ��������� );

	//�������� ���� ���� �׳� ����ȯ 
	//reinterpret_cast<������>( ������ );	//( ������ �ּ� ���� ������ �׳� �ٲ�� �ؽ� ���̺� ���鶧 ���� )


	//��DC �� ��´�.
	HDC backDC = m_pBackBufferImage->GetBitDC();

	//backDC �� ������ ������� Ŭ����
	RECT rcBack = { 0, 0, WINSIZE_X, WINSIZE_Y };
	FillRect( backDC, &rcBack, (HBRUSH)GetStockObject(WHITE_BRUSH) );

	//�� ����
	m_pNowScene->Render(backDC);


	//Ÿ�� ������ ����غ���
	TIME_MGR->DrawTimeInfo(backDC );

	//������� ������ hdc �� ��� ����
	m_pBackBufferImage->Draw( m_hdc, 0, 0 );
}



//////////////////////////////////////////////////////////////////////////

//���� ���ν��� �Լ�
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

	case WM_DESTROY:			//�����찡 �ı��ȴٸ�..
		PostQuitMessage( 0 );	//���α׷� ���� ��û ( �޽��� ������ ���������� �ȴ� )
		break;
	}
	return DefWindowProc( hWnd, iMessage, wParam, lParam );
}

