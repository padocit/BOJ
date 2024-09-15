#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	stack<int> st;
	int N;
	cin >> N;
	size_t count = 0;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		while (!st.empty() && st.top() <= num)
			st.pop();
		
		count += st.size();
		st.push(num);
	}
	cout << count;
	return 0;
}