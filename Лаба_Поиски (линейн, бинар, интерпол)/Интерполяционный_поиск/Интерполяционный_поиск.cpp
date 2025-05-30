﻿#include <iostream>
#include <clocale>
using namespace std;

int interpol_search(int mass[], int n, int key) // вычисляет приблизительное расположение ключа, ориентируясь на расстояние между искомым и текущим значением элемента 
{
	int left = 0;
	int right = n - 1;
	while (left <= right)
	{
		int mid = left + (((key - mass[left]) * (right - left)) / (mass[right] - mass[left]));
		if (mass[mid] == key)
		{
			return mid; // если key найдено, возвращаем его индекс 
		}
		else
		{
			if (mass[mid] < key)
			{
				left = mid + 1; // ищем в правой половине массива
			}
			else
			{
				right = mid - 1; // ищем в левой половине массива
			}
		}
	}
	return -1; // возвращаем -1, если key не найдено 
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int mass[100];
	cout << "Введите размерность массива (не больше 100): ";
	int n;
	cin >> n;
	cout << "Введите элементы массива в порядке возрастания: ";
	for (int i = 0; i < n; i++)
	{
		cin >> mass[i];
	}
	cout << "Введите ключ: ";
	int key;
	cin >> key;
	int a = interpol_search(mass, n, key);
	if (a == -1)
	{
		cout << "Ключ не найден в массиве";
	}
	else
	{
		cout << "Ключ найден в массиве под номером " << a + 1;
	}
	return 0;
}
