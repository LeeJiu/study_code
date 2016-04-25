#include "stdafx.h"
#include "selectScene.h"

float selectScene::_angle = 0.f;
float selectScene::_maxSpd = 0.f;
SHIP selectScene::_type = BATTLE;

selectScene::selectScene()
{
}


selectScene::~selectScene()
{
}

HRESULT selectScene::init()
{
	IMAGEMANAGER->addFrameImage("button", "image/button.bmp", 64, 32, 2, 1, true, 0xff00ff);
	IMAGEMANAGER->addFrameImage("select", "image/select.bmp", 42, 21, 1, 1, false, false);

	_decreaseAngle = new button;
	_decreaseAngle->init("button", CENTERX - 100, CENTERY + 100, PointMake(0, 0), PointMake(0, 0), onDcrsAngleButton);
	_increaseAngle = new button;
	_increaseAngle->init("button", CENTERX + 100, CENTERY + 100, PointMake(1, 0), PointMake(1, 0), onIncrsAngleButton);

	_decreaseMaxSpd = new button;
	_decreaseMaxSpd->init("button", CENTERX - 100, CENTERY + 150, PointMake(0, 0), PointMake(0, 0), onDcrsMaxSpdButton);
	_increaseMaxSpd = new button;
	_increaseMaxSpd->init("button", CENTERX + 100, CENTERY + 150, PointMake(1, 0), PointMake(1, 0), onIncrsMaxSpdButton);

	_select = new button;
	_select->init("select", CENTERX, CENTERY + 200, PointMake(0, 0), PointMake(0, 0), onSelectButton);

	_battle.x = WINSIZEX / 4;
	_carrier.x = WINSIZEX / 4 * 2;
	_phoenix.x = WINSIZEX / 4 * 3;
	_battle.y = _carrier.y = _phoenix.y = CENTERY;

	_battle.angle = _carrier.angle = _phoenix.angle = 0.f;
	_battle.maxSpd = _carrier.maxSpd = _phoenix.maxSpd = 0.f;

	_battle.image = IMAGEMANAGER->findImage("battle");
	_carrier.image = IMAGEMANAGER->findImage("carrier");
	_phoenix.image = IMAGEMANAGER->findImage("phoenix");

	_battle.rc = RectMakeCenter(_battle.x, _battle.y, _battle.image->getFrameWidth(), _battle.image->getFrameHeight());
	_carrier.rc = RectMakeCenter(_carrier.x, _carrier.y, _carrier.image->getFrameWidth(), _carrier.image->getFrameHeight());
	_phoenix.rc = RectMakeCenter(_phoenix.x, _phoenix.y, _phoenix.image->getFrameWidth(), _phoenix.image->getFrameHeight());

	_battle.image->setFrameX(_battle.angle / PI8);
	_carrier.image->setFrameX(_carrier.angle / PI16);
	_phoenix.image->setFrameX(_phoenix.angle / (PI / 13));

	return S_OK;
}

void selectScene::release()
{
	SAFE_DELETE(_decreaseAngle);
	SAFE_DELETE(_increaseAngle);
	SAFE_DELETE(_decreaseMaxSpd);
	SAFE_DELETE(_increaseMaxSpd);
	SAFE_DELETE(_select);
}

void selectScene::update()
{
	_decreaseAngle->update();
	_increaseAngle->update();
	_decreaseMaxSpd->update();
	_increaseMaxSpd->update();
	_select->update();

	if (PtInRect(&_battle.rc, _ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			selectScene::_angle = _battle.angle;
			selectScene::_maxSpd = _battle.maxSpd;
			selectScene::_type = BATTLE;
		}
	}
	if (PtInRect(&_carrier.rc, _ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			selectScene::_angle = _carrier.angle;
			selectScene::_maxSpd = _carrier.maxSpd;
			selectScene::_type = CARRIER;
		}
	}
	if (PtInRect(&_phoenix.rc, _ptMouse))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			selectScene::_angle = _phoenix.angle;
			selectScene::_maxSpd = _phoenix.maxSpd;
			selectScene::_type = PHOENIX;
		}
	}

	switch (selectScene::_type)
	{
	case BATTLE:
		_battle.angle = selectScene::_angle;
		_battle.maxSpd = selectScene::_maxSpd;
		_battle.image->setFrameX(_battle.angle / PI8);
		break;
	case CARRIER:
		_carrier.angle = selectScene::_angle;
		_carrier.maxSpd = selectScene::_maxSpd;
		_carrier.image->setFrameX(_carrier.angle / PI16);
		break;
	case PHOENIX:
		_phoenix.angle = selectScene::_angle;
		_phoenix.maxSpd = selectScene::_maxSpd;
		_phoenix.image->setFrameX(_phoenix.angle / (PI / 13));
		break;
	}
}

void selectScene::render()
{
	_decreaseAngle->render();
	_increaseAngle->render();
	_decreaseMaxSpd->render();
	_increaseMaxSpd->render();
	_select->render();

	_battle.image->frameRender(getMemDC(), _battle.rc.left, _battle.rc.top);
	_carrier.image->frameRender(getMemDC(), _carrier.rc.left, _carrier.rc.top);
	_phoenix.image->frameRender(getMemDC(), _phoenix.rc.left, _phoenix.rc.top);

	char str[128];
	sprintf_s(str, "radian : %.2f", selectScene::_angle);
	TextOut(getMemDC(), CENTERX - 50, CENTERY + 90, str, strlen(str));
	
	sprintf_s(str, "max speed : %.2f", selectScene::_maxSpd);
	TextOut(getMemDC(), CENTERX - 50, CENTERY + 140, str, strlen(str));
}

void selectScene::saveInfo()
{
	char temp[128];
	vector<string> vStr;

	vStr.push_back(itoa((int)_type, temp, 10));
	vStr.push_back(itoa((selectScene::_angle * 1000), temp, 10));
	vStr.push_back(itoa((selectScene::_maxSpd * 1000), temp, 10));

	TXTDATA->txtSave("saveData.txt", vStr);
}

void selectScene::onDcrsAngleButton()
{
	selectScene::_angle -= 0.05f;
	if (selectScene::_angle < 0)
		selectScene::_angle += PI2;
}

void selectScene::onIncrsAngleButton()
{
	selectScene::_angle += 0.05f;
	if (selectScene::_angle > PI2)
		selectScene::_angle -= PI2;
}

void selectScene::onDcrsMaxSpdButton()
{
	selectScene::_maxSpd -= 0.1f;
	if (selectScene::_maxSpd < 0)
		selectScene::_maxSpd = 0.f;
}

void selectScene::onIncrsMaxSpdButton()
{
	selectScene::_maxSpd += 0.1f;
}

void selectScene::onSelectButton()
{
	saveInfo();
	SCENEMANAGER->changeScene("starwars");
}
