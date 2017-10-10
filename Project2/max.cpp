#include <iostream>
using namespace std;

int max()
{
	int A[10] = { 10, 2, 6, 51, 73, 92, 2, 5, 5, 78 };
	int max = A[0];
	for (int i = 1; i < 10; i++)
		if (A[i] > max)
			max = A[i];
	cout << max << endl;
	system("pause");
	return max;
}