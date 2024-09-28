#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	int count = 0;
	while (N-- > 0)
	{
		stack<char> s;
		string word;
		cin >> word;
		for (char c : word)
		{
			if (c == 'A')
			{
				if (s.empty() || s.top() != 'A')
					s.push(c);
				else
					s.pop();
			}
			else if (c == 'B')
			{
				if (s.empty() || s.top() != 'B')
					s.push(c);
				else
					s.pop();
			}
		}

		// count
		if (s.empty()) count++;
	}
	// print
	std::cout << count;

	return 0;
}