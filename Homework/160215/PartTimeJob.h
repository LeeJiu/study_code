#pragma once
#include "SalesPerson.h"
class PartTimeJob :
	public SalesPerson
{
public:
	void GetPay();		//���� �޴´�
	//�߰��� �Լ�
	void GetTheKick();	//�߸���
	void Tout();		//ȣ������

	PartTimeJob();
	~PartTimeJob();
};

