#pragma once

#include "gameNode.h"
#include "player.h"
#include "enemy.h"
#include <algorithm>

class gameStudy : public gameNode
{
private:
	typedef vector<gameObject*> vObject;
	typedef vObject::iterator viObject;

	vObject _vObject;
	viObject _viObject;

	gameObject* _obj;

public:
	gameStudy();
	virtual ~gameStudy();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	static bool Compare(gameObject* start, gameObject* end)
	{
		return start->getRect().bottom < end->getRect().bottom;
	}
};

