#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	long long square[1001];

	int n;
	cin >> n; // 1~1000

	square[0] = 0;
	square[1] = 1;
	square[2] = 2;
	for (int k = 3; k <= n; k++)
		square[k] = (square[k - 1] % 10007 + square[k - 2] % 10007) % 10007;

	cout << square[n];
	return 0;
}