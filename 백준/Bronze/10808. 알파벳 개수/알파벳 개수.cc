#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int count[26] = { 0, }; // 알파벳 26개
	
	string S;
	cin >> S;
	
	for (int i = 0; i < S.length(); i++)
		count[S[i] - 'a'] += 1;

	for (int i = 0; i < 26; i++)
		cout << count[i] << ' ';

	return 0;
}