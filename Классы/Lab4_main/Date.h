#pragma once

#include <iostream>
#include "Triad.h"
using namespace std;

//класс Date наследуется от класса Triad
class Date :
	public Triad
{
public:
	//конструктор без параметров
	Date(void);  

public:
	//деструктор 
	~Date(void); 

	//конструктор с параметрами
	Date(int, int, int);

	//конструктор копирования
	Date(const Date&); 

	//селекторы 
	int Get_day() { return day; }
	int Get_month() { return month; }
	int Get_year() { return year; }

	//модификаторы
	void Set_day(int);
	void Set_month(int);
	void Set_year(int);

	//перугрузка операций присваивания 
	Date& operator=(const Date&);
	string operator>(Date& other);
	string operator<(Date& other);
	string operator==(Date& other);

	//глобальные операторы-функции ввода-вывода
	friend istream& operator>>(istream& in, Date&d);
	friend ostream& operator<<(ostream& out, const Date&d);

	//атрибуты
protected:
	int day;
	int month;
	int year;
};