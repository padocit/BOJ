#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int S = 0;
	int M;
	cin >> M;

	while (M--)
	{
		string op;
		int x;
		cin >> op;
		// 비트마스킹 - x는 (1<<x) 로 표현.
		if (op == "add")
		{
			cin >> x;
			--x;
			S |= (1 << x); // 1은 0001 2는 0010 3은 0100 ...
		}
		else if (op == "remove")
		{
			cin >> x;
			--x;
			S &= ~(1 << x);
		}
		else if (op == "check")
		{
			cin >> x;
			--x;
			if (S & (1 << x)) cout << "1\n";
			else cout << "0\n";
		}
		else if (op == "toggle")
		{
			cin >> x;
			--x;
			if (S & (1 << x)) S &= ~(1 << x);
			else S |= (1 << x);
		}
		else if (op == "all")
		{
			S |= (1 << 20) - 1; // 20개 켜짐
		}
		else if (op == "empty")
		{
			S = 0;
		}
	}

	return 0;
}