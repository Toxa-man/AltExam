#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "Natural10Base.h"
#include "Integer10Base.h"
using namespace std;
class Natural
{
private:
	vector<int>array;
	vector<int>base;
	vector<int> baseIn();
public:
	Natural();
	~Natural();
	Natural& operator=(const Natural& right);
	friend const Natural operator+(const Natural & right, const Natural & left);
	friend const Natural operator-(const Natural & right, const Natural & left);
	friend const Natural operator*(const Natural & right, const Natural & left);
	friend istream & operator>>(istream & is, Natural & num);
	friend ostream & operator<<(ostream & os,const Natural& num);
	bool isEmpty();
	Natural10Base natTo10BaseNat();
	friend int findRevNum(int num, int mod);
	friend class Integer;
	friend istream & operator>>(istream & is, Integer & num);
	friend const Integer operator+(const Integer & right, const Integer & left);
	friend const Integer operator-(const Integer & right, const Integer & left);
	friend const Integer operator*(const Integer & right, const Integer & left);
	friend Integer int10BaseToInteger(Integer10Base num);
	friend bool operator==(const Integer & left, const Integer & right);
	friend bool operator>(const Integer & left, const Integer & right);
	friend bool operator<(const Integer & left, const Integer & right);
};

