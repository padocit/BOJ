#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int a[11] = { 0, };
	a[0] = 0;
	a[1] = 1;
	a[2] = 2;
	a[3] = 4;
	for (int i = 4; i < 11; i++)
		a[i] = a[i - 1] + a[i - 2] + a[i - 3];

	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int n;
		cin >> n;
		cout << a[n] << '\n';
	}

	return 0;
}