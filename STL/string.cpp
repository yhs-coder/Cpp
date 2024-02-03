#include <iostream>
#include <string>
#include <ctime>
using namespace std;

// 1.4��Ĭ�ϳ�Ա����
void test_string1()
{
	string s1;
	string s2("hello");
	string s3("hello", 2);
	string s4(s2);
	string s5(s2, 1, 8);
	string s6(s2, 1, string::npos);
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;
	cout << s6 << endl;

}

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

// c_str() : ��string����ת��Ϊc�ַ���
void test_string6()
{
	string s = "hello world";
	cout << s << endl;
	cout << s.c_str() << endl;

	s += '\0';
	s += "linux";
	cout << s << endl;			// ���õ���string���ص�operator
	cout << s.c_str() << endl;	// ת��ΪC���͵��ַ������������'\0'��ֹͣ

	// ��Щ�ַ�����ǲ��ɼ���
	for (unsigned char ch = 0; ch < 255; ch++) {
		cout << ch << " ";

	}
	cout << endl;
}
// string�������޸Ĳ���
void test_string7()
{

	string str;
	// �������
	str.push_back(' ');
	str.append("hello ");	//��str��׷���ַ���
	str += 'y';				// += �ȿ��Լ��ַ���Ҳ�ɼ��ַ���
	str += "ang";
	cout << str << endl;
	cout << str.c_str() << endl;

	// ���Ҳ���
	string file("string.cpp.zip");
	// ��ȡ�ļ���׺��
	//size_t pos = file.find('.');
	size_t pos = file.rfind('.');
	// ��ȡ���ַ���
	string suffix(file.substr(pos));	// Ĭ�Ͻ�ȡ�����
	cout << suffix << endl;
	suffix = file.substr(pos, file.size() - pos);
	cout << suffix << endl;
	
	// npos��string�����һ����̬��Ա����
	// static const size_t npos = -1;

}

int main()
{
	//test_string1();
	//test_string2();
	//test_string3();
	//test_string4();
	//test_string5();
	//test_string6();
	test_string7();
	return 0;
}
