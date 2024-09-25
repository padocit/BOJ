#include <bits/stdc++.h>

using namespace std;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T-- > 0) // main loop
	{
		// input cmd (func)
		string cmd;
		cin >> cmd;

		// input deque size
		int size;
		cin >> size;

		// input deque (init)
		deque<int> d;
		string init;
		cin >> init;
		string num = "";
		for (char c : init)
		{
			if (isdigit(c))
				num += c;
			else if (c == ',' || c == ']' && num != "")
			{
				d.push_back(stoi(num));
				num = "";
			}
		}

		// test
		bool isError = false;
		bool head = true;
		for (char c : cmd)
		{
			if (c == 'R')
				head = !head;
			else // D
			{
				if (d.empty()) // error
				{
					isError = true;
					break;
				}
				if (head)
					d.pop_front();
				else // tail
					d.pop_back();
			}
		}

		// print (detect error)
		if (isError) cout << "error\n";
		else
		{
			cout << '[';
			if (head)
			{
				for (int i = 0; i < d.size(); i++)
				{
					cout << d[i];
					if (i != d.size() - 1) cout << ',';
				}
			}
			else
			{
				for (int i = d.size() - 1; i >= 0; i--)
				{
					cout << d[i];
					if (i > 0) cout << ',';
				}
			}
			cout << "]\n";
		}
	}
	return 0;
}