#include "Person.h"

int main(void)
{
	Person Boy("지우", 14, "남자");
	Person Girl("이슬", 14, "여자");

	cout << "초기화" << endl;
	Boy.Print();
	Girl.Print();

	cout << "Girl = Boy" << endl;
	Girl = Boy;
	Girl.Print();

	cout << "Boy + 1, Girl + 2" << endl;
	Boy + 1;
	Girl + 2;
	Boy.Print();
	Girl.Print();

	return 0;
}