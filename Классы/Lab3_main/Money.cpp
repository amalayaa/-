#include <iostream>
#include <cmath>
#include "Money.h"
using namespace std;

//���������� �������� ������������ 
Money& Money::operator=(const Money& t)
{
	//�������� �� ����������������
	if (&t == this) return *this;
	ruble = t.ruble;
	kopeika = t.kopeika;
	return *this;
}

//���������� �������� �������� ����� � �������� �����
Money& Money::operator+(double amount) const 
{
	long ruble_part = static_cast<long>(amount);  // ����� ����� double -> �����
	int kopeika_part = static_cast<int>(round((amount - ruble_part) * 100)); // ������� ����� double -> ������� (� �����������)
	long new_ruble = ruble + ruble_part;  // ��������� �����
	int new_kopeika = kopeika + kopeika_part; // ��������� �������
	Money result(new_ruble, new_kopeika);  // ������� ����� ������ Money � ������ � �����������
	return result; // ���������� ����� ������ Money
}

//���������� �������� ���������(>)
string Money::operator>(Money& other)
{
	if (ruble > other.ruble) return "��";
	if (ruble == other.ruble && kopeika > other.kopeika) return "��";
	return "���";
}

//���������� �������� ���������(<)
string Money::operator<(Money& other)
{
	if (ruble < other.ruble) return "��";
	if (ruble == other.ruble && kopeika < other.kopeika) return "��";
	return "���";
}

//���������� �������� ���������(==)
string Money::operator==(Money& other)
{
	if (ruble == other.ruble && kopeika == other.kopeika) return "��";
	return "���";
}

//���������� ��������� �����
istream& operator>>(istream& in, Money& t)
{
	cout << "ruble? "; in >> t.ruble;
	cout << "kopeika? "; in >> t.kopeika;
	return in;
}

//���������� ��������� ������
ostream&operator<<(ostream&out, const Money&t)
{
	return (out << t.ruble << " , " << t.kopeika);
}