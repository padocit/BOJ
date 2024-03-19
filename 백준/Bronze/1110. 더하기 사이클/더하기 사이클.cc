#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	if (N < 10) N *= 10;

	int temp = N;
	int count = 0;
	do
	{
		count++;
		int left = N % 10;
		int right = ((N / 10) + (N % 10)) % 10;
		N = left * 10 + right;
	} while (N != temp);

	cout << count;

	return 0;
}