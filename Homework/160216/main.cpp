#include "Person.h"

int main(void)
{
	Person Boy("����", 14, "����");
	Person Girl("�̽�", 14, "����");

	cout << "�ʱ�ȭ" << endl;
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