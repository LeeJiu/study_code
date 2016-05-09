#pragma once

#include "singletonBase.h"

#include <vector>
#include <map>

class elements
{
public:
	int index;
	int state;
	int draw;

	elements() {};
	~elements() {};
};

class database : public singletonBase<database>
{
private:
	typedef vector<string> arrElements;
	typedef vector<string>::iterator iterElements;
	typedef map<string, elements*> arrElement;
	typedef map<string, elements*>::iterator iterElement;

private:
	arrElement _mTotalElement;

public:
	database();
	~database();

	HRESULT init();
	void release();

	void loadDatabase(string name);

	elements* getElementData(string str) { return _mTotalElement.find(str)->second; }

	void setElementDataNumber(string str, int number);
	void setElementDataState(string str, int state);
	void setElementDataDraw(string str, int draw);
};

