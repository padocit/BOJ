#include <bits/stdc++.h>

using namespace std;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	deque<int> d;
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) // init deque
		d.push_back(i + 1);
	
	int count = 0;
	while (M-- > 0) // main loop
	{
		// input: which num
		int num;
		cin >> num;

		// detect -> select 2 or 3 -> count
		int idx = 0;
		for (int i = 0; i < d.size(); i++)
			if (d[i] == num) idx = i;
		// 2
		if (idx - 0 < d.size() - idx)
		{
			while (d.front() != num)
			{
				int temp = d.front();
				d.pop_front();
				d.push_back(temp);
				count++;
			}
		}
		else // 3
		{
			while (d.front() != num)
			{
				int temp = d.back();
				d.pop_back();
				d.push_front(temp);
				count++;
			}
		}

		// pop_front
		d.pop_front();
	}

	// print
	cout << count;
	return 0;
}