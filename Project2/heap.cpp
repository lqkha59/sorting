#include <iostream>
#include <vector>

using namespace std;
vector<int> heapvectorA;
vector<int> heapsortvectorA;

/*
int siftdown(vector<int> A, int i) {
	int largerst = i;
	int left = 2*i + 1;
	int right = left + 1;
	if (left<A.size() && A[left]>A[largerst])
		largerst = left;
	if (right<A.size() && A[right]>A[largerst])
		largerst = right;
	if (largerst != i) {
		int val = A[i];
		A[i] = A[largerst];
		A[largerst] = val;
		return siftdown(A, largerst);
	}
	else
		return 0;
}

int siftup(vector<int> A, int i) {
	int val = A[i];
	while (i > 0 && val > A[(i - 1) / 2]) {
		A[i] = A[(i - 1) / 2];
		i = (i - 1) / 2;
		A[i] = val;
	}
	return 0;
}

int heapify(vector<int> A) {
	for (int i = (A.size() - 1 - 1) / 2; i >= 0; i--) {
		siftdown(A, i);
	}
	return 0;
}

int heap_delete_root(vector<int> A) {
	A[0] = A[A.size() - 1];
	A.resize(A.size() - 1);
	siftdown(A, 1);
	return 0;
}

int heapdelete(vector<int> A, int i) {
	if (i == 0)
		heap_delete_root(A);
	else {
		A[i] = A[A.size() - 1];
		A.resize(A.size() - 1);
		if (A[(i - 1) / 2] >= A[i])
			siftdown(A, i);
		else
			siftup(A, i);
	}
	return 0;
}

int insert(vector<int> A, int val) {
	A.resize(A.size() + 1);
	int i = A.size() - 1;
	A[i] = val;
	siftup(A, i);
	return 0;
}

int heapsort(vector<int> A) {
	heapify(A);
	for (int i = A.size() - 1; i > 0; i--) {
		int val = A[1];
		A[1] = A[i];
		A[i] = val;
		A.resize(A.size() - 1);
		siftdown(A, 1);
	}
	return 0;
}

int main() {
	//use heapvectorA for siftdown
	heapvectorA.push_back(22);
	heapvectorA.push_back(71);
	heapvectorA.push_back(24);
	heapvectorA.push_back(66);
	heapvectorA.push_back(27);
	heapvectorA.push_back(23);
	heapvectorA.push_back(8);
	heapvectorA.push_back(5);
	heapvectorA.push_back(32);
	heapvectorA.push_back(25);
	heapvectorA.push_back(18);
	cout << "heapvectorA before siftdown root:";
	for (int i = 0; i < heapvectorA.size(); i++) {
		cout << " " << heapvectorA[i];
	}
	cout << endl;
	siftdown(heapvectorA, 0);
	cout << "heapvectorA after siftdown root:";
	for (int i = 0; i < heapvectorA.size(); i++) {
		cout << " " << heapvectorA[i];
	}
	cout << endl;

	system("pause");
	return 0;
}
*/

int siftdown(int i) {
	int largerst = i;
	int left = 2 * i + 1;
	int right = left + 1;
	if (left<heapvectorA.size() && heapvectorA[left]>heapvectorA[largerst])
		largerst = left;
	if (right<heapvectorA.size() && heapvectorA[right]>heapvectorA[largerst])
		largerst = right;
	if (largerst != i) {
		int val = heapvectorA[i];
		heapvectorA[i] = heapvectorA[largerst];
		heapvectorA[largerst] = val;
		return siftdown(largerst);
	}
	else
		return 0;
}

int siftup(int i) {
	int val = heapvectorA[i];
	while (i > 0 && val > heapvectorA[(i - 1) / 2]) {
		heapvectorA[i] = heapvectorA[(i - 1) / 2];
		i = (i - 1) / 2;
		heapvectorA[i] = val;
	}
	return 0;
}

int heapify() {
	for (int i = (heapvectorA.size() - 1 - 1) / 2; i >= 0; i--) {
		siftdown(i);
	}
	return 0;
}

int heap_delete_root() {
	heapvectorA[0] = heapvectorA[heapvectorA.size() - 1];
	heapvectorA.resize(heapvectorA.size() - 1);
	siftdown(0);
	return 0;
}

int heapdelete(int i) {
	if (i == 0)
		heap_delete_root();
	else {
		heapvectorA[i] = heapvectorA[heapvectorA.size() - 1];
		heapvectorA.resize(heapvectorA.size() - 1);
		if (heapvectorA[(i - 1) / 2] >= heapvectorA[i])
			siftdown(i);
		else
			siftup(i);
	}
	return 0;
}

int insert(int val) {
	heapvectorA.resize(heapvectorA.size() + 1);
	int i = heapvectorA.size() - 1;
	heapvectorA[i] = val;
	siftup(i);
	return 0;
}

int heapsort() {
	heapify();
	heapsortvectorA.resize(heapvectorA.size());
	for (int i = heapvectorA.size() - 1; i > 0; i--) {
		int val = heapvectorA[0];
		heapvectorA[0] = heapvectorA[i];
		heapvectorA[i] = val;
		heapsortvectorA[i] = heapvectorA[i];
		heapvectorA.resize(heapvectorA.size() - 1);
		siftdown(0);
	}
	heapsortvectorA[0] = heapvectorA[0];
	return 0;
}

int heapapp() {
	//siftdown
	heapvectorA.push_back(22);
	heapvectorA.push_back(71);
	heapvectorA.push_back(24);
	heapvectorA.push_back(66);
	heapvectorA.push_back(27);
	heapvectorA.push_back(23);
	heapvectorA.push_back(8);
	heapvectorA.push_back(5);
	heapvectorA.push_back(32);
	heapvectorA.push_back(25);
	heapvectorA.push_back(18);
	cout << "heapvectorA before siftdown root:";
	for (int i = 0; i < heapvectorA.size(); i++) {
		cout << " " << heapvectorA[i];
	}
	cout << endl;
	siftdown(0);
	cout << "heapvectorA after siftdown root:";
	for (int i = 0; i < heapvectorA.size(); i++) {
		cout << " " << heapvectorA[i];
	}
	cout << endl;

	//heapify
	heapvectorA.resize(8);
	heapvectorA[0] = 3;
	heapvectorA[1] = 6;
	heapvectorA[2] = 10;
	heapvectorA[3] = 18;
	heapvectorA[4] = 8;
	heapvectorA[5] = 7;
	heapvectorA[6] = 25;
	heapvectorA[7] = 400;
	cout << "heapvectorA before heapify:";
	for (int i = 0; i < heapvectorA.size(); i++) {
		cout << " " << heapvectorA[i];
	}
	cout << endl;
	heapify();
	cout << "heapvectorA after heapify:";
	for (int i = 0; i < heapvectorA.size(); i++) {
		cout << " " << heapvectorA[i];
	}
	cout << endl;

	//delete root
	heap_delete_root();
	cout << "heapvectorA after delete root:";
	for (int i = 0; i < heapvectorA.size(); i++) {
		cout << " " << heapvectorA[i];
	}
	cout << endl;

	//delete node
	heapdelete(5);
	cout << "heapvectorA after delete node 5 = 7:";
	for (int i = 0; i < heapvectorA.size(); i++) {
		cout << " " << heapvectorA[i];
	}
	cout << endl;

	//insert
	insert(500);
	cout << "heapvectorA after insert the value 500:";
	for (int i = 0; i < heapvectorA.size(); i++) {
		cout << " " << heapvectorA[i];
	}
	cout << endl;

	//heapsort
	heapsort();
	cout << "heapvectorA after sort by heap sort will produce heapsortvectorA as:";
	for (int i = 0; i < heapsortvectorA.size(); i++) {
		cout << " " << heapsortvectorA[i];
	}
	cout << endl;

	system("pause");
	return 0;
}