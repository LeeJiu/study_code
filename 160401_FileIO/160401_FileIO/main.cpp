#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
	ifstream ifile;

	char line[200]; // �� �پ� �о �ӽ÷� ������ ����

	ifile.open("input.txt");  // ���� ����

	if (ifile.is_open())
	{
		while (ifile.getline(line, sizeof(line))) // �� �پ� �о� ó���� �����Ѵ�.
		{
			cout << line << endl; // ���� ���
		}
	}

	ifile.close(); // ���� �ݱ�


	ofstream ofile;
	ofile.open("output.txt");

	char str[1024];

	// ���� ����
	cout << "���� ����� ���� ���� �Է�" << endl;
	cin.getline(str, 255);
	ofile << str << endl;


	ofile.close(); // ���ϴݱ�

	return 0;
}