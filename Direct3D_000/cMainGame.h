#pragma once

class cImage;			//�̷�Ŭ������ �ִ�


class cMainGame
{
private:	
	HDC				m_hdc;		//������ HDC
	cImage*			m_pBackBufferImage;		//����� �̹���

	cScene_00*		m_pNowScene;//���� ��

public:
	cMainGame(void);
	~cMainGame(void);

	//����
	HRESULT Init(void);

	//����
	void Release();

	//������Ʈ
	void Update();

	//��ο�
	void Draw();

	
public:

	//���ν���
	LRESULT MainProc( HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam );

};
