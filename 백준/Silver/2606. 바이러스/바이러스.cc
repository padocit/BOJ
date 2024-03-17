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

	bool checked[100] = { 0, }; // queue에 넣은 적 있는 숫자는 다시 넣지 않는다.
	queue<int> q;
	q.push(0); checked[0] = 1;
	int count = 0;
	while (!q.empty())
	{
		int a = q.front();
		q.pop();

		for (int b = 0; b < N; b++)  // b의 초기값 주의
			if (pc[a][b] == 1 && !checked[b])
			{
				q.push(b);
				count++;  // queue에 push 되는 숫자들은 모두 바이러스에 걸리는 셈이다.
				checked[b] = 1;
			}
	}
	cout << count << '\n';

	return 0;
}
