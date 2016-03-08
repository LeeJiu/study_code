#include "Owner.h"



Owner::Owner()
{
	_item[0] = new Item("버그 검", "개발자의 알고리즘을 쪼갠다", 100, 50, 5);
	_item[1] = new Item("버그 스태프", "연쇄적인 버그가 터진다", 150, 100, 10);
	_item[2] = new Item("서버 다운 스킬북", "서버 다운으로 서버 개발자의 월급을 삭감시킨다", 300, 500, 50);
	_item[3] = new Item("슈뢰딩버그", "개발자에게 알 수 없는 공포감을 준다(디버프)", 0, 600, 60);
	_item[4] = new Item("디버깅", "개발자를 천국으로 보내준다", 10000, 100000, 10000);
}


Owner::~Owner()
{
	for (int i = 0; i < 5; ++i)
		delete _item[i];
}

//아이템의 이름을 보여주자
void Owner::ShowItemList()
{
	cout << "=====================상점======================" << endl;
	for (int i = 0; i < 5; ++i)
	{
		cout << i + 1 << ". " << _item[i]->getName() << endl;
	}
	cout << "===============================================" << endl << endl;
}

void Owner::ShowItemInfo(int nNum)
{
	nNum--;
	cout << "=================아이템 정보===================" << endl;
	cout << "이름 : " << _item[nNum]->getName() << endl;
	cout << "설명 : " << _item[nNum]->getInfo() << endl;
	cout << "구매 가격 : " << _item[nNum]->getSellPrice() << endl;
	cout << "===============================================" << endl << endl;
}

//선택한 아이템을 반환
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
