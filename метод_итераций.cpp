#include <iostream>
#include <clocale>
#include <math.h>
#include <ctime>
using namespace std;

float fi(float x)
{
    return 1 / (3 + sin(3.6 * x));
}
void func(float x, float (*fi)(float))
{
    cout << "Введите значение епсилон: ";
    float eps;
    cin >> eps;
    int start = clock();
    while (abs((fi(x) - x)) > eps)
    {
        cout << "xn = " << x << ", xn + 1 = " << fi(x) << endl;
        x = fi(x);
    }
    cout << "Корень уравнения = " << x << endl;
    int end = clock();
    cout << "Время выполнения программы: " << end - start;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    float x = 0.5;
    func(x, fi);
    return 0;
}