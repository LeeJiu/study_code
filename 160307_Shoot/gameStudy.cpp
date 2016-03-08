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

	_up = _down = true;

	_count = _warningPlayer = _warningEnemy = 0;
	_playerHp = _enemyHp = 350;
	_playerFt = _enemyFt = 0;

	_ptPlayer.x = WINSIZEX / 7;
	_ptPlayer.y = CENTERY;
	_ptEnemy.x = WINSIZEX / 7 * 6;
	_ptEnemy.y = RND->getFromIntTo(110, WINSIZEY - 80);
	_player = RectMakeCenter(_ptPlayer.x, _ptPlayer.y, 100, 100);
	_enemy = RectMakeCenter(_ptEnemy.x, _ptEnemy.y, 100, 100);

	_bgBar[0] = RectMake(10, 10, 350, 30);
	_bgBar[1] = RectMake(WINSIZEX - 360, 10, 350, 30);
	_bgBar[2] = RectMake(10, 50, 100, 10);
	_bgBar[3] = RectMake(WINSIZEX - 110, 50, 100, 10);

	_enemyHpX = WINSIZEX - 360;
	_enemyFtX = WINSIZEX - 10;

	_hpBar[0] = RectMake(10, 10, _playerHp, 30);			//�÷��̾�
	_fatalBar[0] = RectMake(10, 50, _playerFt, 10);
	
	_hpBar[1] = RectMake(_enemyHpX, 10, _enemyHp, 30);		//��
	_fatalBar[1] = RectMake(_enemyFtX, 50, _enemyFt, 10);

	return S_OK;
}

void gameStudy::release()
{

	gameNode::release();
}

void gameStudy::update()
{
	_count++;

	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		if(_up)
			_ptPlayer.y -= 5;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		if (_down)
			_ptPlayer.y += 5;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{	//�Ѿ� ����
		_vBullet.push_back(RectMakeCenter(_ptPlayer.x + 60, _ptPlayer.y, 10, 10));
	}

	//���� �����ϴ� ����
	if (_ptEnemy.y < _ptPlayer.y + 50 && _ptEnemy.y > _ptPlayer.y - 50)
	{
		//0.5�ʿ� �ѹ� �ѽ���
		if(_count % 10 == 0)
			_vEBullet.push_back(RectMakeCenter(_ptEnemy.x - 55, _ptEnemy.y, 10, 10));
	}

	//�̵� ������ ���ѽ�Ű��
	if (_player.top < 60)
	{
		_up = false;
		_down = true;
	}
	else if (_player.bottom > WINSIZEY - 30)
	{
		_down = false;
		_up = true;
	}
	else if (_player.top > 60 && _player.bottom < WINSIZEY - 30)
	{
		_up = true;
		_down = true;
	}

	if (_ptPlayer.y < _ptEnemy.y)		//�÷��̾ ���ʿ� �ִٸ�
	{
		_ptEnemy.y -= 3;
	}
	else if (_ptPlayer.y > _ptEnemy.y)	//�÷��̾ �Ʒ��ʿ� �ִٸ�
	{
		_ptEnemy.y += 3;
	}

	//�÷��̾� �Ѿ�
	for (_viBullet = _vBullet.begin(); _viBullet < _vBullet.end();)
	{
		_viBullet->left += 5;
		_viBullet->right += 5;

		//�Ѿ��� ������ ȭ�� ������ ������
		if (_viBullet->left > WINSIZEX)
		{	//�Ѿ��� ������
			_viBullet = _vBullet.erase(_viBullet);
		}
		//�Ѿ��� ������ ������
		else if (IntersectRect(&RectMake(0, 0, 0, 0), &(*_viBullet), &_enemy))
		{
			//���� HP�� ����
			_enemyHpX += 10;		//�� ���� ��ġ ����
			_enemyHp -= 10;			//�� ũ�� ����
			_viBullet = _vBullet.erase(_viBullet);
			_playerFt += 10;
		}
		else
		{
			_viBullet++;			//�� ��� ���⼭ �ɸ���?
		}
	}
	
	//�� �Ѿ�
	for (_viEBullet = _vEBullet.begin(); _viEBullet < _vEBullet.end();)
	{
		_viEBullet->left -= 5;
		_viEBullet->right -= 5;

		if (_viEBullet->right < 0)
		{
			_viEBullet = _vEBullet.erase(_viEBullet);
		}
		//�Ѿ��� �÷��̾�� ������
		else if (IntersectRect(&RectMake(0, 0, 0, 0), &(*_viEBullet), &_player))
		{
			//�÷��̾��� HP�� ����
			_playerHp -= 10;
			_viEBullet = _vEBullet.erase(_viEBullet);
			_enemyFt += 25;		//��ų ������ ����
			_enemyFtX -= 25;
		}
		else
		{
			_viEBullet++;
		}
	}

	//�÷��̾��� ������ �������� �� ����
	if (_playerFt >= 100)
	{
		_playerFt = 0;
		//_laser[0] = RectMakeCenter(_ptPlayer.x, _ptPlayer.y, 500, 10);
	}

	//���� ������ ������ �� ����
	if (_enemyFt >= 100)
	{
		_enemyFt = 0;
		_enemyFtX = WINSIZEX - 10;
	}


	//�÷��̾� HP ����
	if (_playerHp < 350 * 0.5)
		_warningPlayer = 1;
	if(_playerHp < 350 * 0.1)
		_warningPlayer = 2;
	if (_playerHp <= 0)
	{
		release();
		MessageBox(_hWnd, "Lose!!!", "Result", MB_OK);
	}
	
	//�� HP ����
	if (_enemyHp < 350 * 0.5)
		_warningEnemy = 1;
	if (_enemyHp < 350 * 0.1)
		_warningEnemy = 2;
	if (_enemyHp <= 0)
	{
		release();
		MessageBox(_hWnd, "Won!!!", "Result", MB_OK);
	}


	//������Ʈ �ٽ� �׸���
	_player = RectMakeCenter(_ptPlayer.x, _ptPlayer.y, 100, 100);
	_enemy = RectMakeCenter(_ptEnemy.x, _ptEnemy.y, 100, 100);
	_hpBar[0] = RectMake(10, 10, _playerHp, 30);			
	_hpBar[1] = RectMake(_enemyHpX, 10, _enemyHp, 30);
	_fatalBar[0] = RectMake(10, 50, _playerFt, 10);
	_fatalBar[1] = RectMake(_enemyFtX, 50, _enemyFt, 10);

	gameNode::update();
}

void gameStudy::render(HDC hdc)
{
	HBRUSH MyBrush, OldBrush;
	MyBrush = (HBRUSH)GetStockObject(DC_BRUSH);
	OldBrush = (HBRUSH)SelectObject(hdc, MyBrush);

	for (int i = 0; i < 4; ++i)
	{
		Rectangle(hdc, _bgBar[i].left, _bgBar[i].top, _bgBar[i].right, _bgBar[i].bottom);
	}

	SetDCBrushColor(hdc, RGB(255, 0, 0));
	for (int i = 0; i < 2; ++i)
	{
		Rectangle(hdc, _fatalBar[i].left, _fatalBar[i].top, _fatalBar[i].right, _fatalBar[i].bottom);
	}
	
	/*for (int i = 0; i < 2; ++i)
	{
		Rectangle(hdc, _laser[i].left, _laser[i].top, _laser[i].right, _laser[i].bottom);
	}*/
		
	switch (_warningPlayer)
	{
	case 0:
		SetDCBrushColor(hdc, RGB(0, 255, 0));
		break;
	case 1:
		SetDCBrushColor(hdc, RGB(255, 255, 0));
		break;
	case 2:
		SetDCBrushColor(hdc, RGB(255, 0, 0));
		break;
	}
	Rectangle(hdc, _hpBar[0].left, _hpBar[0].top, _hpBar[0].right, _hpBar[0].bottom);

	switch (_warningEnemy)
	{
	case 0:
		SetDCBrushColor(hdc, RGB(0, 255, 0));
		break;
	case 1:
		SetDCBrushColor(hdc, RGB(255, 255, 0));
		break;
	case 2:
		SetDCBrushColor(hdc, RGB(255, 0, 0));
		break;
	}
	Rectangle(hdc, _hpBar[1].left, _hpBar[1].top, _hpBar[1].right, _hpBar[1].bottom);

	SetDCBrushColor(hdc, RGB(0, 0, 255));
	Rectangle(hdc, _player.left, _player.top, _player.right, _player.bottom);
	SetDCBrushColor(hdc, RGB(255, 0, 0));
	Rectangle(hdc, _enemy.left, _enemy.top, _enemy.right, _enemy.bottom);

	SetDCBrushColor(hdc, RGB(0, 0, 0));
	//�Ѿ� �׸���
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		Rectangle(hdc, _viBullet->left, _viBullet->top, _viBullet->right, _viBullet->bottom);
	}

	SetDCBrushColor(hdc, RGB(128, 128, 128));
	for (_viEBullet = _vEBullet.begin(); _viEBullet != _vEBullet.end(); ++_viEBullet)
	{
		Rectangle(hdc, _viEBullet->left, _viEBullet->top, _viEBullet->right, _viEBullet->bottom);
	}

	SelectObject(hdc, OldBrush);
	DeleteObject(MyBrush);
}
