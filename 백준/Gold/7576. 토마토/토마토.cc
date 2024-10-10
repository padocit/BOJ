#include <bits/stdc++.h>

using namespace std;

int board[1000][1000]; // -1, 0, 1 -> vis 대신
int D[1000][1000]; // 거리 정보
int N = 1000, M = 1000;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// input
	cin >> M >> N;
	for (int r = 0; r < N; r++)
		for (int c = 0; c < M; c++)
			cin >> board[r][c];

	// 시작 지점 저장 (익은 토마토 = 1)
	queue<pair<int, int>> BFSQ; 
	for (int r = 0; r < N; r++)
		for (int c = 0; c < M; c++)
			if (board[r][c] == 1)
				BFSQ.push({ r, c });

	// 토마토 모두 익어있으면 0 출력
	if (BFSQ.size() == M * N)
	{
		cout << 0;
		return 0;
	}

	while (!BFSQ.empty())
	{
		pair<int, int> curr = BFSQ.front(); BFSQ.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = curr.first + dx[i];
			int ny = curr.second + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (board[nx][ny] != 0) continue;
			BFSQ.push({ nx, ny });
			D[nx][ny] = D[curr.first][curr.second] + 1;
			board[nx][ny] = 1;
		}
		//debug
		/*cout << endl;
		for (int r = 0; r < N; r++)
		{
			for (int c = 0; c < M; c++)
				cout << board[r][c] << ' ';
			cout << endl;
		}*/
	}
	
	int min_d = 0;
	for (int r = 0; r < N; r++)
		for (int c = 0; c < M; c++)
		{
			if (board[r][c] == 0) // 토마토 0 남아있으면 -1 출력
			{
				cout << -1;
				return 0;
			}
			else // 최소 날짜 계산
			{
				min_d = min_d >= D[r][c] ? min_d : D[r][c];
			}
		}

	cout << min_d;


	return 0;
}