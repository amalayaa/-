#include <iostream>
#include <clocale>
using namespace std;

void HanoiTower(int n, int start, int point, int help)
{
    if (n > 0)
    {
        HanoiTower(n - 1, start, help, point); // Перемещаем n - 1 дисков со start на help
        cout << "Переместить диск " << n << " с стержня " << start << " на стержень " << point << endl;
        HanoiTower(n - 1, help, point, start); // Перемещаем n - 1 дисков с help на point
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int disk;
    cout << "Введите количество дисков: ";
    cin >> disk;
    HanoiTower(disk, 1, 3, 2); // Перемещение дисков с стержня 1 на стержень 3, используя стержень 2 в качестве вспомогательного
    return 0;
}