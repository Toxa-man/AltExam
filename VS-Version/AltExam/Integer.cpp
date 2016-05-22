#include "Integer.h"



Integer::Integer() //Конструктор
{
		nat.base = nat.baseIn();
		nat.array.resize(nat.base.size());
}


Integer::~Integer() //Деструктор
{
}

Integer & Integer::operator=(const Integer & right) //Оператор сравнения
{
	if (this == &right)
		return *this;

	nat.array = right.nat.array;
	nat.base = right.nat.base;
	return *this;
}

Integer10Base Integer::integerToInt10Base() //Перевод целого числа в десятичное
{
	if (nat.isEmpty())
	{
		Natural10Base res = intToNat10(0);
		return TRANS_N_Z(res);
	}
	Integer10Base res;
	res.pos = 1;
	res.A.A.resize(1);
	Integer num;
	int k(0), baseIter(0);
	vector<int>koeff(nat.base.size());
	vector<int>newBase = nat.base;
	num.nat.array = nat.array;
	while (num.nat.array.size() != 0)
	{
		Natural reverseNum;
		koeff[k] = num.nat.array[0];
		for (int i(0); i < num.nat.array.size(); i++) //Вычитаем q из х
		{
			num.nat.array[i] = num.nat.array[i] - koeff[k];
			if (num.nat.array[i] < 0)
				while (num.nat.array[i] < 0)
					num.nat.array[i] += newBase[i];
		}
		if (num.nat.isEmpty() && (num.nat.array.size() != 1) && (koeff.size() < 2))
		{
			res.A = intToNat10(koeff[k]);
			res.pos = 1;
			return res;
		}
		if (num.nat.isEmpty() && (koeff.size()>1))
			break;

		newBase.erase(newBase.begin());
		num.nat.array.erase(num.nat.array.begin());
		reverseNum.array.resize(num.nat.array.size());
		reverseNum.base.resize(num.nat.base.size());
		for (int i(0); i < newBase.size(); i++)
			reverseNum.array[i] = findRevNum(nat.base[k], newBase[i]);
		num.nat = num.nat*reverseNum;
		k++;
	}

	Natural10Base temp, temp1, M;
	temp.A.resize(1);
	temp.A[0] = 1;
	M.A.resize(1);
	M.A[0] = 1;
	k = 0;
	for (int i(0); i < koeff.size(); i++)
	{
		if (!i)
			res.A = intToNat10(koeff[i]);
		else
		{
			if (koeff[i] == 0)
				temp.A[0] = 0;
			else
			{
				temp = MUL_NN_N(temp, intToNat10(nat.base[k]));
				k++;
				temp1 = MUL_NN_N(temp, intToNat10(koeff[i]));
				res.A = ADD_NN_N(res.A, temp1);
			}
		}
	}
	if (koeff[koeff.size() - 1] == 1)
	{
		M = MUL_NN_N(temp, intToNat10(nat.base[k]));
		res = SUB_ZZ_Z(res, TRANS_N_Z(M));
	}


	return res;
}

const Integer operator+(const Integer & left, const Integer & right) //Сложение
{
	Integer res;
	for (int i(0); i < left.nat.base.size(); i++)
		res.nat.array[i] = (left.nat.array[i] + right.nat.array[i]) % res.nat.base[i];
	return res;
}

const Integer operator-(const Integer & left, const Integer & right) //Вычитание
{
	Integer res;
	for (int i(0); i < left.nat.base.size(); i++)
	{
		res.nat.array[i] = (left.nat.array[i] - right.nat.array[i]) % res.nat.base[i];
		if (res.nat.array[i] < 0)
			while (res.nat.array[i] < 0)
				res.nat.array[i] += res.nat.base[i];
	}
	return res;
}

const Integer operator*(const Integer & left, const Integer & right) //Умножение
{
	Integer res;
	res.nat.array.resize(left.nat.array.size());
	for (int i(0); i < left.nat.array.size(); i++)
		res.nat.array[i] = (right.nat.array[i] * left.nat.array[i]) % res.nat.base[i + (right.nat.base.size() - right.nat.array.size())];
	return res;
}

const Integer operator/(const Integer & left, const Integer & right) //Деление
{
	Integer10Base rightInt, leftInt, resInt;
	Integer res = right;
	rightInt = res.integerToInt10Base();
	res = left;
	leftInt = res.integerToInt10Base();
	resInt = DIV_ZZ_Z(leftInt,TRANS_Z_N(rightInt));
	if ((!rightInt.pos) && (!leftInt.pos))
		resInt.pos = 1;
	if ((leftInt.pos) && (!rightInt.pos))
		resInt.pos = 0;
	res = int10BaseToInteger(resInt);
	return res;
}

const Integer operator%(const Integer & left, const Integer & right) //Остаток от деления
{
	Integer res;
	res = left - (left / right)*right;
	if (res < 0)
		res = res + right;
	return res;
}

bool operator==(const Integer & left, const Integer & right) //Сравнение
{
	for (int i(0); i < left.nat.base.size(); i++)
		if (left.nat.array[i] != right.nat.array[i])
			return false;
	return true;
}

bool operator>(const Integer & left, const Integer & right) //Больше
{
	Integer num;
	num = left - right;
	if (num.nat.isEmpty())
		return false;
	int k(0), baseIter(0);
	vector<int>koeff(left.nat.base.size());
	vector<int>newBase = left.nat.base;
	while (num.nat.array.size() != 0)
	{
		Natural reverseNum;
		koeff[k] = num.nat.array[0];
		for (int i(0); i < num.nat.array.size(); i++) //Вычитаем q из х
		{
			num.nat.array[i] = num.nat.array[i] - koeff[k];
			if (num.nat.array[i] < 0)
				while (num.nat.array[i] < 0)
					num.nat.array[i] += newBase[i];
		}
		if (num.nat.isEmpty() && (num.nat.array.size() != 1))
			return true;

		newBase.erase(newBase.begin());
		num.nat.array.erase(num.nat.array.begin());
		reverseNum.array.resize(num.nat.array.size());
		reverseNum.base.resize(num.nat.base.size());
		for (int i(0); i < newBase.size(); i++)
			reverseNum.array[i] = findRevNum(num.nat.base[k], newBase[i]);
		num.nat = num.nat*reverseNum;
		k++;
	}
	return false;

}

bool operator<(const Integer & left, const Integer & right) //Меньше
{
	Integer num;
	num = left - right;
	if ((!(left>right)) && (!num.nat.isEmpty()))
		return true;
	else
		return false;
}

bool operator<=(const Integer & left, const Integer & right)
{
	if ((left < right) || (left == right))
		return true;
	else
		return false;
}

bool operator>=(const Integer & left, const Integer & right)
{
	if ((left > right) || (left == right))
		return true;
	else
		return false;
}

bool operator==(const Integer & left, const int & right)
{
	Integer res;
	res = int10BaseToInteger(TRANS_N_Z(intToNat10(0)));
	if (left == res)
		return true;
	else
		return false;
}

bool operator>(const Integer & left, const int & right)
{
	Integer res;
	res = int10BaseToInteger(TRANS_N_Z(intToNat10(0)));
	if (left > res)
		return true;
	else
		return false;
}

bool operator<(const Integer & left, const int & right)
{
	Integer res;
	res = int10BaseToInteger(TRANS_N_Z(intToNat10(0)));
	if (left < res)
		return true;
	else
		return false;
}

bool operator<=(const Integer & left, const int & right)
{
	Integer res;
	res = int10BaseToInteger(TRANS_N_Z(intToNat10(0)));
	if (left <= res)
		return true;
	else
		return false;
}

bool operator>=(const Integer & left, const int & right)
{
	Integer res;
	res = int10BaseToInteger(TRANS_N_Z(intToNat10(0)));
	if (left >= res)
		return true;
	else
		return false;
}



istream & operator>>(istream & ins, Integer & num) //Ввод
{
	string str;
	Integer10Base num10;
	cin >> str;
	if (str[0] == '-')
	{
		num10.pos = 0;
		str.erase(0, 1);
	}
	num10.A.A.resize(str.length());
	for (int i(str.length() - 1), j(0); i >= 0; i--, j++)
	{
		num10.A.A[j] = str[i] - '0';
	}
	int k(num.nat.base.size() - 1);
	do
	{
		num.nat.array[k] = nat10ToInt(TRANS_Z_N(MOD_ZZ_Z(num10, intToNat10(num.nat.base[k])))); 
		k--;
	} while (k != -1);
	return ins;

}

ostream & operator<<(ostream & ots, const Integer & num) //Вывод
{
	Integer10Base res;
	Integer temp = num;
	res = temp.integerToInt10Base();
	if (!res.pos)
		cout << '-';
	for (int i(res.A.A.size() - 1); i >= 0; i--)
		cout << res.A.A[i];
	return ots;
}

Integer int10BaseToInteger(Integer10Base num) //Десятичное число в целое
{
	Integer res;
	int k(res.nat.base.size() - 1);
	do
	{
		res.nat.array[k] = nat10ToInt(TRANS_Z_N(MOD_ZZ_Z(num, intToNat10(res.nat.base[k]))));
		k--;
	} while (k != -1);
	return res;
}


