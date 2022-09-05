#include <iostream>
#include <random>
#include <stdlib.h>

using namespace std;

char order;

int FirstValue[3][3] = { };
int SecondValue[3][3] = { };

void Init();
void Core(char act);
void Multiple();
void Add();
void Sub();
void Determinant();
void Transposed_matrix();
void Change4X4();

int main()
{
	while (1)
	{
		Init();
	}
}

void Init()
{
	cout << "\n======================================\n";
	// �������� ���� ��� �ΰ� ����
	cout << "- First -\n";
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			int temp = rand() % 3;
			FirstValue[i][j] = temp;
			cout << FirstValue[i][j];
			if (j < 2) cout << " ";
		}
		cout << endl;
	}
	cout << "\n- Second -\n";
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			int temp = rand() % 3;
			SecondValue[i][j] = temp;
			cout << SecondValue[i][j];
			if (j < 2) cout << " ";
		}
		cout << endl;
	}
	cout << "======================================\n";

	cout << "m : ����� ����\n";
	cout << "a : ����� ����\n";
	cout << "d : ����� ����\n";
	cout << "r : ��Ľ��� ��\n";
	cout << "t : ��ġ ���\n";
	cout << "h : 3X3 ����� 4X4 ��ķ� ��ȯ�ϰ� ��Ľ��� �� ���\n";
	cout << "s : ����� ���� ���� �����ϰ� �����Ѵ�\n";
	cout << "q : ���α׷� ����\n";

	cin >> order;

	Core(order);
}

void Core(char act)
{
	switch (act)
	{
	case 'm':
		Multiple();
		break;
	case 'a':
		Add();
		break;
	case 'd':
		Sub();
		break;
	case 'r':
		Determinant();
		break;
	case 't':
		Transposed_matrix();
		break;
	case 'h':

		break;
	case 's':
		break;
	case 'q':
		exit(1);
		break;
	default:
		break;

	}
}

void Multiple()
{
	cout << "======================================\n";
	int Result[3][3] = { };

	// ��� ���
	cout << "- Result -\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				Result[i][j] += FirstValue[i][k] * SecondValue[k][j];
			}
			cout << Result[i][j];
			if (j < 2) cout << " ";
		}
		cout << endl;
	}

	cout << "======================================\n";
}

void Add()
{
	cout << "======================================\n";
	int Result[3][3] = { };

	// ��� ���
	cout << "- Result -\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			Result[i][j] += FirstValue[i][j] + SecondValue[i][j];
			cout << Result[i][j];
			if (j < 2) cout << "  ";
		}
		cout << endl;
	}

	cout << "======================================\n";
}

void Sub()
{
	cout << "======================================\n";
	int Result[3][3] = { };

	// ��� ���
	cout << "- Result -\n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			Result[i][j] += FirstValue[i][j] - SecondValue[i][j];
			cout << Result[i][j];
			if (j < 2) cout << "  ";
		}
		cout << endl;
	}

	cout << "======================================\n";
}

void Determinant()
{
	cout << "======================================\n";
	int Result[3][3] = { };

	cout << "First Determinant : ";
	int det = FirstValue[0][0] * (FirstValue[1][1] * FirstValue[2][2] - FirstValue[2][1] * FirstValue[1][2])
		- FirstValue[0][1] * (FirstValue[1][0] * FirstValue[2][2] - FirstValue[1][2] * FirstValue[2][0])
		+ FirstValue[0][2] * (FirstValue[1][0] * FirstValue[2][1] - FirstValue[1][1] * FirstValue[2][0]); 
	cout << det << endl;

	cout << "Second Determinant : ";
	det = SecondValue[0][0] * (SecondValue[1][1] * SecondValue[2][2] - SecondValue[2][1] * SecondValue[1][2])
		- SecondValue[0][1] * (SecondValue[1][0] * SecondValue[2][2] - SecondValue[1][2] * SecondValue[2][0])
		+ SecondValue[0][2] * (SecondValue[1][0] * SecondValue[2][1] - SecondValue[1][1] * SecondValue[2][0]); 
	cout << det << endl;

	cout << "======================================\n";
}

void Transposed_matrix()
{
	cout << "======================================\n";
	int FirstTransposed[3][3] = {0};
	int SecondTransposed[3][3] = {0};

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			FirstTransposed[j][i] = FirstValue[i][j];
		}
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			SecondTransposed[j][i] = SecondValue[i][j];
		}
	}

	cout << "First Transposed\n";
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cout << FirstTransposed[i][j];
			if (j < 2) cout << " ";
		}
		cout << endl;
	}
	cout << "First Determinant : ";
	int det = FirstTransposed[0][0] * (FirstTransposed[1][1] * FirstTransposed[2][2] - FirstTransposed[2][1] * FirstTransposed[1][2])
		- FirstTransposed[0][1] * (FirstTransposed[1][0] * FirstTransposed[2][2] - FirstTransposed[1][2] * FirstTransposed[2][0])
		+ FirstTransposed[0][2] * (FirstTransposed[1][0] * FirstTransposed[2][1] - FirstTransposed[1][1] * FirstTransposed[2][0]);
	cout << det << endl;

	cout << "\nSecond Transposed\n";
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cout << SecondTransposed[i][j];
			if (j < 2) cout << " ";
		}
		cout << endl;
	}
	cout << "Second Determinant : ";
	det = SecondTransposed[0][0] * (SecondTransposed[1][1] * SecondTransposed[2][2] - SecondTransposed[2][1] * SecondTransposed[1][2])
		- SecondTransposed[0][1] * (SecondTransposed[1][0] * SecondTransposed[2][2] - SecondTransposed[1][2] * SecondTransposed[2][0])
		+ SecondTransposed[0][2] * (SecondTransposed[1][0] * SecondTransposed[2][1] - SecondTransposed[1][1] * SecondTransposed[2][0]);
	cout << det << endl;
	cout << "======================================\n";
}

void Change4X4()
{

}