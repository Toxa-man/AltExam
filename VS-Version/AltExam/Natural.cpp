
#include "Natural.h"
int findRevNum(int num, int mod) //Поиск обратного числа
{
	int x(1), y(0), quotient, j(0), temp, mainMod = mod;
	do
	{
		quotient = num/mod;
		temp = num;
		num = mod;
		mod = temp%mod;
		if (j % 2 == 0)
			x = x - y*quotient;
		else
			y = y - quotient*x;
		j++;
	}while (num%mod != 0);
	if ((j - 1) % 2 == 0)
	{
		if (x < 0)
			while (x < 0)
				x += mainMod;
		return x;
	}
	else
	{
		if (y < 0)
			while (y < 0)
				y += mainMod;
		return y;
	}
}

Natural::Natural() //Конструктор
{
	base = baseIn();
	array.resize(base.size());
}


Natural::~Natural() //Деструктор
{
}


Natural & Natural::operator=(const Natural & right) //Оператор сравнения
{
	if (this == &right) 
		return *this;

	array = right.array;
	base = right.base;
	return *this;
}

bool Natural::isEmpty() //Проверка на равенство нулю
{
	bool flag(1);
	for (int i(0); i < array.size(); i++)
		if (array[i] != 0)
			return false;
	return true;
}

Natural10Base Natural::natTo10BaseNat() //Алгоритм перевода из вектора остатков в десятичное число
{
	Natural10Base res;
	res.A.resize(1);
	Natural num;
	int k(0), baseIter(0);
	vector<int>koeff(base.size());
	vector<int>newBase = base;
	num.array = array;
	while (num.array.size() != 0)
	{
		Natural reverseNum;
		koeff[k] = num.array[0];
		for (int i(0); i < num.array.size(); i++) //Вычитаем q из х
		{
			num.array[i] = num.array[i] - koeff[k];
			if (num.array[i] < 0)
				while (num.array[i] < 0)
					num.array[i] += newBase[i];
		}
		if (num.isEmpty() && (num.array.size()!=1) && (koeff.size()<2))
			return intToNat10(koeff[k]);
		if (num.isEmpty() && (koeff.size()>1))
			break;

		newBase.erase(newBase.begin());
		num.array.erase(num.array.begin());
		reverseNum.array.resize(num.array.size());
		reverseNum.base.resize(num.base.size());
		for (int i(0); i < newBase.size(); i++)
			reverseNum.array[i] = findRevNum(base[k], newBase[i]); 
		num = num*reverseNum;
		k++;



	}

	for (int i(0); i < koeff.size(); i++)
	{
		Natural10Base temp;
		temp.A.resize(1);
		temp.A[0] = 1;
		if (!i)
			res = intToNat10(koeff[i]);
		else
		{
			if (koeff[i] == 0)
				temp.A[0] = 0;
			else
			{
				for (int j(0); j < i; j++)
					temp = MUL_NN_N(temp, intToNat10(base[j]));
				temp = MUL_NN_N(temp, intToNat10(koeff[i]));
				res = ADD_NN_N(res, temp);
			}
		}
	}


	return res;
}

vector<int> Natural::baseIn() //Функция ввода простох чисел из файла in.txt
{
	vector<int>a(500);
	fstream in;
	in.open("in.txt", ios::in);
	bool inWord(true);
	string str = "";

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
	
	
	
	reverse(a.begin(), a.end());
	in.close();
	return a;

}

const Natural operator+(const Natural & right, const Natural & left) //Сложение чисел
{
	Natural res;
	for (int i(0); i < right.base.size(); i++)
		res.array[i] = (right.array[i] + left.array[i]) % res.base[i];
	return res;
}

const Natural operator-(const Natural & right, const Natural & left) //Вычитание чисел
{
	Natural res;
	for (int i(0); i < right.base.size(); i++)
	{
		res.array[i] = (right.array[i] - left.array[i]) % res.base[i];
		if (res.array[i] < 0)
			while (res.array[i] < 0)
				res.array[i] += res.base[i];
	}
	return res;
}

const Natural operator*(const Natural & right, const Natural & left) //Умножение чисел
{
	Natural res;
	res.array.resize(right.array.size());
	for (int i(0); i < right.array.size(); i++)
		res.array[i] = (right.array[i] * left.array[i]) % res.base[i+(right.base.size()-right.array.size())];
	return res;
}

istream & operator>>(istream & ins, Natural & num) //Ввод числа
{
	string str;
	Natural10Base num10;
	cin >> str;
	num10.A.resize(str.length());
	for (int i(str.length() - 1), j(0); i >= 0; i--, j++)
	{
		num10.A[j] = str[i] - '0';
	}
	int k(num.base.size()-1);
	do
	{
		num.array[k] = nat10ToInt(MOD_NN_N(num10, intToNat10(num.base[k])));
		k--;
	} while ((num.array[k+1]  != nat10ToInt(num10)) && (k!=-1));
	for (int i(k); i >= 0; i--)
		num.array[i] = num.array[k + 1];
	return ins;
}

ostream & operator<<(ostream & ots,const Natural & num) //Вывод числа
{
	Natural10Base res;
	Natural temp = num;
	res = temp.natTo10BaseNat();
	for (int i(res.A.size() - 1); i >= 0; i--)
		cout << res.A[i];
	return ots;
}
