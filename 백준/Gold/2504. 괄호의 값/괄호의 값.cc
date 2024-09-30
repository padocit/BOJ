#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	stack<char> s;
	string str;
	cin >> str;
	int value = 1;
	int sum = 0;
	for (int i = 0; i < str.size(); i++)
	{
		char c = str[i];
		// distributive law
		if (c == '(')
		{
			s.push(c);
			value *= 2;
		}
		else if (c == '[')
		{
			s.push(c);
			value *= 3;
		}
		else if (c == ')')
		{
			// exception
			if (s.empty() || s.top() != '(')
			{
				cout << 0;
				return 0;
			}
			// sum
			if (str[i - 1] == '(')
				sum += value;
			// kill
			s.pop();
			value /= 2;
		}
		else if (c == ']')
		{
			if (s.empty() || s.top() != '[')
			{
				cout << 0;
				return 0;
			}
			if (str[i - 1] == '[')
				sum += value;
			s.pop();
			value /= 3;
		}
	}
	if (!s.empty()) 
		cout << 0;
	else 
	{
		cout << sum;
	}
	return 0;
}