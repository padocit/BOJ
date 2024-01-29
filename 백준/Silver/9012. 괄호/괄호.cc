#include <iostream>
#include <stack>

using namespace std;

class VPS
{
public:
	VPS()
	{
		cin >> T_;
	}

	bool isVPS(string s)
	{
		stack<char> st;
		for (int i = 0; i < s.length(); i++)
		{
			char c = s.at(i);
			if (c == '(')
				st.push(c);
			else // c == ')'
			{
				if (st.empty())
					return false;
				else
					st.pop();
			}
		}
		if (!st.empty()) return false;
		return true;
	}

	void testVPS()
	{
		while (T_-- > 0)
		{
			string s;
			cin >> s;

			if (isVPS(s))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}

private:
	int T_;
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	VPS test;
	test.testVPS();

	return 0;
}