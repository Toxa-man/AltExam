#pragma once
#include <vector>
using namespace std;
struct Natural10Base
{
	vector<unsigned int> A;
};

bool COM_NN_D(Natural10Base First, Natural10Base Second);//Сравнивает два числа. Возвращает 1,
											 // если первое больше или равно второму. 0 - если меньше.
bool NZER_N_B(Natural10Base chislo); //Проверяет число на не равенство нулю
							   //1- число положительное, 0 - число равно 0
Natural10Base ADD_1N_N(Natural10Base chislo); //Прибавляет 1 к числу
Natural10Base ADD_NN_N(Natural10Base chislo1, Natural10Base chislo2);//Складывает два числа
Natural10Base SUB_NN_N(Natural10Base First, Natural10Base Second); //Вычитает из одного числа другое. Работает только
												 //для неотрицательных результатов, поэтому перед вызовом этой функции
												 //необходимо убедиться, что первое число не меньше второго
Natural10Base MUL_ND_N(Natural10Base ch, int cifra); //Умножает число на цифру
Natural10Base MUL_Nk_N(Natural10Base &Input, int k); //Умножает число на 10^k
Natural10Base MUL_NN_N(Natural10Base chislo1, Natural10Base chislo2); //Перемножает два числа
Natural10Base SUB_NDN_N(Natural10Base chislo1, Natural10Base chislo2, int c); //Вычитает из первого числа второе, умноженное на цифру
															//аналогично вычитанию, перед вызовом необходимо убедиться,
															//что результат возможен, т.е. неотрицателен
Natural10Base DIV_NN_Dk(Natural10Base chislo1, Natural10Base chislo2);//Вычисляет первую цифру частного, умноженную на 10^k,
													//где k - позиция этой цифры в частном
Natural10Base DIV_NN_N(Natural10Base delimoe, Natural10Base delitel); //Находит неполное частное двух чисел
Natural10Base MOD_NN_N(Natural10Base chislo1, Natural10Base chislo2);//Находит остаток от деления первого числа на второе
Natural10Base GCF_NN_N(Natural10Base chislo1, Natural10Base chislo2);//Находит НОД двух чисел
Natural10Base LCM_NN_N(Natural10Base chislo1, Natural10Base chislo2);//Находит НОК двух чисел

Natural10Base intToNat10(int a);
int nat10ToInt(Natural10Base a);