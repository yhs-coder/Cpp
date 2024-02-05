#include <iostream>
#include <cassert>
#pragma warning(disable:4996)
namespace yang
{
	class string
	{
	public:
		// ����
		string(const char* str = nullptr)
			: _str(new char[strlen(str) + 1])	// +1��Ϊ�˴��'\0'
		{
			strcpy(_str, str);
		}

		// ���
		string(const string& s) 
			: _str(new char[strlen(s._str) + 1])
		{
			strcpy(_str, s._str);
		}

		~string() {
			if (_str) {
				delete[] _str;
				_str = nullptr;
				std::cout << "~string" << std::endl;
			}
		}

		// ��ֵ����
		string& operator = (const string& s) {
			if (this != &s) {
				delete[] _str;
				_str = new char[strlen(s._str) + 1];
				strcpy(_str, s._str);
			}
			return *this;
		}

		size_t size() {
			return strlen(_str);
		}

		char& operator[](size_t i) {
			return _str[i];
		}

		const char* c_str() {
			return _str;
		}

		// ׷���ַ���
		void append(const char* str) {

		}

		// ���뵥���ַ�
		string& operator +=(char ch) {

		}

		string& operator+= (const char* str) {

		}

		// Ԥ���ռ�
		void reserve(size_t n) {
			if (n > _capacity) {
				char* newstr = new char[n + 1];	// + 1��Ϊ�˴洢�����ַ�'\0'
				strcpy(newstr, _str);
				delete[] _str;
				_str = newstr;
				_capacity = n;
			}
		}


		void resize(size_t n, char ch = '\0') {
			// ���������
			//		1. n < _size ,��Ч�ַ�����
			//		2. n > _capacity, ����
			//		3. n > _size ���� n < _capacity
			if (n < _size) {
				_str[n] = '\0';
				_size = n;
			} else {
				if (n > _capacity) {
					reserve(n);
				}
				for (size_t i = _size; i < n; i++) {
					_str[i] = ch;
				}
				_size = n;
				_str[_size] = '\0';
			}
		}

		string& insert(size_t pos, char ch) {

		}

		// ��posλ�ò����ַ���
		string& insert(size_t pos, const char* str) {
			assert(pos < _size);
			size_t len = strlen(str);
			// �����ַ����ռ䲻�����Ƚ�������
			if (_size + len > _capacity) {
				reserve(_size + len);
			}
			
			int end = _size;
			while (end >= pos) {
				_str[end + len] = _str[end];
				end--;
			}
			//!strcpy(_str + pos, str); // ������strcpy�´�������ַ�'\0',���pos+len+1λ�õ��ַ����ǵ�
			// ʹ�ñ����ķ�ʽ�����ַ�
			/*for(size_t i = 0; i < len; i++) {
				_str[pos++] = str[i++];
			}*/
			strncpy(_str + pos, str, len);
			_size += len;
			return *this;
		}

		void erase(size_t pos, size_t len = npos) {

		}

		size_t find(char ch, size_t pos = 0) {}
		size_t find(const char* str, size_t pos = 0);
		bool operator < (const string& s);
		bool operator == (const string& s);
		bool operator <= (const string& s);
		bool operator > (const string& s);
		bool operator >= (const string& s);
		bool operator != (const string& s);
	private:
		char*	_str;		// �洢�ַ�������
		size_t	_size;		// ��Ч�ַ��ĸ���
		size_t	_capacity;	// �洢��Ч�ַ�������	
		static size_t npos;
	};

	size_t string::npos = -1;
};


using namespace yang;
void test_string1() {
	yang::string s1("hello");
	yang::string s2;
	for (size_t i = 0; i < s1.size(); i++) {
		s1[i] += 1;
		std::cout << s1[i] << " ";
	}
	std::cout << std::endl;
}

void test_string2()
{
	string s1("hello");
	string s2(s1);
	std::cout << s1.c_str() << std::endl;
	std::cout << s2.c_str() << std::endl;
	string s3("world");
	s1 = s3;
	std::cout << s3.c_str() << std::endl;
	std::cout << s1.c_str() << std::endl;
}

int main()
{
	//test_string1();
	test_string2() ;
	return 0;
}
