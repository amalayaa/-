#include <iostream>
#include <clocale>
#include <cmath>
using namespace std;

float fi(float x)
{
	return x - 1 / (3 + sin(3.6 * x));
}
float pr(float x)
{
	return 1 - (3.6 * cos(3.6 * x) / pow(3 + sin(3.6 * x), 2));
}
void func(float x, float (*fi)(float), float (*pr)(float))
{ 
	cout << "Введите значение епсилон:" << endl;
	float eps;
	cin >> eps;

	while (abs((x - (fi(x) / pr(x)) - x)) > eps)
	{
		cout << "xn = " << x << ", xn + 1 = " << x - (fi(x) / pr(x)) << endl;
		x = x - (fi(x) / pr(x));
	}
	cout << "Корень уравнения = " << x;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	float x = 0.5;
	func(x, fi, pr);
}