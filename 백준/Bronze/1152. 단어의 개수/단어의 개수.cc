#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	getline(cin, s);
	int sum = 0;

	int i;
	for (i = 0; i < s.length() - 1; ++i)
		if (s.at(i) != ' ' && s.at(i + 1) == ' ') ++sum;
	if (s.at(i) != ' ') ++sum;
	cout << sum;
	return 0;
}