#pragma once

#include "gameNode.h"
#include "button.h"

class selectScene : public gameNode
{
private:
	button* _buttonAngleUp;
	button* _buttonAngleDown;

public:
	selectScene();
	~selectScene();

	HRESULT init();
	void release();
	void update();
	void render();

	static void onAngleUp();
	static void onAngleDown();
};

