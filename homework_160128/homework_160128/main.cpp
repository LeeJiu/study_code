#include <iostream>
#include <Windows.h>		//Sleep(), GetTickCount() ...
#include <ctime>
using namespace std;

int Add(int, int, int);
int Sub(int, int, int);
int Mul(int, int, int);
double Div(double, double, double);


int main(void)
{
	//5. strtok : ���ڿ��� �����ڸ� ���� �и������ִ� �Լ�.
	char str[1024] = "���, �� ������ �� ����?";
	//���� ��� ����
	//���
	//��
	//������
	//��
	//����?
	/*char * ptr = strtok(str, ", ");

	while (ptr != NULL)
	{
		cout << ptr << endl;
		ptr = strtok(NULL, ", ");
	}*/

	char * token;
	char * seperator = ",? ";
	char * context;

	token = strtok_s(str, seperator, &context);
	cout << token << endl;

	while ((token=strtok_s(NULL, seperator, &context)) != NULL)
	{
		cout << token << endl;
	}

	//Sleep(2000);		//2s ���
	//system("cls");	//ȭ�� ����
	//system("pause"); //����� Ű������ �̾ ����


	cout << Add(100, 20, 5) << endl;
	cout << Mul(1, 2, 3) << endl;
	cout << Sub(1, 2, 3) << endl;
	cout << Div(1, 2, 3) << endl;

	//*****
	//****
	//***
	//**
	//*
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5 - i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}

	//*
	//**
	//***
	//****
	//*****

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < i + 1; j++)
			cout << "*";
		cout << endl;
	}

	//*****
	// ****
	//  ***
	//   **
	//    *

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i >= j + 1)
				cout << " ";
			else cout << "*";
		}
		cout << endl;
	}

	//    *
	//   **
	//  ***
	// ****
	//*****
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if(3-i >=j) cout << " ";
			else cout << "*";
		}
		cout << endl;
	}

	//�ζ�
	srand((unsigned)time(NULL));
	int number[45];
	for (int i = 0; i < 45; i++)
	{
		number[i] = i + 1;
	}

	int temp;
	for (int i = 0; i < 90; i++)
	{
		int dest = rand() % 45;
		int sour = rand() % 45;
		
		temp = number[dest];
		number[dest] = number[sour];
		number[sour] = temp;
	}

	cout << "�ζ� ��ȣ" << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << number[i] << ", ";
	}
	cout << endl;

	//�ֹι�ȣ ������
	//���� �Է�: 93 / 1993 -> 93
	//�� �Է�: 1 -> 01�� ó���ϰԲ�
	//�� �Է�: 32x, 9���ε� 31x
	//���� �Է�: ����, ���� -> 1, 2 strcmp
	//5�ڸ� ������ ����
	//�� �������� �տ��� ���� ��� ���� ���� ���� 1�� �ڸ�
	//��� : 930213 - 2000000
	

	return 0;
}

int Add(int a, int b, int c)
{
	return a + b + c;
}

int Sub(int a, int b , int c)
{
	return a - b - c;
}

int Mul(int a, int b, int c)
{
	return a* b* c;
}

double Div(double a, double b, double c)
{
	return a / b / c;
}
