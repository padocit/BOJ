#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<bool> check(1000001, 0); // 0 ~ 1000000

	int n;
	cin >> n;
	vector<int> a;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		a.push_back(num);
		check[num] = true;
	}

	int x;
	int count = 0;
	cin >> x; // target
	for (auto i : a)
	{
		int j = x - i;
		if (j > 0 && j <= 1000000 && check[j] && i != j)
		{
			count++;
			check[i] = false;
		}
	}
	cout << count;

	return 0;
}