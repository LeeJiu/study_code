#include <vector>
#include <list>
#include <map>
//#include <algorithm>
#include <functional>
#include <iostream>
#include <ctime>

using namespace std;

int main(void)
{
	//=====================Vector=====================
	vector<int> vNum;
	vector<int>::iterator viNum;

	cout << "<Vector>" << endl;

	//크기를 할당하여 초기 재할당을 막자
	vNum.reserve(20);

	//데이터 삽입
	//크기 20을 할당하고 21번째 데이터를 넣으려고 하면
	//재할당시 크기를 얼마나 더 추가해서 만들까?
	for (int i = 0; i < 21; ++i)
	{
		vNum.push_back(i + 1);
	}

	//iterator로 for문 돌면서 값 출력
	for (viNum = vNum.begin(); viNum != vNum.end(); ++viNum)
	{
		cout << *viNum << " ";

	}
	cout << endl;
	cout << "~재할당 크기 확인~" << endl;
	cout << vNum.capacity() << endl;	//이전 크기의 1.5배로 재할당

	cout << "~두 번째 위치에 100 추가~" << endl;
	viNum = vNum.begin();
	vNum.insert(++viNum, 100);
	
	cout << "~세 번째 위치의 데이터 삭제~" << endl;
	viNum = vNum.begin();				//첫 번째를 가리키고
	viNum = vNum.erase(viNum+2);		//erase안의 반복자가 가리키고 있는 데이터를 지우고, 그 다음 데이터를 가리킨다.


	cout << "~맨 마지막 데이터 삭제~" << endl;
	vNum.pop_back();
	//vector 배열처럼 쓰기
	for (int i = 0; i < vNum.size(); i++)
	{
		cout << vNum[i] << " ";
	}
	cout << endl;


	cout << "~모든 데이터 삭제~" << endl;
	vNum.clear();
	if (vNum.empty())
		cout << "데이터가 없습니다." << endl << endl;



	//=====================List=====================
	list<int> lNum;
	list<int>::iterator liNum;

	cout << "<List>" << endl;

	//데이터 삽입, 앞 뒤로
	for (int i = 0; i < 10; ++i)
	{
		lNum.push_back(i + 1);
		lNum.push_front((i + 1)*-1);
	}
	//iterator로 for문 돌면서 값 출력
	for (liNum = lNum.begin(); liNum != lNum.end(); ++liNum)
	{
		cout << *liNum << " ";
	}
	cout << endl;

	cout << "~맨 마지막 데이터 삭제~" << endl;
	lNum.pop_back();
	cout << "~맨 첫 번째 데이터 삭제~" << endl;
	lNum.pop_front();
	for (liNum = lNum.begin(); liNum != lNum.end(); ++liNum)
	{
		cout << *liNum << " ";
	}
	cout << endl;

	cout << "~두 번째 위치에 20 추가~" << endl;
	liNum = lNum.begin();
	liNum++;
	liNum = lNum.insert(liNum, 20);
	cout << "~데이터 5 삭제~" << endl;
	lNum.remove(5);
	for (liNum = lNum.begin(); liNum != lNum.end(); ++liNum)
	{
		cout << *liNum << " ";
	}
	cout << endl;

	cout << "~모든 데이터 삭제~" << endl;
	lNum.clear();
	if (lNum.empty())
		cout << "데이터가 없습니다." << endl << endl;



	//=====================Map=====================
	map<int, int> mNum;					// == map<int, int, less<int>> mNum;
	map<int, int>::iterator miNum;

	cout << "<Map>" << endl;

	for (int i = 0; i < 10; ++i)
	{
		mNum.insert(pair<int, int>(10 - i, i + 1));		//키 값을 10 -> 1 순으로 insert
	}

	cout << "오름차순으로 정렬된 map 출력" << endl;
	//오름차순으로 자동 정렬되는지 확인
	for (miNum = mNum.begin(); miNum != mNum.end(); ++miNum)
	{
		cout << "(" << (*miNum).first << ", " << (*miNum).second << ") ";
	}
	cout << endl << endl;

	cout << "~키 값 5의 데이터 삭제~" << endl;
	mNum.erase(5);	//특정 키 값의 요소를 삭제
	for (miNum = mNum.begin(); miNum != mNum.end(); ++miNum)
	{
		cout << "(" << (*miNum).first << ", " << (*miNum).second << ") ";
	}
	cout << endl << endl;

	cout << "~맨 첫 번째에서 키 값 4까지의 데이터 삭제~" << endl;
	mNum.erase(mNum.begin(), mNum.upper_bound(4));
	for (miNum = mNum.begin(); miNum != mNum.end(); ++miNum)
	{
		cout << "(" << (*miNum).first << ", " << (*miNum).second << ") ";
	}
	cout << endl << endl;



	//정렬 알고리즘을 사용하기 위해서 #include <functional> 추가!
	map<int, int, greater<int>> mNum2;
	map<int, int>::iterator miNum2;

	for (int i = 0; i < 10; ++i)
	{
		mNum2.insert(pair<int, int>(i + 1, i + 1));	//키 값을 1 -> 10 순으로 insert
	}

	cout << "내림차순으로 정렬된 map 출력" << endl;
	//내림차순으로 자동 정렬되는지 확인
	for (miNum2 = mNum2.begin(); miNum2 != mNum2.end(); ++miNum2)
	{
		cout << "(" << (*miNum2).first << ", " << (*miNum2).second << ") ";
	}
	cout << endl << endl;

	cout << "~모든 데이터 삭제~" << endl;
	mNum2.clear();		// ==  mNum2.erase(mNum2.begin(), mNum2.end());

	if (mNum2.empty())
		cout << "데이터가 없습니다." << endl;

	return 0;
}