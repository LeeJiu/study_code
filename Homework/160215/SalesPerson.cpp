#include "SalesPerson.h"


//�������̵�
void SalesPerson::GetPay()
{
	std::cout << "���� + �μ�Ƽ���� �޴´�" << std::endl;
}

void SalesPerson::Sell()
{
	std::cout << "������ �Ǹ�/�����Ѵ�" << std::endl;
}

void SalesPerson::Report()
{
	std::cout << "������ �����Ѵ�" << std::endl;
}

SalesPerson::SalesPerson()
{
	std::cout << "Create class SalesPerson" << std::endl;
}


SalesPerson::~SalesPerson()
{
	std::cout << "Destroy class SalesPerson" << std::endl;
}
