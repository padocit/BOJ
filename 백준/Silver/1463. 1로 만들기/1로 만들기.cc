#include <iostream>
#include <queue>

using namespace std;

int main()
{
	struct num
	{
		int level;
		int n;
	};

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	bool *checked = new bool[N + 1];
	for (int i = 0; i < N + 1; i++)
	{
		checked[i] = false;
	}

	queue<num> q;
	q.push({0, N});
	int lv = 0;
	while (!q.empty())
	{
		lv = q.front().level;
		N = q.front().n;
		q.pop();

		if (N == 1)
			break;

		if (N == 3 || N == 2)
		{
			lv = lv + 1;
			break;
		}

		if (N % 3 == 0 && !checked[N / 3])
		{
			checked[N / 3] = true;
			q.push({ lv + 1, N / 3 });
		}
		if (N % 2 == 0 && !checked[N / 2])
		{
			checked[N / 2] = true;
			q.push({ lv + 1, N / 2 });
		}
		if (!checked[N - 1])
		{
			checked[N - 1] = true;
			q.push({ lv + 1, N - 1 });
		}
	}
	cout << lv << '\n';

	return 0;
}