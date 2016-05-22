//«аголовочный файл класса целых чисел
#pragma once
#include "Natural.h"
class Integer
{
	Natural nat; //Ќатуральное число
public:
	Integer();// онструктор
	~Integer();// онструктор
	Integer& operator=(const Integer& right);//перегруженный оператор присваивани€
	friend const Integer operator+(const Integer & left, const Integer & right); //перегруженный оператор сложени€
	friend const Integer operator-(const Integer & left, const Integer & right);//перегруженный оператор вычитани€
	friend const Integer operator*(const Integer & left, const Integer & right);//перегруженный оператор умножени€
	friend const Integer operator/(const Integer & left, const Integer & right);//перегруженный оператор делени€
	friend const Integer operator%(const Integer & left, const Integer & right);//перегруженный оператор остатка от делени€
	friend bool operator==(const Integer & left, const Integer & right); //перегруженный оператор сравнени€
	friend bool operator>(const Integer & left, const Integer & right); //перегруженный оператор "Ѕольше"
	friend bool operator<(const Integer & left, const Integer & right);//перегруженный оператор "ћеньше"
	friend bool operator<=(const Integer & left, const Integer & right);//перегруженный оператор "ћеньше или равно"
	friend bool operator>=(const Integer & left, const Integer & right);//перегруженный оператор "Ѕольше или равно"

	friend bool operator==(const Integer & left, const int & right); //перегруженный оператор сравнени€
	friend bool operator>(const Integer & left, const int & right); //перегруженный оператор "Ѕольше"
	friend bool operator<(const Integer & left, const int & right);//перегруженный оператор "ћеньше"
	friend bool operator<=(const Integer & left, const int & right);//перегруженный оператор "ћеньше или равно"
	friend bool operator>=(const Integer & left, const int & right);//перегруженный оператор "Ѕольше или равно"

	friend istream & operator>>(istream & ins, Integer & num); //перегруженный оператор ввода
	friend ostream & operator<<(ostream & ots, const Integer& num); //перегруженный оператор вывода
	friend Integer int10BaseToInteger(Integer10Base num);//ƒружественна€ функци€ перевода дес€тичного числа в вектор остатков
	Integer10Base integerToInt10Base(); //ѕеревод вектора остатков в дес€тичное число
};

