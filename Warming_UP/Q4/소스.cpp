#include <iostream>
#include <ctime>
using namespace std;


class myRect
{
public:
	myRect(int _x, int _y, int _width, int _height) { X = _x, Y = _y, Width = _width, Height = _height; }
	~myRect() { };

public:
	int X;
	int Y;
	int Width;
	int Height;
};

void PrintRectInfo(myRect* _rect1, myRect* _rect2);
bool isCollid(myRect* _rect1, myRect* _rect2);

int main()
{
	srand((unsigned int)time(NULL));

	// 사각형 두개 좌표 뽑기
	int rand_rect1X = rand() % 800;
	int rand_rect2X = rand() % 800;
	int rand_rect1Y = rand() % 800;
	int rand_rect2Y = rand() % 800;
	
	//myRect* Rect1 = new myRect(rand_rect1X, rand_rect1Y, 10, 10);
	//myRect* Rect2 = new myRect(rand_rect2X, rand_rect2Y, 10, 10);

	myRect* Rect1 = new myRect(300, 500, 100, 100);
	myRect* Rect2 = new myRect(300, 300, 100, 100);

	PrintRectInfo(Rect1, Rect2);

	char command;

	while (1)
	{
		cout << "Command: ";
		cin >> command;

		switch (command)
		{
		case 'w':
			Rect1->Y -= 30;

			PrintRectInfo(Rect1, Rect2);
			if (isCollid(Rect1, Rect2))
				cout << "Collid!" << endl;
			else
				cout << "not Collid" << endl;
			break;
		case 'a':
			break;
		case 's':
			break;
		case 'd':
			break;
		case 'i':
			break;
		case 'j':
			break;
		case 'k':
			break;
		case 'l':
			break;
		}
	}

	if (isCollid(Rect1, Rect2))
		cout << "Collid!" << endl;
	else
		cout << "not Collid" << endl;
}

void PrintRectInfo(myRect* _rect1, myRect* _rect2)
{
	cout << "Rect1: (" << _rect1->X - _rect1->Width << ", " << _rect1->Y - _rect1->Height << ") (" <<
		_rect1->X + _rect1->Width << ", " << _rect1->Y + _rect1->Height << ")" << endl;
	cout << "Rect2: (" << _rect2->X - _rect2->Width << ", " << _rect2->Y - _rect2->Height << ") (" <<
		_rect2->X + _rect2->Width << ", " << _rect2->Y + _rect2->Height << ")" << endl;
}

bool isCollid(myRect* _rect1, myRect* _rect2)
{
	// 한 사각형이 다른 사각형에 완전히 들어가면 충돌처리 안해버림
	if (_rect1->X + _rect1->Width >= _rect2->X && _rect1->X <= _rect2->X + _rect2->Width &&
		_rect1->Y + _rect1->Height >= _rect2->Y && _rect1->Y <= _rect2->Y + _rect2->Height)
		return true;
	else
		return false;
}