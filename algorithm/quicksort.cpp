#include <iostream>

using namespace std;

int llist[6];

void quickSort(int* data, int i, int j) {
	if (i >= j) return;

	int left = i;
	int right = j;
	int pivot = data[(i + j) / 2];

	while (left <= right) {
		while (data[left] < pivot) left++;
		while (data[right] > pivot) right--;
		if (left <= right)
		{
			swap(data[left], data[right]);
			left++;
			right--;
		}
	}

	quickSort(data, left, j);
	quickSort(data, i, right);
}

int main() {

	for (int i = 0; i < 6; i++)
		cin >> llist[i];

	quickSort(llist, 0, 5);

	for (int i = 0; i < 6; i++)
		cout << llist[i];

	return 0;
}