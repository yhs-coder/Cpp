#pragma once
#include <assert.h>
// ģ��ʵ��vector

namespace yang {

	template <class T>
	class vector {
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		vector()
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr) {}

		vector(int n, const T& value = T()) 
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr) 
		{
			reserve(n);
			while (n--) {
				push_back(value);
			}
			cout << "call vector(int n, const T& value = T()) " << endl;
		}
		// ��ʹ��iterator�����������ᵼ�³�ʼ���ĵ���������[first,last)ֻ����vector�ĵ�����
		// ��������������������������[first,last)���������������ĵ�����
		template <class InputIterator>
		vector(InputIterator first, InputIterator last) {
			reserve(last - first);
			while (first != last) {
				push_back(*first);
				first++;
			}
			cout << "call vector(InputIterator first, InputIterator last)" << endl;
		}
		
		~vector() {
			delete[] _start;
			_start = _finish = _endofstorage = nullptr;
		}

		// �������췽��һ
		/*vector(const vector<T>& v) {
			// ���
			_start = new T[v.capacity()];
			_finish = _start;
			_endofstorage = _start + v.capacity();

			// ��������
			for (size_t i = 0; i < v.size(); i++) {
				*_finish = v[i];
				_finish++;
			}
		}*/

		// �������췽����
		vector(const vector<T>& v)
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			// �ȿ���Ԥ���ռ�
			reserve(v.capacity());
			for (const auto& e : v) {
				push_back(e);
			}
		}

		/*vector<T>& operator = (const vector<T>& v) {
			// ��ֹ�Ը�ֵ
			if (this != &v) {
				delete[] _start;
				_start = new T[v.capacity()];
				memcpy(_start, v._start, sizeof(T) * v.size());
				/ *_finish = _start + v.size();
				_endofstorage = _start + v.capacity();* /
			}
			return *this;
		}*/

		// v1 = v3 �ִ�д��
		vector<T>& operator = (vector<T>& v) {
			swap(v);
			return *this;
		}


		void swap(vector<T>& v) {
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endofstorage, v._endofstorage);
		}
		// ���������
		iterator begin() {
			return _start;
		}

		iterator end() {
			return _finish;
		}
		const_iterator begin() const {
			return _start;
		}

		const_iterator end() const {
			return _finish;
		}

		// ���ʣ��ɶ���д
		T& operator[] (size_t pos) {
			assert(pos < size());
			return _start[pos];
		}

		// �����汾��operator[]
		const T& operator[] (size_t pos) const {
			assert(pos < size());
			return _start[pos];
		}

		void reserve(size_t n) {
			size_t sz = size();
			if (n > capacity()) {
				T* tmp = new T[n];
				if (_start) {
					// memcpy(tmp, _start, sizeof(T) * sz); // ���ֽڿ�����ǳ����
					for (size_t i = 0; i < sz; i++) {
						tmp[i] = _start[i];		// ���õ���operator = �����
					}
					delete[] _start;
				}
				_start = tmp;
				_finish = tmp + sz;
				_endofstorage = tmp + n;
			}
		}

		// T& value = T(), ��value��ȱʡֵ��C++���������ṩ �� �Զ����������ƵĹ��죬������Ϊ��֧��ģ��
		void resize(size_t n, const T& val = T()) {
			// �����
			/*	(1) n > size()
					  1. n < capacity()
					  2. n > capacity() ����
				(2) n < size()
			*/
			// 1. ���nС�ڵ�ǰ��size,�����ݸ�����С��n
			if (n < size()) {
				_finish = _start + n;
			}
			else{
				// �ռ䲻������
				if (n > capacity()) {
					reserve(n);
				}
				// �������
				// ������memset������,��Ϊmenset�ǰ��ֽ�Ϊ��λ���в���
				while (_finish < _start + n) {
					*_finish = val;
					_finish++;
				}
			}

		}

		void push_back(const T& x) {
			/*if (_finish == _endofstorage) {
				size_t newcapacity = capacity() == 0 ? 2 : capacity() * 2;
				reserve(newcapacity);
			}
			*_finish = x;
			_finish++;*/
			insert(_finish, x);
		}

		void pop_back() {
			/*assert(_start < _finish);
			_finish--;*/
			erase(_finish - 1);
		}

		iterator insert(iterator pos, const T& x) {
			// ���posλ�úϷ���
			assert(pos >= _start);	// pos == _startͷ��	
			assert(pos <= _finish); // pos == _finish �൱��β��

			// ����ʱ��Ҫ��������
			if (_finish == _endofstorage) {
				size_t n = pos - _start;
				size_t newcapacity = capacity() == 0 ? 2 : capacity() * 2;
				reserve(newcapacity);
				// ������ݣ�ԭ����pos��������ʧЧ�ˣ�����pos��Ҫ���¼���λ�ã�ָ���¿ռ�
				pos = _start + n;
			}
			iterator end = _finish - 1;
			while (end >= pos) {
				*(end + 1) = *(end);
				end--;
			}
			*pos = x;
			_finish++;
			return pos;
		}

		iterator erase(iterator pos) {
			// ���λ�õ���Ч��
			assert(pos < _finish);
			iterator it = pos;
			while (it < _finish) {
				*it = *(it + 1);
				it++;
			}
			_finish--;
			// ����ֵ��ԭʼposλ�õ���һλ�õĵ�����
			// ɾ���ƶ���Ԫ�غ�posָ��ԭ��λ�õ���һλ��
			return pos;
		}
		size_t size() const {
			return _finish - _start;
		}

		size_t capacity() const {
			return _endofstorage - _start;
		}
		bool empty() const {
			return _start == _finish;
		}

	private:
		iterator _start;		// ָ�����ݿ�Ŀ�ʼ
		iterator _finish;		// ָ�������Чһ��Ԫ�ص���һλ��
		iterator _endofstorage;	// ָ��洢��������һλ��
	};


	void print_vector(const vector<int>& v) {
		vector<int>::const_iterator it = v.begin();
		while (it != v.end()) {
			//*it += 1;
			cout << *it << " ";
			it++;
		}
		cout << endl;
	}
	void test_vector1() {
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		cout << v.size() << endl;
		cout << v.capacity() << endl;

		v.push_back(5);
		// ����
		cout << v.size() << endl;
		cout << v.capacity() << endl;

		// ʹ�ó���������
		print_vector(v);

		vector<int>::iterator it = v.begin();
		while (it != v.end()) {
			*it += 1;
			cout << *it << " ";
			it++;
		}
		cout << endl;

		// ���Է�Χfor����
		for (auto& e : v) {
			e -= 1;
			cout << e << " ";
		}
		cout << endl;

		// ����operator[]
		for (size_t i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << endl;
	}

	// ���Բ��롢ɾ��
	void test_vector2() {
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);
		v.push_back(7);

		v.insert(v.begin(), 0);
		print_vector(v);

		v.pop_back();
		vector<int>::iterator it = v.begin();
		while (it != v.end()) {
			if ((*it % 2) == 0)
				it = v.erase(it);
			else
				it++;
		}
		print_vector(v);
	}

	// ����resize
	void test_vector3() {
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);
		v.push_back(7);

		print_vector(v);
		cout << v.size() << endl;
		cout << v.capacity() << endl << endl;

		v.resize(4);
		print_vector(v);
		cout << v.size() << endl;
		cout << v.capacity() << endl << endl;

		v.resize(8,8);
		print_vector(v);
		cout << v.size() << endl;
		cout << v.capacity() << endl << endl;

		v.resize(12,12);
		print_vector(v);
		cout << v.size() << endl;
		cout << v.capacity() << endl << endl;

	}

	void test_vector4() {
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		
		vector<int> v2(v1);
		for (size_t i = 0; i < v1.size(); i++) {
			cout << v1[i] << " ";
		}
		cout << endl;

		for (size_t i = 0; i < v2.size(); i++) {
			cout << v2[i] << " ";
		}
		cout << endl;

		vector<int> v3;
		v3.push_back(10);
		v3.push_back(20);
		v3.push_back(30);
		v3.push_back(40);

		v1 = v3;
		v1.push_back(50);
		for (auto e : v1) {
			cout << e << " ";
		}
		
		cout << endl;
		for (auto e : v3) {
			cout << e << " ";
		}
		cout << endl;
	}

	void test_vector5() {
		// ����memcpy��������⼰���
		vector<std::string> v;
		v.push_back("1111");
		v.push_back("2222");
		v.push_back("3333");
		v.push_back("4444");
		for (auto e : v) {
			cout << e << " ";
		}
		cout << endl;
	}

	void test_vector6() {
		vector<int> v(5,7);
		vector<int> first;
		if (first.empty()) {
			cout << "It's empty" << endl;
		}

		vector<int> second(4, 100);
		print_vector(second);
		vector<int> third(second.begin(), second.end());	  // ʹ�õ��������г�ʼ��
		print_vector(third);
	}
}