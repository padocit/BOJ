#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	vector<int> h;
	int sum = 0;
	for (int i = 0; i < 9; i++)
	{
		int height;
		cin >> height;
		h.push_back(height);
		sum += height;
	}

	int a, b;
	for (int i = 0; i < 9; i++)
		for (int j = i + 1; j < 9; j++)
			if (sum - h[i] - h[j] == 100)
			{
				h.erase(h.begin() + j);
				h.erase(h.begin() + i);
				i = j = 10;
			}
	
	sort(h.begin(), h.end());

	for (auto i : h)
		cout << i << '\n';
	
	return 0;
}