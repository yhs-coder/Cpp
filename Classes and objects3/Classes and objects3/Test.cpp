#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


//class Date
//{
//public:
//	/*
//	//ȫȱʡ�����ĵĹ��캯��
//	Date(int year = 0, int month = 0, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	*/
//	//���캯����ʼ���б�
//	Date(int year,int month,int day):_year(year),_month(month),_day(day){}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};

/*��ʼ���б���ʼ���Զ������ͳ�Ա��û��Ĭ�Ϲ��캯����*/
class A
{
public:
	A(int val)
	{
		_val = val;
	}
private:
	int _val;
};

class B
{
public:
	B() :_a(2022){}
private:
	A _a;
};


//��ʼ���б������ߴ���Ч��
class Time
{
public:
	Time(int hour = 0)
	{
		_hour = hour;
	}

private:
	int _hour;
};
class Test
{
public:
	/*
	//ʹ�ó�ʼ���б�
	Test(int hour):_t(hour){}
	//ʵ����Test����ʱ���ڳ�ʼ���б��ǵ�����һ��Time�Ĺ��캯��
	*/

	//��ʹ�ó�ʼ���б�
	Test(int hour)
	{
		//��ʹ�ó�ʼ���б�Ҳ�����һ��Time�Ĺ��캯������ȷ������Ҫ����ĳ�Ա������
		Time t(hour); //�ٵ���һ��Time�Ĺ��캯��
		_t = t;		//����һ��Time��ĸ�ֵ��������غ���
	}

private:
	Time _t;
};


/*
	��ʼ���б��ʼ��˳�򣺳�Ա���������������Ĵ��򣬶������ڳ�ʼ���б���Ⱥ�˳��
*/
int i = 0;
class Test1
{
public:
	Test1():_b(i++),_a(i++){}
	//_a��������_b����������ʼ���б��ȳ�ʼ��_a��_b
	void Print()
	{
		cout << "_a:" << _a << endl; //0
		cout << "_b:" << _b << endl; //1
	}
private:
	int _a;
	int _b;


};


/*
	Static��Ա
	1.��̬��Ա����һ��Ҫ��������г�ʼ��
	2.��̬��Ա����û�����ص�thisָ�룬���ܷ����κηǾ�̬��Ա����ֻ�ܷ��ʾ�̬��Ա������
	3.��̬��Ա�������������ⶨ�壬����ʱ�����static�ؼ���
	4.���ʾ�̬��Ա�����ķ���
*/

class Test2
{
public:
	static void Fun()
	{
		//cout << _a << endl;//û��thisָ�룬���ܷ��ʣ�
		cout << _n << endl;
	}
	static int GetN()
	{
		return  _n;
	}
private:
	static int _n;
	int _a;
};

class Test3
{
public:
	static int _n2;
};

int Test3::_n2 = 666;
//��̬��Ա�����Ķ����ʼ��
int Test2::_n = 10;


class Date
{
	//��Ԫ����������
	friend  ostream& operator << (ostream & out, const Date & d);
	friend istream& operator>>(istream& in, Date& d);
	public:
	//ȫȱʡ�����ĵĹ��캯��
	Date(int year = 0, int month = 0, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	

private:
	int _year;
	int _month;
	int _day;
};

ostream& operator << (ostream& out, const Date& d)
{
	out << d._year << "-" << d._month << "-" << d._day << endl;
	return out;
}

istream& operator>>(istream& in, Date& d)
{
	in >> d._year >>d._month >>  d._day ;
	return in;
}


/*
	�ڲ���:
	�ⲿ��Ĵ�С���ڲ���Ĵ�С�޹�
*/

class C
{
public:
	class B
	{
	private:
		int _b;
	};
private:
	int _a;
};


int main()
{
	//Test test(21);
	//Test1 t;
	//t.Print();
	//cout << sizeof(Test2) << endl;

	/* .����̬��Ա����Ϊ����ʱ,�����ַ��ʷ�ʽ��
	Test3 t;
	cout << t._n2 <<endl; //ͨ�������ͻ��������з���
	cout << Test3()._n2 << endl;//ͨ����������ͻ��������з���
	cout << Test3::_n2 << endl; //ͨ������ͻ��������з���
	*/

	
	/*����̬��Ա����Ϊ˽��ʱ�������ַ��ʷ�ʽ��
	Test2 t;
	cout << t.GetN() << endl; //ͨ���������ó�Ա�������з���
	cout << Test2().GetN() << endl;//ͨ������������þ�̬��Ա�������з���
	cout << Test2::GetN() << endl; //ͨ���������þ�̬��Ա�������з���
	*/
	cout << sizeof(C) << endl;
	return 0;
}