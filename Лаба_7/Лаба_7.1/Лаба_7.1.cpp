#include <iostream>
#include <clocale>
#include <string>
using namespace std;

string getSingZodiac(int month, int day)
{
    string sing = "Неизвестно";
    if (month == 1)
    {
        if (day <= 20)
            sing = "Козерог";
        else if (day <= 31)
            sing = "Водолей";
        else return sing;
    }
    else if (month == 2)
    {
        if (day <= 19)
            sing = "Водолей";
        else if (day <= 29) // Учитываем високосный год
            sing = "Рыбы";
        else return sing;
    }
    else if (month == 3)
    {
        if (day <= 20)
            sing = "Рыбы";
        else if (day <= 31)
            sing = "Овен";
        else return sing;
    }
    else if (month == 4)
    {
        if (day <= 20)
            sing = "Овен";
        else if (day <= 30)
            sing = "Телец";
        else return sing;
    }
    else if (month == 5)
    {
        if (day <= 21)
            sing = "Телец";
        else if (day <= 31)
            sing = "Близнецы";
        else return sing;
    }
    else if (month == 6)
    {
        if (day <= 21)
            sing = "Близнецы";
        else if (day <= 30)
            sing = "Рак";
        else return sing;
    }
    else if (month == 7)
    {
        if (day <= 22)
            sing = "Рак";
        else if (day <= 31)
            sing = "Лев";
        else return sing;
    }
    else if (month == 8)
    {
        if (day <= 23)
            sing = "Лев";
        else if (day <= 31)
            sing = "Дева";
        else return sing;
    }
    else if (month == 9)
    {
        if (day <= 23)
            sing = "Дева";
        else if (day <= 30)
            sing = "Весы";
        else return sing;
    }
    else if (month == 10)
    {
        if (day <= 23)
            sing = "Весы";
        else if (day <= 31)
            sing = "Скорпион";
        else return sing;
    }
    else if (month == 11)
    {
        if (day <= 22)
            sing = "Скорпион";
        else if (day <= 30)
            sing = "Стрелец";
        else return sing;
    }
    else if (month == 12)
    {
        if (day <= 22)
            sing = "Стрелец";
        else if (day <= 31)
            sing = "Козерог";
        else return sing;
    }
    return sing;
}

// Перегрузка функции для получения знака зодиака из строки
string getSingZodiac(string monthStr, string dayStr) 
{
    int month = stoi(monthStr);
    int day = stoi(dayStr);
    return getSingZodiac(month, day);
}

string getJapaneseZodiacAnimal(int year)
{
    const string animals[] = {"Крыса", "Бык", "Тигр", "Кролик", "Дракон", "Змея", "Лошадь", "Овца", "Обезьяна", "Петух", "Собака", "Свинья"};
    int animalIndex = (year - 4) % 12;
    if (animalIndex < 0) // Проверка на отрицательный индекс
    {
        animalIndex += 12;
    }
    return animals[animalIndex];
}

// Перегрузка функции для получения животного по японскому календарю из строки
string getJapaneseZodiacAnimal(string yearStr) 
{
    int year = stoi(yearStr); //функция stoi преобразует строку в целочисленное число
    return getJapaneseZodiacAnimal(year);
}

int main()
{
    setlocale(LC_ALL, "Russia");
    system("chcp 1251");
    system("cls");
    cout << "Введите месяц (1-12): ";
    string monthStr;
    cin >> monthStr;
    cout << "Введите день (1-31): ";
    string dayStr;
    cin >> dayStr;
    string SingZodiac = getSingZodiac(monthStr, dayStr);
    cout << "Знак зодиака: " << SingZodiac << endl;
    cout << endl;

    cout << "Введите год: ";
    string yearStr;
    cin >> yearStr;
    string zodiacAnimal = getJapaneseZodiacAnimal(yearStr);
    cout << "Животное по старояпонскому календарю: " << zodiacAnimal << endl;
    return 0;
}