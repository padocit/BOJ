#include <iostream>
using namespace std;

long long factorial(int N, int x = 0)
{
	long long res = 1;
	if (!x) return 1;

	for (int i = 0; i < x; i++)
		res *= N--;
	
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int N, M;
		long long res = 0;
		cin >> N >> M; // mCn

		if (N > M / 2) N = M - N;

		res = factorial(M, N) / factorial(N, N);
		cout << res << '\n';
	}
	return 0;
}