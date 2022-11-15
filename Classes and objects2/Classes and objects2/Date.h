#pragma once
#include<iostream>
using std::cout;
using std::endl;

class Date
{

public:
	//���캯��
	Date(int year = 0, int month = 1,int day = 1);
	//Date(int year, int month, int day);
	//��ӡ����
	void Print()const;

	//����+=����
	Date& operator+=(int day);

	//����+����
	Date operator + (int day)const;

	//����-=����
	Date& operator-=(int day);

	//����-����
	Date operator - (int day)const;

	//ǰ��++
	Date& operator++();
	//����++
	Date operator++(int);
	//ǰ��--
	Date& operator--();
	//����--
	Date operator--(int);

	//���ڵĴ�С��ϵ�Ƚ�
	bool operator>(const Date& d)const;
	bool operator>=(const Date& d)const;
	bool operator<(const Date& d)const;
	bool operator<=(const Date& d)const;
	bool operator==(const Date& d)const;
	bool operator!=(const Date& d)const;

	//���ڼ�����
	int operator -(const Date& d)const;


private:
	int _year;
	int _month;
	int _day;
};

//��ȡĳ��ĳ�µ�����
inline int GetMonthDay(int year, int month);
