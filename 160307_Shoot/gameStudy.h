#pragma once

#include "gameNode.h"

class gameStudy : public gameNode
{
private:
	RECT _player, _enemy, _bgBar[4], _hpBar[2], _fatalBar[2], _laser[2];
	POINT _ptPlayer, _ptEnemy;
	int _count, _playerHp, _enemyHp, _enemyHpX, _warningPlayer, _warningEnemy;
	int _playerFt, _enemyFt, _enemyFtX;
	bool _up, _down;

	vector<RECT> _vBullet;
	vector<RECT>::iterator _viBullet;
	vector<RECT> _vEBullet;
	vector<RECT>::iterator _viEBullet;

public:
	gameStudy();
	~gameStudy();

	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);
};

