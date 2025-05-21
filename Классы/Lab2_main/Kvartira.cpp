#include <iostream>
#include <clocale>
#include <string>
#include "Kvartira.h"
using namespace std;

// ����������� ��� ����������
Kvartira::Kvartira()
{
	address = "";
	ploshchad = 0;
	kolKomnat = 0;
	cout << "����������� ��� ���������� ��� ������� " << this << endl;
}

// ���������� � �����������
Kvartira::Kvartira(string N, double K, int S)
{
	address = N;
	ploshchad = K;
	kolKomnat = S;
	cout << "����������� � ����������� ��� ������� " << this << endl;
}

// ����������� �����������
Kvartira::Kvartira(const Kvartira &t)
{
	address = t.address;
	ploshchad = t.ploshchad;
	kolKomnat = t.kolKomnat;
	cout << "����������� ����������� ��� ������� " << this << endl;
}

// ����������
Kvartira::~Kvartira()
{
	cout << "���������� ��� ������� " << this << endl;
}

// ��������� 
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

// ������������
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

// ����� ��� ��������� ���������
void Kvartira::show()
{
	cout << "�����: " << address << endl;
	cout << "�������: " << ploshchad << endl;
	cout << "���������� ������: " << kolKomnat << endl;
}