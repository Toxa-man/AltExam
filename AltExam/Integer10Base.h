#pragma once
#include "Natural10Base.h"
struct Integer10Base
{
	bool pos;
	Natural10Base A;
};

Natural10Base ABS_Z_N(Integer10Base num); //������ ������.
int POZ_Z_D(Integer10Base num); //����������� ����� ������ �����,1-�������������, 0 - ����� 0, -1 - �������������.
Integer10Base MUL_Z_NEGZ(Integer10Base num); //��������� ������ �� -1.
Integer10Base TRANS_N_Z(Natural10Base num); //����������� � �����
Natural10Base TRANS_Z_N(Integer10Base num);//����� � �����������
Integer10Base ADD_ZZ_Z(Integer10Base first, Integer10Base second); //�������� ���� �����
Integer10Base SUB_ZZ_Z(Integer10Base first, Integer10Base second); //��������� ���� �����.
Integer10Base MUL_ZZ_Z(Integer10Base first, Integer10Base second); //��������� ����� �����
Integer10Base DIV_ZZ_Z(Integer10Base first, Natural10Base second); //������� �� ������� �������� ������ ����� �� ������� 
Integer10Base MOD_ZZ_Z(Integer10Base first, Natural10Base second); //������� �� ������� 