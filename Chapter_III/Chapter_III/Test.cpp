#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<typeinfo>
using std::string;

//using ����һ�������ռ䣬���ڿ���ʡ��ǰ׺��������
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
	*	1.����ͳ�ʼ��string����
	*/
	/*
	string s1;//Ĭ�ϳ�ʼ����s1��һ�����ַ���
	string s2 = s1; //s1������s2��Ҳ˵����s2��s1�ĸ���
	string s3 = "hello";
	string s4(10, 'c');

	string s5 = "hiya"; //������ʼ��
	string s6("hiya");  //ֱ�ӳ�ʼ��  //s6��s5�ȼ�
	string s7(10, 'c'); //ֱ�ӳ�ʼ��

	string s8 = string(10, 'b');  //������ʼ����s8Ϊbbbbbbbbbb
	*/
	/*  s8�ı��ʣ�
		string temp(10,'b');
		string s8=temp;
	*/

	//cout <<s1<<endl<< s8 << endl;

	/*
		2.string ����Ĳ���
	*/

	//2.1 ��дstring����

	/*
	string s;
	cin >> s;  //���Կ�ͷ�Ŀհף�ֱ���ӵ�һ���ַ���ʼ�������¸��հ״�ֹͣ
	cout << s << endl;
	*/

	/*
	string s1, s2;
	cin >> s1 >> s2;
	cout << s1 << s2 << endl;
	*/

	//2.2 ��ȡδ֪������string����
	/*
	string word;
	while (cin >> word)
		cout << word << endl;
	*/

	//2.3 ʹ��getline��ȡһ����
	//2.4 string��empty��size����

	/*
	string line;
	while (getline(cin, line))
	{
		if (!line.empty())
			cout << line << endl;
		if (line.size() > 1)
		{
			cout << "line's size:" << line.size() << endl;
			cout << "string��size�����ķ���ֵ��" << typeid(line.size()).name() << endl;
		}
		else
			break;
	}
	*/
	/*
	//2.5 �Ƚ�string����
	string str = "hello";
	string str2 = "hello world";
	string lang = " haha";
	//lang >str>str2

	//2.6����string�������
	string newstr = str2 + lang;
	cout << newstr << endl;

	//2.7����ֵ��string�������
	string newstr2 = str2 + ", " + lang + '\n';
	cout << newstr2 << endl;
	//string newstr3 = "hello" + " ,,,";//error,��������ֵ�������
	//����ֵ��һ��Ҫ��string����ſ�ƴ��
	string newstr4 = lang + "C++" + " ,hard!";
	cout << newstr4 << endl;

	*/

	/*
		practice!
	*/
	//1.�Ƚ������ַ����Ƿ����
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

	//2.�Ƚ������ַ��Ƿ�ȳ�
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
	//3.�ӱ�׼�����ж������ַ���������������������������ӳɵĴ��ַ�����
	//string s1, s2;
	//while (cin >> s2)
	//{
	//		s1 += s2 +" ";
	//}
	//cout << s1 << endl;
	//


	/*
		3.����string������ַ�
	*/

	//3.1����range forѭ������ÿ���ַ�

/*
	string str("some string");

	//ÿ�����str��һ���ַ�
	for (auto c : str)  //ʹ��auto��������������
		cout << c << endl;
*/
/*
	string s("hello world!!!");
	decltype(s.size()) punct_cnt = 0; //ʹ��decltypeѡ�񲢷���s.size()������

	//ͳ��s�з��ŵ�����
	for (auto c : s)
	{
		if (ispunct(c))//���Ϊ������
			punct_cnt++;
	}
	cout << punct_cnt << " punctuation characters in " << s << endl;
	*/

	//3.2 ʹ�÷�Χfor���ı��ַ����е��ַ�
/*
	string s("hello world!!!");
	//ת���ɴ�д��ʽ
	for (auto& c : s)
		c = toupper(c);
	cout << s << endl;
*/

/*
	practice
*/
//1.��дһ�γ���ʹ�÷�Χfor��佫�ַ����������ַ���X���档
/*
	string s("hello world!!!");
	for (auto& c : s)
		c = 'X';
	cout << s << endl;
*/
//2.��дһ�γ��򣬶���һ�����������ŵ��ַ�������������ȥ��������ַ���ʣ��Ĳ��֡�
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