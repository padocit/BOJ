#include <bits/stdc++.h>

using namespace std;

void PrintRow(int N, int i)
{
	for (int j = N - i; j > 0; j--)
		cout << ' ';
	for (int j = i; j > 0; j--)
		cout << '*';
	for (int j = i - 1; j > 0; j--)
		cout << '*';
}

void Print(int N)
{
	for (int i = N; i > 0; i--)
	{
		PrintRow(N, i); // print one row
		cout << '\n';
	}

	for (int i = 2; i <= N; i++)
	{
		PrintRow(N, i);
		cout << '\n';
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int N;
	cin >> N;

	Print(N);

	return 0;
}