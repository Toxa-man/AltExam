#include <conio.h>
#include "Integer.h"
using namespace std;

int main()
{
	setlocale(0, "");
	
	Integer num1, num2;
	
	
	char c;
	do
	{
		system("cls");
		cout << "AltExam - ��� ���������, ������������� ���������� ������ 5395\n����������� ������� � ����������� �����������." << endl;
		cout << "��������� ������������� ��������� ������ � �������� �������\n� ����������� �������������� ����������." << endl;
		cout << "��������! ���������� ��������� ��������\n����� �������� ��������������� ����� (������� 2-3 �����)" << endl;
		cout << "������� �������� ��������." << endl << endl;
		cout << "������� 1 ����� " << endl;
		cin >> num1;
		cout << "������� 2 ����� " << endl;
		cin >> num2;

		cout << "������� ����: ";
		cin >> c;
		cout << "���������: ";
		switch (c)
		{
		case '+': cout << num1 + num2 << endl; break;
		case '-': cout << num1 - num2 << endl; break;
		case '*': cout << num1 * num2 << endl; break;
		case '/': cout << num1 / num2 << endl; break;
		case '%': cout << num1 % num2 << endl; break;
		}
		if (num1 > num2)
			cout << "������ ������" << endl;
		if (num1 < num2)
			cout << "������ ������" << endl;
		if (num1 == num2)
			cout << "����� �����" << endl;
		else
			cout << "����� �� �����" << endl;

		cout << "��� ����������� ������� ����� �������, ��� ������ ������� ESC " << endl;


	} while (_getch() != 27);
	return 0;
}