#include <iostream>
#include <string>

using namespace std;

int main()
{
	int table[26];
	for (int i = 0; i < 26; ++i)
		table[i] = -1;

	string word;
	cin >> word;
	for (int i = 0; i < word.length(); ++i)
	{
		int idx = word.at(i) - 'a';
		if (table[idx] == -1) table[idx] = i;
	}
    
	for (int i = 0; i < 26; ++i)
		cout << table[i] << ' ';
	return 0;
}