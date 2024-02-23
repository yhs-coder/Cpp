#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Ĭ�ϳ�Ա����
void test_vector1()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	
	vector<int> v2(v1);
	for (size_t i = 0; i < v2.size(); i++) {
		cout << v1[i] << " ";
	}
	cout << endl;
	for (size_t i = 0; i < v2.size(); i++) {
		cout << v2[i] << " ";
	}
	cout << endl;

	vector<int> v3;
	v3.push_back(10);
	v3.push_back(20);
	v3.push_back(30);
	v3.push_back(40); 
	v1 = v3;
	for (size_t i = 0; i < v2.size(); i++) {
		cout << v1[i] << " ";
	} 
	cout << endl;
}

// ���ֱ�����ʽ
void test_vector2()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	// �����޸�����
	// ��ʽ1�� operator[] + size()
	for (size_t i = 0; i < v1.size(); i++) {
		cout << v1[i] << " ";
	}
	cout << endl;

	// ��ʽ2�������� ������������vector�������ͣ�
	vector<int>::iterator it = v1.begin();
	while (it != v1.end()) {
		cout << *it << " ";
		it++;
	}
	cout << endl;

	// ��ʽ3����Χfor -> �����Ǳ������滻�ɵ�������ʽ֧�ֱ�����
	for (auto e : v1) {
		cout << e << " ";
	}
	cout << endl;
}

void print_vector(const vector<int>& vt)
{
	// ֻ��
	vector<int>::const_iterator it = vt.begin();
	while (it != vt.end()) {
		// *it = 1;
		cout << *it << " ";
		it++;
	}
	cout << endl;

}


// �������͵ĵ�����
void test_vector3()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	// ��������� �ɶ���д
	vector<int>::iterator it = v.begin();
	while (it != v.end()) {
		cout << *it << " ";
		it++;
	}
	cout << endl;

	// ����������
	print_vector(v);

	// ���������
	vector<int>::reverse_iterator rit = v.rbegin();
	while (rit != v.rend()) {
		cout << *rit << " ";
		rit++;
	}
	cout << endl;
}

// vector��������
void test_vector4()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	// vector�ռ���������
	size_t sz;
	vector<int> foo;
	sz = foo.capacity();
	// foo.reserve(1000);
	foo.resize(1000);
	cout << "making foo grow:" << endl;
	for (int i = 0; i < 1000; i++) {
		foo.push_back(i);
		if (sz != foo.capacity()) {
			sz = foo.capacity();
			cout << "capacity changed:" << sz << endl;
		}
	}
}

// Ԫ�ط���
void test_vector5()
{

	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	
	cout << v[1] << endl;
	cout << v.at(1) << endl;
	
	// []��at�������Խ��ķ�ʽ
	//v[4] = 1;	// ֱ�Ӷ����ж�
	//v.at(4);	// �׳��쳣
}

// �޸Ĳ��� insert / erase
void test_vector6()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(3);

	// ����
	v.insert(v.begin(), 0);
	v.insert(v.begin(), -1);
	for (auto e : v) {
		cout << e << " ";
	}
	cout << endl;

	// ɾ��
	v.erase(v.begin() + 2);	// ɾ��������Ԫ��
	for (auto e : v) {
		cout << e << " ";
	}
	cout << endl;
}

// ���Һ�����find��sort���ڱ�׼�㷨��
void test_vector7()
{
	vector<int> v;
	v.push_back(5);
	v.push_back(2);
	v.push_back(20);
	v.push_back(1);
	v.push_back(5);
	for (auto e : v) {
		cout << e << " ";
	}
	cout << endl;
	// find�㷨��Χ������ҿ�[begin,end)
	vector<int>::iterator pos = find(v.begin(),v.end(), 5);
	// ɾ����һ����5
	if (pos != v.end()) {
		v.erase(pos);
	}
	for (auto e : v) {
		cout << e << " ";
	}
	cout << endl;

	// ʹ��sort�㷨��������
	sort(v.begin(), v.end());
	for (auto e : v) {
		cout << e << " ";
	}
	cout << endl;
}

int main()
{
	//test_vector1();
	//test_vector2();
	//test_vector3();
	//test_vector4();
	//test_vector5();
	//test_vector6();
	test_vector7();
	return 0;
}