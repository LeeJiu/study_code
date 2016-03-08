#include "Item.h"



Item::Item()
{
}

Item::Item(char * pName, char * pInfo, int nDamage, int nSell, int nBuy)
	: _damage(nDamage), _sellPrice(nSell), _buyPrice(nBuy)
{
	_name = new char[strlen(pName) + 1];
	strcpy_s(_name, strlen(pName) + 1, pName);
	
	_info = new char[strlen(pInfo) + 1];
	strcpy_s(_info, strlen(pInfo) + 1, pInfo);
}


Item::~Item()
{
	delete _name;
	delete _info;
}

char * Item::getName() const
{
	return _name;
}

char * Item::getInfo() const
{
	return _info;
}

int Item::getDamage() const
{
	return _damage;
}

int Item::getSellPrice() const
{
	return _sellPrice;
}

int Item::getBuyPrice() const
{
	return _buyPrice;
}
