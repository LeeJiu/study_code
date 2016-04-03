#include "stdafx.h"
#include "boss.h"


boss::boss()
{
}


boss::~boss()
{
}

HRESULT boss::init(const char * imageName, POINT position)
{
	_isBoss = true;

	_pattern = PATTERN_1;

	_currentFrameX = _currentFrameY = 0;
	_count = 0;

	//const 포인터 변수 : 이미지 이름으로 이미지를 찾아와서 저장
	_imageName = IMAGEMANAGER->findImage(imageName);
	_rc = RectMakeCenter(position.x, position.y, _imageName->getFrameWidth(), _imageName->getFrameHeight());

	return S_OK;
}

void boss::update()
{
	_count++;

	if (_count % 2 == 0)
	{
		_imageName->setFrameX(_imageName->getFrameX() + 1);
		_currentFrameX++;
		if (_currentFrameX > _imageName->getMaxFrameX()) _currentFrameX = 0;
	}
}

bool boss::bulletCountFire()
{
	_fireCount++;

	if (_fireCount % 10 == 0)
	{
		_fireCount = 0;
		return true;
	}
	return false;
}
