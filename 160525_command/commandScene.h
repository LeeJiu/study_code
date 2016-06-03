#pragma once

#include "gameNode.h"

enum STATE 
{
	IDLE, WALK, RUN, COMMAND1
};


class commandScene : public gameNode
{
private:
	enum eKey
	{
		key_left,
		key_up,
		key_right,
		key_down,
		key_a
	};

	string _str;

	vector<BYTE> _vCommand;

	float _fCommandTime;
	float _fCommandClear;

	image* _kusanagi;
	STATE _state;
	RECT _rc;
	float _x, _y;
	bool _isRight;

	int _count, _curFrameX, _curFrameY;

public:
	commandScene();
	~commandScene();

	HRESULT init();
	void release();
	void update();
	void render();

	void command();
	void setImage();
	void setFrame();
};

