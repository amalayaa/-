#include <iostream>
#include <clocale>
using namespace std;

int line_search(int mass[], int n, int key)
{
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (mass[i] == key)
		{
			k += 1;
		}
	}
	return k;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int mass[100];
	cout << "Введите размерность массива (не больше 100): ";
	int n;
	cin >> n;
	cout << "Введите элементы массива: ";
	for (int i = 0; i < n; i++)
	{
		cin >> mass[i];
	}
	cout << "Введите ключ: ";
	int key;
	cin >> key;
	cout << "Ключ встречается " << line_search(mass, n, key) << " раз(а) в массиве";
	return 0;
}