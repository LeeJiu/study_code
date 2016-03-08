#pragma once
#include <iostream>
#include <ctime>
#include <Windows.h>
using namespace std;

struct stCard
{
	char * shape;
	int number;
};


class HighLowSeven
{
	stCard _card[52];
	int _money;

public:
	HighLowSeven();
	~HighLowSeven();

	void CardPrint(int num);
};

