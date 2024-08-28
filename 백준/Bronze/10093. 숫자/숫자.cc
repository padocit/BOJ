#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int num[2];
	cin >> num[0] >> num[1];

	if (num[0] == num[1])
	{
		cout << 0 << '\n';
	}
	else
	{
		if (num[0] > num[1]) swap(num[0], num[1]);

		cout << num[1] - num[0] - 1 << '\n';

		for (int i = num[0] + 1; i < num[1]; i++)
			cout << i << ' ';

	}
}