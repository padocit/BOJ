#include <bits/stdc++.h>

char board[1000][1000];
int R = 1000, C = 1000;
int fireday[1000][1000];
int exitday[1000][1000];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main()
{
	using namespace std;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> R >> C;

	queue<pair<int, int>> traceJ;
	queue<pair<int, int>> traceF;
	for (int i = 0; i < R; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < C; j++)
		{
			board[i][j] = s[j];
			if (s[j] == 'J') traceJ.push({ i, j });
			else if (s[j] == 'F') traceF.push({ i, j });
		}
	}

	while (!traceF.empty())
	{
		pair<int, int> curr = traceF.front(); traceF.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = curr.first + dx[i];
			int ny = curr.second + dy[i];
			if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
			if (board[nx][ny] == '#' || board[nx][ny] == 'F' || fireday[nx][ny] > 0) continue;
			traceF.push({ nx, ny });
			fireday[nx][ny] = fireday[curr.first][curr.second] + 1;
		}
	}

	//debug
	//for (int i = 0; i < R; i++)
	//{
	//	for (int j = 0; j < C; j++)
	//		cout << fireday[i][j];
	//	cout << endl;
	//}
	//cout << endl;

	while (!traceJ.empty())
	{
		pair<int, int> curr = traceJ.front(); traceJ.pop();
		int currday = exitday[curr.first][curr.second];
		// 탈출성공
		if (curr.first == 0 || curr.first == R - 1 || curr.second == 0 || curr.second == C - 1)
		{
			cout << currday + 1; // 하나 더 가야 비로소 탈출
			return 0;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = curr.first + dx[i];
			int ny = curr.second + dy[i];
			if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
			if (board[nx][ny] != '.' || exitday[nx][ny] > 0) continue;
			if (fireday[nx][ny] > 0 && currday + 1 >= fireday[nx][ny]) continue;
			traceJ.push({ nx,ny });
			exitday[nx][ny] = currday + 1;
		}
	}

	cout << "IMPOSSIBLE";
	return 0;
}