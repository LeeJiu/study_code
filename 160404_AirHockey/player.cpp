#include "stdafx.h"
#include "player.h"
#include "ball.h"


player::player()
{
}


player::~player()
{
}

HRESULT player::init()
{
	_ptMouse.x = _player.x = CENTERX;
	_ptMouse.y = _player.y = WINSIZEY - 100;
	_player.radius = 25.f;
	_player.angle = 0.f;
	_player.image = IMAGEMANAGER->addImage("player", "image/player.bmp", _player.x, _player.y, 50, 50, true, 0x00ff00);

	_goal = RectMakeCenter(CENTERX, 20, 140, 40);

	_score = 0;

	return S_OK;
}

void player::release()
{
}

void player::update()
{
	_player.x = _ptMouse.x - _player.image->getWidth() / 2;
	_player.y = _ptMouse.y - _player.image->getHeight() / 2;

	collision();
	goal();
}

void player::render()
{
	IMAGEMANAGER->render("player", getMemDC(), _player.x, _player.y);

	Rectangle(getMemDC(), _goal.left, _goal.top, _goal.right, _goal.bottom);

	char str[128];
	sprintf_s(str, "x: %d, y: %d", _ptMouse.x, _ptMouse.y);
	//TextOut(getMemDC(), _ptMouse.x, _ptMouse.y, str, strlen(str));

	sprintf_s(str, "player : %d", _score);
	//TextOut(getMemDC(), 10, CENTERY + 10, str, strlen(str));
}

void player::collision()
{
	float distance = MY_UTIL::getDistance(_player.x, _player.y, _ball->getX(), _ball->getY());

	if (distance < _player.radius + _ball->getRadius())
	{
		float angle = MY_UTIL::getAngle(_player.x, _player.y, _ball->getX(), _ball->getY());
		_ball->setAngle(angle);
		_ball->setSpeed(10.f);
	}
}

void player::goal()
{
	if (IntersectRect(&_tmp, &_goal,
		&RectMake(_ball->getX(), _ball->getY(), _ball->getRadius() * 2, _ball->getRadius() * 2)))
	{
		float height = _tmp.bottom - _tmp.top;
		if (height > _ball->getRadius())
		{
			_score++;
			_ball->init();
		}
	}
}
