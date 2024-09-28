#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	stack<char> s;
	string str;
	cin >> str;
	int count = 0;
	int stick = 0;
	for (char c : str)
	{
		if (c == '(')
			stick++;
		else // )
		{
			stick--;
			if (s.top() == '(')
				count += stick;
			else  // )
				count += 1;
		}
		s.push(c);
	}
	cout << count;
	return 0;
}