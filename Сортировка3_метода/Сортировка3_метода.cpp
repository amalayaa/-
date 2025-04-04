﻿#include <iostream>
#include <clocale> 
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int const a = 100;
    int mass1[a];
    int mass2[a];
    int mass3[a];
    int n;
    cout << "Введите размерность массива: ";
    cin >> n;
    cout << "Введите массив: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> mass1[i];
    }
    for (int i = 0; i < n; i++) //присваиваем исходный массив чтобы сделать пошаговый вывод
    {
        mass2[i] = mass1[i];
        mass3[i] = mass1[i];
    }
    cout << "Ваш массив: ";
    for (int i = 0; i < n; ++i)
    {
        cout << mass1[i] << " ";
    }
    cout << endl;

    // метод пузырька 
    cout << "Метод пузырька: " << endl;
    for (int i = 0; i < n - 1; ++i) // Внешний цикл: n-1 проходов по массиву
    {
        for (int j = 0; j < n - i - 1; ++j) // Внутренний цикл: сравниваем соседние элементы и меняем их местами, если нужно
        {
            if (mass1[j] > mass1[j + 1]) // Если текущий элемент больше следующего
            {
                int r = mass1[j]; // Сохраняем значение текущего элемента во временной переменной r
                mass1[j] = mass1[j + 1]; // Присваиваем текущему элементу значение следующего элемента
                mass1[j + 1] = r; // Присваиваем следующему элементу значение, которое было сохранено во временной переменной r (то есть, значение текущего элемента)
            }
            for (int k = 0; k < n; k++) //пошаговый вывод
            {
                cout << mass1[k] << " ";
            }
            cout << endl;
        }
    }
    cout << "Итог: " << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << mass1[i] << " ";
    }
    cout << endl;

    // метод выбора 
    cout << "Метод выбора: " << endl;
    int min_index; // Объявляем переменную min_index для хранения индекса минимального элемента
    for (int i = 0; i < n - 1; i++) // Внешний цикл: проходим по массиву до предпоследнего элемента
    {
        min_index = i; // Изначально считаем, что минимальный элемент находится в текущей позиции i
        for (int j = i + 1; j < n; j++) // Внутренний цикл: ищем минимальный элемент, начиная со следующего элемента после i
        {
            if (mass2[j] < mass2[min_index]) // Если нашли элемент, который меньше текущего минимального элемента
            {
                min_index = j; // Запоминаем индекс этого элемента
            }
        }
        int m = mass2[min_index]; // Сохраняем значение минимального элемента во временной переменной m
        mass2[min_index] = mass2[i]; // Присваиваем минимальному элементу значение текущего элемента
        mass2[i] = m; // Присваиваем текущему элементу значение, которое было сохранено во временной переменной m (то есть, значение минимального элемента)
        for (int z = 0; z < n; z++) //пошаговый вывод
        {
            cout << mass2[z] << " ";
        }
        cout << endl;
    }
    cout << "Итог: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << mass2[i] << " ";
    }
    cout << endl;

    // метод вставки 
    cout << "Метод вставки: " << endl;
    int key; // переменная для хранения значения элемента, с которым мы сравниваем текущий
    for (int i = 0; i < n; i++) // Внешний цикл: проходим по массиву с первого элемента
    {
        key = mass3[i]; // Сохраняем текущий элемент во временной переменной key
        int j = i - 1; // Инициализируем j индексом предыдущего элемента
        // если условие выполняется, нам нужно обменять элементы
        while (j >= 0 && mass3[j] > key) // Пока j не достиг начала массива и элемент mass[j] больше key
        {
            mass3[j + 1] = mass3[j]; // Сдвигаем элемент mass[j] на одну позицию вправо
            j--; // Уменьшаем j, чтобы проверить предыдущий элемент
        }
        mass3[j + 1] = key; // Вставляем key на правильное место в отсортированной части массива
        for (int o = 0; o < n; o++) //пошаговый вывод
        {
            cout << mass3[o] << " ";
        }
        cout << endl;
    }
    cout << "Итог: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << mass3[i] << " ";
    }
    return 0;
}