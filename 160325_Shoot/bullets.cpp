#include "stdafx.h"
#include "bullets.h"


missile::missile()
{
}

missile::~missile()
{
}

HRESULT missile::init(int bulletMax)
{
	for (int i = 0; i < bulletMax; i++)
	{
		tagBullet bullet;
		ZeroMemory(&bullet, sizeof(tagBullet)); //memset�� ���� �޸𸮸� 0���� �ʱ�ȭ ��Ų��.
		bullet.bulletImage = new image;
		bullet.bulletImage->init("breath.bmp", 40, 64, true, 0x00ff00);
		bullet.speed = 5.f;
		bullet.fire = false;

		_vBullet.push_back(bullet);
	}

	return S_OK;
}

void missile::release()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); )
	{
		SAFE_DELETE(_viBullet->bulletImage);
		_viBullet = _vBullet.erase(_viBullet);
	}
}

void missile::update()
{
	move();
}

void missile::render()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		if (!_viBullet->fire) continue;

		_viBullet->bulletImage->render(getMemDC(), _viBullet->rc.left,
			_viBullet->rc.top, 0, 0, _viBullet->bulletImage->getFrameWidth(),
			_viBullet->bulletImage->getFrameHeight());
	}
}

//�߻� �Լ�
void missile::fire(float x, float y)
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		if (_viBullet->fire)continue;
		//�� �Ʒ��� �����Դٴ� ���� �߻簡 ���� �� �� �̻��� �̶�� ����?

		_viBullet->fire = true;
		_viBullet->x = _viBullet->fireX = x;
		_viBullet->y = _viBullet->fireY = y;
		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y,
			_viBullet->bulletImage->getWidth(),
			_viBullet->bulletImage->getHeight());
		break;
	}
}

//�̻��� ��������
void missile::move()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		if (!_viBullet->fire) continue;
		//�� �Ʒ��� �����Դٴ� ���� �߻�� �̻����� �ִٴ� �Ŵ�.

		_viBullet->y -= _viBullet->speed;
		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y,
			_viBullet->bulletImage->getWidth(),
			_viBullet->bulletImage->getHeight());

		if (_viBullet->y < 0)	//ȭ�� ������ ������
		{
			_viBullet->fire = false;
		}
		//���̶� �浹�ϸ�
	}
}

bullet::bullet()
{
}

bullet::~bullet()
{
}

HRESULT bullet::init(int bulletMax)
{
	for (int i = 0; i < bulletMax; i++)
	{
		tagBullet bullet;
		ZeroMemory(&bullet, sizeof(tagBullet)); //memset�� ���� �޸𸮸� 0���� �ʱ�ȭ ��Ų��.
		bullet.bulletImage = new image;
		bullet.bulletImage->init("bullet.bmp", 21, 21, true, 0xff00ff);
		bullet.speed = 5.0f;
		bullet.fire = false;

		_vBullet.push_back(bullet);
	}

	return S_OK;
}

void bullet::release()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); )
	{
		SAFE_DELETE(_viBullet->bulletImage);
		_viBullet = _vBullet.erase(_viBullet);
	}
}

void bullet::update()
{
	move();
}

void bullet::render()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		if (!_viBullet->fire) continue;

		_viBullet->bulletImage->frameRender(getMemDC(), _viBullet->rc.left,
			_viBullet->rc.top);
	}
}

void bullet::fire(float x, float y, float enemnyX, float enemyY)
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		if (_viBullet->fire)continue;
		//�� �Ʒ��� �����Դٴ� ���� �߻簡 ���� �� �� �̻��� �̶�� ����?

		_viBullet->fire = true;
		_viBullet->x = _viBullet->fireX = x;
		_viBullet->y = _viBullet->fireY = y;
		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y,
			_viBullet->bulletImage->getWidth(),
			_viBullet->bulletImage->getHeight());
		_viBullet->angle = MY_UTIL::getAngle(x, y, enemnyX, enemyY);
		break;
	}
}

void bullet::move()
{
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		if (!_viBullet->fire) continue;
		//�� �Ʒ��� �����Դٴ� ���� �߻�� �̻����� �ִٴ� �Ŵ�.

		_viBullet->x += cosf(_viBullet->angle) * _viBullet->speed;
		_viBullet->y += -sinf(_viBullet->angle) * _viBullet->speed;
		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y,
			_viBullet->bulletImage->getWidth(),
			_viBullet->bulletImage->getHeight());

		if (_viBullet->y < 0 || _viBullet->x < 0 || _viBullet->x > WINSIZEX)	//ȭ�� ������ ������
		{
			_viBullet->fire = false;
		}
	}
}
