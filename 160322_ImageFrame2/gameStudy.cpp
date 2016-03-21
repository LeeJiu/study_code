#include "stdafx.h"
#include "gameStudy.h"


gameStudy::gameStudy()
{
}


gameStudy::~gameStudy()
{
}

HRESULT gameStudy::init()
{
	gameNode::init();

	_bgImage = new image;
	_sakuraIdle = new image;
	_sakuraWalk = new image;
	_sakuraJump = new image;

	_bgImage->init("sakura_bg.bmp", WINSIZEX, WINSIZEY, false, false);
	_sakuraIdle->init("sakura_idle.bmp", 180, 194, 3, 2, true, RGB(0, 255, 0));
	_sakuraWalk->init("sakura_walk.bmp", 336, 190, 6, 2, true, RGB(0, 255, 0));
	_sakuraJump->init("sakura_jump.bmp", 360, 194, 3, 2, true, RGB(0, 255, 0));

	_x = CENTERX;
	_y = CENTERY;
	_jumpPw = 0.f;

	_isIdle = true;
	_isRight = true;
	_isJump = false;
	_count = 0;
	_index = 0;

	return S_OK;
}

void gameStudy::release()
{
	SAFE_RELEASE(_sakuraIdle);
	SAFE_RELEASE(_sakuraWalk);

	SAFE_DELETE(_sakuraIdle);
	SAFE_DELETE(_sakuraWalk);

	gameNode::release();
}

void gameStudy::update()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_isIdle = false;		//walk motion
		if (_isRight) _isRight = !_isRight;
		_x -= 3.f;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_isIdle = false;		//walk motion
		if (!_isRight) _isRight = !_isRight;
		_x += 3.f;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP)) 
	{
		_isIdle = false;
		_y -= 3.f;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_isIdle = false;
		_y += 3.f;
	}

	/*if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		if (!_isJump)
		{
			_isIdle = false;
			_isJump = true;
			_jumpPw = 5.f;
		}
	}*/
	
	//Ű�� ����, idle motion
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT)) _isIdle = true;
	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT)) _isIdle = true;
	if (KEYMANAGER->isOnceKeyUp(VK_UP)) _isIdle = true;
	if (KEYMANAGER->isOnceKeyUp(VK_DOWN)) _isIdle = true;


	if (_isRight && !_isIdle)
	{
		_count++;
		_sakuraWalk->setFrameY(0);		//���������� �ȴ� �̹��� ������ Y��ǥ
		if (_count % FRAME == 0)
		{
			_index++;
			if (_index > _sakuraWalk->getMaxFrameX())	//�ε����� ������ �����Ӻ��� ũ��
				_index = 0;								//ù ��° �ε����� / ������ ���� ����

			_sakuraWalk->setFrameX(_index);				//�̹��� ������ X��ǥ�� ����
		}

	}
	else if (!_isRight && !_isIdle)
	{
		_count++;
		_sakuraWalk->setFrameY(1);		//�������� �ȴ� �̹��� ������ Y��ǥ
		if (_count % FRAME == 0)
		{
			_index--;					//�¿� ���� ��Ų �̹����� �����ʺ��� �ε����� �о�;���
			if (_index < 0)				//�ε����� ù ��° �����Ӻ��� �۾�����
				_index = _sakuraWalk->getMaxFrameX();	//������ �ε����� / ������ ���� ����

			_sakuraWalk->setFrameX(_index);
		}
	}
	else if (_isRight && _isIdle)
	{
		_count++;
		_sakuraIdle->setFrameY(0);		//���������� �ȴٰ� idle �̹��� ������ Y��ǥ
		if (_count % FRAME == 0)
		{
			_index++;
			if (_index > _sakuraIdle->getMaxFrameX())	//�ε����� ������ �����Ӻ��� ũ��
				_index = 0;								//ù ��° �ε����� / ������ ���� ����

			_sakuraIdle->setFrameX(_index);				//�̹��� ������ X��ǥ�� ����
		}

	}
	else if (!_isRight && _isIdle)
	{
		_count++;
		_sakuraIdle->setFrameY(1);		//�������� �ȴٰ� idle �̹��� ������ Y��ǥ
		if (_count % FRAME == 0)
		{
			_index--;					//�¿� ���� ��Ų �̹����� �����ʺ��� �ε����� �о�;���
			if (_index < 0)				//�ε����� ù ��° �����Ӻ��� �۾�����
				_index = _sakuraIdle->getMaxFrameX();	//������ �ε����� / ������ ���� ����

			_sakuraIdle->setFrameX(_index);
		}
	}
	/*else if (_isJump && _isRight)
	{
		_count++;
		_sakuraJump->setFrameY(0);
		if (_count % FRAME == 0)
		{
			_index++;
			if (_index > _sakuraJump->getMaxFrameX())
				_index = 0;
			
			_sakuraJump->setFrameX(_index);
		}
	}
	else if (_isJump && !_isRight)
	{
		_count++;
		_sakuraJump->setFrameY(1);
		if (_count % FRAME == 0)
		{
			_index--;
			if (_index < 0)
				_index = _sakuraJump->getMaxFrameX();

			_sakuraJump->setFrameX(_index);
		}
	}*/


	gameNode::update();
}

void gameStudy::render(HDC hdc)
{
	//����ۿ��� �ѷ��ش�
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//======================
	//�� ���̿��� �׷��ָ� ��.

	_bgImage->render(backDC, 0, 0);

	if (_isIdle)
		_sakuraIdle->frameRender(backDC, _x, _y,  _sakuraIdle->getFrameX(), _sakuraIdle->getFrameY());
	else if (!_isIdle)
	{
		//if (_isJump)
		//	_sakuraJump->frameRender(backDC, _x, _y, _sakuraJump->getFrameX(), _sakuraJump->getFrameY());
		//else
			_sakuraWalk->frameRender(backDC, _x, _y, _sakuraWalk->getFrameX(), _sakuraWalk->getFrameY());

	}


	//======================
	this->getBackBuffer()->render(hdc, 0, 0);
}


