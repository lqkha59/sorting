#include <iostream>
#include <vector>
using namespace std;
vector<int> mergevector;

int merge(int p, int q, int n) {
	vector<int> L, R;
	int a = q - p + 1;	//number of elements in L
	int b = n - q;		//number of elements in R
	L.resize(a);
	R.resize(b);

	//copy subvector from A to L, R
	for (int i = 0; i < a; i++) {
		L[i] = mergevector[p + i];
	}
	for (int i = 0; i < b; i++) {
		R[i] = mergevector[q + 1 + i];
	}

	//merge 2 sub in one (sorted) until 1 sub finish
	int i = 0, j = 0;
	int r = p;
	for (; i < a && j < b;) {
		if (L[i] <= R[j]) {
			mergevector[r] = L[i];
			i++;
		}
		else {
			mergevector[r] = R[j];
			j++;
		}
		r++;
	}

	//if R finish, L remains
	for (; i < a; i++) {
		mergevector[r] = L[i];
		r++;
	}

	//if L finish, R remains
	for (; j < b; j++) {
		mergevector[r] = R[j];
		r++;
	}
	return 0;
}

int mergesort(int i, int j) {
	if (i == j) return 0;
	int m = (i + j) / 2;
	mergesort(i, m);
	mergesort(m + 1, j);
	merge(i, m, j);
	return 0;
}

int mergeapp() {
	mergevector.push_back(5);
	mergevector.push_back(7);
	mergevector.push_back(6);
	mergevector.push_back(2);
	mergevector.push_back(59);
	mergevector.push_back(15);
	mergevector.push_back(3);
	mergevector.push_back(34);
	mergevector.push_back(27);
	cout << "The vector initially is: " << endl;
	for (int i = 0; i < mergevector.size(); i++)
		cout << " " << mergevector[i];
	mergesort(0, mergevector.size() - 1);
	cout << "\nThe vector after mergesort is: " << endl;
	for (int i = 0; i < mergevector.size(); i++)
		cout << " " << mergevector[i];
	system("pause");
	return 0;
}