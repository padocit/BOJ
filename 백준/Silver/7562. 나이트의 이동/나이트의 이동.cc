#include <bits/stdc++.h>

using namespace std;

int D[300][300];
int L = 300;
int dx[8] = { -2, -1, 1, 2, -2, -1, 1, 2 };
int dy[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };

// x, y
// indexing: y, x (row, col)

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T-- > 0)
	{
		// 초기화
		for (int i = 0; i < 300; i++)
		{
			fill(D[i], D[i] + 300, 0);
		}

		// 입력: L, 시작위치, 목표위치 
		cin >> L;
		pair<int, int> start;
		pair<int, int> goal;
		cin >> start.first >> start.second;
		cin >> goal.first >> goal.second;
		
		// 예외: start == goal
		if (start == goal)
		{
			cout << 0 << '\n';
			continue;
		}

		// BFS -> step 기록
		queue<pair<int, int>> Q;
		Q.push(start);
		while(!Q.empty())
		{
			pair<int, int> cur = Q.front(); Q.pop();
			for (int i = 0; i < 8; i++)
			{
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];
				if (nx < 0 || ny < 0 || nx >= L || ny >= L) continue;
				if (D[ny][nx] > 0) continue;
				Q.push({ nx, ny }); 
				D[ny][nx] = D[cur.second][cur.first] + 1;
				// 조기 종료
				if (nx == goal.first && ny == goal.second) continue;
			}
		}

		// 출력: step
		cout << D[goal.second][goal.first] << '\n';
	}

	return 0;
}