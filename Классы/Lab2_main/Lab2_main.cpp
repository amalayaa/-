#include <iostream>
#include <clocale>
#include <string>
#include "Kvartira.h"
using namespace std;

Kvartira make_kvartira()
{
	string s;
	double d;
	int i;
	cout << "Введите адрес квартиры: ";
	getline(cin, s);
	cout << "Введите площадь квартиры: ";
	cin >> d;
	cout << "Введите количество комнат в квартире: ";
	cin >> i;
	Kvartira t(s, d, i);
	return t;
}

// функция для передачи объекта как параметра
void print_kvartira(Kvartira t)
{
	t.show();
}

void main()
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	system("cls");

	// конструктор без параметров
	Kvartira t1;
	t1.show();

	// конструтор с параметрами
	Kvartira t2("Чайковского 11", 30.0, 2);
	t2.show();

	// констуктор копирования
	Kvartira t3 = t2;
	t3.set_address("20 лет Победы 15");
	t3.set_ploshchad(40.0);
	t3.set_kolKomnal(4);

	// конструтор копирования
	print_kvartira(t3);

	// конструктор копирования
	t1 = make_kvartira();
	t1.show();
}