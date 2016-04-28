#include "stdafx.h"
#include "starwarsScene.h"
#include "battle.h"
#include "carrier.h"

starwarsScene::starwarsScene()
{
}


starwarsScene::~starwarsScene()
{
}

HRESULT starwarsScene::init()
{
	_battle = new battle;
	_carrier = new carrier;

	_battle->init("battle", WINSIZEX / 3, CENTERY);
	_carrier->init("carrier", WINSIZEX / 3 * 2, CENTERY);

	return S_OK;
}

void starwarsScene::release()
{
	_battle->release();
	SAFE_DELETE(_battle);

	_carrier->release();
	SAFE_DELETE(_carrier);
}

void starwarsScene::update()
{
	_battle->update();
	_carrier->update();

	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		SCENEMANAGER->changeScene("select");
	}
}

void starwarsScene::render()
{
	_battle->render();
	_carrier->render();
}
