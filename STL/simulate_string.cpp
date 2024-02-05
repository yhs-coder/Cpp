#include <iostream>
#include <cassert>
#pragma warning(disable:4996)
namespace yang
{
	class string
	{
	public:
		// 构造
		string(const char* str = nullptr)
			: _str(new char[strlen(str) + 1])	// +1是为了存放'\0'
		{
			strcpy(_str, str);
		}

		// 深拷贝
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

		// 赋值拷贝
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

		// 追加字符串
		void append(const char* str) {

		}

		// 插入单个字符
		string& operator +=(char ch) {

		}

		string& operator+= (const char* str) {

		}

		// 预留空间
		void reserve(size_t n) {
			if (n > _capacity) {
				char* newstr = new char[n + 1];	// + 1是为了存储结束字符'\0'
				strcpy(newstr, _str);
				delete[] _str;
				_str = newstr;
				_capacity = n;
			}
		}


		void resize(size_t n, char ch = '\0') {
			// 三种情况：
			//		1. n < _size ,有效字符减少
			//		2. n > _capacity, 增容
			//		3. n > _size 但是 n < _capacity
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

		// 在pos位置插入字符串
		string& insert(size_t pos, const char* str) {
			assert(pos < _size);
			size_t len = strlen(str);
			// 插入字符串空间不够就先进行扩容
			if (_size + len > _capacity) {
				reserve(_size + len);
			}
			
			int end = _size;
			while (end >= pos) {
				_str[end + len] = _str[end];
				end--;
			}
			//!strcpy(_str + pos, str); // 很严重strcpy会拷贝结束字符'\0',会把pos+len+1位置的字符覆盖掉
			// 使用遍历的方式插入字符
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
		char*	_str;		// 存储字符的数组
		size_t	_size;		// 有效字符的个数
		size_t	_capacity;	// 存储有效字符的容量	
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
