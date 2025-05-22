#include <iostream>
#include "Date.h"
using namespace std;

//���������� ��� ���������� 
Date::Date(void):Triad()
{
	day = 0;
	month = 0;
	year = 0;
}

//��������� 
Date::~Date(void)
{

}

//����������� � �����������
Date::Date(int D, int M, int Y):Triad(first, second, third)
{
	day = D;
	month = M;
	year = Y;
}

//���������� ����������� 
Date::Date(const Date& d)
{
	first = d.first;
	second = d.second;
	third = d.third;
	day = d.day;
	month = d.month;
	year = d.year;
}

//������������ 
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

//���������� �������� ������������ 
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

// �������� ���������
string Date::operator>(Date& other)
{
	if (year != other.year) 
	{
		return (year > other.year) ? "��" : "���";
	}
	else if (month != other.month) 
	{
		return (month > other.month) ? "��" : "���";
	}
	else 
	{
		return (day > other.day) ? "��" : "���";
	}
}
string Date::operator>(Date& d) 
{
	if (year != d.year) 
	{
		return (year > d.year) ? "��" : "���";
	}
	else if (month != d.month) 
	{
		return (month > d.month) ? "��" : "���";
	}
	else 
	{
		return (day > d.day) ? "��" : "���";
	}
}

string Date::operator==(Date& d)
{
	return (year == d.year && month == d.month && day == d.day) ? "��" : "���";
}


//���������� ������� ��� �����
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

//���������� ������� ������
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