#include <iostream>
#include <cmath>
#include "Money.h"
using namespace std;

//перегрузка операции присваивания 
Money& Money::operator=(const Money& t)
{
	//проверка на самоприсваивание
	if (&t == this) return *this;
	ruble = t.ruble;
	kopeika = t.kopeika;
	return *this;
}

//перегрузка операции сложения суммы и дробного числа
Money& Money::operator+(double amount) const 
{
	long ruble_part = static_cast<long>(amount);  // Целая часть double -> рубли
	int kopeika_part = static_cast<int>(round((amount - ruble_part) * 100)); // Дробная часть double -> копейки (с округлением)
	long new_ruble = ruble + ruble_part;  // Суммируем рубли
	int new_kopeika = kopeika + kopeika_part; // Суммируем копейки
	Money result(new_ruble, new_kopeika);  // Создаем новый объект Money с суммой и нормализуем
	return result; // Возвращаем новый объект Money
}

//перегрузка операции сравнения(>)
string Money::operator>(Money& other)
{
	if (ruble > other.ruble) return "да";
	if (ruble == other.ruble && kopeika > other.kopeika) return "да";
	return "нет";
}

//перегрузка операции сравнения(<)
string Money::operator<(Money& other)
{
	if (ruble < other.ruble) return "да";
	if (ruble == other.ruble && kopeika < other.kopeika) return "да";
	return "нет";
}

//перегрузка операции сравнения(==)
string Money::operator==(Money& other)
{
	if (ruble == other.ruble && kopeika == other.kopeika) return "да";
	return "нет";
}

//перегрузка оператора ввода
istream& operator>>(istream& in, Money& t)
{
	cout << "ruble? "; in >> t.ruble;
	cout << "kopeika? "; in >> t.kopeika;
	return in;
}

//перегрузка оператора вывода
ostream&operator<<(ostream&out, const Money&t)
{
	return (out << t.ruble << " , " << t.kopeika);
}