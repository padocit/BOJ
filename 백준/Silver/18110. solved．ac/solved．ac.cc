#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	if (n == 0)
	{
		cout << "0\n";
		return 0;
	}

	vector<int> v;
	for(int i = 0; i < n; i++)
	{
		int lv;
		cin >> lv;
		v.push_back(lv);
	}
	sort(v.begin(), v.end());
	int cut = round((double)n * 0.15);

	int sum = 0;
	for (int i = cut; i < n - cut; i++)
		sum += v[i];

	int avg = round((double)sum / (n - cut * 2));

	cout << avg << '\n';

	return 0;
}