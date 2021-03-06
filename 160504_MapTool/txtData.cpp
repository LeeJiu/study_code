#include "stdafx.h"
#include "txtData.h"


txtData::txtData()
{
}


txtData::~txtData()
{
}


HRESULT txtData::init()
{
	return S_OK;
}

void txtData::release()
{

}

//세이브
void txtData::txtSave(const char* saveFileName, vector<string> vStr)
{
	HANDLE file;

	char str[65536];
	DWORD write;

	strncpy_s(str, 65536, vectorArrayCombine(vStr), 65534);

	//파일 생성
	file = CreateFile(saveFileName, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL, NULL);

	//파일에 쓰기
	WriteFile(file, str, 65536, &write, NULL);

	CloseHandle(file);
}

char* txtData::vectorArrayCombine(vector<string> vArray)
{
	char str[65536];

	ZeroMemory(str, sizeof(str));

	for (int i = 0; i < vArray.size(); i++)
	{
		strncat_s(str, 65536, vArray[i].c_str(), 65534);
		if (i + 1 < vArray.size()) strcat_s(str, ",");
	}

	return str;
}


//로드
vector<string> txtData::txtLoad(const char* loadFileName)
{
	HANDLE file;

	char str[65536];
	DWORD read;

	memset(str, 0, sizeof(str));

	file = CreateFile(loadFileName, GENERIC_READ, 0, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, str, 65536, &read, NULL);
	CloseHandle(file);

	return charArraySeparation(str);
}

vector<string> txtData::charArraySeparation(char charArray[])
{
	vector<string> vArray;

	char* temp;
	char* separator = ",";
	char* token;

	token = strtok_s(charArray, separator, &temp);
	vArray.push_back(token);

	while (NULL != (token = strtok_s(NULL, separator, &temp)))
	{
		vArray.push_back(token);
	}

	return vArray;
}