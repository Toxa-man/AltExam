#include <iostream>
#include <conio.h>
#include <vector>
#include <fstream>
#include <string>
#include "Integer.h"
using namespace std;

vector<int> baseIn()
{
	bool inWord(true);
	string str;
	vector<int>a(500);
	fstream in;
	in.open("in.txt", ios::in);
	char c(0);
	int i(0), j(0);
	while (!in.eof())
	{
		in.get(c);
		if (isdigit(c))
		{
			inWord = true;
			str += c;
		}
		else
		{
			if (inWord)
			{
				a[i] = stoi(str);
				i++;
				str.clear();
			}
			inWord = false;
		}


	}
	in.close();
	return a;
}



int main()
{
	setlocale(0, "");
	Integer num1, num2;
	char c;
	cout << "������� 1 ����� " << endl;
	cin >> num1;
	cout << "������� 2 ����� " << endl;
	cin >> num2;
	/*cout << "������� ����: ";
	cin >> c;
	cout << "���������: ";
	switch (c)
	{
	case '+': cout << num1 + num2 << endl; break;
	case '-': cout << num1 - num2 << endl; break;
	case '*': cout << num1 * num2 << endl; break;
	case '/': cout << num1 / num2 << endl; break;
	case '%': cout << num1 % num2 << endl; break;
	}*/
	if (num1 > num2)
		cout << "������ ������" << endl;
	if (num1 < num2)
		cout << "������ ������" << endl;
	if (num1 == num2)
		cout << "����� �����" << endl;
	else
		cout << "����� �� �����";
	_getch();
	return 0;
}