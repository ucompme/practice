#include <iostream>

#define ARRAY_SIZE(a) size(a)/sizeof(a[0])
#define ALPHABET_SIZE 26
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

using namespace std;

struct DATA {
	int a1, a2;
	DATA() {}
	DATA(int a1, int a2) : a1(a1), a2(a2) {}
	bool operator ==(const DATA& A)const {
		return a1 == A.a1 && a2 == A.a2;
	}

	bool operator !=(const DATA& A)const {
		return a1 != A.a1 || a2 != A.a2;
	}
};


class hash_table {
public:
	const static int SIZE = 10000;
	struct NODE {
		DATA val;
		NODE* next;
		NODE() {}
		NODE(DATA val, NODE* next) :val(val), next(next) {}
	};
	NODE* table[SIZE];
	hash_table() {
		for (int i = 0; i < SIZE; i++)table[i] = NULL;
	}

	int hash(DATA& A) {
		return (A.a1 + A.a2) % SIZE;
	}

	void insert(DATA key) {
		int idx = hash(key);
		table[idx] = new NODE(key, table[idx]);
	}

	void remove(DATA key) {
		int idx = hash(key);
		NODE* prev = NULL;
		NODE* it = table[idx];
		while (it != NULL && it->val != key) {
			prev = it;
			it = it->next;
		}
		if (it == NULL) return;
		if (prev == NULL) {
			table[idx] = table[idx]->next;
		}
		else {
			prev->next = it->next;
		}
	}

	bool search(DATA key) {
		int idx = hash(key);
		NODE* it = table[idx];
		while (it != NULL) {
			if (it->val == key)return true;
			it = it->next;
		}
		return false;
	}
};


int main() {
	hash_table table;
	DATA key1(1, 2); DATA key2(3, 6);
	DATA key3(2, 5); DATA key4(7, 8);
	table.insert(key1);
	table.insert(key2);
	table.insert(key3);
	table.insert(key4);

	if (table.search(key1)) {
		puts("key1 found");
	}

	else {
		puts("key1 not found");
	}

	table.remove(key1);

	if (table.search(key1))
		puts("key1 found");
	else
		puts("key1 not found");

	return 0;
}