#include <iostream>
#include <clocale>
using namespace std;

void transp_matr(int a1[][100], int longM, int b1[][100])
{
	for (int i = 0; i < longM; ++i)
	{
		for (int j = 0; j < longM; ++j)
		{
			b1[i][j] = a1[j][i];
			cout << b1[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int const n = 100;
	int longMatr;
	int matr[n][n];
	int mass[n][n];
	cout << "Введите размер квадратной матрицы: ";
	cin >> longMatr; 
	cout << "Введите вашу матрицу: " << endl;
	for (int i = 0; i < longMatr; ++i)
	{
		for (int j = 0; j < longMatr; ++j)
		{
			cin >> matr[i][j];
		}
	}
	cout << "Ваша матрица: " << endl; 
	for (int i = 0; i < longMatr; ++i)
	{
		for (int j = 0; j < longMatr; ++j)
		{
			cout << matr[i][j] << " ";
		}
		cout << endl;
	}
	cout << "Транспонированная квадратная матрица: " << endl;
	transp_matr(matr, longMatr, mass);
	return 0;
}
