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
			_str = new char[_capacity + 1];	// + 1��Ϊ�˴洢'\0'
			strcpy(_str, str);
		}

		// ���
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
		// ������
		iterator begin() {
			return _str;
		}
		iterator end() {
			return _str + _size;
		}

		/***************************************************************************/
		// capacity ��������

		size_t size() const {
			return strlen(_str);
		}

		size_t capacity() const {
			return _capacity;
		}

		bool empty() const {
			return _size == 0;
		}

		// ����Ч�ַ��ĸ����ĳ�n��
		void resize(size_t n, char ch = '\0') {
			// ���������
			//	1. n < _size ,��Ч�ַ�����
			//	2. n > _size
			//	   2.1  n > _capacity,��Ҫ����
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
				_str[_size] = '\0';	// �ǵ���_str��β���'\0'
			}
		}

		void reserve(size_t n) {
			if (n > _capacity) {
				char* newstr = new char[n + 1];	// + 1��Ϊ�˴洢�����ַ�'\0'
				strcpy(newstr, _str);
				delete[] _str;
				_str = newstr;
				_capacity = n;
			}
		}

		/***************************************************************************/
		// ���ʲ���

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
		// �޸Ĳ���
		
		void push_back(char ch) {
			// �ռ����˽�������
			if (_size == _capacity) {
				size_t new_capacity = _capacity == 0 ? 2 : _capacity * 2;
				reserve(new_capacity);
			}
			_str[_size] = ch;
			_size++;
			_str[_size] = '\0';	// ע�⣬������Ҫ�Ӹ������ַ�'\0'
		}

		// ׷���ַ���
		void append(const char* str) {
			int len = strlen(str);
			if (_size + len > _capacity) {
				// ֱ�������������ܲ���
				reserve(_size + len);
			}
			strcpy(_str + _size, str);
			_size += len;
		}

		// ���뵥���ַ�
		string& operator +=(char ch) {
			push_back(ch);
			return *this;
		}

		string& operator+= (const char* str) {
			append(str);
			return *this;
		}

		string& insert(size_t pos, char ch) {
			// �±겻��Խ��
			assert(pos < _size);
			int end = _size;
			if (_size == _capacity) {
				size_t new_capacity = _capacity == 0 ? 2 : _capacity * 2;
				reserve(new_capacity);
			}
			// �ƶ���'\0'��ʼ
			while (end >= pos) {
				_str[end + 1] = _str[end];
				end--;
			}
			_str[pos] = ch;
			_size++;
			return *this;
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
		char*	_str;			// �洢�ַ�������
		size_t	_size;			// ��Ч�ַ��ĸ���
		size_t	_capacity;		// �洢��Ч�ַ�������,'\0'������Ч�ַ�
		static const size_t npos;
	};

	const size_t string::npos = -1;
};