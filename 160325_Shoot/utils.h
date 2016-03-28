#pragma once


#include <cmath>

#define PI 3.141592654f
#define ONE_RAD (PI / 180)
#define PI2 (PI * 2)

//�Ǽ� ��Һ��ϱ� ���� ���� (���� ���� ������� ����)
#define FLOAT_EPSILON 0.001f 

#define BULLETMAX 5
#define MISSILEMAX 5
#define ENEMYMAX 3


namespace MY_UTIL
{
	//�Ÿ� ���ϴ� �Լ�
	float getDistance(float startX, float startY, float endX, float endY);

	//���� ���ϴ� �Լ�
	float getAngle(float startX, float startY, float endX, float endY);
}
