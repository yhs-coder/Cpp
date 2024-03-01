#include <iostream>
using namespace std;

// �ɱ�ģ�����,��0������������������������������ȷ��
template <typename...T>
void print(T... t)
{
	cout << "sizeof...(T) = " << sizeof...(T) << endl;
	cout << "sizeof...(t) = " << sizeof...(t) << endl;
}

void test1()
{
	print();
	print(1, "hello");
	print(1, true, 3.3, "hello");

}


// ��������Ϊ�գ��ݹ�ֹͣ
void show()
{
	cout << "����Ϊ��" << endl;
}

template <typename T, typename... Args>
void show(T t, Args... args)
{
	cout << t << " ";
	// �ݹ飬 ...λ�ڲ����ұߵ�ʱ�򣬳�Ϊ���
	// ...λ����ߵ�ʱ�򣬳�Ϊ���
	show(args...);
}

void test2()
{
	// ���ʵ�Σ����ÿɱ�����ĺ���ģ��
	show(1, "hello", 3.3);
	show(1, true, 3.14);
	// ����Ϊ�գ�������ͨ�ĺ���
	show();
}


int sum()
{
	return 0;
}

// ʹ�ÿɱ�ģ�����ʵ�ֵ���
template <typename T, typename... Args>
T sum(T t, Args... args)
{
	return t + sum(args...);
}

void test3()
{
	cout << sum(1, 2, 3, 4, 5, 6, 7, 8, 9, 10); // 55
}

union Un
{
	int i;
	char c;
};
union Un un;


int main()
{
	//test1();
	/*test2();
	test3();*/

	un.i = 0x11223344;
	un.c = 0x55;
	printf("%x\n", un.i);
	printf("%x\n", un.c);
	return 0;
}