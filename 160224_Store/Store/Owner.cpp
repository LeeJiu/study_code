#include "Owner.h"



Owner::Owner()
{
	_item[0] = new Item("���� ��", "�������� �˰����� �ɰ���", 100, 50, 5);
	_item[1] = new Item("���� ������", "�������� ���װ� ������", 150, 100, 10);
	_item[2] = new Item("���� �ٿ� ��ų��", "���� �ٿ����� ���� �������� ������ �谨��Ų��", 300, 500, 50);
	_item[3] = new Item("���ڵ�����", "�����ڿ��� �� �� ���� �������� �ش�(�����)", 0, 600, 60);
	_item[4] = new Item("�����", "�����ڸ� õ������ �����ش�", 10000, 100000, 10000);
}


Owner::~Owner()
{
	for (int i = 0; i < 5; ++i)
		delete _item[i];
}

//�������� �̸��� ��������
void Owner::ShowItemList()
{
	cout << "=====================����======================" << endl;
	for (int i = 0; i < 5; ++i)
	{
		cout << i + 1 << ". " << _item[i]->getName() << endl;
	}
	cout << "===============================================" << endl << endl;
}

void Owner::ShowItemInfo(int nNum)
{
	nNum--;
	cout << "=================������ ����===================" << endl;
	cout << "�̸� : " << _item[nNum]->getName() << endl;
	cout << "���� : " << _item[nNum]->getInfo() << endl;
	cout << "���� ���� : " << _item[nNum]->getSellPrice() << endl;
	cout << "===============================================" << endl << endl;
}

//������ �������� ��ȯ
Item * Owner::GetItem(int nNum)
{
	switch (nNum)
	{
	case 1:
		return _item[0];
	case 2:
		return _item[1];
	case 3:
		return _item[2];
	case 4:
		return _item[3];
	case 5:
		return _item[4];
	}
}
