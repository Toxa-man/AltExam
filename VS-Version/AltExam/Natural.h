//Заголовочный файл для класса натуральных чисел
#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "Integer10Base.h"
using namespace std;
class Natural
{
private:
	vector<int>array; //Вектор остатков от деления
	vector<int>base; //Вектор оснований
	vector<int> baseIn(); //Метод, который считывает коэффициенты из файла "in.txt"
public:
	Natural(); //Конструктор
	~Natural();//Конструктор
	Natural& operator=(const Natural& right); //перегруженный оператор присваивания
	friend const Natural operator+(const Natural & right, const Natural & left); //перегруженный оператор сложения
	friend const Natural operator-(const Natural & right, const Natural & left); //перегруженный оператор вычитания
	friend const Natural operator*(const Natural & right, const Natural & left); //перегруженный оператор умножения
	friend istream & operator>>(istream & ins, Natural & num); //перегруженный оператор ввода
	friend ostream & operator<<(ostream & ots,const Natural& num);//перегруженный оператор вывода
	bool isEmpty(); //проверка на равенство нулю
	Natural10Base natTo10BaseNat(); //Перевод в десятичную систему счисления
	friend int findRevNum(int num, int mod); //Поиск обратного значения к num в кольце mod
	friend class Integer; //Дружественный класс Integer
	friend istream & operator>>(istream & ins, Integer & num); //Перегруженные операторы класса Integer
	friend const Integer operator+(const Integer & right, const Integer & left);
	friend const Integer operator-(const Integer & right, const Integer & left);
	friend const Integer operator*(const Integer & right, const Integer & left);
	friend Integer int10BaseToInteger(Integer10Base num);
	friend bool operator==(const Integer & left, const Integer & right);
	friend bool operator>(const Integer & left, const Integer & right);
	friend bool operator<(const Integer & left, const Integer & right);
};

