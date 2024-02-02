#include <iostream>
#include <string>
using namespace std;

// 2. ����string
void test_string2()
{
	string s1("hello");
	s1 += " ";
	s1 += "world";
	cout << s1 << endl;

	// ������ʽ1��ʹ�� [] + �±�
	for (size_t i = 0; i < s1.size(); i++) {
		s1[i] += 1;	// д
	}

	for (size_t i = 0; i < s1.size(); i++) {
		cout << s1[i] << " ";	// ��
	}
	cout << endl;

	// ������ʽ2��ʹ�õ�����
	string::iterator it = s1.begin();
	while (it != s1.end()) {
		*it -= 1;
		++it;
	}
	it = s1.begin();
	while (it != s1.end()) {
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// C++11 ��Χfor  (ԭ���ǵ�����)
	for (auto ch : s1) {
		cout << ch << " ";
	}
	cout << endl;
}

int string2int(const string& str)
{
	int val = 0;
	// ʹ��const string������Ҫʹ�ó���������const_iterator
	// ֻ�ܶ�������д
	string::const_iterator it = str.begin();
	//string::const_reverse_iterator rit = str.rbegin();
	while (it != str.end()) {
		val *= 10;
		val += (*it - '0');	// �ַ�'1' - '0'�ŵ���1
		++it;
	}
	return val;
}

// 3. ��̸������
// ���������ࣺ
//   - ���������뷴��
//	 - ���ԣ���ͨ��const
//   ������������ϣ�һ�����ֵ�����
void test_string3()
{
	string s1("hello world");
	// ������� ���Ӻ���ǰ������
	// ʹ�÷��������
	string::reverse_iterator rit = s1.rbegin();
	while (rit != s1.rend()) {
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	string nums("123456");
	cout << string2int(nums) << endl;
}

// 4.string��������������
void test_string4()
{
	string s("hello world");
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.capacity() << endl;

	// ��s���ַ������
	s.clear();
	// �۲���Ч�ַ��������ڲ��ռ��С
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s += "hello world hello world";
	// ʹ��resize�������ı���Ч�ַ���������ı��ڲ��ռ��С,���ǿռ䲻���Ż����ݣ�
	s.resize(10, 'a');
	// ��s����Ч�ַ��������ӵ�10�������λ����'a'�������
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	//  ��s����Ч�ַ��������ӵ�15�������λ����ȱʡֵ'\0'�������
	s.resize(15);
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	// ����Ч�ַ�������С��5��
	s.resize(5);
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;
}

// 5. ����reserse����
void test_string5()
{
	string s;
#if 0
	// ����reserve�Ƿ��ı�string����ЧԪ�ظ���
	s.reserve(100);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	// ����reserve����С��string�ĵײ�ռ��Сʱ�����Ὣ�ռ���С
	s.reserve(50);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
#else

	// ����reserve��߲������ݵ�Ч�ʣ��������ݴ����Ŀ���
	s.reserve(100);
	size_t sz = s.capacity();
	cout << "making grow:\n";
	for (size_t i = 0; i < 100; i++) {
		s.push_back('a');
		if (sz != s.capacity()) {
			sz = s.capacity();
			cout << "capacity changed:" << sz << endl;
		}
	}
#endif
}

int main()
{
	//test_string2();
	//test_string3();
	//test_string4();
	test_string5();
	return 0;
}
