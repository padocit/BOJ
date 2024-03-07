#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, K;
	cin >> N >> K;

	vector<int> coins;
	for (int i = 0; i < N; i++)
	{
		int A;
		cin >> A;
		coins.push_back(A);
	}

	int sum = 0;
	for (int i = N - 1; i >= 0; i--)
	{
		int A = coins[i];
		if (A > K) continue;

		sum += K / A;
		K %= A;
	}

	cout << sum;

	return 0;
}