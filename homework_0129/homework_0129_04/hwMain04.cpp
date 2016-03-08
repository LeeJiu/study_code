#include <iostream>
#include <ctime>
using namespace std;

void Year(int num[], int *y);
void Month(int num[], int *m);
void Date(int num[], int *m, int *d);
void Gender(int num[], char g[]);
void RandNum(int num[]);
void LastNum(int num[]);
void Print(int num[]);

int main(void)
{
	int year = 0, month = 0, date = 0, end = 0;
	int number[13] = { 0, };
	char gender[10];

	cout << "���� ������" << endl;
	while (end != -1)
	{
		Year(number, &year);
		Month(number, &month);
		Date(number, &month, &date);
		Gender(number, gender);
		RandNum(number);
		LastNum(number);
		Print(number);
		cout << "�����Ϸ��� -1 �Է�: ";
		cin >> end;
	}

	return 0;
}

void Year(int num[], int * y)
{
	while (true)
	{
		cout << "�� �Է�: ";
		cin >> *y;

		if (!cin.good()) //cin �Է��� �ùٸ��� �ʴٸ�
		{
			//�߻��� ���� �÷��׸� �ʱ�ȭ
			cin.clear();
			//�Է¹��� �ȿ� �ִ� ���� ù��° �Է¹��� ���ڸ�ŭ ���ų� �ι�° ���� ���������� �����
			cin.ignore(INT_MAX, '\n');
			continue;
		}

		if (*y >= 0)
			break;
	}
	if (*y > 100)
		*y %= 100;
	//put year
	num[0] = *y / 10;
	num[1] = *y % 10;

}

void Month(int num[], int * m)
{
	cout << "�� �Է�: ";
	cin >> *m;
	//�� �Է� ����
	while (*m > 12)
	{
		cout << "�߸��� �Է��Դϴ�." << endl;
		cout << "�ٽ� �Է�: ";
		cin >> *m;
	}
	//put month
	num[2] = *m / 10;
	num[3] = *m % 10;
}

void Date(int num[], int * m, int * d)
{
	cout << "�� �Է�: ";
	cin >> *d;
	//���� �� �Է� ����
	if (*m < 8 && *m % 2 == 1 && *d > 31)
	{	//1, 3, 5, 7��
		cout << *m << "���� 31�ϱ��� �Դϴ�." << endl;
		while (*d > 31)
		{
			cout << "�ٽ� �Է�: ";
			cin >> *d;
		}
	}
	else if (*m > 8 && *m % 2 == 0 && *d > 31)
	{	//8, 10, 12��
		cout << *m << "���� 31�ϱ��� �Դϴ�." << endl;
		while (*d > 31)
		{
			cout << "�ٽ� �Է�: ";
			cin >> *d;
		}
	}
	else if (*m < 8 && *m % 2 == 0 && *m != 2 && *d > 30)
	{	//4, 6��
		cout << *m << "���� 30�ϱ��� �Դϴ�." << endl;
		while (*d > 30)
		{
			cout << "�ٽ� �Է�: ";
			cin >> *d;
		}
	}
	else if (*m > 8 && *m % 2 == 0 && *d > 30)
	{	//9, 11��
		cout << *m << "���� 30�ϱ��� �Դϴ�." << endl;
		while (*d > 30)
		{
			cout << "�ٽ� �Է�: ";
			cin >> *d;
		}
	}
	else if (*m == 2 && *d > 28)
	{	//2��
		cout << *m << "���� 28�ϱ��� �Դϴ�." << endl;
		while (*d > 28)
		{
			cout << "�ٽ� �Է�: ";
			cin >> *d;
		}
	}

	//put date
	num[4] = *d / 10;
	num[5] = *d % 10;
}

void Gender(int num[], char g[])
{
	cout << "����: ";
	cin >> g;

	//put gender
	if (strcmp("����", g) < 0)
	{
		num[6] = 2;
	}
	else
		num[6] = 1;
}

void RandNum(int num[])
{
	srand((unsigned)time(NULL));
	//put random number
	for (int i = 7; i < 12; i++)
	{
		num[i] = rand() % 10;
	}
}

void LastNum(int num[])
{
	int sum = 0;
	//put last number
	for (int i = 0; i < 13; i++)
	{
		sum += num[i];
	}
	num[12] = sum % 10;
}

void Print(int num[])
{
	for (int i = 0; i < 13; i++)
	{
		if (i == 6)
		{
			cout << " - ";
		}
		cout << num[i];
	}
	cout << endl << endl;
}
