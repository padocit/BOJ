#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	stack<pair<int, int>> ST; // value, index
	int N;
	cin >> N;
	vector<int> NGE(N);
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		while (!ST.empty() && ST.top().first < num)
		{
			NGE[ST.top().second] = num; // 수열 index
			ST.pop();
		}
		ST.push({num, i});
	}
	// 남은 원소 -> 오큰수 -1 일괄처리
	while (!ST.empty())
	{
		NGE[ST.top().second] = -1;
		ST.pop();
	}
	//print
	for (auto a : NGE)
		cout << a << ' ';
	return 0;
}