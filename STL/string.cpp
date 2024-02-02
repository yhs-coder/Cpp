#include <iostream>
#include <string>
using namespace std;

// 2. 遍历string
void test_string2()
{
	string s1("hello");
	s1 += " ";
	s1 += "world";
	cout << s1 << endl;

	// 遍历方式1：使用 [] + 下标
	for (size_t i = 0; i < s1.size(); i++) {
		s1[i] += 1;	// 写
	}

	for (size_t i = 0; i < s1.size(); i++) {
		cout << s1[i] << " ";	// 读
	}
	cout << endl;

	// 遍历方式2：使用迭代器
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

	// C++11 范围for  (原理是迭代器)
	for (auto ch : s1) {
		cout << ch << " ";
	}
	cout << endl;
}

int string2int(const string& str)
{
	int val = 0;
	// 使用const string对象，需要使用常量迭代器const_iterator
	// 只能读，不能写
	string::const_iterator it = str.begin();
	//string::const_reverse_iterator rit = str.rbegin();
	while (it != str.end()) {
		val *= 10;
		val += (*it - '0');	// 字符'1' - '0'才等于1
		++it;
	}
	return val;
}

// 3. 再谈迭代器
// 迭代器分类：
//   - 方向：正向与反向
//	 - 属性：普通与const
//   方向与属性组合，一共四种迭代器
void test_string3()
{
	string s1("hello world");
	// 倒序遍历 （从后往前遍历）
	// 使用反向迭代器
	string::reverse_iterator rit = s1.rbegin();
	while (rit != s1.rend()) {
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	string nums("123456");
	cout << string2int(nums) << endl;
}

// 4.string类对象的容量操作
void test_string4()
{
	string s("hello world");
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.capacity() << endl;

	// 将s的字符串清空
	s.clear();
	// 观察有效字符个数及内部空间大小
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s += "hello world hello world";
	// 使用resize函数（改变有效字符，并不会改变内部空间大小,除非空间不够才会扩容）
	s.resize(10, 'a');
	// 将s中有效字符个数增加到10个，多出位置用'a'进行填充
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	//  将s中有效字符个数增加到15个，多出位置用缺省值'\0'进行填充
	s.resize(15);
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	// 将有效字符个数缩小到5个
	s.resize(5);
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;
}

// 5. 测试reserse函数
void test_string5()
{
	string s;
#if 0
	// 测试reserve是否会改变string中有效元素个数
	s.reserve(100);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	// 测试reserve参数小于string的底层空间大小时，不会将空间缩小
	s.reserve(50);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
#else

	// 利用reserve提高插入数据的效率，避免增容带来的开销
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
