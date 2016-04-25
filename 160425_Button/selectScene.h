#pragma once

#pragma warning(disable : 4996)

#include "gameNode.h"
#include "button.h"

struct tagSelect
{
	image* image;
	RECT rc;
	float x, y;
	float angle;
	float maxSpd;
};

class selectScene : public gameNode
{
private:
	tagSelect _battle, _carrier, _phoenix;

	button* _decreaseAngle;
	button* _increaseAngle;
	button* _decreaseMaxSpd;
	button* _increaseMaxSpd;
	button* _select;

public:
	static SHIP _type;
	static float _angle;
	static float _maxSpd;

public:
	selectScene();
	~selectScene();

	HRESULT init();
	void release();
	void update();
	void render();

	static void saveInfo();

	static void onDcrsAngleButton();
	static void onIncrsAngleButton();
	static void onDcrsMaxSpdButton();
	static void onIncrsMaxSpdButton();
	static void onSelectButton();
};

