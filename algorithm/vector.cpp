#include <iostream>

using namespace std;

template<class T>

class vector {
public:
	int _size;
	int capa;
	T* arr;
	vector() {
		_size = 0;
		capa = 32;
		arr = new T[capa];
	}

	vector(int k) {
		_size = capa = k;
		arr = new T[capa];
	}

	~vector() {
		delete[] arr;
	}

	void clear() {
		delete[] arr;
		_size = 0;
		capa = 32;
		arr = new T[capa];
	}

	void resize(int k) {
		T* tmp;
		tmp = new T[k];
		for (int i = 0; i < _size; i++)
			tmp[i] = arr[i];
		delete[] arr;
		arr = tmp;
		_size = capa = k;
	}

	int size() const {
		return _size;
	}

	T* begin() const {
		return &arr[0];
	}

	T* end() const {
		return &arr[_size];
	}

	void push_back(T val) {
		if (_size == capa) {
			resize(_size * 2);
			_size /= 2;
		}
		arr[_size++] = val;
	}

	void pop_back() {
		_size--;
	}

	T& operator [](int idx) {
		return arr[idx];
	}

	T operator [](int idx)const{
		return arr[idx];
	}
};

int main() {

	vector<int> v;
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(7);
	v.pop_back();
	for (int i = 0; i < 4; i++)
		cout << v[i] << endl;

	return 0;
}