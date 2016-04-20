#include "stdafx.h"
#include "battle.h"
#include "carrier.h"


battle::battle()
{
}


battle::~battle()
{
}

HRESULT battle::init()
{
	_battle.unit = IMAGEMANAGER->findImage("battle");
	_battle.x = WINSIZEX / 6;
	_battle.y = CENTERY;
	_battle.angle = 0.0f;
	_battle.rc = RectMakeCenter(_battle.x, _battle.y,
		_battle.unit->getFrameWidth(), _battle.unit->getFrameHeight());
	_battle.speed = 0.0f;

	_bullet = new bullet;
	_bullet->init("image/rotate_missile.bmp", 10, 500);

	EFFECTMANAGER->addEffect("explosion3", "image/explosion.bmp", 832, 62, 32, 62, 1, 0.2, 300);

	return S_OK;
}

void battle::release()
{
	_bullet->release();
	SAFE_DELETE(_bullet);
}

void battle::update()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_battle.angle += 0.06f;
		if (_battle.angle > PI * 2) _battle.angle -= PI * 2;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_battle.angle -= 0.06f;
		if (_battle.angle < 0) _battle.angle += PI * 2;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP)) _battle.speed += 0.02f;
	if (KEYMANAGER->isStayKeyDown(VK_DOWN)) _battle.speed -= 0.02f;

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		_bullet->fire(_battle.x, _battle.y, _battle.angle, 5.f);
	}

	int frame;
	float angle;

	/*angle = _battle.angle + PI16;
	if (angle >= PI * 2) angle -= PI * 2;*/

	frame = int(_battle.angle / PI8);
	_battle.unit->setFrameX(frame);

	/*float elapsedTime = TIMEMANAGER->getElapsedTime();
	float moveSpeed = elapsedTime * 200;*/

	_battle.x += cosf(_battle.angle) * _battle.speed /** moveSpeed*/;
	_battle.y += -sinf(_battle.angle) * _battle.speed /** moveSpeed*/;

	_battle.rc = RectMakeCenter(_battle.x, _battle.y, 
		_battle.unit->getFrameWidth(), _battle.unit->getFrameHeight());

	collision();

	_bullet->update();
	EFFECTMANAGER->update();
}

void battle::render()
{
	_bullet->render();
	_battle.unit->frameRender(getMemDC(), _battle.rc.left, _battle.rc.top);
	EFFECTMANAGER->render();

	char str[128];
	sprintf_s(str, "%dµµ %3.2f", int(_battle.angle * 180 / PI), _battle.speed);
	TextOut(getMemDC(), _battle.rc.left, _battle.rc.top - 20, str, strlen(str));
}

void battle::collision()
{
	for (int i = 0; i < _bullet->getVBullet().size(); ++i)
	{
		RECT bullet = _bullet->getVBullet()[i].rc;
		if (IntersectRect(&RectMake(0, 0, 0, 0), &bullet, &_carrier->getRect()))
		{
			EFFECTMANAGER->play("explosion3", bullet.right, bullet.top);
			_bullet->removeBullet(i);
		}
	}
}
