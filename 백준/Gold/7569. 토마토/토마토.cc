#include <bits/stdc++.h>

int board[100][100][100]; // -1 없음, 0 안익음, 1 익음
int H = 100, N = 100, M = 100; // 높이, 행, 열
int day[100][100][100];
int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };


using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// input
	queue<tuple<int, int, int>> BFSQ;
	cin >> M >> N >> H;
	for (int h = 0; h < H; h++)
	{
		for (int r = 0; r < N; r++)
		{
			for (int c = 0; c < M; c++)
			{
				int state;
				cin >> state;
				board[h][r][c] = state;
				if (state == 1) // 익은 토마토
					BFSQ.push({ h, r, c, });
			}
		}
	}

	// 이미 전부 익어있으면
	if (BFSQ.size() == H * N * M) 
	{
		std::cout << 0;
		return 0;
	}

	// min day
	int min_day = numeric_limits<int>::min();

	// BFS
	while (!BFSQ.empty())
	{
		int this_day = 0;
		tuple<int, int, int> cur = BFSQ.front(); BFSQ.pop();
		for (int i = 0; i < 6; i++)
		{
			int nz = get<0>(cur) + dz[i];
			int ny = get<1>(cur) + dy[i];
			int nx = get<2>(cur) + dx[i];
			if (nx < 0 || ny < 0 || nz < 0 || nx >= M || ny >= N || nz >= H) continue;
			if (board[nz][ny][nx] != 0 || day[nz][ny][nx] > 0) continue;
			BFSQ.push({ nz, ny, nx });
			this_day = day[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
			day[nz][ny][nx] = this_day;
			board[nz][ny][nx] = 1;
		}
		min_day = (this_day > min_day) ? this_day : min_day; // this_day가 더 크면 대입 (교체)
	}

	// 모두 익었는지 검사 + debug
	bool isDone = true;
	for (int h = 0; h < H; h++)
	{
		for (int r = 0; r < N; r++)
		{
			for (int c = 0; c < M; c++)
			{
				if (board[h][r][c] == 0)
					isDone = false; // 안익은게 있음
			}
		}
	}

	if (!isDone)
		std::cout << -1;
	else
		std::cout << min_day;

	return 0;
}