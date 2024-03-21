#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	long long p[101];
	p[1] = 1;
	p[2] = 1;
	p[3] = 1;
	p[4] = 2;
	p[5] = 2;
	for (int k = 6; k <= 100; k++)
		p[k] = p[k - 5] + p[k - 1];

	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int N;
		cin >> N;
		cout << p[N] << '\n';
	}

	return 0;
}