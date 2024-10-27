#include <bits/stdc++.h>

char board[1000][1000];
int w = 1000, h = 1000;
int timeFire[1000][1000];
int timeMove[1000][1000];
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T-- > 0)
	{
		// 초기화 및 입력
		for (int i = 0; i < 1000; i++)
		{
			for (int j = 0; j < 1000; j++)
			{
				board[i][j] = '#';
				timeFire[i][j] = -1;
				timeMove[i][j] = -1;
			}
		}
		queue<pair<int, int>> fireQ;
		queue<pair<int, int>> moveQ;
		cin >> w >> h;
		for (int r = 0; r < h; r++)
		{
			string row;
			cin >> row;
			for (int c = 0; c < w; c++)
			{
				char ch = row[c];
				board[r][c] = ch;
				if (ch == '*')
				{
					fireQ.push({ r, c });
					timeFire[r][c] = 0;
				}
				else if (ch == '@')
				{
					moveQ.push({ r, c });
					timeMove[r][c] = 0;
				}
			}
		}
		// BFS1: 불의 전파 시간 저장
		while (!fireQ.empty())
		{
			pair<int, int> cur = fireQ.front(); fireQ.pop();
			for (int i = 0; i < 4; i++)
			{
				int nr = cur.first + dr[i];
				int nc = cur.second + dc[i];
				if (nc < 0 || nr < 0 || nc >= w || nr >= h) continue;
				if (board[nr][nc] == '#' || board[nr][nc] == '*' || timeFire[nr][nc] > -1) continue;
				fireQ.push({ nr, nc });
				timeFire[nr][nc] = timeFire[cur.first][cur.second] + 1;
			}
		}
		// BFS2: 탈출 가능 여부 검사 (timeMove < timeFire)
		bool exited = false;
		while (!moveQ.empty())
		{
			pair<int, int> cur = moveQ.front(); moveQ.pop();
			for (int i = 0; i < 4; i++)
			{
				int nr = cur.first + dr[i];
				int nc = cur.second + dc[i];
				if (nr < 0 || nc < 0 || nr >= h || nc >= w) // 탈출 성공
				{
					cout << timeMove[cur.first][cur.second] + 1 << '\n';
					exited = true;
					break;
				}
				if (board[nr][nc] != '.' || timeMove[nr][nc] > -1) continue;
				if (timeFire[nr][nc] > -1 && timeFire[nr][nc] <= timeMove[cur.first][cur.second] + 1) continue;
				moveQ.push({ nr, nc });
				timeMove[nr][nc] = timeMove[cur.first][cur.second] + 1;
			}
			if (exited) break;
		}	
        // 탈출 실패
		if (!exited)
		{
			cout << "IMPOSSIBLE" << '\n';
		}
	}

	return 0;
}