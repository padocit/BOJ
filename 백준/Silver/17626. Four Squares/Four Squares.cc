#include <iostream>
#include <cmath>

using namespace std;

int dp[50001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int z = 1; z <= sqrt(50000); z++)
		dp[z*z] = 1;

	for (int i = 0; i <= 50001; i++)
		for (int k = 0; k*k <= i; k++)
		{
			if (dp[i] == 0)
				dp[i] = dp[k * k] + dp[i - k * k];
			else
				dp[i] = min(dp[i], dp[k * k] + dp[i - k * k]);
		}

	int n;
	cin >> n;
	cout << dp[n];
	return 0;
}