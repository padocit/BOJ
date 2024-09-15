#include <bits/stdc++.h>

using namespace std;

struct tower
{
	int idx;
	int value;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	stack<tower> st;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		while (!st.empty() && st.top().value < num)
			st.pop();

		if (st.empty())
			cout << 0 << ' ';
		else
			cout << st.top().idx << ' ';

		st.push({i + 1, num});
	}

	return 0;
}