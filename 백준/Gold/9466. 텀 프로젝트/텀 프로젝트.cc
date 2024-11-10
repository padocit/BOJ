#include <bits/stdc++.h>

using namespace std;

int MAT[100001];
int state[100001]; // step
int n;

constexpr int NOT_VISITED = 0;
constexpr int CYCLE_IN = -1;

void Update(int x) {
	int curr = x;
	while (true) {
		state[curr] = x; // x = this step
		curr = MAT[curr];
		// 이번 방문 cycle
		if (state[curr] == x) {
			while (state[curr] != CYCLE_IN) {
				state[curr] = CYCLE_IN;
				curr = MAT[curr];
			}
			return;
		}
		else if (state[curr] != NOT_VISITED) // 이전 방문 cycle
			return;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) // main loop
	{
		// init
		cin >> n;
		for (int i = 1; i <= n; i++) {
			state[i] = NOT_VISITED;
			cin >> MAT[i];
		}

		// Algorithm
		for (int i = 1; i <= n; i++) {
			if (state[i] == NOT_VISITED) Update(i);
		}
		
		// Count
		int count = 0;
		for (int i = 1; i <= n; i++) {
			if (state[i] != CYCLE_IN) count++;
		}
		cout << count << '\n';	
	}

	return 0;
}
