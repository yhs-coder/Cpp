#pragma once

namespace yang
{
	template <class T>
	// ��������ڵ�
	struct __list_node {
		__list_node<T>* prev;
		__list_node<T>* next;
		T data;

		__list_node(const T& x = T())
			: data(x)
			, prev(nullptr)
			, next(nullptr)
		{}
	};

	template <class T, class Ref, class Ptr>
	// ������
	struct __list_iterator {
		typedef __list_node<T> Node;
		typedef __list_iterator<T, Ref, Ptr> Self;
		Node* node;

		__list_iterator(Node* node) : node(node) {}

		// *it
		Ref operator*()
		{
			return node->data;
		}

		// it->
		Ptr operator->()
		{
			return &node->data;
		}

		// ++it ǰ��++
		Self& operator++()
		{
			node = node->next;
			return *this;
		}
		// ����++
		Self operator++(int)
		{
			/*__list_iterator<T> tmp(node);
			node = node->next;
			return tmp;*/
			Self tmp(*this);
			++(*this);
			return tmp;
		}

		// --it ǰ��--
		Self& operator--()
		{
			node = node->prev;
			return *this;
		}

		// --it ����--
		Self operator--(int)
		{
			// __list_iterator<T> tmp(node);
			Self tmp(*this);
			// node = node->prev;
			--(*this);
			return tmp;
		}

		// it != end()
		bool operator != (const Self& it)
		{
			return node != it.node;
		}

		bool operator == (const Self& it)
		{
			return node == it.node;
		}

	};

	template <class T>
	class list {
		typedef __list_node<T> Node;
	public:
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;

		// ��ͷ˫��ѭ������
		list()
		{
			_head = new Node;
			_head->next = _head;
			_head->prev = _head;
		}

		~list()
		{
			clear();
			delete _head;	// �ͷ�ͷ�ڵ�
			_head = nullptr;
		}

		void clear()
		{
			// �ͷų�ͷ�ڵ������еĽڵ�
			iterator it = begin();
			while (it != end())
			{
				erase(it++);
			}
		}

		iterator begin()
		{
			return iterator(_head->next);
		}

		// ���һ�����ݵ���һλ��
		iterator end()
		{
			return iterator(_head);
		}

		// ��������õ�����������
		const_iterator begin() const
		{
			cout << "const_iterator" << endl;
			return const_iterator(_head->next);
		}

		// ���һ�����ݵ���һλ��
		const_iterator end() const
		{
			return const_iterator(_head);
		}


		// ����
		void push_back(const T& x)
		{
			/*Node* newnode = new Node(x);
			Node* tail = _head->prev;	// ����β�ڵ�
			tail->next = newnode;
			newnode->prev = tail;
			newnode->next = _head;
			_head->prev = newnode;*/

			// ����insert
			insert(end(), x);
		}

		void pop_back()
		{
			// ����erase
			// erase(iterator(_head->prev));
			erase(--end());	// �ڱ��ڵ��ǰһ�ڵ����β�ڵ�
		}
		void push_front(const T& x)
		{
			insert(begin(), x);
		}
		void pop_front()
		{
			erase(begin());
		}

		void insert(iterator pos, const T& x)
		{
			Node* cur = pos.node;
			Node* prev = cur->prev;
			Node* newnode = new Node(x);
			// prev newnode cur
			prev->next = newnode;
			newnode->prev = prev;
			newnode->next = cur;
			cur->prev = newnode;
		}

		iterator erase(iterator pos)
		{
			assert(pos != end());

			Node* cur = pos.node;
			Node* prev = cur->prev;
			Node* next = cur->next;
			delete cur;
			prev->next = next;
			next->prev = prev;
			return next;
		}

	private:
		Node* _head;	// �ڱ�ͷ�ڵ�
	};

	void test_list1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(4);
		lt.push_back(5);
		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			cout << *it << " ";
			//++it;
			it++;
		}
		cout << endl;
	}

	struct Date
	{
		int year = 0;
		int month = 1;
		int day = 1;
	};

	void test_list2()
	{
		list<Date> lt;
		lt.push_back(Date());
		lt.push_back(Date());

		list<Date>::iterator it = lt.begin();
		while (it != lt.end())
		{
			//cout << *it << " "; 
			// ԭ����it->()->year������Ϊ�˿ɶ��ԣ�����������������Ĵ���
			cout << it->year << "-" << it->month << "-" << it->day << endl;
			cout << (*it).year << "-" << (*it).month << "-" << (*it).day << endl;
			it++;
		}
	}


	void print_list(const list<int>& lt)
	{
		list<int>::const_iterator it = lt.begin();
		while (it != lt.end())
		{
			//!*it = 2;
			cout << *it << " ";
			it++;
		}
		cout << endl;
	}
	void test_list3()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(4);
		lt.push_back(5);
		print_list(lt);

		lt.pop_back();
		lt.pop_front();
		lt.push_front(111);
		lt.push_back(666);
		print_list(lt);

		lt.clear();
		lt.push_back(100);
		print_list(lt);
	}
}
