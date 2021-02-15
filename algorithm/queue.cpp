#include <iostream>

using namespace std;

template<class T>

class queue {
public:
	struct Node {
		Node* next;
		T val;
		Node() {}
		Node(T val) :val(val), next(0) {}
	};

	Node* head;
	Node* tail;
	int _size;

	queue() {
		head = tail = 0;
		_size = 0;
	}

	void push(T val) {
		Node* tmp = new Node(val);
		if (head == 0)
			head = tail = tmp;
		else
		{
			tail->next = tmp;
			tail = tmp;
		}
		_size++;
	}

	void pop() {
		Node* tmp = head;
		head = head->next;
		delete tmp;
		_size--;
	}
	
	bool empty() const {
		return _size==0;
	}

	T front() const {
		return head->val;
	}

	T back() const {
		return tail->val;
	}

	int size() const {
		return _size;
	}
};