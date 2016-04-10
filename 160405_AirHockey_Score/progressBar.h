#pragma once

#include "gameNode.h"

class progressBar : public gameNode
{
private:
	RECT _rcProgress;
	int _x, _y;
	float _width;

	image* _progressBarFront;
	image* _progressBarBack;

public:
	progressBar();
	~progressBar();

	HRESULT init(int x, int y, int width, int height);
	void release();
	void update();
	void render();

	//������ ��
	void gauge(float currentGauge, float maxGauge);

	//��ǥ �¾�
	void setX(int x) { _x = x; }
	void setY(int y) { _y = y; }

};

