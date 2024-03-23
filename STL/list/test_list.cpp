#include <iostream>
#include <list>
#include <vector>
#include <assert.h>
using namespace std;


// const����ʹ�ó���������
void print_list(const list<int>& lt)
{
	list<int>::const_iterator it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}


// list���졢�������졢��ֵ
// ������ʽ��1. ʹ�õ����� 2. ʹ�÷�Χfor
void test_list1()
{
	list<int> lt1;
	lt1.push_back(1);
	lt1.push_back(2);
	lt1.push_back(3);
	lt1.push_back(4);
	
	// ʹ�õ���������
	list<int>::iterator it1 = lt1.begin();
	while (it1 != lt1.end())
	{
		cout << *it1 << " ";
		it1++;
	}
	cout << endl;

	list<int> lt2(lt1);
	print_list(lt2);

	list<int> lt3;
	lt3.push_back(10);
	lt3.push_back(20);
	lt3.push_back(30);
	lt3.push_back(40);

	lt1 = lt3;
	// ֻҪһ������֧�ֵ��������Ϳ���ʹ�÷�Χfor
	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;

	// ʹ�÷�������� reserve_iterator
	list<int>::reverse_iterator rit = lt1.rbegin();
	while (rit != lt1.rend())
	{
		cout << *rit << " ";
		rit++;
	}
	cout << endl;
}

// list�޸Ĳ����ӿ�
void test_list2()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	// ͷ��
	lt.push_front(0);
	lt.push_front(-1);
	print_list(lt);

	// βɾ
	lt.pop_back();
	// ͷɾ
	lt.pop_front();
	print_list(lt);
}

// ����λ�õĲ���ɾ��
void test_list3()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);
	lt.push_back(6);

	print_list(lt);
	list<int>::iterator pos = find(lt.begin(), lt.end(), 3);
	if (pos != lt.end())
	{
		lt.insert(pos, 30);
		lt.erase(pos);
	}
	print_list(lt);
}

void test_vector()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	vector<int>::iterator pos = find(v.begin(), v.end(), 3);
	if (pos != v.end())
	{
		pos = v.insert(pos, 30);
		pos++;
		v.erase(pos);
	}
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

// ���������
void test_list4()
{
	list<int> lt;
	lt.push_back(2);
	lt.push_back(1);
	lt.push_back(5);
	lt.push_back(4);
	lt.sort();

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	lt.reverse();
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
}

// list������ʧЧ�ĳ���

void test_list5()
{
	list<int> lt;
	lt.push_back(3);
	lt.push_back(2);
	lt.push_back(1);
	lt.push_back(5);
	lt.push_back(4);
	lt.push_back(6);
	list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		// ɾ�������е�ż��
		if (*it % 2 == 0)
		{
			// erase�᷵����һλ�õĵ�����
			it = lt.erase(it);
		}
		else
		{
			it++;
		}
	}
	print_list(lt);
}


#include "list.h" // ģ��ʵ�ֵ�list

int main()
{
	//test_list1();
	//test_list2();
	//test_list3();
	//test_list4();
	//test_list5();
	//test_vector();

	// --------------------------------

	// ����ģ��ʵ�ֵ�list
	//yang::test_list1();
	//yang::test_list2();
	//yang::test_list3();
	yang::test_list4();
	return 0;
}