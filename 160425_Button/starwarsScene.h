#pragma once

#include "gameNode.h"
#include "ship.h"


class starwarsScene : public gameNode
{
private:
	ship* _ship;
	SHIP _type;
	float _loadAngle;
	float _loadMaxSpd;

public:
	starwarsScene();
	~starwarsScene();

	HRESULT init();
	void release();
	void update();
	void render();
	
	void loadInfo();
};

