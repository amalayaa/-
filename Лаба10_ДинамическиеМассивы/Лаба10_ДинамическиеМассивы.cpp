#include<iostream>
#include<clocale>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Введите количество строк (n): ";
	int n;
	cin >> n;
	cout << "Введите количество столбцов (m): ";
	int m;
	cin >> m;
	int** array = new int* [n];
	for (int i = 0; i < n; i++)
	{
		array[i] = new int[m];
	}
	cout << "Введите элементы массива: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> array[i][j];
		}
	}
	cout << "Введите номер строки, которую хотите добавить в массив: ";
	int k;
	cin >> k;
	cout << "Исходный массив: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
	int* copyRow = new int[m]; // Выделяем память для новой строки
	for (int j = 0; j < m; j++) // Копируем элементы строки с номером k-1
	{
		copyRow[j] = array[k - 1][j];
	}
	int** newArray = new int* [n + 1]; // Выделяем память для нового массива большего размера
	for (int i = 0; i < n; i++) // Копируем старые строки в новый массив
	{
		newArray[i] = array[i];  // Копируем *указатель* на строку (не нужно выделять память заново)
	}
	newArray[n] = new int[m]; // Выделяем память для новой строки и добавляем ее в конец
	for (int j = 0; j < m; j++)
	{
		newArray[n][j] = copyRow[j]; // Копируем значения в новую строку
	}
	delete[] copyRow;
	delete[] array; // Освобождаем память, занимаемую старым массивом *указателей* (но не сами строки, они перенесены в newArray)
	array = newArray; // Назначаем старому массиву указатель на новый массив
	n++; // Увеличиваем количество строк
	cout << "Новый массив (с добавленной строкой): " << endl;
	for (int i = 0; i < n; i++) // Теперь используем новое значение n
	{
		for (int j = 0; j < m; j++)
		{
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
	
	for (int i = 0; i < n; ++i)
	{
		delete[] array[i];
	}
	delete[] array;
	return 0;
}