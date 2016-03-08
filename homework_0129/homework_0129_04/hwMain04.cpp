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

	cout << "윤년 없음ㅋ" << endl;
	while (end != -1)
	{
		Year(number, &year);
		Month(number, &month);
		Date(number, &month, &date);
		Gender(number, gender);
		RandNum(number);
		LastNum(number);
		Print(number);
		cout << "종료하려면 -1 입력: ";
		cin >> end;
	}

	return 0;
}

void Year(int num[], int * y)
{
	while (true)
	{
		cout << "연 입력: ";
		cin >> *y;

		if (!cin.good()) //cin 입력이 올바르지 않다면
		{
			//발생한 에러 플레그를 초기화
			cin.clear();
			//입력버퍼 안에 있는 글자 첫번째 입력받은 숫자만큼 비우거나 두번째 인자 만날때까지 비우자
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
	cout << "월 입력: ";
	cin >> *m;
	//월 입력 조건
	while (*m > 12)
	{
		cout << "잘못된 입력입니다." << endl;
		cout << "다시 입력: ";
		cin >> *m;
	}
	//put month
	num[2] = *m / 10;
	num[3] = *m % 10;
}

void Date(int num[], int * m, int * d)
{
	cout << "일 입력: ";
	cin >> *d;
	//월별 일 입력 조건
	if (*m < 8 && *m % 2 == 1 && *d > 31)
	{	//1, 3, 5, 7월
		cout << *m << "월은 31일까지 입니다." << endl;
		while (*d > 31)
		{
			cout << "다시 입력: ";
			cin >> *d;
		}
	}
	else if (*m > 8 && *m % 2 == 0 && *d > 31)
	{	//8, 10, 12월
		cout << *m << "월은 31일까지 입니다." << endl;
		while (*d > 31)
		{
			cout << "다시 입력: ";
			cin >> *d;
		}
	}
	else if (*m < 8 && *m % 2 == 0 && *m != 2 && *d > 30)
	{	//4, 6월
		cout << *m << "월은 30일까지 입니다." << endl;
		while (*d > 30)
		{
			cout << "다시 입력: ";
			cin >> *d;
		}
	}
	else if (*m > 8 && *m % 2 == 0 && *d > 30)
	{	//9, 11월
		cout << *m << "월은 30일까지 입니다." << endl;
		while (*d > 30)
		{
			cout << "다시 입력: ";
			cin >> *d;
		}
	}
	else if (*m == 2 && *d > 28)
	{	//2월
		cout << *m << "월은 28일까지 입니다." << endl;
		while (*d > 28)
		{
			cout << "다시 입력: ";
			cin >> *d;
		}
	}

	//put date
	num[4] = *d / 10;
	num[5] = *d % 10;
}

void Gender(int num[], char g[])
{
	cout << "성별: ";
	cin >> g;

	//put gender
	if (strcmp("남자", g) < 0)
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
