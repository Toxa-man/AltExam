//������������ ���� ������ ����� �����
#pragma once
#include "Natural.h"
class Integer
{
	Natural nat; //����������� �����
public:
	Integer();//�����������
	~Integer();//�����������
	Integer& operator=(const Integer& right);//������������� �������� ������������
	friend const Integer operator+(const Integer & left, const Integer & right); //������������� �������� ��������
	friend const Integer operator-(const Integer & left, const Integer & right);//������������� �������� ���������
	friend const Integer operator*(const Integer & left, const Integer & right);//������������� �������� ���������
	friend const Integer operator/(const Integer & left, const Integer & right);//������������� �������� �������
	friend const Integer operator%(const Integer & left, const Integer & right);//������������� �������� ������� �� �������
	friend bool operator==(const Integer & left, const Integer & right); //������������� �������� ���������
	friend bool operator>(const Integer & left, const Integer & right); //������������� �������� "������"
	friend bool operator<(const Integer & left, const Integer & right);//������������� �������� "������"
	friend bool operator<=(const Integer & left, const Integer & right);//������������� �������� "������ ��� �����"
	friend bool operator>=(const Integer & left, const Integer & right);//������������� �������� "������ ��� �����"

	friend bool operator==(const Integer & left, const int & right); //������������� �������� ���������
	friend bool operator>(const Integer & left, const int & right); //������������� �������� "������"
	friend bool operator<(const Integer & left, const int & right);//������������� �������� "������"
	friend bool operator<=(const Integer & left, const int & right);//������������� �������� "������ ��� �����"
	friend bool operator>=(const Integer & left, const int & right);//������������� �������� "������ ��� �����"

	friend istream & operator>>(istream & ins, Integer & num); //������������� �������� �����
	friend ostream & operator<<(ostream & ots, const Integer& num); //������������� �������� ������
	friend Integer int10BaseToInteger(Integer10Base num);//������������� ������� �������� ����������� ����� � ������ ��������
	Integer10Base integerToInt10Base(); //������� ������� �������� � ���������� �����
};

