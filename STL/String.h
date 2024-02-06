#pragma once
namespace yang
{
	class string
	{
	public: 
		typedef char* iterator;
	public:
		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];	// + 1是为了存储'\0'
			strcpy(_str, str);
		}

		// 深拷贝
		string(const string& s)
		{
			_size = s._size;
			_capacity = s._capacity;
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);
		}

		~string() {
			if (_str) {
				delete[] _str; 
				_str = nullptr;
				_size = _capacity = 0;
				std::cout << "~string" << std::endl;
			}
		}

		string& operator = (const string& s) {
			if (this != &s) {
				delete[] _str;
				_str = new char[strlen(s._str) + 1];
				strcpy(_str, s._str);
				_size = s._size;
				_capacity = s._capacity;
			}
			return *this;
		}

		/***************************************************************************/
		// 迭代器
		iterator begin() {
			return _str;
		}
		iterator end() {
			return _str + _size;
		}

		/***************************************************************************/
		// capacity 容量操作

		size_t size() const {
			return strlen(_str);
		}

		size_t capacity() const {
			return _capacity;
		}

		bool empty() const {
			return _size == 0;
		}

		// 将有效字符的个数改成n个
		void resize(size_t n, char ch = '\0') {
			// 三种情况：
			//	1. n < _size ,有效字符减少
			//	2. n > _size
			//	   2.1  n > _capacity,需要增容
			//	   2.2. n < _capacity
			if (n < _size) {
				_str[n] = '\0';
				_size = n;
			}
			else {
				if (n > _capacity) {
					reserve(n);
				}
				for (size_t i = _size; i < n; i++) {
					_str[i] = ch;
				}
				_size = n;
				_str[_size] = '\0';	// 记得在_str结尾添加'\0'
			}
		}

		void reserve(size_t n) {
			if (n > _capacity) {
				char* newstr = new char[n + 1];	// + 1是为了存储结束字符'\0'
				strcpy(newstr, _str);
				delete[] _str;
				_str = newstr;
				_capacity = n;
			}
		}

		/***************************************************************************/
		// 访问操作

		char& operator[](size_t index) {
			assert(index < _size);
			return _str[index];
		}

		const char& operator[](size_t index) const {
			assert(index < _size);
			return _str[index];
		}

		const char* c_str() const {
			return _str;
		}

		/***************************************************************************/
		// 修改操作
		
		void push_back(char ch) {
			// 空间满了进行增容
			if (_size == _capacity) {
				size_t new_capacity = _capacity == 0 ? 2 : _capacity * 2;
				reserve(new_capacity);
			}
			_str[_size] = ch;
			_size++;
			_str[_size] = '\0';	// 注意，这里需要加个结束字符'\0'
		}

		// 追加字符串
		void append(const char* str) {
			int len = strlen(str);
			if (_size + len > _capacity) {
				// 直接增容两倍可能不够
				reserve(_size + len);
			}
			strcpy(_str + _size, str);
			_size += len;
		}

		// 插入单个字符
		string& operator +=(char ch) {
			push_back(ch);
			return *this;
		}

		string& operator+= (const char* str) {
			append(str);
			return *this;
		}

		string& insert(size_t pos, char ch) {
			// 下标不可越界
			assert(pos < _size);
			int end = _size;
			if (_size == _capacity) {
				size_t new_capacity = _capacity == 0 ? 2 : _capacity * 2;
				reserve(new_capacity);
			}
			// 移动从'\0'开始
			while (end >= pos) {
				_str[end + 1] = _str[end];
				end--;
			}
			_str[pos] = ch;
			_size++;
			return *this;
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

		void clear() {
			_size = 0;
			_str[_size] = '\0';
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
		char*	_str;			// 存储字符的数组
		size_t	_size;			// 有效字符的个数
		size_t	_capacity;		// 存储有效字符的容量,'\0'不是有效字符
		static const size_t npos;
	};

	const size_t string::npos = -1;
};