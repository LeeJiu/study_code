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


	_floor = WINSIZEY / 2 - 10;
	_x = WINSIZEX / 5;
	_y = _floor;

	_isWalk = true;
	_isJump = false;
	_gravity = 0.1f;
	_count = _jumpPw = _offsetX = _offsetY = 0;

	IMAGEMANAGER->addImage("background", "sakura_bg2.bmp", WINSIZEX, WINSIZEY, false, false);
	_box = IMAGEMANAGER->addImage("box", "box.bmp", 50, 50, false, false);
	_sakura = IMAGEMANAGER->addFrameImage("sakuraJump", "sakura_jump.bmp", _x, _y, 360, 194, 3, 2, true, RGB(0, 255, 0));
	_sakura = IMAGEMANAGER->addFrameImage("sakuraWalk", "sakura_walk.bmp", _x, _y, 336, 190, 6, 2, true, RGB(0, 255, 0));

	_rcPlayer = RectMake(_x, _y, _sakura->getFrameWidth(), _sakura->getFrameHeight());

	_ptBox[0].x = (WINSIZEX / 2) - 50;
	_ptBox[0].y = _floor + 50;
	for (int i = 1; i < 3; i++)
	{
		_ptBox[i].x = _ptBox[i - 1].x + RND->getFromIntTo(200, 300);
		_ptBox[i].y = _floor + 50;
		_rcBox[i] = RectMake(_ptBox[i].x, _ptBox[i].y, 50, 50);
	}						 

	return S_OK;
}

void gameStudy::release()
{


	gameNode::release();
}

void gameStudy::update()
{
	//배경 이동
	_offsetX += 5.f;
	

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		if (!_isJump)
		{
			_isWalk = false;
			_isJump = true;
			_jumpPw = 4.f;
			_gravity = 0.1f;
		}
	}

	if (_isJump && !_isWalk)
	{
		_y -= _jumpPw;
		_jumpPw -= _gravity;

		_count++;
		_sakura->setFrameY(0);

		int height = _sakura->getFrameHeight();

		if (_count % JUMPFRAME == 0)
		{
			collision();
			if (_jumpPw > 0 && _y < _floor)
			{
				_sakura->setFrameX(0);
			}
			else if (_jumpPw < 0 && _y < _floor - (height / 2))
			{
				_sakura->setFrameX(1);
			}
			else if (_jumpPw < 0 && _y < _floor && _y > _floor - (height / 2))
			{
				_sakura->setFrameX(2);
				_y = _floor;
				_gravity = 0;
				_jumpPw = 0;
			}
			else if (_jumpPw == 0 && _floor == _y)
			{
				_isJump = false;
				_isWalk = true;
			}
		}
	}
	else if (!_isJump && _isWalk)
	{
		_count++;
		_sakura->setFrameY(0);		//오른쪽으로 걷는 이미지 프레임 Y좌표
		if (_count % WALKFRAME == 0)
		{
			collision();
			_index++;
			if (_index > _sakura->getMaxFrameX())	//인덱스가 마지막 프레임보다 크면
				_index = 0;							//첫 번째 인덱스로 / 프레임 루프 돌자

			_sakura->setFrameX(_index);				//이미지 프레임 X좌표를 지정
		}
	}

	//박스 이동
	for (int i = 0; i < 3; i++)
	{
		_ptBox[i].x -= 3;

		if (_ptBox[0].x + 50 < 0)
		{
			_ptBox[0].x = _ptBox[2].x + 50 + RND->getFromIntTo(200, 300);
		}
		if (_ptBox[1].x + 50 < 0)
		{
			_ptBox[1].x = _ptBox[0].x + 50 + RND->getFromIntTo(200, 300);
		}
		if (_ptBox[2].x + 50 < 0)
		{
			_ptBox[2].x = _ptBox[1].x + 50 + RND->getFromIntTo(200, 300);
		}
		_rcBox[i] = RectMake(_ptBox[i].x, _ptBox[i].y, 50, 50);
	}
	
	_rcPlayer = RectMake(_x, _y, _sakura->getFrameWidth(), _sakura->getFrameHeight());

	gameNode::update();
}

void gameStudy::render(HDC hdc)
{
	//백버퍼에서 뿌려준다
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//======================
	//이 사이에서 그려주면 됨.

	IMAGEMANAGER->loopRender("background", backDC, &RectMake(0, 0, WINSIZEX, WINSIZEY), _offsetX, _offsetY);
	
	if (_isJump)
		IMAGEMANAGER->frameRender("sakuraJump", backDC, _x - 40, _y, _sakura->getFrameX(), _sakura->getFrameY());
	else
		IMAGEMANAGER->frameRender("sakuraWalk", backDC, _x, _y, _sakura->getFrameX(), _sakura->getFrameY());

	for (int i = 0; i < 3; ++i)
	{
		IMAGEMANAGER->render("box", backDC, _ptBox[i].x, _ptBox[i].y);
	}


	//======================
	this->getBackBuffer()->render(hdc, 0, 0);
}

void gameStudy::collision()
{
	if (_isJump)
	{
		for (int i = 0; i < 3; i++)
		{
			if (IntersectRect(&RectMake(0, 0, 0, 0), &_rcPlayer, &_rcBox[i]))
			{
				//if (_rcPlayer.right > _rcBox[i].left && _rcPlayer.bottom > _rcBox[i].top)
				if (_x + _sakura->getFrameWidth() > _rcBox[i].left && _y + _sakura->getFrameHeight() > _rcBox[i].top)
				{
					_x = _rcBox[i].left - _sakura->getFrameWidth();
				}
				/*else if (_x > _rcBox[i].left && _rcPlayer.bottom < _rcBox[i].top)
				{
					_y = _rcBox[i].top - _sakura->getFrameHeight();
					_isWalk = true;
				}*/
			}
		}
	}
	else if (_isWalk)
	{
		for (int i = 0; i < 3; i++)
		{
			if (IntersectRect(&RectMake(0, 0, 0, 0), &_rcPlayer, &_rcBox[i]))
			{
				//if (_rcPlayer.right > _rcBox[i].left && _rcPlayer.bottom > _rcBox[i].top)
				if (_x + _sakura->getFrameWidth() > _rcBox[i].left && _y + _sakura->getFrameHeight() > _rcBox[i].top)
				{
					_x = _rcBox[i].left - _sakura->getFrameWidth();
				}
				//else if (_x > _rcBox[i].left && _rcPlayer.bottom < _rcBox[i].top)
				//{
				//	_y = _rcBox[i].top - _sakura->getFrameHeight();
				//}
			}
		}
	}

}


