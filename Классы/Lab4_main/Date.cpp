#include <iostream>
#include "Date.h"
using namespace std;

//конструтор без параметров 
Date::Date(void):Triad()
{
	day = 0;
	month = 0;
	year = 0;
}

//деструтор 
Date::~Date(void)
{

}

//конструктор с параметрами
Date::Date(int D, int M, int Y):Triad(first, second, third)
{
	day = D;
	month = M;
	year = Y;
}

//конструтор копирования 
Date::Date(const Date& d)
{
	first = d.first;
	second = d.second;
	third = d.third;
	day = d.day;
	month = d.month;
	year = d.year;
}

//модификаторы 
void Date::Set_day(int D)
{
	day = D;
}
void Date::Set_month(int M)
{
	month = M;
}
void Date::Set_year(int Y)
{
	year = Y;
}

//перегрузка операции присваивания 
Date& Date::operator=(const Date& d)
{
	if (&d == this) return *this;
	first = d.first;
	second = d.second;
	third = d.third;
	day = d.day;
	month = d.month;
	year = d.year;
	return *this;
}

// Операции сравнения
string Date::operator>(Date& other)
{
	if (year != other.year) 
	{
		return (year > other.year) ? "да" : "нет";
	}
	else if (month != other.month) 
	{
		return (month > other.month) ? "да" : "нет";
	}
	else 
	{
		return (day > other.day) ? "да" : "нет";
	}
}
string Date::operator>(Date& d) 
{
	if (year != d.year) 
	{
		return (year > d.year) ? "да" : "нет";
	}
	else if (month != d.month) 
	{
		return (month > d.month) ? "да" : "нет";
	}
	else 
	{
		return (day > d.day) ? "да" : "нет";
	}
}

string Date::operator==(Date& d)
{
	return (year == d.year && month == d.month && day == d.day) ? "да" : "нет";
}


//глобальная функция для ввода
istream& operator>>(istream& in, Date& d)
{
	cout << "first: "; in >> d.first;
	cout << "second: "; in >> d.second;
	cout << "third: "; in >> d.third;
	cout << "day: "; in >> d.day;
	cout << "month: "; in >> d.month;
	cout << "year: "; in >> d.year;
	return in;
}

//глобальная функция вывода
ostream& operator<<(ostream& out, const Date& d)
{
	out << "\nFIRST: " << d.first;
	out << "\nSECOND: " << d.second;
	out << "\nTHIRD: " << d.third;
	out << "\nDAY: " << d.day;
	out << "\nMONTH: " << d.month;
	out << "\nYEAR: " << d.year;
	out << "\n";
	return out;
}