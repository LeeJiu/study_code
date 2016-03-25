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

	_count = 0;
	_index = 0;

	_gravity = 0.1f;
	_cmpJumpPw = 4.0f;
	_jumpPw = 0;
	
	IMAGEMANAGER->addImage("background", "sakura_bg2.bmp", WINSIZEX, WINSIZEY, false, false);
	_box = IMAGEMANAGER->addImage("box", "box.bmp", 50, 50, false, false);
	_sakura = IMAGEMANAGER->addFrameImage("sakuraJump", "sakura_jump.bmp", 360, 194, 3, 2, true, RGB(0, 255, 0));
	_sakura = IMAGEMANAGER->addFrameImage("sakuraWalk", "sakura_walk.bmp", 336, 190, 6, 2, true, RGB(0, 255, 0));
	_sakura = IMAGEMANAGER->addFrameImage("sakuraIdle", "sakura_idle.bmp", 180, 194, 3, 2, true, RGB(0, 255, 0));

	//플레이어 초기화
	_player.ground = OFF_GROUND;
	_player.state = IDLE;
	_player.x = WINSIZEX / 3;
	_player.y = WINSIZEY / 3;
	_player.player = { _player.x, _player.y, _player.x + _sakura->getFrameWidth(),  _player.y + _sakura->getFrameHeight() };
	_isRight = true;

	_rcBox = RectMake(CENTERX, WINSIZEY / 5 * 4 - 75, _box->getFrameWidth(), _box->getFrameHeight());
	_rcLand = RectMakeCenter(CENTERX, WINSIZEY / 5 * 4, WINSIZEX, 50);

	return S_OK;
}

void gameStudy::release()
{


	gameNode::release();
}

void gameStudy::update()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		if(_player.state != JUMP)
			_player.state = WALK;
		if (_isRight) _isRight = !_isRight;
		_player.x -= 3.f;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		if (_player.state != JUMP)
			_player.state = WALK;
		if (!_isRight) _isRight = !_isRight;
		_player.x += 3.f;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		if (_player.state != JUMP)
		{
			if (_player.ground == ON_GROUND)
				_player.ground = OFF_GROUND;
			_player.state = JUMP;
			_jumpPw = 4.f;
			_gravity = 0.15f;
		}
	}

	//키를 떼면, idle motion
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		if (_player.state != JUMP)
			_player.state = IDLE;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		if (_player.state != JUMP)
			_player.state = IDLE;
	}

	collision();

	imageFrame();

	//플레이어 위치 최종 갱신
	//_player.player = { _player.x, _player.y, _player.x + _sakura->getFrameWidth(),  _player.y + _sakura->getFrameHeight() };

	gameNode::update();
}

void gameStudy::render(HDC hdc)
{
	//백버퍼에서 뿌려준다
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//======================
	//이 사이에서 그려주면 됨.

	IMAGEMANAGER->render("background", backDC, 0, 0);
	IMAGEMANAGER->render("box", backDC, CENTERX, WINSIZEY / 5 * 4 - 75);
	
	Rectangle(backDC, _rcLand.left, _rcLand.top, _rcLand.right, _rcLand.bottom);
	Rectangle(backDC, _player.player.left, _player.player.top, _player.player.right, _player.player.bottom);
	
	if(_player.state == IDLE)
		IMAGEMANAGER->frameRender("sakuraIdle", backDC, _player.x, _player.y, _sakura->getFrameX(), _sakura->getFrameY());
	else if (_player.state == JUMP)
		IMAGEMANAGER->frameRender("sakuraJump", backDC, _player.x - 40, _player.y, _sakura->getFrameX(), _sakura->getFrameY());
	else
		IMAGEMANAGER->frameRender("sakuraWalk", backDC, _player.x, _player.y, _sakura->getFrameX(), _sakura->getFrameY());


	//======================
	this->getBackBuffer()->render(hdc, 0, 0);
}

void gameStudy::collision()
{
	if (_player.ground == ON_GROUND)	//지면에 서 있을 때
	{
		// x, y로  rect 갱신
		_player.player = { _player.x, _player.y, _player.x + _sakura->getFrameWidth(),  _player.y + _sakura->getFrameHeight() };
		if (IntersectRect(&_tmp, &_player.player, &_rcBox))
		{
			float height = _tmp.bottom - _tmp.top;
			float width = _tmp.right - _tmp.left;
			
			if (height > width)	// 상자의 좌우에서 충돌하면 tmp의 높이가 더 높음
			{
				// 상자의 왼쪽에서 충돌
				if (_rcBox.left == _tmp.left)
				{
					_player.x -= width;
				}
				// 상자의 오른쪽에서 충돌
				else if (_rcBox.right == _tmp.right)
				{
					_player.x += width;
				}
			}
			_player.state = IDLE;
		}
	}
	else if (_player.ground == OFF_GROUND)	//공중에 있을 때
	{
		_player.y -= _jumpPw;
		_jumpPw -= _gravity;
		
		// x, y로  rect 갱신
		_player.player = { _player.x, _player.y, _player.x + _sakura->getFrameWidth(),  _player.y + _sakura->getFrameHeight() };
		if (IntersectRect(&_tmp, &_player.player, &_rcLand))
		{
			float height = _tmp.bottom - _tmp.top;
			_player.y -= height;
			_player.ground = ON_GROUND;
			_player.state = IDLE;
			_jumpPw = 0;
			_gravity = 0;
		}
		//점프해서 박스 위로 올라왔을 때
		else if (IntersectRect(&_tmp, &_player.player, &_rcBox) && _player.state == JUMP)
		{
			float height = _tmp.bottom - _tmp.top;
			float width = _tmp.right - _tmp.left;

			if (height > width)	// 상자의 좌우에서 충돌하면 tmp의 높이가 더 높음
			{
				// 상자의 왼쪽에서 충돌
				if (_rcBox.left == _tmp.left)
				{
					_player.x -= width;
				}
				// 상자의 오른쪽에서 충돌
				else if (_rcBox.right == _tmp.right)
				{
					_player.x += width;
				}
			}
			else if (height < width)
			{
				// 상자의 윗쪽에서 충돌
				if (_rcBox.top == _tmp.top)
				{
					_player.y -= height;
					_player.state = IDLE;
					_jumpPw = 0;
				}
			}
		}
		//박스 위에서 움직일 때
		else if (IntersectRect(&_tmp, &_player.player, &_rcBox) && _player.state != JUMP)
		{
			float height = _tmp.bottom - _tmp.top;
			float width = _tmp.right - _tmp.left;
			if (height < width)
			{
				// 상자의 윗쪽에서 충돌
				if (_rcBox.top == _tmp.top)
				{
					_player.y -= height;
					_jumpPw = 0;
				}
			}
		}
	}
	_player.player = { _player.x, _player.y, _player.x + _sakura->getFrameWidth(),  _player.y + _sakura->getFrameHeight() };
}

void gameStudy::imageFrame()
{
	switch (_player.state)
	{
	case IDLE:
	{
		if (_isRight)
		{
			_count++;
			_sakura->setFrameY(0);		//오른쪽으로 걷다가 idle 이미지 프레임 Y좌표
			if (_count % FRAME == 0)
			{
				_index++;
				if (_index > _sakura->getMaxFrameX())	//인덱스가 마지막 프레임보다 크면
					_index = 0;							//첫 번째 인덱스로 / 프레임 루프 돌자

				_sakura->setFrameX(_index);				//이미지 프레임 X좌표를 지정
			}
		}
		else
		{
			_count++;
			_sakura->setFrameY(1);		//왼쪽으로 걷다가 idle 이미지 프레임 Y좌표
			if (_count % FRAME == 0)
			{
				_index--;					//좌우 반전 시킨 이미지라서 오른쪽부터 인덱스를 읽어와야함
				if (_index < 0)				//인덱스가 첫 번째 프레임보다 작아지면
					_index = _sakura->getMaxFrameX();	//마지막 인덱스로 / 프레임 루프 돌자

				_sakura->setFrameX(_index);
			}
		}
	}
		break;
	case WALK:
	{
		if (_isRight)
		{
			_count++;
			_sakura->setFrameY(0);			//오른쪽으로 걷는 이미지 프레임 Y좌표
			if (_count % FRAME == 0)
			{
				_index++;
				if (_index > _sakura->getMaxFrameX())	//인덱스가 마지막 프레임보다 크면
					_index = 0;							//첫 번째 인덱스로 / 프레임 루프 돌자

				_sakura->setFrameX(_index);				//이미지 프레임 X좌표를 지정
			}
		}
		else
		{
			_count++;
			_sakura->setFrameY(1);			//왼쪽으로 걷는 이미지 프레임 Y좌표
			if (_count % FRAME == 0)
			{
				_index--;					//좌우 반전 시킨 이미지라서 오른쪽부터 인덱스를 읽어와야함
				if (_index < 0)				//인덱스가 첫 번째 프레임보다 작아지면
					_index = _sakura->getMaxFrameX();	//마지막 인덱스로 / 프레임 루프 돌자

				_sakura->setFrameX(_index);
			}
		}
	}
		break;
	case JUMP:
	{
		if (_isRight)
		{
			_count++;
			_sakura->setFrameY(0);

			if (_count % FRAME == 0)
			{
				if (_jumpPw > _cmpJumpPw / 4)
				{
					_sakura->setFrameX(0);
				}
				else if (_jumpPw < _cmpJumpPw / 4 && _jumpPw >(_cmpJumpPw / 4 * 3) * -1)
				{
					_sakura->setFrameX(1);
				}
				else if (_jumpPw < (_cmpJumpPw / 4 * 3) * -1)
				{
					_sakura->setFrameX(2);
				}
			}
		}
		else
		{
			_count++;
			_sakura->setFrameY(1);

			if (_count % FRAME == 0)
			{
				if (_jumpPw > _cmpJumpPw / 4)
				{
					_sakura->setFrameX(2);
				}
				else if (_jumpPw < _cmpJumpPw / 4 && _jumpPw >(_cmpJumpPw / 4 * 3) * -1)
				{
					_sakura->setFrameX(1);
				}
				else if (_jumpPw < (_cmpJumpPw / 4 * 3) * -1)
				{
					_sakura->setFrameX(0);
				}
			}
		}
	}
		break;
	}
}