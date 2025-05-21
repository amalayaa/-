#include <iostream>
#include <clocale>
#include "fraction.h"
using namespace std;

// реальзация метода для инициализации полей структуры
void fraction::Init(double F, double S)
{
	first = F;
	second = S;
}

// реализация метода для чтения значений полей структуры
void fraction::Read()
{
	cout << "\nfirst? "; cin >> first;
	cout << "\nsecond? "; cin >> second;
}

// реализация метода для вывода значений полей структуры
void fraction::Show()
{
	cout << "\nfirst = " << first;
	cout << "\nsecond = " << second;
	cout << "\n";
}

// метод для вычисления расстояния от точки с координатами (first, second) до начала координат 
double fraction::distance()
{
	return sqrt(first * first + second * second);
}