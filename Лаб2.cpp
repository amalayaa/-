#include <iostream>
#include <cmath>
#include <clocale>
#include <iomanip>
using namespace std;
double f(double x, double pi)
{
	return (x * sin(pi / 4)) / (1 - 2 * x * cos(pi / 4) + pow(x, 2));
}
double Fn(double x, int n, double pi)
{
	if (n == 0)
	{
		return 0;
	}
	else
	{
		return pow(x, n) * sin((n * pi) / 4) + Fn(x, n - 1, pi);
	}
}
double Fe(double x, double eps, double pi)
{
	double res = 0;
	double n = 0;
	double f;
	f = pow(x, n) * sin((n * pi) / 4);
	do
	{
		res += f;
		++n;
		f = pow(x, n) * sin((n * pi) / 4);
	} while (abs(f) >= eps);
	return res;
}
int main()
{
	cout << fixed << setprecision(6);
	double eps = 0.0001;
	double pi = 2 * acos(0.0);
	double k = 10;
	double a = 0.1;
	double b = 0.8;
	double c = (b - a) / k;
	for (double x = a; x <= b; x += c)
	{
		double Se = Fe(x, eps, pi);
		double Sn = Fn(x, 40, pi);
		double y = f(x, pi);
		cout << "X = " << x << " " << "Sn = " << Sn << " " << "Se = " << Se << " " << "Y = " << y << '\n';
	}
	return 0;
}
