#include <iostream> 
#include<clocale>
using namespace std; 

const int BOARD_SIZE = 8; //Размер шахматной доски

bool Safe(int n, int m, int queens[]) // Функция проверки безопасности позиции
{ 
    for (int i = 0; i < n; ++i) // Проверяем предыдущие строки
    { 
        if (queens[i] == m || abs(queens[i] - m) == n - i) // Если есть угроза
        { 
            return false; // Позиция не безопасна
        }
    }
    return true; // Позиция безопасна
}

bool Queens(int n, int queens[]) // Функция решения задачи
{ 
    if (n == BOARD_SIZE) // Если все ферзи расставлены
    { 
        return true; // Решение найдено
    }
    for (int m = 0; m < BOARD_SIZE; ++m)
    { 
        if (Safe(n, m, queens)) // Если позиция безопасна
        { 
            queens[n] = m; // Ставим ферзя
            if (Queens(n + 1, queens)) // Рекурсивный вызов для следующей строки
            { 
                return true; // Решение найдено, выходим
            }
        }
    }
    return false; // Решений нет
}

void printReshenie(int queens[]) // Функция вывода решения
{ 
    for (int i = 0; i < BOARD_SIZE; ++i)
    { 
        for (int j = 0; j < BOARD_SIZE; ++j)
        { 
            if (queens[i] == j) // Если в клетке ферзь
            { 
                cout << "1 "; // Выводим ферзя
            }
            else // Если клетка пуста
            { 
                cout << ". "; // Выводим пустую клетку
            }
        }
        cout << endl; 
    }
    cout << endl; 
}

int main()
{ 
    setlocale(LC_ALL, "Russian");
    int mass[BOARD_SIZE]; // Массив для хранения решения
    if (Queens(0, mass))// Если решение найдено
    { 
        cout << "Решение задачи о 8 ферзях: " << endl; // Выводим сообщение
        printReshenie(mass); // Выводим решение
    }
    else
    {
        cout << "Решений нет" << endl;
    }
    return 0;
}
