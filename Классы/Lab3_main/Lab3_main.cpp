#include <iostream>
#include <clocale>
#include "Money.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	system("cls");
	Money A;
	Money B;
	double amount;

	cout << "Введите первую денежную сумму: " << endl;
	cin >> A;
	cout << "Вы ввели: " << A << endl;
	cout << "Введите дробное число для добавления: ";
	cin >> amount;
	long ruble_part = static_cast<long>(amount);
	int kopeika_part = (int)((amount - ruble_part) * 100 + 0.5);
	Money sum(A.get_ruble() + ruble_part, A.get_kopeika() + kopeika_part);
	cout << "Результат сложения: " << sum << endl;

	cout << "Введите вторую денежную сумму для сравнения:" << endl;
	cin >> B;
	cout << "Вы ввели: " << B << endl;
	cout << "Первая сумма больше второй? " << (A > B) << endl;
	cout << "Первая сумма меньше второй? " << (A < B) << endl;
	cout << "Первая сумма равна второй? " << (A == B) << endl;

	return 0;
}