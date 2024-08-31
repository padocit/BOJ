#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int stu[6][2] = { 0, };
	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		int S, Y;
		cin >> S >> Y;
		stu[Y - 1][S]++; // Y: 1~6 -> 0~5
	}

	int count = 0;
	for (int y = 0; y < 6; y++)
		for (int s = 0; s < 2; s++)
		{
			if (stu[y][s] % K == 0)
				count += stu[y][s] / K;
			else
				count += stu[y][s] / K + 1;
		}

	cout << count;

	return 0;
}