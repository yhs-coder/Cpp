#define _CRT_SECURE_NO_WARNINGS

#include"Date.h"

//��ȡĳ��ĳ�µ�����
inline int GetMonthDay(int year, int month)
{
	//����洢ƽ��ÿ���µ�����
	static int dayArray[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int day = dayArray[month];
	//�ж��Ƿ�Ϊ����
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
	{
		//����2������
		day = 29;
	}
	return day;
}

Date::Date(int year, int month, int day)
{
	//������ڵĺϷ���
	if (year >= 0 && month >= 1 && month <= 12 && day >= 1 && day <= GetMonthDay(year, month))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
	{
		cout << "�Ƿ�����" << endl;
		cout << year << "��" << month << "��" << day << "��" << endl;
	}
}

void Date::Print()const
{
	cout << _year << "��" << _month << "��" << _day << "��" << endl;
}

Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		*this -= -day;
	}
	else
	{
		_day += day;
		//���ڲ��Ϸ���ͨ�����ϵ�����ֱ��������ںϷ�Ϊֹ
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			_month++;
			if (_month > 12)
			{
				_month = 1;
				_year++;
			}
		}
	}
	return *this;
}
Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		*this += -day;
	}
	else
	{
		_day -= day;
		while (_day <= 0)
		{
			_month--;
			if (_month <= 0)
			{
				_year--;
				_month = 12;
			}
			_day += GetMonthDay(_year, _month);
		}
	}
	return *this;
}
Date Date::operator + (int day)const
{
	Date tmp(*this);//��������tmp�����ڷ���
	tmp += day;
	return tmp;
}

Date Date::operator - (int day)const
{
	Date tmp(*this);//��������tmp�����ڷ���
	tmp -= day;
	return tmp;
}

Date& Date::operator++()
{
	//����operator+=
	*this += 1;
	return *this;
}

Date Date::operator++(int)
{
	Date tmp(*this);
	//����operator+=
	*this += 1;
	return tmp;
}

Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

Date Date::operator--(int)
{
	Date tmp(*this);
	//����operator+=
	*this -= 1;
	return tmp;
}

bool Date::operator>(const Date& d)const
{
	if (_year > d._year)
		return true;
	else if (_year == d._year)
	{
		if (_month > d._month)
			return true;
		else if (_month == d._month)
		{
			if (_day > d._day)
				return true;	
		}
	}
		return false;
}

bool Date::operator>=(const Date& d)const
{
	return *this > d || *this == d;
}


bool Date::operator==(const Date& d)const
{
	return _year == d._year && _month == d._month && _day == d._day;
}

bool Date::operator<(const Date& d)const
{
	return !(*this >= d);
}

bool Date::operator<=(const Date& d)const
{
	return !(*this > d);
}

bool Date::operator!=(const Date& d)const
{
	return !(*this == d);
}

int Date::operator -(const Date& d)const
{

	Date max = *this;//����*this���ڽϴ�
	Date min = d; //d���ڽ�С
	int flag = 1; //��ʱ���Ϊ��ֵ
	//��־λ��1��ʾ����-1��ʾ��

	//�������
	if (max < min)
	{
		max = d;
		min = *this;
		flag = -1; //���Ӧ��Ϊ��ֵ
	}
	int count = 0; //��¼����������������ֵ��
	while (max != min)
	{
		min ++; //����++
		count++;//����������
	}

	//���Ҫ��flag,�ſ��Խ������
	return count*flag;

}

