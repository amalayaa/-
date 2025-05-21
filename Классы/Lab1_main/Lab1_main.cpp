#include <iostream>
#include <clocale>
#include "fraction.h"
using namespace std;

fraction make_fraction(double F, double S)
{
	fraction t; // создали временную переменную
	t.Init(F, S); // инициализировали поля переменной t с помощью параметров функции
	return t; // вернули значение переменной t
}

int main()
{
	setlocale(LC_ALL, "Russian");
	fraction point;
	point.Init(1, 1); // инициализируем поля струтуры
	point.Read(); // читаем значения полей структуры 
	point.Show(); // выводим значения полей струтуры 
	cout << "Расстояние от точки с координатами (first, second) до начала координат: " << point.distance();
	return 0;
}