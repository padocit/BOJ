#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int num[7];
	int sum = 0;
	int min = 100;

	for (int i = 0; i < 7; i++)
	{
		cin >> num[i];
		if (num[i] % 2 == 1)
		{
			sum += num[i];
			min = min < num[i] ? min : num[i];
		}
	}

	if (sum == 0)
		cout << -1 << '\n';
	else
	{
		cout << sum << '\n';
		cout << min;
	}
}