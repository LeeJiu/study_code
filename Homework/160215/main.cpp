#include <iostream>
#include "Worker.h"
#include "SalesPerson.h"
#include "PartTimeJob.h"
using namespace std;

int main(void)
{
	Worker wk;
	SalesPerson sp;
	PartTimeJob pj;

	wk.GoToWork();
	wk.Work();
	wk.GoHome();
	cout << "�Ѵ� ��" << endl;
	wk.GetPay();
	cout << endl;

	sp.GoToWork();
	sp.Work();
	sp.Sell();
	sp.Report();
	sp.GoHome();
	cout << "�Ѵ� ��" << endl;
	sp.GetPay();
	cout << endl;

	pj.GoToWork();
	pj.Work();
	pj.Tout();
	pj.GetTheKick();
	pj.GoHome();
	pj.GetPay();
	cout << endl;

	return 0;
}