#include "stdafx.h"
#include "starwarsScene.h"
#include "battle.h"
#include "carrier.h"
#include "phoenix.h"

starwarsScene::starwarsScene()
{
}


starwarsScene::~starwarsScene()
{
}

HRESULT starwarsScene::init()
{
	loadInfo();
	
	switch (_type)
	{
	case BATTLE:
		_ship = new battle;
		_ship->init("battle", _loadAngle, _loadMaxSpd);
		break;
	case CARRIER:
		_ship = new carrier;
		_ship->init("carrier", _loadAngle, _loadMaxSpd);
		break;
	case PHOENIX:
		_ship = new phoenix;
		_ship->init("phoenix", _loadAngle, _loadMaxSpd);
		break;
	}

	return S_OK;
}

void starwarsScene::release()
{
	_ship->release();
	SAFE_DELETE(_ship);
}

void starwarsScene::update()
{
	_ship->update();
}

void starwarsScene::render()
{
	_ship->render();

	char str[128];
	sprintf_s(str, " %.3f, %.3f", _loadAngle, _loadMaxSpd);
	TextOut(getMemDC(), 0, 60, str, strlen(str));
}

void starwarsScene::loadInfo()
{
	vector<string> vStr;

	vStr = TXTDATA->txtLoad("saveData.txt");

	_type = (SHIP)atoi(vStr[0].c_str());
	_loadAngle = atoi(vStr[1].c_str()) * 0.001;
	_loadMaxSpd = atoi(vStr[2].c_str()) * 0.001;
}
