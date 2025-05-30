﻿#include <iostream>
#include <clocale>
using namespace std;

struct Node  // Объявляем структуру Node, которая представляет собой узел списка.
{
    int data;  // Объявляем член структуры Node с именем data типа int, который будет хранить данные в узле.
    Node* next_ptr;  // Объявляем член структуры Node с именем next_ptr типа Node*, который будет хранить указатель на следующий узел в списке.

    void addData(int Data)  // Объявляем функцию-член addData, которая принимает целое число Data и устанавливает его в качестве значения для data.
    {
        data = Data;  // Присваиваем значение Data члену data структуры Node.
        next_ptr = nullptr;  // Устанавливаем next_ptr в nullptr (нулевой указатель), так как при создании нового узла он пока не указывает ни на что.
    }
};

struct List  // Объявляем структуру List, которая представляет собой список.
{
    Node* head = nullptr;  // Объявляем член структуры List с именем head типа Node*, который будет хранить указатель на первый узел в списке. Инициализируем его в nullptr.
    Node* tail = nullptr;  // Объявляем член структуры List с именем tail типа Node*, который будет хранить указатель на последний узел в списке. Инициализируем его в nullptr.

    void push_back(int data)  // Объявляем функцию-член push_back, которая принимает целое число data и добавляет новый узел с этим значением в конец списка.
    {
        Node* node = new Node;  // Создаем новый узел с помощью оператора new.
        node->addData(data);  // Устанавливаем данные для нового узла.
        if (head == nullptr)  // Если список пуст (head равен nullptr):
        {
            head = node;  // Устанавливаем head на новый узел.
            tail = node;  // Устанавливаем tail на новый узел (так как это единственный элемент).
        }
        else  // Если список не пуст
        {
            tail->next_ptr = node;  // Устанавливаем next_ptr текущего последнего узла (tail) на новый узел.
            tail = node;  // Устанавливаем tail на новый узел (так как он теперь последний).
        }
    }

    void deleteAfter(int number)  // Объявляем функцию-член deleteAfter, которая принимает целое число number и удаляет узел, следующий после узла с указанным номером.
    {
        if (head == nullptr) return;  // Если список пуст (head равен nullptr), выходим из функции.

        Node* current = head;  // Устанавливаем указатель current на начало списка (head).
        int count = 1;  // Инициализируем счетчик count значением 1 (так как отсчет начинается с 1, а не с 0).
        while (current && count < number)  // Пока current не равен nullptr (не достигли конца списка) и count меньше number:
        {
            current = current->next_ptr;  // Перемещаем current на следующий узел.
            count++;  // Увеличиваем счетчик count.
        }

        if (current == nullptr || current->next_ptr == nullptr) return;  // Если current равен nullptr (узел с заданным номером не найден) или current->next_ptr равен nullptr (после узла с заданным номером нет узла), выходим из функции.

        Node* toDelete = current->next_ptr;  // Устанавливаем указатель toDelete на узел, который нужно удалить (узел, следующий после current).
        current->next_ptr = toDelete->next_ptr;  // Перенаправляем указатель next_ptr текущего узла (current) на узел, следующий после удаляемого узла (toDelete), исключая удаляемый узел из списка.

        // Обновляем tail, если удаляем последний элемент
        if (toDelete == tail)  // Если удаляемый узел является последним узлом (tail):
        {
            tail = current;  // Устанавливаем tail на текущий узел (так как он теперь последний).
        }
    }

    void addKToBeginning(int K)  // Объявляем функцию-член addKToBeginning, которая принимает целое число K и добавляет K новых узлов в начало списка.
    {
        for (int i = 0; i < K; ++i)  // Цикл, который выполняется K раз.
        {
            int a;  // Объявляем переменную a типа int для хранения значения нового узла.
            cout << "Введите новый элемент (" << i + 1 << "/" << K << "): ";  // Выводим сообщение с просьбой ввести значение для нового элемента.
            cin >> a;  // Считываем значение с клавиатуры и сохраняем его в переменной a.

            Node* newNode = new Node;  // Создаем новый узел с помощью оператора new.
            newNode->addData(a);  // Устанавливаем данные для нового узла.
            newNode->next_ptr = head;  // Устанавливаем next_ptr нового узла на текущую голову списка (head).
            head = newNode;  // Устанавливаем head на новый узел (так как он теперь первый).

            if (tail == nullptr)  // Если список пуст (tail равен nullptr):
            {
                tail = newNode;  // Устанавливаем tail на новый узел (так как это единственный элемент).
            }
        }
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    system("cls");
    List list;
    int temp;
    cout << "Введите размерность списка: ";
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cout << "Введите " << i + 1 << " элемент списка: ";
        cin >> temp;
        list.push_back(temp);
    }
    cout << endl;
    cout << "Ваш список: ";
    for (Node* node = list.head; node != list.tail->next_ptr; node = node->next_ptr)
    {
        cout << node->data << ' ';
    }
    cout << endl;
    cout << "Введите заданный номер элемента: ";
    int b;
    cin >> b;
    list.deleteAfter(b);
    cout << "Ваш список после удаления элемента после элемента с заданным номером: ";
    for (Node* node = list.head; node != list.tail->next_ptr; node = node->next_ptr)
    {
        cout << node->data << ' ';
    }
    cout << endl;
    cout << "Введите количество элементов, которое вы хотите добавить в начало списка: ";
    int k;
    cin >> k;
    list.addKToBeginning(k);
    cout << "Ваш список после добавления элементов: ";
    for (Node* node = list.head; node != list.tail->next_ptr; node = node->next_ptr)
    {
        cout << node->data << ' ';
    }
    return 0;
}