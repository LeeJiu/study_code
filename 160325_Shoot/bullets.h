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

	//�߻� �Լ�
	void fire(float x, float y);

	//�̻��� ��������
	void move();

	//������ �����ڸ� ��������. call by reference
	//�׳� ������ call by value �̹Ƿ� ����� ���� ����
	//���� ������ �̷������ �ʴ´�.
	vector<tagBullet>& getMissileVec() { return _vBullet; }
};

//���� �淿 ������
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

	//�߻� �Լ�
	void fire(float x, float y, float shipX, float shipY);

	//�̻��� ��������
	void move();

	vector<tagBullet>& getBulletVec() { return _vBullet; }
};