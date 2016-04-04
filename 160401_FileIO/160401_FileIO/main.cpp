#include <iostream>
#include <fstream>

using namespace std;

int main(void)
{
	ifstream ifile;

	char line[200]; // 한 줄씩 읽어서 임시로 저장할 공간

	ifile.open("input.txt");  // 파일 열기

	if (ifile.is_open())
	{
		while (ifile.getline(line, sizeof(line))) // 한 줄씩 읽어 처리를 시작한다.
		{
			cout << line << endl; // 내용 출력
		}
	}

	ifile.close(); // 파일 닫기


	ofstream ofile;
	ofile.open("output.txt");

	char str[1024];

	// 파일 쓰기
	cout << "파일 출력을 위한 내용 입력" << endl;
	cin.getline(str, 255);
	ofile << str << endl;


	ofile.close(); // 파일닫기

	return 0;
}