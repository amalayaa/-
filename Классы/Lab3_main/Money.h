#pragma once

#include <iostream>
using namespace std;

class Money
{
	long ruble;
	int kopeika;
public:
	Money() { ruble = 0; kopeika = 0; }
	Money(long r, int k) 
	{
		ruble = r; 
		kopeika = k;
	}
	Money(const Money& t)
	{
		ruble = t.ruble; 
		kopeika = t.kopeika;
	}
	~Money() {};

	long get_ruble() { return ruble; }
	int get_kopeika() { return kopeika; }

	void set_ruble(long r) { ruble = r; }
	void set_kopeika(int k) { kopeika = k; }
	
	// перегруженные операции 
	Money&operator=(const Money&);
	Money&operator+(double amount) const;
	string operator>(Money& other);
	string operator<(Money& other);
	string operator==(Money& other);

	//глобальные функции ввода - вывода
	friend istream& operator>>(istream& in, Money& t);
	friend ostream& operator<<(ostream& out, const Money& t);
};