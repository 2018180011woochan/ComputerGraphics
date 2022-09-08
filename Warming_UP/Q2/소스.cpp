#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int main()
{
	char str[256];
	int wordCnt = 0;
	int NumCnt = 0;
	int UpperCnt = 0;

	vector<string> vecString;
	ifstream readFile{ "data.txt", ios_base::in };

	if (readFile.is_open())
	{
		while (!readFile.eof())
		{
			//getline(readFile, str);
			readFile.getline(str, 256);
			//readFile >> str;
			vecString.push_back(str);
			cout << str << endl;
		}
		readFile.close();
	}

	for (int i = 0; i < vecString.size(); ++i)
	{
		istringstream iss(vecString[i]);
		string str_buf;
		while (getline(iss, str_buf, ' ')) {
			wordCnt += 1;

			// 숫자 세기
			if (atoi(str_buf.c_str()) != 0)
			{
				for (int i = 0; i < str_buf.size(); ++i)
				{
					if (!isdigit(str_buf[i]))
						NumCnt -= 1;
				}
				NumCnt += 1;
			}

			if (isupper(str_buf[0]))
				UpperCnt += 1;

		}
	}

	cout << "\nWord count: " << wordCnt << endl;
	cout << "Num count: " << NumCnt << endl;
	cout << "Capital count: " << UpperCnt << endl;

	return 0;
}
