#include "stdafx.h"
#include "enemy.h"


enemy::enemy()
{
}


enemy::~enemy()
{
}


HRESULT enemy::init()
{
	return S_OK;
}

//적 초기화 / 이미지 + 위치
HRESULT enemy::init(const char* imageName, POINT position)
{
	_isBoss = false;

	_currentFrameX = _currentFrameY = 0;
	_count = 0;
	_fireCount = 0;
	_rndFireCount = RND->getFromIntTo(1, 1000);

	//const 포인터 변수 : 이미지 이름으로 이미지를 찾아와서 저장
	_imageName = IMAGEMANAGER->findImage(imageName);
	_rc = RectMakeCenter(position.x, position.y, _imageName->getFrameWidth(), _imageName->getFrameHeight());

	return S_OK;
}

void enemy::release()
{

}

void enemy::update()
{
	//적 프레임 렌더를 돌려주자
	_count++;

	if (_count % 2 == 0)
	{
		_imageName->setFrameX(_imageName->getFrameX() + 1);
		_currentFrameX++;
		if (_currentFrameX > _imageName->getMaxFrameX()) _currentFrameX = 0;
	}
}

void enemy::render()
{
	draw();
}


void enemy::move()
{

}

void enemy::draw()
{
	_imageName->frameRender(getMemDC(), _rc.left, _rc.top, _currentFrameX, _currentFrameY);
}

bool enemy::bulletCountFire()
{
	_fireCount++;

	if (_fireCount % _rndFireCount == 0)
	{
		_fireCount = 0;
		_rndFireCount = RND->getFromIntTo(1, 1000);
		return true;
	}

	return false;
}