#include <iostream>
#include <clocale>
using namespace std;

struct Node
{
	int data;
	Node* next_ptr;
};

struct Stack
{
		Node* head = nullptr;
		int size;

	void push_back(int Data) // функция добавления элемента
	{
		Node* node = new Node;
		node->data = Data;
		node->next_ptr = head;
		head = node;
	}

	void deleteAfter(int Data) // функция удаления элемента после заданного
	{
		Node* node = head;
		while (node != nullptr)
		{
			if (node->data == Data)
			{
				if (node->next_ptr != nullptr)
				{
					Node* deleteElement = node->next_ptr;
					node->next_ptr = deleteElement->next_ptr;
					delete deleteElement;
					size--;
					return;
				}
				else
				{
					cout << "После элемента " << Data << " нет других элементов" << endl;
					return;
				}
			}
			node = node->next_ptr;
		}
		cout << "Элемент " << Data << " не найден в стеке" << endl;
	}

	void addKElements(int K) // функция добавления К элментов в начало стека
	{
		for (int i = 0; i < K; ++i)
		{
			int data;
			cout << "Введите значение для нового элемента (" << i + 1 << "/" << K << "): ";
			cin >> data;
			push_back(data);
		}
	}

	void Show() // функция вывода стека на экран
	{
		Node* temp = head;
		while (temp != 0)
		{
			cout << temp->data << " ";
			temp = temp->next_ptr;
		}
		cout << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	system("cls");
	Stack MyStack;
	int temp;
	cout << "Введите размерность стека: ";
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cout << "Введите " << i + 1 << " элемент стека: ";
		cin >> temp;
		MyStack.push_back(temp);
	}
	cout << "Ваш стек: ";
	MyStack.Show(); 
	cout << "Введите значение элемента после которого удалится элемент: ";
	int b;
	cin >> b;
	MyStack.deleteAfter(b);
	cout << "Ваш стек после удаления элемента: ";
	MyStack.Show();
	cout << "Введите количество элементов, которое вы хотите добавить в начало стека: ";
	int k;
	cin >> k;
	MyStack.addKElements(k);
	cout << "Ваш стек после добавления элементов: ";
	MyStack.Show();
	return 0;
}