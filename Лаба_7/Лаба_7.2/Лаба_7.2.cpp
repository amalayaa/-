#include <iostream>
#include <clocale>
#include <cstdarg>
using namespace std;

// Функция для нахождения минимального из чисел типа int
int findMin(int num_args, ...) 
{
    va_list args;
    va_start(args, num_args);
    int minNum = 2147483647;
    for (int i = 0; i < num_args; ++i)
    {
        int a = va_arg(args, int);
        if (a < minNum)
        {
            minNum = a;
        }
    }
    va_end(args);
    return minNum;
}

int main() 
{
    setlocale(LC_ALL, "Russia");
    system("chcp 1251");
    system("cls");
    int min1 = findMin(5, 12, 7, 44, 1, 9);
    cout << "Минимальное число из 5 чисел: " << min1 << endl;

    int min2 = findMin(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0);
    cout << "Минимальное число из 10 чисел: " << min2 << endl;

    int min3 = findMin(12, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10, -11, -12);
    cout << "Минимальное число из 12 чисел: " << min3 << endl;
    return 0;
}

