#include <bits/stdc++.h>
#include <limits>

using namespace std;

int board[500][500];
int n = 500, m = 500;
int vis[500][500];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main()
{
	cin >> n >> m;

	for (int r = 0; r < n; r++)
		for (int c = 0; c < m; c++)
			cin >> board[r][c];

	int count = 0; // 그림 개수
	int maxS = 0; // 가장 넓은 넓이 

	queue<pair<int, int>> Q;
	for (int r = 0; r < n; r++)
		for (int c = 0; c < m; c++)
		{
			if (board[r][c] && !vis[r][c])
			{
				// BFS
				count += 1;
				int S = 1; // 이 그림의 넓이

				Q.push({ r, c });
				vis[r][c] = 1;
				while (!Q.empty())
				{
					pair<int, int> cur = Q.front(); Q.pop();
					for (int i = 0; i < 4; i++)
					{
						int nx = cur.first + dx[i]; // why?
						int ny = cur.second + dy[i];

						if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
						if (vis[nx][ny] || !board[nx][ny]) continue;
						
						vis[nx][ny] = 1;
						Q.push({ nx, ny });
						S++;
					}
				}
				maxS = S > maxS ? S : maxS;
			}
		}

	cout << count << '\n' << maxS;

	return 0;
}