#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<typeinfo>
using std::string;

//using 声明一个命名空间，后期可以省略前缀的作用域
using std::cin;
using std::cout;
using std::endl;

void test2()
{
	cout << "Enter two numbers:" << endl;
	int v1, v2;
	cin >> v1 >> v2;
	cout << "The sum of " << v1 << " and " << v2 << " is " << v1 + v2 << endl;
}
void test1()
{
	int i;
	cin >> i;
	std::cout << i;

}

void test_String()
{
	/*
	*	1.定义和初始化string对象
	*/
	/*
	string s1;//默认初始化，s1是一个空字符串
	string s2 = s1; //s1拷贝给s2，也说成是s2是s1的副本
	string s3 = "hello";
	string s4(10, 'c');

	string s5 = "hiya"; //拷贝初始化
	string s6("hiya");  //直接初始化  //s6、s5等价
	string s7(10, 'c'); //直接初始化

	string s8 = string(10, 'b');  //拷贝初始化，s8为bbbbbbbbbb
	*/
	/*  s8的本质：
		string temp(10,'b');
		string s8=temp;
	*/

	//cout <<s1<<endl<< s8 << endl;

	/*
		2.string 对象的操作
	*/

	//2.1 读写string对象

	/*
	string s;
	cin >> s;  //忽略开头的空白，直到从第一个字符开始，遇到下个空白处停止
	cout << s << endl;
	*/

	/*
	string s1, s2;
	cin >> s1 >> s2;
	cout << s1 << s2 << endl;
	*/

	//2.2 读取未知数量的string对象
	/*
	string word;
	while (cin >> word)
		cout << word << endl;
	*/

	//2.3 使用getline读取一整行
	//2.4 string的empty和size操作

	/*
	string line;
	while (getline(cin, line))
	{
		if (!line.empty())
			cout << line << endl;
		if (line.size() > 1)
		{
			cout << "line's size:" << line.size() << endl;
			cout << "string的size函数的返回值：" << typeid(line.size()).name() << endl;
		}
		else
			break;
	}
	*/
	/*
	//2.5 比较string对象
	string str = "hello";
	string str2 = "hello world";
	string lang = " haha";
	//lang >str>str2

	//2.6两个string对象相加
	string newstr = str2 + lang;
	cout << newstr << endl;

	//2.7字面值和string对象相加
	string newstr2 = str2 + ", " + lang + '\n';
	cout << newstr2 << endl;
	//string newstr3 = "hello" + " ,,,";//error,两个字面值不可相加
	//字面值的一侧要有string对象才可拼接
	string newstr4 = lang + "C++" + " ,hard!";
	cout << newstr4 << endl;

	*/

	/*
		practice!
	*/
	//1.比较两个字符串是否相等
	/*
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		if (s1 == s2)
		{
			cout << "The two strings are equal." << endl;
		}
		else
		{
			cout << "The larger string is " << ((s1 > s2) ? s1 : s2);
		}
	}
	*/

	//2.比较两个字符是否等长
	/*
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		if (s1.size() == s2.size())
			cout << "The two strings have the same length." << endl;
		else
			cout << "The longer string is " << (s1.size() > s2.size() ? s1:s2);
	}
	*/
	//3.从标准输入中读入多个字符串并将他们连接起来，输出连接成的大字符串。
	//string s1, s2;
	//while (cin >> s2)
	//{
	//		s1 += s2 +" ";
	//}
	//cout << s1 << endl;
	//


	/*
		3.处理string对象的字符
	*/

	//3.1利用range for循环处理每个字符

/*
	string str("some string");

	//每行输出str的一个字符
	for (auto c : str)  //使用auto决定变量的类型
		cout << c << endl;
*/
/*
	string s("hello world!!!");
	decltype(s.size()) punct_cnt = 0; //使用decltype选择并返回s.size()的类型

	//统计s中符号的数量
	for (auto c : s)
	{
		if (ispunct(c))//如果为标点符号
			punct_cnt++;
	}
	cout << punct_cnt << " punctuation characters in " << s << endl;
	*/

	//3.2 使用范围for语句改变字符串中的字符
/*
	string s("hello world!!!");
	//转换成大写形式
	for (auto& c : s)
		c = toupper(c);
	cout << s << endl;
*/

/*
	practice
*/
//1.编写一段程序，使用范围for语句将字符串内所有字符用X代替。
/*
	string s("hello world!!!");
	for (auto& c : s)
		c = 'X';
	cout << s << endl;
*/
//2.编写一段程序，读入一个包含标点符号的字符串，将标点符号去除后输出字符串剩余的部分。
	string s = "this, is. a :string!";
	string result;
	for (auto c : s)
		if (!ispunct(c))
			result += c;
	cout << result << endl;


}

void test_vector()
{

}
int main()
{
	//test1();
	//test2();
	//test_String();
	return 0;
}