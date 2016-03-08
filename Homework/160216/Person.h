#pragma once
#include <iostream>
using namespace std;

class Person
{
private:
	char * name;
	int age;
	char * gender;

public:
	//생성자로 초기화
	Person(const char * pName, int nAge, char * pGender);
	~Person();

	//연산자 오버로딩
	Person& operator=(const Person&);
	Person& operator+(int);
	Person& operator-(int);

	void Print();
};