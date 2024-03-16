#include <iostream>
#include <set>

using namespace std;

int dn(int n)
{
	int sum = n;
	sum += n / 1000; n %= 1000;
	sum += n / 100; n %= 100;
	sum += n / 10; n %= 10;
	sum += n;

	return sum;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	set<int> notselfnum;
	for (int i = 1; i <= 10000; i++)
		notselfnum.insert(dn(i));

	for (int i = 1; i <= 10000; i++)
	{
		if (notselfnum.find(i) == notselfnum.end())
			cout << i << '\n';
	}

	return 0;
}