#include <iostream>
#include <clocale>
#include "fraction.h"
using namespace std;

// ���������� ������ ��� ������������� ����� ���������
void fraction::Init(double F, double S)
{
	first = F;
	second = S;
}

// ���������� ������ ��� ������ �������� ����� ���������
void fraction::Read()
{
	cout << "\nfirst? "; cin >> first;
	cout << "\nsecond? "; cin >> second;
}

// ���������� ������ ��� ������ �������� ����� ���������
void fraction::Show()
{
	cout << "\nfirst = " << first;
	cout << "\nsecond = " << second;
	cout << "\n";
}

// ����� ��� ���������� ���������� �� ����� � ������������ (first, second) �� ������ ��������� 
double fraction::distance()
{
	return sqrt(first * first + second * second);
}