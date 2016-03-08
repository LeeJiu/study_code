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

	//ũ�⸦ �Ҵ��Ͽ� �ʱ� ���Ҵ��� ����
	vNum.reserve(20);

	//������ ����
	//ũ�� 20�� �Ҵ��ϰ� 21��° �����͸� �������� �ϸ�
	//���Ҵ�� ũ�⸦ �󸶳� �� �߰��ؼ� �����?
	for (int i = 0; i < 21; ++i)
	{
		vNum.push_back(i + 1);
	}

	//iterator�� for�� ���鼭 �� ���
	for (viNum = vNum.begin(); viNum != vNum.end(); ++viNum)
	{
		cout << *viNum << " ";

	}
	cout << endl;
	cout << "~���Ҵ� ũ�� Ȯ��~" << endl;
	cout << vNum.capacity() << endl;	//���� ũ���� 1.5��� ���Ҵ�

	cout << "~�� ��° ��ġ�� 100 �߰�~" << endl;
	viNum = vNum.begin();
	vNum.insert(++viNum, 100);
	
	cout << "~�� ��° ��ġ�� ������ ����~" << endl;
	viNum = vNum.begin();				//ù ��°�� ����Ű��
	viNum = vNum.erase(viNum+2);		//erase���� �ݺ��ڰ� ����Ű�� �ִ� �����͸� �����, �� ���� �����͸� ����Ų��.


	cout << "~�� ������ ������ ����~" << endl;
	vNum.pop_back();
	//vector �迭ó�� ����
	for (int i = 0; i < vNum.size(); i++)
	{
		cout << vNum[i] << " ";
	}
	cout << endl;


	cout << "~��� ������ ����~" << endl;
	vNum.clear();
	if (vNum.empty())
		cout << "�����Ͱ� �����ϴ�." << endl << endl;



	//=====================List=====================
	list<int> lNum;
	list<int>::iterator liNum;

	cout << "<List>" << endl;

	//������ ����, �� �ڷ�
	for (int i = 0; i < 10; ++i)
	{
		lNum.push_back(i + 1);
		lNum.push_front((i + 1)*-1);
	}
	//iterator�� for�� ���鼭 �� ���
	for (liNum = lNum.begin(); liNum != lNum.end(); ++liNum)
	{
		cout << *liNum << " ";
	}
	cout << endl;

	cout << "~�� ������ ������ ����~" << endl;
	lNum.pop_back();
	cout << "~�� ù ��° ������ ����~" << endl;
	lNum.pop_front();
	for (liNum = lNum.begin(); liNum != lNum.end(); ++liNum)
	{
		cout << *liNum << " ";
	}
	cout << endl;

	cout << "~�� ��° ��ġ�� 20 �߰�~" << endl;
	liNum = lNum.begin();
	liNum++;
	liNum = lNum.insert(liNum, 20);
	cout << "~������ 5 ����~" << endl;
	lNum.remove(5);
	for (liNum = lNum.begin(); liNum != lNum.end(); ++liNum)
	{
		cout << *liNum << " ";
	}
	cout << endl;

	cout << "~��� ������ ����~" << endl;
	lNum.clear();
	if (lNum.empty())
		cout << "�����Ͱ� �����ϴ�." << endl << endl;



	//=====================Map=====================
	map<int, int> mNum;					// == map<int, int, less<int>> mNum;
	map<int, int>::iterator miNum;

	cout << "<Map>" << endl;

	for (int i = 0; i < 10; ++i)
	{
		mNum.insert(pair<int, int>(10 - i, i + 1));		//Ű ���� 10 -> 1 ������ insert
	}

	cout << "������������ ���ĵ� map ���" << endl;
	//������������ �ڵ� ���ĵǴ��� Ȯ��
	for (miNum = mNum.begin(); miNum != mNum.end(); ++miNum)
	{
		cout << "(" << (*miNum).first << ", " << (*miNum).second << ") ";
	}
	cout << endl << endl;

	cout << "~Ű �� 5�� ������ ����~" << endl;
	mNum.erase(5);	//Ư�� Ű ���� ��Ҹ� ����
	for (miNum = mNum.begin(); miNum != mNum.end(); ++miNum)
	{
		cout << "(" << (*miNum).first << ", " << (*miNum).second << ") ";
	}
	cout << endl << endl;

	cout << "~�� ù ��°���� Ű �� 4������ ������ ����~" << endl;
	mNum.erase(mNum.begin(), mNum.upper_bound(4));
	for (miNum = mNum.begin(); miNum != mNum.end(); ++miNum)
	{
		cout << "(" << (*miNum).first << ", " << (*miNum).second << ") ";
	}
	cout << endl << endl;



	//���� �˰����� ����ϱ� ���ؼ� #include <functional> �߰�!
	map<int, int, greater<int>> mNum2;
	map<int, int>::iterator miNum2;

	for (int i = 0; i < 10; ++i)
	{
		mNum2.insert(pair<int, int>(i + 1, i + 1));	//Ű ���� 1 -> 10 ������ insert
	}

	cout << "������������ ���ĵ� map ���" << endl;
	//������������ �ڵ� ���ĵǴ��� Ȯ��
	for (miNum2 = mNum2.begin(); miNum2 != mNum2.end(); ++miNum2)
	{
		cout << "(" << (*miNum2).first << ", " << (*miNum2).second << ") ";
	}
	cout << endl << endl;

	cout << "~��� ������ ����~" << endl;
	mNum2.clear();		// ==  mNum2.erase(mNum2.begin(), mNum2.end());

	if (mNum2.empty())
		cout << "�����Ͱ� �����ϴ�." << endl;

	return 0;
}