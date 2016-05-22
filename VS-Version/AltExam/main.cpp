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
		cout << "AltExam - это программа, разработанная студентами группы 5395\nКвятковским Антоном и Гаврильевой Александрой." << endl;
		cout << "Программа демонстрирует алгоритмы работы с длинными числами\nс применением многомодульной арифметики." << endl;
		cout << "Внимание! Вычисление некоторых значений\nможет занимать продолжительное время (порядка 2-3 минут)" << endl;
		cout << "Просьба проявить терпение." << endl << endl;
		cout << "Введите 1 число " << endl;
		cin >> num1;
		cout << "Введите 2 число " << endl;
		cin >> num2;

		cout << "Введите знак: ";
		cin >> c;
		cout << "Результат: ";
		switch (c)
		{
		case '+': cout << num1 + num2 << endl; break;
		case '-': cout << num1 - num2 << endl; break;
		case '*': cout << num1 * num2 << endl; break;
		case '/': cout << num1 / num2 << endl; break;
		case '%': cout << num1 % num2 << endl; break;
		}
		if (num1 > num2)
			cout << "Первое больше" << endl;
		if (num1 < num2)
			cout << "Первое меньше" << endl;
		if (num1 == num2)
			cout << "Числа равны" << endl;
		else
			cout << "Числа не равны" << endl;

		cout << "Для продолжения нажмите любую клавишу, для выхода нажмите ESC " << endl;


	} while (_getch() != 27);
	return 0;
}