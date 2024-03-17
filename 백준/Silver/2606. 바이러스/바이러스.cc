#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	bool pc[100][100] = { 0, }; // 0~99

	int N;
	cin >> N;

	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int a, b;
		cin >> a >> b;
		pc[a - 1][b - 1] = 1;
		pc[b - 1][a - 1] = 1;
	}

	bool checked[100] = { 0, };
	queue<int> q;
	q.push(0);
	checked[0] = 1;
	int count = 0;
	while (!q.empty())
	{
		int a = q.front();
		q.pop();

		for (int b = 0; b < N; b++)
			if (pc[a][b] == 1 && !checked[b])
			{
				q.push(b);
				count++;
				checked[b] = 1;
			}
	}
	cout << count << '\n';

	return 0;
}