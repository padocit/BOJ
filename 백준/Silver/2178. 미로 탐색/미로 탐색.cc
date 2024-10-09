#include <bits/stdc++.h>

using namespace std;

int board[100][100];
int dis[100][100];
int N = 100, M = 100;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string row;
		cin >> row;
		for (int j = 0; j < M; j++)
			board[i][j] = row[j] - '0';
	}

	queue<pair<int, int>> Q;
	Q.push({ 0, 0 });
	dis[0][0] = 1;
	while (!Q.empty())
	{
		pair<int, int> cur = Q.front(); Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (!board[nx][ny] || dis[nx][ny]) continue;

			// movable block
			Q.push({ nx, ny });
			dis[nx][ny] = dis[cur.first][cur.second] + 1;
		}
	}
	cout << dis[N - 1][M - 1];
	return 0;
}