#pragma once
#include <iostream>
#include <string>
using namespace std;

class Kvartira
{
	// ��������
	string address;
	double ploshchad;
	int kolKomnat;
public:
	Kvartira(); // ����������� ��� ����������
	Kvartira(string, double, int); //���������� � ����������� 
	Kvartira(const Kvartira&); // ����������� �����������
	~Kvartira(); // ���������� 
	string get_address(); // ��������
	void set_address(string); // �����������
	double get_ploshchad(); // ��������
	void set_ploshchad(double); // �����������
	int get_kolKomnat(); // ��������
	void set_kolKomnal(int); // �����������
	void show(); // �������� ���������
};