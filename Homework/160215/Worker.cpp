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
	std::cout << "���Ѵ�" << std::endl;
}

void Worker::GetPay()
{
	std::cout << "������ �޴´�" << std::endl;
}

void Worker::GoToWork()
{
	std::cout << "����Ѵ�" << std::endl;
}

void Worker::GoHome()
{
	std::cout << "����Ѵ�" << std::endl;
}

void Worker::QuitJob()
{
	std::cout << "��ǥ����" << std::endl;
}
