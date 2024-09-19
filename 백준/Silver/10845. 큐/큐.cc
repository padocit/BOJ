#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	queue<int> q;
	unsigned int N;
	cin >> N;
	while (N-- > 0)
	{
		string cmd;
		cin >> cmd;
		if (cmd == "push")
		{
			int x;
			cin >> x;
			q.push(x);
		}
		else if (cmd == "pop")
		{
			if (q.empty())
				cout << -1 << '\n';
			else
			{
				int x = q.front();
				q.pop();
				cout << x << '\n';
			}
		}
		else if (cmd == "size")
		{
			cout << q.size() << '\n';
		}
		else if (cmd == "empty")
		{
			cout << q.empty() << '\n';
		}
		else if (cmd == "front")
		{
			if (q.empty())
				cout << -1 << '\n';
			else
				cout << q.front() << '\n';
		}
		else if (cmd == "back")
		{
			if (q.empty())
				cout << -1 << '\n';
			else
				cout << q.back() << '\n';
		}
	}

	return 0;
}