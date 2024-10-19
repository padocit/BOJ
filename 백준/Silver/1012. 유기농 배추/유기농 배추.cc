#include <bits/stdc++.h>

int board[50][50];
bool vis[50][50];
int N = 50, M = 50;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T, K;
	cin >> T;
	while (T-- > 0)
	{
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				board[i][j] = 0;
				vis[i][j] = 0;
			}
		}

		queue<pair<int, int>> temp;

		cin >> M >> N >> K;
		for (int i = 0; i < K; i++)
		{
			int X, Y;
			cin >> X >> Y;
			board[X][Y] = 1;
			temp.push({ X, Y });
		}

		int count = 0;
		while (!temp.empty())
		{
			pair<int, int> choo = temp.front(); temp.pop();
			if (vis[choo.first][choo.second]) continue; // BFS에서 이미 다녀간 위치

			// BFS
			count += 1;
			queue<pair<int, int>> Q;
			Q.push({ choo.first, choo.second });
			vis[choo.first][choo.second] = true;
			while (!Q.empty())
			{
				pair<int, int> curr = Q.front(); Q.pop();
				for (int i = 0; i < 4; i++)
				{
					int nx = curr.first + dx[i];
					int ny = curr.second + dy[i];
					if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
					if (!board[nx][ny] || vis[nx][ny]) continue;
					vis[nx][ny] = true;
					Q.push({ nx, ny });
				}
			}
		}
		cout << count << '\n';
	}
	return 0;
}