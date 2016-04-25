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
	

	return S_OK;
}

HRESULT starwarsScene::init(SHIP ship)
{
	switch (ship)
	{
	case BATTLE:
		_ship = new battle;
		_ship->init("battle", CENTERX, CENTERY);
		break;
	case CARRIER:
		_ship = new carrier;
		_ship->init("carrier", CENTERX, CENTERY);
		break;
	case PHOENIX:
		_ship = new phoenix;
		_ship->init("phoenix", CENTERX, CENTERY);
		break;
	case NONE:
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
}
