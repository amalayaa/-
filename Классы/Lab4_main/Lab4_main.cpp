#include <iostream>
#include <clocale>
#include "Triad.h"
#include "Date.h"
using namespace std;

//функция принимает объект базового класса как параметр
void f1(Triad& t)
{
	t.Set_first(10);
	cout << t;
}

//функция возвращает объект базового класса как результат 
Triad f2()
{
	Date d(1, 9, 2026);
	return d;
}

void main()
{
	//работа с класса Triad
	Triad A;
	cin >> A;
	cout << A;
	Triad B(10, 20, 30);
	cout << B;
	A = B;
	cout << A;

	//работа с классом Date
	Date C;
	cin >> C;
	cout << C;
	f1(C); //передаем объект класса Date
	A = f2(); //создаем функции объекта класса Date
	cout << A;
}