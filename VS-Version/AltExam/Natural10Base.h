#pragma once
#include <vector>
using namespace std;
struct Natural10Base
{
	vector<unsigned int> A;
};

bool COM_NN_D(Natural10Base First, Natural10Base Second);//���������� ��� �����. ���������� 1,
											 // ���� ������ ������ ��� ����� �������. 0 - ���� ������.
bool NZER_N_B(Natural10Base chislo); //��������� ����� �� �� ��������� ����
							   //1- ����� �������������, 0 - ����� ����� 0
Natural10Base ADD_1N_N(Natural10Base chislo); //���������� 1 � �����
Natural10Base ADD_NN_N(Natural10Base chislo1, Natural10Base chislo2);//���������� ��� �����
Natural10Base SUB_NN_N(Natural10Base First, Natural10Base Second); //�������� �� ������ ����� ������. �������� ������
												 //��� ��������������� �����������, ������� ����� ������� ���� �������
												 //���������� ���������, ��� ������ ����� �� ������ �������
Natural10Base MUL_ND_N(Natural10Base ch, int cifra); //�������� ����� �� �����
Natural10Base MUL_Nk_N(Natural10Base &Input, int k); //�������� ����� �� 10^k
Natural10Base MUL_NN_N(Natural10Base chislo1, Natural10Base chislo2); //����������� ��� �����
Natural10Base SUB_NDN_N(Natural10Base chislo1, Natural10Base chislo2, int c); //�������� �� ������� ����� ������, ���������� �� �����
															//���������� ���������, ����� ������� ���������� ���������,
															//��� ��������� ��������, �.�. �������������
Natural10Base DIV_NN_Dk(Natural10Base chislo1, Natural10Base chislo2);//��������� ������ ����� ��������, ���������� �� 10^k,
													//��� k - ������� ���� ����� � �������
Natural10Base DIV_NN_N(Natural10Base delimoe, Natural10Base delitel); //������� �������� ������� ���� �����
Natural10Base MOD_NN_N(Natural10Base chislo1, Natural10Base chislo2);//������� ������� �� ������� ������� ����� �� ������
Natural10Base GCF_NN_N(Natural10Base chislo1, Natural10Base chislo2);//������� ��� ���� �����
Natural10Base LCM_NN_N(Natural10Base chislo1, Natural10Base chislo2);//������� ��� ���� �����

Natural10Base intToNat10(int a);
int nat10ToInt(Natural10Base a);