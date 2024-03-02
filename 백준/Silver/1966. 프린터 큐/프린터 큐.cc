#include <iostream>
#include <queue>

using namespace std;

struct paper
{
	int index;
	int priority;

	bool operator < (const paper& op) const
	{
		return this->priority < op.priority;
	}
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		queue<paper> q;
		priority_queue<int> pq;

		int N, M;
		cin >> N >> M;

		for (int j = 0; j < N; j++)
		{
			paper p;
			p.index = j;
			cin >> p.priority;
			q.push(p);
			pq.push(p.priority);
		}

		int num = 1;
		while(!q.empty())
		{
			paper current = q.front();

			if (current.priority == pq.top()) // 젤 큰거라면
			{
				if (current.index == M)
				{
					cout << num << '\n';
					break;
				}
				else
				{
					q.pop();
					pq.pop();
					num++;
				}
			}
			else
			{
				q.pop();
				q.push(current);
			}
		}
	}


	return 0;
}