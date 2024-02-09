#include <iostream>

using namespace std;

void count(int N)
{
	int x = N / 5;
	int y = N / 3;
	int v;
	for (int i = x; i >= 0; i--)
		for (int j = y; j >= 0; j--)
		{
			v = 5 * i + 3 * j;
			if ((v == N))
			{
				cout << i + j;
				return;
			}
		}

	cout << "-1";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	count(N);

	return 0;
}