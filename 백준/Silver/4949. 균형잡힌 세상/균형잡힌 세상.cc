#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	queue<string> q;
	while (true)
	{
		string s;
		getline(cin, s);
		if (s == ".") break;
		q.push(s);
	}
	
	while(!q.empty())
	{
		string s = q.front();
		q.pop();

		stack<char> st;
		char last = ' ';
		bool failed = false;
		for (int i = 0; i < s.length(); i++)
		{
			last = s.at(i);
			if (last == '(' || last == '[')
				st.push(last);
			
			if (last == ')')
			{
				if (!st.empty() && st.top() == '(') st.pop();
				else
				{
					failed = true;
					break;
				}
			}
			else if (last == ']')
			{
				if (!st.empty() && st.top() == '[') st.pop();
				else
				{
					failed = true;
					break;
				}
			}
		}
		if (st.empty() && last == '.' && !failed)
			cout << "yes\n";
		else
			cout << "no\n";
	}
	

	return 0;
}