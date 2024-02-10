#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int K;
	cin >> K;

	stack<int> st;
	while (K-- > 0)
	{
		int n;
		cin >> n;
		if (n == 0)
		{
			if (st.empty()) continue;
			st.pop();
		}
		else
		{
			st.push(n);
		}
	}

	int sum = 0;
	while(!st.empty())
	{
		sum += st.top();
		st.pop();
	}
	cout << sum;
	return 0;
}