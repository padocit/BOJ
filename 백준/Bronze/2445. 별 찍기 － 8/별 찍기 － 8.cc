#include <bits/stdc++.h>

using namespace std;

void PrintRow(int N, int i)
{
	int row = i - 1;
	for (int j = row; j >= 0; j--)
		cout << '*';
	for (int j = N - row - 1; j > 0; j--)
		cout << ' ';
	for (int j = N - row - 1; j > 0; j--)
		cout << ' ';
	for (int j = row; j >= 0; j--)
		cout << '*';

}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) // 1 ~ N
	{
		PrintRow(N, i); // print '*' i times
		cout << '\n';
	}

	for (int i = N - 1; i > 0; i--) // N-1 ~ 1
	{
		PrintRow(N, i);
		cout << '\n';
	}

	return 0;
}