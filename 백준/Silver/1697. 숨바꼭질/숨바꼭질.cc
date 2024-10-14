#include <bits/stdc++.h>

/*
가능한 경우?
1. 수빈 < 동생
2. 동생 < 수빈
3. 수빈 == 동생
*/

using namespace std;

int Pos[100001];
int T[100001];
int dx[3] = { -1, 1, 2 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K;
	cin >> N >> K;

	if (N == K) // 예외: 같은 경우
	{
		cout << 0;
		return 0;
	}

	queue<int> BFS;
	BFS.push(N);
	while (!BFS.empty())
	{
		int curPos = BFS.front(); BFS.pop();
		for (int i = 0; i < 3; i++)
		{
			int nextPos;
			if (dx[i] == 2)
				nextPos = curPos * 2;
			else
				nextPos = curPos + dx[i];

			if (nextPos < 0 || nextPos > 100000) continue;
			if (T[nextPos] > 0) continue; // 이미 방문
			BFS.push(nextPos);
			T[nextPos] = T[curPos] + 1;
		}
	}
	cout << T[K];
	return 0;
}