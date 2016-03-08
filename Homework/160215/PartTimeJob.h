#pragma once
#include "SalesPerson.h"
class PartTimeJob :
	public SalesPerson
{
public:
	void GetPay();		//돈을 받는다
	//추가된 함수
	void GetTheKick();	//잘린다
	void Tout();		//호객행위

	PartTimeJob();
	~PartTimeJob();
};

