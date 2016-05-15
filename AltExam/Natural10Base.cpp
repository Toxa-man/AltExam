#include "Natural10Base.h"
#include <iostream>

bool COM_NN_D(Natural10Base First, Natural10Base Second)//���������� ��� �����. ���������� 1, 
{											// ���� ������ ������ ��� ����� �������. 0 - ���� ������.(��������� ��������� 5372)
	if (First.A.size() < Second.A.size())
		return 0;
	else
	{
		if (First.A.size() > Second.A.size())
			return 1;
		int i = First.A.size() - 1, k = 1;
		do
		{
			if (First.A[i] > Second.A[i])
			{
				return 1;
			}
			else
			{
				if (First.A[i] < Second.A[i])
				{
					return 0;
				}
				else
					if (i == 0)
						return 1;
					else
						--i;
			}
		} while (k);
	}
}

bool NZER_N_B(Natural10Base chislo) //��������� ����� �� �� ��������� ����
{							  //1- ����� �������������, 0 - ����� ����� 0 (����� ����� 5372)
	if (chislo.A.empty())
		return 0;
	else
	{
		int sum = 0;
		for (int i = 0; i < chislo.A.size(); ++i)
			sum = sum + chislo.A[i];
		if (sum)
			return 1;
		else
			return 0;
	}
}

Natural10Base ADD_1N_N(Natural10Base chislo) //���������� 1 � ����� (������������ ��� 5372)
{
	int k = 1, i = 0;
	do
	{
		if (chislo.A[i] == 9)
		{
			chislo.A[i] = 0;
			++i;
			if (i == chislo.A.size())
			{
				chislo.A.push_back(1);
				k = 0;
			}
		}
		else
		{
			chislo.A[i] = ++chislo.A[i];
			k = 0;
		}
	} while (k);
	return chislo;
}

Natural10Base ADD_NN_N(Natural10Base chislo1, Natural10Base chislo2)//���������� ��� ����� (�������� ���� 5372)
{
	if (!COM_NN_D(chislo1, chislo2))
		chislo1.A.swap(chislo2.A);
	int s = 0;
	Natural10Base Sum;
	for (int i = 0; i < chislo2.A.size(); ++i)
	{
		Sum.A.push_back((chislo1.A[i] + chislo2.A[i] + s) % (10));
		s = (chislo1.A[i] + chislo2.A[i] + s) / (10);
	}
	if (chislo1.A.size() != chislo2.A.size())
		for (int i = chislo2.A.size(); i < chislo1.A.size(); ++i)
		{
			Sum.A.push_back((chislo1.A[i] + s) % (10));
			s = (chislo1.A[i] + s) / (10);
		}
	if (s > 0)
	{
		Sum.A.push_back(s);
	}
	return Sum;
};

Natural10Base SUB_NN_N(Natural10Base First, Natural10Base Second) //�������� �� ������ ����� ������. �������� ������
{												//��� ��������������� �����������, ������� ����� ������� ���� ������� 
	int p = 0;									//���������� ���������, ��� ������ ����� �� ������ ������� (������ ����� 5372)
	for (int i = 0; i < Second.A.size(); ++i)
	{
		if (First.A[i] + 10 - Second.A[i] - p < 10)
		{
			First.A[i] = First.A[i] + 10 - Second.A[i] - p;
			p = 1;
		}
		else
		{
			First.A[i] = First.A[i] - Second.A[i] - p;
			p = 0;
		}
	}
	for (int i = Second.A.size(); i < First.A.size(); ++i)
	{
		if (First.A[i] + 10 - p < 10)
		{
			First.A[i] = First.A[i] + 10 - p;
			p = 1;
		}
		else
		{
			First.A[i] = First.A[i] - p;
			p = 0;
		}
	}
	int k = 0;
	int i = First.A.size() - 1;
	for (i; i > 0; --i)
	{
		if (First.A[i])
			k = 1;
		if (!First.A[i] && !k)
			First.A.pop_back();
	}
	return First;
}

Natural10Base MUL_ND_N(Natural10Base ch, int cifra) //�������� ����� �� ����� (��������� ����� 5372)
{
	int s = 0;
	Natural10Base chislo;
	for (int i = 0; i < ch.A.size(); ++i)
	{
		chislo.A.push_back((ch.A[i] * cifra + s) % 10);
		s = (ch.A[i] * cifra + s) / 10;
	}

	if (s > 0)
	{
		chislo.A.push_back(s);
	}
	return chislo;
}

Natural10Base MUL_Nk_N(Natural10Base &Input, int k) //�������� ����� �� 10^k (������� ����� 5372)
{
	for (int i = 0; i < k; ++i)
		Input.A.insert(Input.A.begin(), 0);
	return Input;
}

Natural10Base MUL_NN_N(Natural10Base chislo1, Natural10Base chislo2) //����������� ��� ����� (�������� ���� 5372)
{
	Natural10Base Proizved;
	for (int i = 0; i < chislo2.A.size(); ++i)
	{
		Proizved = ADD_NN_N(MUL_Nk_N(MUL_ND_N(chislo1, chislo2.A[i]), i), Proizved);
	}
	if ((Proizved.A[Proizved.A.size()-1] == 0) && (Proizved.A.size()>1))
		Proizved.A.erase(Proizved.A.begin() + 1, Proizved.A.end());
	return Proizved;
}

Natural10Base SUB_NDN_N(Natural10Base chislo1, Natural10Base chislo2, int c) //�������� �� ������� ����� ������, ���������� �� �����
{															//���������� ���������, ����� ������� ���������� ���������,
	return SUB_NN_N(chislo1, MUL_ND_N(chislo2, c));			//��� ��������� ��������, �.�. ������������� (������ ����� 5372)
}

Natural10Base DIV_NN_Dk(Natural10Base chislo1, Natural10Base chislo2)//��������� ������ ����� ��������, ���������� �� 10^k, 
{													//��� k - ������� ���� ����� � ������� (���������� ����� 5372)
	Natural10Base chislo;
	int j = (chislo1.A.size() - 1);
	for (int i = 0; i < chislo2.A.size(); ++i, --j)
		chislo.A.insert(chislo.A.begin(), chislo1.A[j]);
	if (!COM_NN_D(chislo, chislo2))
		chislo.A.insert(chislo.A.begin(), chislo1.A[j]);

	int i = 10;
	do
	{
		--i;
	} while (!COM_NN_D(chislo, MUL_ND_N(chislo2, i)));
	chislo.A.erase(chislo.A.begin(), chislo.A.end());
	chislo.A.push_back(i);
	return MUL_Nk_N(chislo, j);
}

Natural10Base DIV_NN_N(Natural10Base delimoe, Natural10Base delitel) //������� �������� ������� ���� ����� (����� ����� 5372)
{
	Natural10Base chastnoe;
	if (!COM_NN_D(delimoe, delitel))
	{
		chastnoe.A.push_back(0);
		return chastnoe;
	}
	else
	{
		do
		{
			chastnoe = ADD_NN_N(chastnoe, DIV_NN_Dk(delimoe, delitel));
			delimoe = SUB_NN_N(delimoe, MUL_NN_N(delitel, DIV_NN_Dk(delimoe, delitel)));
		} while (COM_NN_D(delimoe, delitel));
		return chastnoe;
	}
}

Natural10Base MOD_NN_N(Natural10Base chislo1, Natural10Base chislo2)//������� ������� �� ������� ������� ����� �� ������ (������� ����� 5372)
{
	if (!COM_NN_D(chislo1, chislo2))
		return chislo1;
	return SUB_NN_N(chislo1, MUL_NN_N(DIV_NN_N(chislo1, chislo2), chislo2));
}

Natural10Base GCF_NN_N(Natural10Base chislo1, Natural10Base chislo2)//������� ��� ���� ����� (������ ����� 5372)
{
	if (!COM_NN_D(chislo1, chislo2))
		chislo1.A.swap(chislo2.A);
	Natural10Base n;
	n.A.push_back(0);
	while (!(MOD_NN_N(chislo1, chislo2).A == n.A))
	{
		chislo1 = MOD_NN_N(chislo1, chislo2);
		chislo1.A.swap(chislo2.A);
		if ((chislo2.A.size() == 1) && (chislo2.A[0] == 0))
			return chislo1;
	}
	return chislo2;
}

Natural10Base LCM_NN_N(Natural10Base chislo1, Natural10Base chislo2)//������� ��� ���� ����� (������ ����� 5372)
{
	return DIV_NN_N(MUL_NN_N(chislo1, chislo2), GCF_NN_N(chislo1, chislo2));
}

Natural10Base intToNat10(int a)
{
	Natural10Base num;
	int i(0);
	while (a != 0)
	{
		num.A.resize(i + 1);
		num.A[i] = a % 10;
		a /= 10;
		i++;
	}
	return num;
}

int nat10ToInt(Natural10Base a)
{
	int num(0);
	for (int i(0), j(1); i < a.A.size(); i++, j *= 10)
		num = num + a.A[i] * j;
	return num;
}
