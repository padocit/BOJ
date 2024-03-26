#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	int c = 2;
	while (N > 1)
	{
		if (N % c == 0)
		{
			cout << c << '\n';
			N /= c;
		}
		else
			c++;
	}

	return 0;
}