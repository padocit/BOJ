#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	
	for (int i = N; i > 0; i--)
	{
		for (int j = i; j < N; j++)
			cout << ' ';
		for (int j = N - i; j < N; j++)
			cout << '*';

		cout << '\n';
	}

	return 0;
}