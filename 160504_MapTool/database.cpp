#include "stdafx.h"
#include "database.h"


database::database()
{
}


database::~database()
{
}

HRESULT database::init()
{
	//loadDatabase("database.txt");

	return S_OK;
}

void database::release()
{
	iterElement mIter = _mTotalElement.begin();

	for (; mIter != _mTotalElement.end(); ++mIter)
	{
		SAFE_DELETE(mIter->second);
	}

	_mTotalElement.clear();
}

void database::loadDatabase(string name)
{
	//������ �о�´�
	arrElements vTemp;
	vTemp = TXTDATA->txtLoad(name.c_str());

	string str;
	int count = 0;

	//|,number,state,|,number,state,
	for (unsigned int i = 0; i < vTemp.size(); i++)
	{
		if (vTemp[i] == "|")
		{
			elements* em = new elements;
			str = vTemp[i + 1];
			_mTotalElement.insert(pair<string, elements*>(vTemp[i + 1], em));
			if (i != 0) count += 4;
			continue;
		}

		iterElement mIter = _mTotalElement.find(str);
		//�о�� �����͵�
		if (i == count + 1) mIter->second->index = atoi(vTemp[i].c_str());
		else if (i == count + 2) mIter->second->state = atoi(vTemp[i].c_str());
		else if (i == count + 3) mIter->second->draw = atoi(vTemp[i].c_str());
	}

	vTemp.clear();
}

void database::setElementDataNumber(string str, int number)
{
	iterElement mIter = _mTotalElement.find(str);
	mIter->second->index = number;
}

void database::setElementDataState(string str, int state)
{
	iterElement mIter = _mTotalElement.find(str);
	mIter->second->state = state;
}

void database::setElementDataDraw(string str, int draw)
{
	iterElement mIter = _mTotalElement.find(str);
	mIter->second->draw = draw;
}
