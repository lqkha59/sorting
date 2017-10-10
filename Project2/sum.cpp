#include <iostream>
using namespace std;

int sum()
{
	int sum = 0;
	int n;
	cout << "Enter the last number n = " << endl;
	cin >> n;
	for (int i = 1; i <= n; i++)
		sum += i;
	cout << "The sum is: " << sum << endl;
	system("pause");
	return sum;
}