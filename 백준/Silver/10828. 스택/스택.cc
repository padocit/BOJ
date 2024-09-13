#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	stack<int> st;
	int N;
	cin >> N;
	while (N-- > 0)
	{
		string cmd;
		cin >> cmd;
		if (cmd == "push")
		{
			int num;
			cin >> num;
			st.push(num);
		}
		else if (cmd == "top")
		{
			if (st.empty()) cout << -1 << '\n';
			else cout << st.top() << '\n';
		}
		else if (cmd == "pop")
		{
			if (st.empty()) cout << -1 << '\n';
			else
			{
				cout << st.top() << '\n'; 
				st.pop();
			}
		}
		else if (cmd == "size") cout << st.size() << '\n';
		else if (cmd == "empty") cout << st.empty() << '\n';
	}

	return 0;
}