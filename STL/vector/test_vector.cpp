#include <iostream>
using std::cout;
using std::endl;
#include "simulate_vector.h"


namespace yang {

	// ģ��ʵ��vector
	template <class T>
	class vector {
	public:
		// ���ͱ���
		typedef T* iterator;
		typedef const T* const_iterator;

		// Ĭ�ϳ�Ա����
		// ���캯��
		vector();
		vector(int n, const T& value = T())

	};

}


int main()
{
	//yang::test_vector1();
	//yang::test_vector2();
	//yang::test_vector3();
	//yang::test_vector4();
	//yang::test_vector5();
	yang::test_vector6();
	return 0;
}





