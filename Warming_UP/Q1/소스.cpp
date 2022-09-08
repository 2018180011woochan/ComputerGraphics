#include <iostream>
#include <random>
#include <stdlib.h>
#include <math.h>

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

double DetMat(int mat[][4], int size);
double CofacMat(int mat[][4], int p, int q, int size);

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
	// 랜덤값을 갖는 행렬 두개 생성
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

	cout << "m : 행렬의 곱셈\n";
	cout << "a : 행렬의 덧셈\n";
	cout << "d : 행렬의 뺄셈\n";
	cout << "r : 행렬식의 값\n";
	cout << "t : 전치 행렬\n";
	cout << "h : 3X3 행렬을 4X4 행렬로 변환하고 행렬식의 값 출력\n";
	cout << "s : 행렬의 값을 새로 랜덤하게 설정한다\n";
	cout << "q : 프로그램 종료\n";

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
		Change4X4();
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

	// 결과 출력
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

	// 결과 출력
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

	// 결과 출력
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
	cout << "======================================\n";
	int FirstTransposed[4][4] = { 0 };
	int SecondTransposed[4][4] = { 0 };
	double factor;

	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			FirstTransposed[i][j] = FirstValue[i][j];
			if (i == 3 || j == 3) {
				FirstTransposed[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			SecondTransposed[i][j] = SecondValue[i][j];
			if (i == 3 || j == 3) {
				SecondTransposed[i][j] = 0;
			}
		}
	}

	FirstTransposed[3][3] = 1;
	SecondTransposed[3][3] = 1;

	cout << "First Transposed\n";
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			cout << FirstTransposed[i][j];
			if (j < 3) cout << " ";
		}
		cout << endl;
	}
	cout << "First Determinant : " << DetMat(FirstTransposed, 4) << endl;

	cout << "\nSecond Transposed\n";
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			cout << SecondTransposed[i][j];
			if (j < 3) cout << " ";
		}
		cout << endl;
	}
	cout << "Second Determinant : " << DetMat(SecondTransposed, 4) << endl;

	cout << "======================================\n";
}

double DetMat(int mat[][4], int size) {
	int p = 0;
	int q = 0;
	double det = 0;
	if (size == 1) {
		return mat[0][0];
	}
	else if ( size == 2 ) { 
		return mat[0][0]*mat[1][1] - mat[0][1]*mat[1][0];
	}
	else {
		for (q = 0, det = 0; q < size; q++) {
			det = det + mat[0][q] * CofacMat(mat, 0, q, size);
		}
		return det;
	}
	return 0;
}

double CofacMat(int mat[][4], int p, int q, int size) {
	int i = 0, j = 0;
	int x=0, y=0;
	int cmat[4][4] = { };
	double cofactor=0;

	for (i=0,x=0 ; i<size ; i++) {
		if (i != p) {
			for (j=0,y=0 ; j<size ; j++) {
				if (j != q) {
					cmat[x][y] = mat[i][j];
					y++;
				}
			}
			x++;
		}
	}
	cofactor = pow(-1,p)*pow(-1,q)*DetMat(cmat,size-1); 

	return cofactor;
}