#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	int r = 1;
	while (true)
	{
		r = a % b;
		if (r == 0) return b;
		a = b;
		b = r;
	}
	return -1;
}

int lcm(int a, int b)
{
	int n = gcd(a, b);
	return (a / n) * (b / n) * n;
}

int main()
{
	int a, b;
	cin >> a >> b;
	cout << gcd(a, b) << endl;
	cout << lcm(a, b) << endl;
	return 0;
}