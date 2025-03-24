#include <iostream>
#include <clocale>
using namespace std;

int findMin(int mass[], int n)
{
    int minNum = mass[0];
    for (int i = 1; i < n; ++i) 
    {
        if (mass[i] < minNum) 
        {
            minNum = mass[i];
        }
    }
    return minNum;
}

int main() 
{
    setlocale(LC_ALL, "Russia");
    system("chcp 1251");
    system("cls");
    int n = 5;
    int mass[5];
    int n2 = 10;
    int mass2[10];
    int n3 = 12;
    int mass3[12];
    cout << "Для последовательности размером 5" << endl;
    for (int i = 0; i < n; ++i) 
    {
        cout << "Введите " << i + 1 << " элемент последовательности: ";
        cin >> mass[i];
    }
    int min = findMin(mass, n);
    cout << "Минимальное число в последовательности: " << min << endl;
    cout << endl;

    cout << "Для последовательности размером 10" << endl;
    for (int i = 0; i < n2; ++i)
    {
        cout << "Введите " << i + 1 << " элемент последовательности: ";
        cin >> mass2[i];
    }
    int min2 = findMin(mass2, n2);
    cout << "Минимальное число в последовательности: " << min2 << endl;
    cout << endl;

    cout << "Для последовательности размером 12" << endl;
    for (int i = 0; i < n3; ++i)
    {
        cout << "Введите " << i + 1 << " элемент последовательности: ";
        cin >> mass3[i];
    }
    int min3 = findMin(mass3, n3);
    cout << "Минимальное число в последовательности: " << min3 << endl;
    return 0;
}

