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
	//�����ڷ� �ʱ�ȭ
	Person(const char * pName, int nAge, char * pGender);
	~Person();

	//������ �����ε�
	Person& operator=(const Person&);
	Person& operator+(int);
	Person& operator-(int);

	void Print();
};