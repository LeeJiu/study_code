#pragma once
#include "Item.h"
#include <vector>

using std::cout;
using std::endl;

class Owner
{
private:
	Item * _item[5];

public:
	Owner();
	~Owner();

	void ShowItemList();
	void ShowItemInfo(int nNum);
	Item* GetItem(int nNum);
};

