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
	cout << "¬ведите 1 число " << endl;
	cin >> num1;
	cout << "¬ведите 2 число " << endl;
	cin >> num2;
	/*cout << "¬ведите знак: ";
	cin >> c;
	cout << "–езультат: ";
	switch (c)
	{
	case '+': cout << num1 + num2 << endl; break;
	case '-': cout << num1 - num2 << endl; break;
	case '*': cout << num1 * num2 << endl; break;
	case '/': cout << num1 / num2 << endl; break;
	case '%': cout << num1 % num2 << endl; break;
	}*/
	if (num1 > num2)
		cout << "ѕервое больше" << endl;
	if (num1 < num2)
		cout << "ѕервое меньше" << endl;
	if (num1 == num2)
		cout << "„исла равны" << endl;
	else
		cout << "„исла не равны";
	_getch();
	return 0;
}