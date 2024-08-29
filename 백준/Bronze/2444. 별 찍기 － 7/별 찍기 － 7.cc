#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = N - i - 1; j > 0; j--)
			cout << ' ';
		for (int j = N - i - 1; j < N; j++)
			cout << '*';
		for (int j = N - i; j < N; j++)
			cout << '*';

		cout << '\n';
	}

	for (int i = 1; i < N; i++)
	{
		for (int j = i; j > 0; j--)
			cout << ' ';
		for (int j = N - i; j > 0; j--)
			cout << '*';
		for (int j = N - i - 1; j > 0; j--)
			cout << '*';

		cout << '\n';
	}

	return 0;
}