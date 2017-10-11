#include <iostream>
#include <vector>
using namespace std;
vector<int> quickvector;

int partition(int i, int j) {
	int h = i;
	for (int k = i + 1; k <= j; k++) {
		if (quickvector[k] < quickvector[i]) {
			h++;
			int val = quickvector[h];
			quickvector[h] = quickvector[k];
			quickvector[k] = val;
		}
	}
	int init = quickvector[i];
	quickvector[i] = quickvector[h];
	quickvector[h] = init;
	return h;
}

int quicksort(int i, int j) {
	if (i < j) {
		int h = partition(i, j);
		quicksort(i, h - 1);
		quicksort(h + 1, j);
	}
	return 0;
}

//binary search
int binarysearch(int i, int j, int key) {
	while (i < j) {
		int k = (i + j) / 2;
		if (quickvector[k] == key)
			return k;
		if (quickvector[k] < key)
			i = k + 1;
		else
			j = k - 1;
	}
	return -1;
}

int main() {
	quickvector.push_back(12);
	quickvector.push_back(30);
	quickvector.push_back(21);
	quickvector.push_back(8);
	quickvector.push_back(6);
	quickvector.push_back(9);
	quickvector.push_back(1);
	quickvector.push_back(7);
	cout << "quickvector before quicksort:";
	for (int i = 0; i < quickvector.size(); i++) {
		cout << " " << quickvector[i];
	}
	cout << endl;
	quicksort(0, quickvector.size()-1);
	cout << "quickvector after quicksort:";
	for (int i = 0; i < quickvector.size(); i++) {
		cout << " " << quickvector[i];
	}
	cout << endl;

	//binary search
	cout << "Search element 21: The index of 21 is " << binarysearch(0, quickvector.size(), 21) << endl;

	system("pause");
	return 0;
}