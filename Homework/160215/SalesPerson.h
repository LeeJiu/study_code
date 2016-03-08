#pragma once
#include "Worker.h"
class SalesPerson :
	public Worker
{
public:
	void GetPay();		//돈을 받는다
	//추가된 함수
	void Sell();		//물건 판매
	void Report();		//보고

	SalesPerson();
	~SalesPerson();
};

