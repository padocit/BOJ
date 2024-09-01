#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	while (N-- > 0) // Test case
	{
		int count[26] = { 0, }; // 0~25

		string src;
		string dst;
		bool isFailed = false;

		cin >> src >> dst; // only lower-case

		if (src.size() != dst.size())
		{
			cout << "Impossible\n";
			continue;
		}

		for (auto c : src)
			count[c - 'a']++;
		for (auto c : dst)
		{
			count[c - 'a']--;

			if (count[c - 'a'] < 0)
			{
				isFailed = true;
				break;
			}
		}

		if (isFailed)
			cout << "Impossible\n";
		else
			cout << "Possible\n";
	}
	return 0;
}