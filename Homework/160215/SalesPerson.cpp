#include "SalesPerson.h"


//오버라이딩
void SalesPerson::GetPay()
{
	std::cout << "월급 + 인센티브을 받는다" << std::endl;
}

void SalesPerson::Sell()
{
	std::cout << "물건은 판매/영업한다" << std::endl;
}

void SalesPerson::Report()
{
	std::cout << "실적을 보고한다" << std::endl;
}

SalesPerson::SalesPerson()
{
	std::cout << "Create class SalesPerson" << std::endl;
}


SalesPerson::~SalesPerson()
{
	std::cout << "Destroy class SalesPerson" << std::endl;
}
