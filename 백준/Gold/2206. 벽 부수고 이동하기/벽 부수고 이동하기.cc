#include <bits/stdc++.h>

int board[1000][1000];
int D[1000][1000][2]; // 0: 벽안뚫음 1: 벽뚫음
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string row;
		cin >> row;
		for (int j = 0; j < M; j++)
			board[i][j] = row[j] - '0';
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			D[i][j][0] = -1;
			D[i][j][1] = -1;
		}

	// BFS
	/*
	1. 벽을 안뚫고 여기까지옴 + 이번에도 벽 안뚫음
	2. 벽을 안뚫고 여기까지옴 + 이번에 벽 뚫음    => 벽 만난 케이스
	3. 벽 뚫고 여기까지옴 + 이번에 벽 안뚫음
	*/
	queue<pair<int, int>> Q;
	Q.push({ 0, 0 });
	D[0][0][0] = 1;
	while (!Q.empty())
	{
		pair<int, int> cur = Q.front(); Q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (board[nx][ny] == 1) // 벽을 만났다.
			{
				if (D[cur.first][cur.second][0] > -1) // case2
				{
					//cout << "이 벽 뚫음: " << nx << ' ' << ny << endl;
					Q.push({ nx, ny });
					D[nx][ny][1] = D[cur.first][cur.second][0] + 1;
					//cout << D[nx][ny][1] << endl;
				}
				continue;
			}
			// case1
			if (D[nx][ny][0] == -1 && D[cur.first][cur.second][0] > -1)
			{
				//cout << "벽 안뚫고 지나옴: " << nx << ' ' << ny << endl;
				Q.push({ nx, ny });
				D[nx][ny][0] = D[cur.first][cur.second][0] + 1;
				//cout << D[nx][ny][0] << endl;
			}
			// case3
			if (D[nx][ny][1] == -1 && D[cur.first][cur.second][1] > -1)
			{
				//cout << "벽 뚫고 지나옴: " << nx << ' ' << ny << endl;
				Q.push({ nx, ny });
				D[nx][ny][1] = D[cur.first][cur.second][1] + 1;
				//cout << D[nx][ny][1] << endl;
			}
		}
	}
	int dis0 = D[N - 1][M - 1][0];
	int dis1 = D[N - 1][M - 1][1];

	if (dis0 == -1 && dis1 == -1) cout << -1;
	else if (dis0 == -1) cout << dis1;
	else if (dis1 == -1) cout << dis0;
	else cout << ((dis0 < dis1) ? dis0 : dis1);

	return 0;
}