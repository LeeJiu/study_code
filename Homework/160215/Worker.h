#pragma once
#include <iostream>

class Worker
{
public:
	Worker();
	~Worker();

	void Work();		//일한다
	void GetPay();		//돈을 받는다
	void GoToWork();	//일하러 간다
	void GoHome();		//집에 간다
	void QuitJob();		//일을 그만둔다
};

