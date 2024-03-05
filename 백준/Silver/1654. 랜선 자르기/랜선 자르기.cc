#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int K, N;
	cin >> K >> N;
	
	vector<int> lines;
	long long sum = 0;
	for (int i = 0; i < K; i++)
	{
		int length;
		cin >> length;
		lines.push_back(length);
		sum += length;
	}

	long long right = round((double)sum / N);
	long long left = 1;

	long long max_length = 0;
	while (left <= right)
	{
		long long mid = (left + right) / 2;

		int count = 0;
		for (int l : lines)
			count += l / mid;

		if (count < N)
			right = mid - 1;
		else if (count > N)
		{
			left = mid + 1;
			if (max_length == 0 || max_length < mid)
				max_length = mid;
		}
		else // count == mid
		{
			max_length = mid;
			left = mid + 1;
		}
	}

	cout << max_length << '\n';

	return 0;
}