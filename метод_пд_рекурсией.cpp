#include <iostream>
#include <clocale>
#include <ctime>
#include <cmath>
using namespace std;

double f(double x)
{
	return x - 1 / (3 + sin(3.6 * x));
}

double n(double a, double b, int k, float eps)
{
	double c = (a + b) / 2;
	if (abs(a - b) <= eps)
	{
		cout << "Количество итераций: " << k << endl;
		cout << "Приближенный корень: " << c << endl;
		return (a + b) / 2;
	}
	else
	{
		cout << "Корень при " << k + 1 << " итерации x0 = " << c << endl;

		if (f(c) * f(a) > 0)
		{
			return n(c, b, k + 1, eps);
		}
		else
		{
			return n(a, c, k + 1, eps);
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Введите значение епсилон: ";
	double eps;
	cin >> eps;
	int start = clock();
	n(0, 0.85, 0, eps);
	cout << "Время выполнения программ: " << clock() - start << endl;
	return 0;
}