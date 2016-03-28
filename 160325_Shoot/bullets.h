#pragma once

#include "gameNode.h"
#include <vector>

struct tagBullet
{
	image* bulletImage;
	RECT rc;
	int radius;
	float angle;
	float x, y;
	float fireX, fireY;
	float speed;
	bool fire;
};

class missile : public gameNode
{
private:
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;


public:
	missile();
	~missile();

	HRESULT init(int bulletMax);
	void release();
	void update();
	void render();

	//발사 함수
	void fire(float x, float y);

	//미사일 움직움직
	void move();

	//벡터의 참조자를 던져주자. call by reference
	//그냥 던지면 call by value 이므로 복사된 값이 가서
	//값의 변경은 이루어지지 않는다.
	vector<tagBullet>& getMissileVec() { return _vBullet; }
};

//각도 뷸렛 만들자
class bullet : public gameNode
{
private:
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;

public:
	bullet();
	~bullet();

	HRESULT init(int bulletMax);
	void release();
	void update();
	void render();

	//발사 함수
	void fire(float x, float y, float shipX, float shipY);

	//미사일 움직움직
	void move();

	vector<tagBullet>& getBulletVec() { return _vBullet; }
};