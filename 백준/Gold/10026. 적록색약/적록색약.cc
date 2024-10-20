#include <bits/stdc++.h>

char board1[100][100]; // 적록색약X RGB
bool vis1[100][100];
char board2[100][100]; // 적록색약O GB
bool vis2[100][100];
int N = 100;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	string row;
	for (int r = 0; r < N; r++)
	{
		cin >> row;
		for (int c = 0; c < N; c++)
		{
			char rgb = row[c];
			board1[r][c] = rgb;
			board2[r][c] = (rgb == 'R') ? 'G' : rgb;
		}
	}
	// BFS 2번 (적록색약X , O)
	// count[3] 2개 따로 기록
	// Brute-force..

	queue<pair<int, int>> Q1;
	queue<pair<int, int>> Q2;
	int count1 = 0;
	int count2 = 0;

	// board1
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			if (vis1[r][c]) continue;

			char rgb = board1[r][c];
			count1++;
			Q1.push({ r, c });
			vis1[r][c] = true;
			while (!Q1.empty())
			{
				pair<int, int> cur = Q1.front(); Q1.pop();
				for (int i = 0; i < 4; i++)
				{
					int nx = cur.first + dx[i];
					int ny = cur.second + dy[i];
					if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
					if (board1[nx][ny] != rgb || vis1[nx][ny]) continue;
					Q1.push({ nx, ny });
					vis1[nx][ny] = true;
				}
			}
		}
	}
	// board2
	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			if (vis2[r][c]) continue;

			char rgb = board2[r][c];
			count2++;
			Q1.push({ r, c });
			vis2[r][c] = true;
			while (!Q1.empty())
			{
				pair<int, int> cur = Q1.front(); Q1.pop();
				for (int i = 0; i < 4; i++)
				{
					int nx = cur.first + dx[i];
					int ny = cur.second + dy[i];
					if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
					if (board2[nx][ny] != rgb || vis2[nx][ny]) continue;
					Q1.push({ nx, ny });
					vis2[nx][ny] = true;
				}
			}
		}
	}
	cout << count1 << ' ' << count2;
	return 0;
}