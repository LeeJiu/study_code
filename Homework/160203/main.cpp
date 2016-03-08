#include <iostream>
using namespace std;

int main(void)
{
	char * star = "*****";
	char * space = "     ";

	//*****
	//****
	//***
	//**
	//*
	for (int i = 0; i < 5; i++)
	{
		cout << (star+i) << endl;
	}

	//*
	//**
	//***
	//****
	//*****
	for (int i = 0; i < 5; i++)
	{
		cout << (star + 4 - i) << endl;
	}

	//*****
	// ****
	//  ***
	//   **
	//    *
	for (int i = 0; i < 5; i++)
	{
		cout << space + 5 - i << star + i << endl;
	}

	//    *
	//   **
	//  ***
	// ****
	//*****
	for (int i = 0; i < 5; i++)
	{
		cout << space+i+1 << star+4-i << endl;
	}

	return 0;
}