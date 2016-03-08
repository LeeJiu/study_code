#include "Worker.h"



Worker::Worker()
{
	std::cout << "Create class Worker" << std::endl;
}


Worker::~Worker()
{
	std::cout << "Destroy class Worker" << std::endl;
}

void Worker::Work()
{
	std::cout << "일한다" << std::endl;
}

void Worker::GetPay()
{
	std::cout << "월급을 받는다" << std::endl;
}

void Worker::GoToWork()
{
	std::cout << "출근한다" << std::endl;
}

void Worker::GoHome()
{
	std::cout << "퇴근한다" << std::endl;
}

void Worker::QuitJob()
{
	std::cout << "사표낸다" << std::endl;
}
