#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	stack<int> myStack;
	while (N-- > 0)
	{
		string s;
		cin >> s;
		if (s == "push")
		{
			int num; 
			cin >> num;  // 버퍼에서 가져오는 법은?
			myStack.push(num);
		}
		else if (s == "pop")
		{
			if (myStack.empty())
			{
				cout << "-1\n";
				continue;
			}
			cout << myStack.top() << '\n';
			myStack.pop();
		}
		else if (s == "size")
		{
			cout << myStack.size() << '\n';
		}
		else if (s == "empty")
		{
			cout << myStack.empty() << '\n';
		}
		else if (s == "top")
		{
			if (myStack.empty())
			{
				cout << "-1\n";
				continue;
			}
			cout << myStack.top() << '\n';
		}
		else
		{
			return -1;
		}
	}
	return 0;
}