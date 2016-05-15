#pragma once
#include "Natural10Base.h"
struct Integer10Base
{
	bool pos;
	Natural10Base A;
};

Natural10Base ABS_Z_N(Integer10Base num); //Модуль целого.
int POZ_Z_D(Integer10Base num); //Определение знака целого числа,1-положительное, 0 - равно 0, -1 - отрицательное.
Integer10Base MUL_Z_NEGZ(Integer10Base num); //Умножение целого на -1.
Integer10Base TRANS_N_Z(Natural10Base num); //Натуральное в целое
Natural10Base TRANS_Z_N(Integer10Base num);//Целое в натуральное
Integer10Base ADD_ZZ_Z(Integer10Base first, Integer10Base second); //Сложение двух целых
Integer10Base SUB_ZZ_Z(Integer10Base first, Integer10Base second); //Вычитание двух целых.
Integer10Base MUL_ZZ_Z(Integer10Base first, Integer10Base second); //Умножение целых чисел
Integer10Base DIV_ZZ_Z(Integer10Base first, Natural10Base second); //Частное от деления большего целого числа на меньшее 
Integer10Base MOD_ZZ_Z(Integer10Base first, Natural10Base second); //Остаток от деление 