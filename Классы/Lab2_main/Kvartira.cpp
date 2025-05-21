#include <iostream>
#include <clocale>
#include <string>
#include "Kvartira.h"
using namespace std;

// конструктор без параметров
Kvartira::Kvartira()
{
	address = "";
	ploshchad = 0;
	kolKomnat = 0;
	cout << "Конструктор без параметров для объекта " << this << endl;
}

// конструтор с параметрами
Kvartira::Kvartira(string N, double K, int S)
{
	address = N;
	ploshchad = K;
	kolKomnat = S;
	cout << "Конструктор с параметрами для объекта " << this << endl;
}

// конструктор копирования
Kvartira::Kvartira(const Kvartira &t)
{
	address = t.address;
	ploshchad = t.ploshchad;
	kolKomnat = t.kolKomnat;
	cout << "Конструктор копирования для объекта " << this << endl;
}

// деструктор
Kvartira::~Kvartira()
{
	cout << "Деструктор для объекта " << this << endl;
}

// селекторы 
string Kvartira::get_address()
{
	return address;
}

double Kvartira::get_ploshchad()
{
	return ploshchad;
}

int Kvartira::get_kolKomnat()
{
	return kolKomnat;
}

// модификаторы
void Kvartira::set_address(string N)
{
	address = N;
}

void Kvartira::set_ploshchad(double K)
{
	ploshchad = K;
}

void Kvartira::set_kolKomnal(int S)
{
	kolKomnat = S;
}

// метод для просмотра атрибутов
void Kvartira::show()
{
	cout << "Адрес: " << address << endl;
	cout << "Площадь: " << ploshchad << endl;
	cout << "Количество комнат: " << kolKomnat << endl;
}