#pragma once

#include <iostream>
#include "Triad.h"
using namespace std;

//����� Date ����������� �� ������ Triad
class Date :
	public Triad
{
public:
	//����������� ��� ����������
	Date(void);  

public:
	//���������� 
	~Date(void); 

	//����������� � �����������
	Date(int, int, int);

	//����������� �����������
	Date(const Date&); 

	//��������� 
	int Get_day() { return day; }
	int Get_month() { return month; }
	int Get_year() { return year; }

	//������������
	void Set_day(int);
	void Set_month(int);
	void Set_year(int);

	//���������� �������� ������������ 
	Date& operator=(const Date&);
	string operator>(Date& other);
	string operator<(Date& other);
	string operator==(Date& other);

	//���������� ���������-������� �����-������
	friend istream& operator>>(istream& in, Date&d);
	friend ostream& operator<<(ostream& out, const Date&d);

	//��������
protected:
	int day;
	int month;
	int year;
};