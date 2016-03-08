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
	//5. strtok : 문자열을 구분자를 통해 분리시켜주는 함수.
	char str[1024] = "언니, 저 마음에 안 들죠?";
	//과제 출력 예제
	//언니
	//저
	//마음에
	//안
	//들죠?
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

	//Sleep(2000);		//2s 재워
	//system("cls");	//화면 갱신
	//system("pause"); //멈춰라 키누르면 이어서 시작


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

	//로또
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

	cout << "로또 번호" << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << number[i] << ", ";
	}
	cout << endl;

	//주민번호 생성기
	//연도 입력: 93 / 1993 -> 93
	//월 입력: 1 -> 01로 처리하게끔
	//일 입력: 32x, 9월인데 31x
	//성별 입력: 남자, 여자 -> 1, 2 strcmp
	//5자리 랜덤한 숫자
	//맨 마지막은 앞에서 나온 모든 수를 더한 값의 1의 자리
	//출력 : 930213 - 2000000
	

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
