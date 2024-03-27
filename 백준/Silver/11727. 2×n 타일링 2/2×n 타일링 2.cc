#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int dp[1001];
	dp[0] = 1;
	dp[1] = 1;

	int n;
	cin >> n;

	for (int i = 2; i <= n; i++)
		dp[i] = (dp[i - 1] % 10007 + dp[i - 2] * 2 % 10007) % 10007;

	cout << dp[n];

	return 0;
}