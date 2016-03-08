#include "PartTimeJob.h"



void PartTimeJob::GetPay()
{
	std::cout << "시급을 받는다" << std::endl;
}

void PartTimeJob::GetTheKick()
{
	std::cout << "안타깝지만 잘렸다" << std::endl;
}

void PartTimeJob::Tout()
{
	std::cout << "호객행위를 한다" << std::endl;
}

PartTimeJob::PartTimeJob()
{
	std::cout << "Create class PartTimeJob" << std::endl;
}


PartTimeJob::~PartTimeJob()
{
	std::cout << "Destroy class PartTimeJob" << std::endl;
}
