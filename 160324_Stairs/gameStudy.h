#pragma once

#include "gameNode.h"

#define FRAME 10

enum PLAYERSTATE
{
	ON_GROUND,
	OFF_GROUND
};

enum PLAYERSTATE2
{
	IDLE,
	WALK,
	JUMP
};

struct tagPlayer
{
	RECT player;
	PLAYERSTATE ground;
	PLAYERSTATE2 state;
	float x, y;
};

class gameStudy : public gameNode
{
private:
	image* _sakura;
	image* _shadow;
	image* _box;

	tagPlayer _player;
	bool _isRight;

	RECT _rcBox[3], _rcLand, _tmp;
	
	float _jumpPw, _cmpJumpPw, _gravity;
	int _count, _index;

public:
	gameStudy();
	~gameStudy();

	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

	void collision();
	void imageFrame();
};

