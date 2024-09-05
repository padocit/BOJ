#include <bits/stdc++.h>
#include <list>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	while (T-- > 0)
	{
		list<char> pw;
		string log;
		cin >> log;
		auto cursor = pw.begin();
		for (char c : log)
		{
			if (c == '-')
			{
				if (cursor != pw.begin())
				{
					cursor = pw.erase(--cursor);
				}
			}
			else if (c == '<')
			{
				if (cursor != pw.begin()) cursor--;
			}
			else if (c == '>')
			{
				if (cursor != pw.end()) cursor++;
			}
			else
			{ 
				pw.insert(cursor, c);
			}
		}
		for (auto c : pw)
			cout << c;
		cout << '\n';
	}

	return 0;
}