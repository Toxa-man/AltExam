//������������ ���� ��� ������ ����������� �����
#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "Integer10Base.h"
using namespace std;
class Natural
{
private:
	vector<int>array; //������ �������� �� �������
	vector<int>base; //������ ���������
	vector<int> baseIn(); //�����, ������� ��������� ������������ �� ����� "in.txt"
public:
	Natural(); //�����������
	~Natural();//�����������
	Natural& operator=(const Natural& right); //������������� �������� ������������
	friend const Natural operator+(const Natural & right, const Natural & left); //������������� �������� ��������
	friend const Natural operator-(const Natural & right, const Natural & left); //������������� �������� ���������
	friend const Natural operator*(const Natural & right, const Natural & left); //������������� �������� ���������
	friend istream & operator>>(istream & ins, Natural & num); //������������� �������� �����
	friend ostream & operator<<(ostream & ots,const Natural& num);//������������� �������� ������
	bool isEmpty(); //�������� �� ��������� ����
	Natural10Base natTo10BaseNat(); //������� � ���������� ������� ���������
	friend int findRevNum(int num, int mod); //����� ��������� �������� � num � ������ mod
	friend class Integer; //������������� ����� Integer
	friend istream & operator>>(istream & ins, Integer & num); //������������� ��������� ������ Integer
	friend const Integer operator+(const Integer & right, const Integer & left);
	friend const Integer operator-(const Integer & right, const Integer & left);
	friend const Integer operator*(const Integer & right, const Integer & left);
	friend Integer int10BaseToInteger(Integer10Base num);
	friend bool operator==(const Integer & left, const Integer & right);
	friend bool operator>(const Integer & left, const Integer & right);
	friend bool operator<(const Integer & left, const Integer & right);
};

