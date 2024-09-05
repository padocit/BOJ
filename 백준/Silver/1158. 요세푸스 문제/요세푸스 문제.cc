#include <bits/stdc++.h>
#include <list>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	list<int> Y;
	for (int i = 0; i < N; i++)
		Y.push_back(i + 1);
	
	auto cur = Y.begin();
	cout << '<';
	bool isFirst = true;
	while (!Y.empty())
	{
		if (!isFirst) cout << ", ";
		for (int k = 1; k < K; k++)
		{
			if (cur == Y.end()) cur = Y.begin();
			cur++;
		}
		if (cur == Y.end()) cur = Y.begin();
		cout << *cur;
		cur = Y.erase(cur);
		isFirst = false;
	}
	cout << '>';
	return 0;
}