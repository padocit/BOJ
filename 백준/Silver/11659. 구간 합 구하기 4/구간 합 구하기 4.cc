#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, M;
	cin >> N >> M;
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		if (i == 0)
			arr[i] = num;
		else
			arr[i] = arr[i - 1] + num;
	}

	for (int t = 0; t < M; t++)
	{
		int i, j;
		cin >> i >> j;
		if (i == 1)
			cout << arr[j - 1] << '\n';
		else
			cout << arr[j - 1] - arr[i - 2] << '\n';
	}

	return 0;
}