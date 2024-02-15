#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int A, B;
	cin >> A >> B;

	int arrA[3] = { A / 100, A % 100 / 10, A % 10 };
	int arrB[3] = { B / 100, B % 100 / 10, B % 10 };

	int newA = arrA[2] * 100 + arrA[1] * 10 + arrA[0];
	int newB = arrB[2] * 100 + arrB[1] * 10 + arrB[0];

	cout << max(newA, newB);

	return 0;
}