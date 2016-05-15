#include "Integer10Base.h"

int POZ_Z_D(Integer10Base num) //Сигнатура, определение знака целого числа.	
{			 //Выполнил Предтеченский Дмитрий (5396).
	if (!num.pos)
		return -1;
	else if (NZER_N_B(num.A))
		return 1;
	return 0;
}

Integer10Base TRANS_N_Z(Natural10Base num) //Преобразование натурального числа в целое число.
{			       //Выполнил Предтеченский Дмитрий (5396).	
	Integer10Base newNum;
	newNum.pos = 1;
	newNum.A = num;
	return newNum;
}

Natural10Base TRANS_Z_N(Integer10Base num) //Преобразование целого положительного числа в натуральное число.
{			       //Выполнил Предтеченский Дмитрий (5396).	
	return num.A;
}

Natural10Base ABS_Z_N(Integer10Base num) //Модуль целого числа.
{			     //Выполнил Предтеченский Дмитрий (5396).
	return num.A;
}

Integer10Base MUL_Z_NEGZ(Integer10Base num) //Умножение целого числа на -1
{				//Выполнил Предтеченский Дмитрий (5396).
	num.pos = !num.pos;
	return num;
}

Integer10Base ADD_ZZ_Z(Integer10Base first, Integer10Base second) //Сложение двух целых чисел.
{						//Выполнил Предтеченский Дмитрий (5396).
	Integer10Base sum;

	if (((first.pos == 1) && (second.pos == 1)) || ((first.pos == 0) && (second.pos == 0)))
	{
		sum.A = ADD_NN_N(first.A, second.A);
		if (first.pos == 0 || (second.pos == 0))
			sum.pos = 0;
		else
			sum.pos = 1;
	}
	else
	{
		if (COM_NN_D(first.A, second.A))
		{
			sum.A = SUB_NN_N(first.A, second.A);
			if (first.pos == 0)
				sum.pos = 0;
			else
				sum.pos = 1;
		}
		else
		{
			sum.A = SUB_NN_N(second.A, first.A);
			if (second.pos == 0)
				sum.pos = 0;
			else
				sum.pos = 1;
		}
	}
	return sum;
}

Integer10Base SUB_ZZ_Z(Integer10Base first, Integer10Base second) //Вычитание двух целых чисел.
{						//Выполнил Предтеченский Дмитрий (5396).
	Integer10Base sub;

	if (POZ_Z_D(first) <= 0)
		if (POZ_Z_D(second) <= 0)
			if (COM_NN_D(first.A, second.A))
			{
				sub.A = SUB_NN_N(ABS_Z_N(first), ABS_Z_N(second));
				sub = MUL_Z_NEGZ(sub);
			}
			else
				sub.A = SUB_NN_N(ABS_Z_N(second), ABS_Z_N(first));
		else {
			sub.A = ADD_NN_N(ABS_Z_N(first), ABS_Z_N(second));
			sub = MUL_Z_NEGZ(sub);
		}
	else {
		if (POZ_Z_D(second) >= 0) {
			if (!COM_NN_D(first.A, second.A)) {
				sub.A = SUB_NN_N(ABS_Z_N(second), ABS_Z_N(first));
				sub = MUL_Z_NEGZ(sub);
			}
			else
				sub.A = SUB_NN_N(ABS_Z_N(first), ABS_Z_N(second));
		}
		else
			sub.A = ADD_NN_N(ABS_Z_N(first), ABS_Z_N(second));
	}
	return sub;
}

Integer10Base MUL_ZZ_Z(Integer10Base first, Integer10Base second) //Умножение двух целых чисел.
{						//Выполнил Предтеченский Дмитрий (5396).
	Integer10Base mul;
	mul.A = MUL_NN_N(first.A, second.A);
	if (((first.pos == 0) && (second.pos == 0)) || ((first.pos == 1) && (second.pos == 1)))
		mul.pos = 1;
	else
		mul.pos = 0;

	return mul;
}

Integer10Base MOD_ZZ_Z(Integer10Base first, Natural10Base second) //Остаток от деления целого числа на целое число. 
{						//Выполнила Чаркова Дарья (5396).
	Integer10Base result;
	if (first.pos)
		result.A = MOD_NN_N(first.A, second);
	else
	{
		result = DIV_ZZ_Z(first, second);
		result = MUL_ZZ_Z(result, TRANS_N_Z(second));
		result = SUB_ZZ_Z(first, result);
		//result = SUB_ZZ_Z(first, MUL_ZZ_Z(DIV_ZZ_Z(first, second),TRANS_N_Z(second)));
		if ((result.pos == 0) && (NZER_N_B(result.A)))
			result = ADD_ZZ_Z(result, TRANS_N_Z(second));
	}
	result.pos = 1;
	return result;
};

Integer10Base DIV_ZZ_Z(Integer10Base first, Natural10Base second) //Частное от деления большего целого числа на меньшее 
												//или равное натуральное число с остатком (делитель отличен от нуля).
{						//Выполнил Уразаев Евгений (5396).
	Integer10Base div;

	div.A = DIV_NN_N(first.A, second);

	if (POZ_Z_D(first) < 0)
		div.pos = 0;

	return div;
}