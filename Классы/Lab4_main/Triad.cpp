#include <iostream>
#include "Triad.h"
using namespace std;

//���������� ��� ���������� 
Triad::Triad(void)
{
	first = 0;
	second = 0;
	third = 0;
}

//��������� 
Triad::~Triad(void)
{

}

//����������� � �����������
Triad::Triad(int F, int S, int T)
{
	first = F;
	second = S;
	third = T;
}

//���������� ����������� 
Triad::Triad(const Triad& triad)
{
	first = triad.first;
	second = triad.second;
	third = triad.third;
}

//������������ 
void Triad::Set_first(int F)
{
	first = F;
}
void Triad::Set_second(int S)
{
	second = S;
}
void Triad::Set_third(int T)
{
	third = T;
}

//���������� �������� ������������ 
Triad& Triad::operator=(const Triad& t)
{
	if (&t == this) return *this;
	first = t.first;
	second = t.second;
	third = t.third;
	return *this;
}

//���������� ������� ��� �����
istream& operator>>(istream&in, Triad&t)
{ 
	cout << "first: "; in >> t.first;
	cout << "second: "; in >> t.second;
	cout << "third: "; in >> t.third;
	return in;
}

//���������� ������� ������
ostream& operator<<(ostream& out, const Triad& t)
{
	out << "\nFIRST: " << t.first;
	out << "\nSECOND: " << t.second;
	out << "\nTHIRD: " << t.third;
	out << "\n";
	return out;
}