#include "stdafx.h"
#include "player.h"
#include "balloon.h"


player::player()
{
}


player::~player()
{
}

HRESULT player::init(const char * imageName)
{
	_targetImage = IMAGEMANAGER->findImage(imageName);

	_leftPt.x = CENTERX - 50;
	_leftPt.y = CENTERY;
	_rightPt.x = CENTERX + 50;
	_rightPt.y = CENTERY;

	_leftTarget = RectMakeCenter(_leftPt.x, _leftPt.y, _targetImage->getWidth(), _targetImage->getHeight());
	_rightTarget = RectMakeCenter(_rightPt.x, _rightPt.y, _targetImage->getWidth(), _targetImage->getHeight());

	_score = 0;

	return S_OK;
}

void player::release()
{
}

void player::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		collision(false);
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		collision(true);
	}

	move();
}

void player::render()
{
	_targetImage->render(getMemDC(), _leftTarget.left, _leftTarget.top);
	_targetImage->render(getMemDC(), _rightTarget.left, _rightTarget.top);
	
	char score[128];
	sprintf_s(score, "Score");
	TextOut(getMemDC(), 50, 353, score, strlen(score));
	sprintf_s(score, "%d", _score);
	TextOut(getMemDC(), 50, 373, score, strlen(score));
}

void player::move()
{
	for (int i = 0; i < _balloon->getVBalloon().size(); i++)
	{
		if (!_balloon->getVBalloon()[i].fire) continue;

		float leftDist = MY_UTIL::getDistance(_leftPt.x, _leftPt.y, _balloon->getVBalloon()[i].x, _balloon->getVBalloon()[i].y);
		float rightDist = MY_UTIL::getDistance(_rightPt.x, _rightPt.y, _balloon->getVBalloon()[i].x, _balloon->getVBalloon()[i].y);

		if (leftDist > rightDist)
		{
			if (_rightPt.y < _balloon->getVBalloon()[i].y - 20)
			{
				_rightPt.y += 3.f;
				_rightTarget = RectMakeCenter(_rightPt.x, _rightPt.y, _targetImage->getWidth(), _targetImage->getHeight());
			}
			else if (_rightPt.y > _balloon->getVBalloon()[i].y + 20)
			{
				_rightPt.y -= 3.f;
				_rightTarget = RectMakeCenter(_rightPt.x, _rightPt.y, _targetImage->getWidth(), _targetImage->getHeight());
			}
		}
		else
		{
			if (_leftPt.y < _balloon->getVBalloon()[i].y - 20)
			{
				_leftPt.y += 5.f;
				_leftTarget = RectMakeCenter(_leftPt.x, _leftPt.y, _targetImage->getWidth(), _targetImage->getHeight());
			}
			else if (_leftPt.y > _balloon->getVBalloon()[i].y + 20)
			{
				_leftPt.y -= 5.f;
				_leftTarget = RectMakeCenter(_leftPt.x, _leftPt.y, _targetImage->getWidth(), _targetImage->getHeight());
			}
		}
	}
}

void player::collision(bool isRight)
{
	if (isRight)
	{
		for (int i = 0; i < _balloon->getVBalloon().size(); i++)
		{
			if (!_balloon->getVBalloon()[i].fire) continue;
			
			if (IntersectRect(&RectMake(0, 0, 0, 0), &_rightTarget, &_balloon->getVBalloon()[i].rc))
			{
				_balloon->getVBalloon()[i].bomb = true;
				_balloon->setBombImage("bomb", i);
				score(i);
			}
			break;
		}
	}
	else
	{
		for (int i = 0; i < _balloon->getVBalloon().size(); i++)
		{
			if (!_balloon->getVBalloon()[i].fire) continue;

			if (IntersectRect(&RectMake(0, 0, 0, 0), &_leftTarget, &_balloon->getVBalloon()[i].rc))
			{
				_balloon->getVBalloon()[i].bomb = true;
				_balloon->setBombImage("bomb", i);
				score(i);
			}
			break;
		}
	}
}

void player::score(int arrNum)
{
	switch (_balloon->getVBalloon()[arrNum].type)
	{
	case ORIGINAL:
		_score += 50;
		break;
	case DOUBLE:
		_score += 100;
		break;
	case BOMB:
		_score -= 50;
		break;
	}
}