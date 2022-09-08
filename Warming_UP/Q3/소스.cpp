#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

vector<string> vecString;
char input;
bool isEToggle = false;
int index;
int offset;

string prev_str;
string new_str;

void Core(int _in);
void PirntWord();

int main()
{
	char str[256];

	ifstream readFile{ "data.txt", ios_base::in };

	if (readFile.is_open())
	{
		while (!readFile.eof())
		{
			readFile.getline(str, 256);
			vecString.push_back(str);
			cout << str << endl;
		}
		readFile.close();
	}

	while (1)
	{
		cout << "\nd: 문장 전체를 뒤집기\n";
		cout << "e: 동일한 간격으로 띄어쓰기를 일정 개수 삽입하기\n";
		cout << "f: 띄어쓰기를 기준으로 문자 뒤집기\n";
		cout << "g: 문자 내부의 특정 문자열을 다른 문자열로 바꾸기\n";
		cout << "h: 앞뒤에서 읽었을 때 어디까지 같은 문자인지 출력하기\n";
		cout << "q: 종료\n";

		cin >> input;

		cout << "\n";

		Core(input);
	}

	return 0;
}

void Core(int _in)
{
	switch (_in)
	{
	case 'd':
		reverse(vecString.begin(), vecString.end());

		for (int i = 0; i < vecString.size(); ++i)
		{
			reverse(vecString[i].begin(), vecString[i].end());
		}
		PirntWord();
		break;
	case 'e':	
		if (!isEToggle)
		{
			for (int i = 0; i < vecString.size(); ++i)
			{
				for (int j = 3; j < vecString[i].size(); j += 3)
				{
					vecString[i].insert(j, "@@");
					j += 2;
				}
			}
			isEToggle = true;
		}
		else
		{
			for (int i = 0; i < vecString.size(); ++i)
			{
				vecString[i].erase(remove(vecString[i].begin(), vecString[i].end(), '@'), vecString[i].end());
			}
			isEToggle = false;
		}
		PirntWord();
		break;
	case 'f':
		for (int i = 0; i < vecString.size(); ++i)
		{
			istringstream iss(vecString[i]);
			string str_buf;
			while (getline(iss, str_buf, '@')) {
				string pre_buf = str_buf;
				reverse(str_buf.begin(), str_buf.end());

				vecString[i].replace(vecString[i].find(pre_buf), pre_buf.size(), str_buf);
			}
		}
		PirntWord();
		break;
	case 'g':
		cout << "바꿀 문자: ";
		cin >> prev_str;
		cout << "새로운 문자: ";
		cin >> new_str;

		for (int i = 0; i < vecString.size(); ++i)
		{
			for (int j = 0; j < vecString[i].size(); ++j)
			{
				offset = vecString[i].find(prev_str, offset);

				if (std::string::npos == offset)
					continue;

				vecString[i].replace(vecString[i].find(prev_str), prev_str.length(), new_str);	
			}
			offset = 0;
		}
		PirntWord();
		break;
	case 'h':
		for (int i = 0; i < vecString.size(); ++i)
		{
			if (i == 7)
				int a = 10;
			string result;
			int mysize = vecString[i].size();
			
			for (int j = 0; j < mysize; ++j)
			{
				if (j == mysize - (j + 1))
					break;
				else if (vecString[i][j] == vecString[i][mysize - (j + 1)])
					result += vecString[i][j];
				
				else
					break;
			}

			if (result == "")
				cout << vecString[i] << " : " << 0 << endl;
			else
				cout << vecString[i] << " : " << result << endl;
		}
		break;
	case 'q':
		exit(1);
		break;
	}
}

void PirntWord()
{
	for (int i = 0; i < vecString.size(); ++i)
		cout << vecString[i] << endl;
}