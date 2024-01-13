#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	cin >> s;

	int table[26] = { 0, };

	for (int i = 0; i < s.length(); i++)
	{
		if (s.at(i) < 'a') table[s.at(i) - 'A']++;
		else table[s.at(i) - 'a']++;
	}

	int max_i = 0;
	for (int i = 1; i < 26; i++)
		if (table[i] > table[max_i]) max_i = i;

	int n = 0;
	for (int i = 0; i < 26; i++)
		if (table[i] == table[max_i]) ++n;

	char c = max_i + 'A';

	if (n > 1) cout << '?';
	else cout << c;

	return 0;
}