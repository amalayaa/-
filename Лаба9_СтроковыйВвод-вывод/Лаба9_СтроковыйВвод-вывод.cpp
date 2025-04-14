#include <iostream>
#include <clocale>
#include <fstream>
#include <string>
using namespace std;

bool Empty(const string& str) // проверка на пустую строку
{
    return str.length() == 0;
}

bool numbers(const string& str) // функция, которая проверяет есть ли в строке цифры
{
    for (char simvol : str)
    {
        if (simvol >= '0' && simvol <= '9')
        {
            return true; // если есть цифры в строке
        }
    }
    return false; // если нет цифр в строке
}

bool startStrA(const string& str) // функция, которая проверяет начинается ли строка на 'A'
{
    if (Empty(str)) // если строка пустая
    {
        return false; // возвращаем false, чтобы не учитывать пустую строку
    }
    char firstSimvol = str[0]; // присваиваем первый символ строки
    return (firstSimvol == 'A' || firstSimvol == 'a'); // сравниваем первый символ с А или а
}

int main()
{
    setlocale(LC_ALL, "Russian");
    string str; // переменная которая будет хранить строку из прочитанного файла
    ifstream f1("F1.txt");
    ofstream f2("F2.txt");
    if (!f1.is_open() || !f2.is_open()) // проверка на открытие файлов
    {
        cout << "Не удалось открыть файл " << endl; // если не удалось открыть хотя бы один из файлов - ошиька
    }
    int a = 0; // переменная которая будкт считать сколько строк начинающихся на А есть в F2
    while (getline(f1, str)) // читаем F1 и записываем в F2 строки без цифр
    {
        if (!numbers(str)) // проверка на содержание цифр
        {
            f2 << str << endl; // записываем строку в F2
            if (startStrA(str)) // если строка начинается на А
            {
                a++; // увеличиваем значение переменной
            }
        }
    }
    f1.close();
    f2.close();
    cout << "Количество строк начинающихся 'A' в F2: " << a << endl;
    return 0;
}