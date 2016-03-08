#include "Person.h"


Person::Person(const char * pName, int nAge, char * pGender)
	: age(nAge)
{
	name = new char[strlen(pName) + 1];
	strcpy_s(name, strlen(pName) + 1, pName);

	gender = new char[strlen(pGender) + 1];
	strcpy_s(gender, strlen(pGender) + 1, pGender);
}

Person::~Person()
{
	delete[] name;
	delete[] gender;
}

Person& Person::operator=(const Person& person)
{
	name = new char[strlen(person.name) + 1];
	strcpy_s(name, strlen(person.name) + 1, person.name);

	age = person.age;

	gender = new char[strlen(person.gender) + 1];
	strcpy_s(gender, strlen(person.gender) + 1, person.gender);

	return *this;
}

Person & Person::operator+(int num)
{
	age += num;
	return *this;
}

Person & Person::operator-(int num)
{
	age -= num;
	return *this;
}

void Person::Print()
{
	cout << "이름: " << name << " 나이: " << age << " 성별: " << gender << endl;;
}
