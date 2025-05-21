#pragma once
#include <iostream>
#include <string>
using namespace std;

class Kvartira
{
	// атрибуты
	string address;
	double ploshchad;
	int kolKomnat;
public:
	Kvartira(); // конструктор без параметров
	Kvartira(string, double, int); //конструтор с параметрами 
	Kvartira(const Kvartira&); // конструктор копирования
	~Kvartira(); // деструктор 
	string get_address(); // селектор
	void set_address(string); // модификатор
	double get_ploshchad(); // селектор
	void set_ploshchad(double); // модификатор
	int get_kolKomnat(); // селектор
	void set_kolKomnal(int); // модификатор
	void show(); // просмотр атрибутов
};