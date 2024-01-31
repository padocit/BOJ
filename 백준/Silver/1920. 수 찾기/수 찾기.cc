#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> nums;
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		nums.push_back(n);
	}
	sort(nums.begin(), nums.end());

	int M;
	cin >> M;
	vector<int> target;
	for (int i = 0; i < M; i++)
	{
		int n;
		cin >> n;
		target.push_back(n);
	}

	for (auto i : target)
	{
		cout << binary_search(nums.begin(), nums.end(), i) << '\n';
	}

	return 0;
}