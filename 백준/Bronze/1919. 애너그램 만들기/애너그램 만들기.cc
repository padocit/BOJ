#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int count1[26] = { 0, };
	int count2[26] = { 0, };
	int totalCount = 0;

	string s1, s2;
	cin >> s1 >> s2;

	for (auto c : s1)
		count1[c - 'a']++;
	for (auto c : s2)
		count2[c - 'a']++;

	for (int i = 0; i < 26; i++)
		totalCount += max(count1[i], count2[i]) - min(count1[i], count2[i]);

	cout << totalCount;

	return 0;
}