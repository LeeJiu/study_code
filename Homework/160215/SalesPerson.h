#pragma once
#include "Worker.h"
class SalesPerson :
	public Worker
{
public:
	void GetPay();		//���� �޴´�
	//�߰��� �Լ�
	void Sell();		//���� �Ǹ�
	void Report();		//����

	SalesPerson();
	~SalesPerson();
};

