#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int X;
	cin >> X;

	int k = 0;
	int a = 1;
	int b = 1;
	for (int n = 1; k < X; n++)
	{
		if (n % 2) // 홀수
		{
			for (int i = n; i > 0; i--)
			{
				k++;
				a = i;
				b = n + 1 - a;
				if (k == X)
				{
					cout << a << '/' << b;
					return 0;
				}
			}
		}
		else
		{
			for (int i = 1; i <= n; i++)
			{
				k++;
				a = i;
				b = n + 1 - a;
				if (k == X)
				{
					cout << a << '/' << b;
					return 0;
				}
			}
		}
	}
	return 0;
}