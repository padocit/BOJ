#include <bits/stdc++.h>

int board[305][305];
int delta[305][305]; // 녹는 속도
bool vis[305][305];
int N, M;
int d_row[4] = { 1, -1, 0, 0 };
int d_col[4] = { 0, 0, 1, -1 };

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int r = 0; r < N; r++)
		for (int c = 0; c < M; c++)
			cin >> board[r][c];

	int year = 0;
	while (true) {
		// 초기화 & 다 녹았는지 검사
		bool isMelt = true;
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < M; c++) {
				vis[r][c] = false;
				delta[r][c] = 0;
				if (board[r][c] > 0) isMelt = false;
			}
		}
		if (isMelt) {
			cout << 0; // 다 녹았으면 0 출력
			return 0;
		}
		// component 검사 BFS & 녹는 속도 업데이트
		int count = 0;
		queue<pair<int, int>> BFSQ;
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < M; c++) {
				if (board[r][c] == 0 || vis[r][c]) continue;
				count++;
				BFSQ.push({ r,c });
				vis[r][c] = true;
				while (!BFSQ.empty()) {
					pair<int, int> cur = BFSQ.front(); BFSQ.pop();
					for (int i = 0; i < 4; i++) {
						int nr = cur.first + d_row[i];
						int nc = cur.second + d_col[i];
						if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
						if (board[nr][nc] == 0) delta[cur.first][cur.second]++;
						if (board[nr][nc] == 0 || vis[nr][nc]) continue;
						BFSQ.push({ nr,nc });
						vis[nr][nc] = true;
					}
				}
			}
		}
		if (count > 1) { // divided
			cout << year;
			return 0;
		}
		// 시간 보내서 녹이기
		year++;
		for (int r = 0; r < N; r++) 
			for (int c = 0; c < M; c++) 
				board[r][c] = max(board[r][c] - delta[r][c], 0);
	}

	return 0;
}
