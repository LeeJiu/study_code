#include "stdafx.h"
#include "ghostGoblinScene.h"


ghostGoblinScene::ghostGoblinScene()
{
}


ghostGoblinScene::~ghostGoblinScene()
{
}

HRESULT ghostGoblinScene::init()
{
	_knight = new knight;
	_knight->init();

	return S_OK;
}

void ghostGoblinScene::release()
{
	_knight->release();
	SAFE_DELETE( _knight );
}

void ghostGoblinScene::update()
{
	_knight->update();
}

void ghostGoblinScene::render()
{
	_knight->render();
}
