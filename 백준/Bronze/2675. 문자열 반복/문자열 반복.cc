#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int n;
		cin >> n;
		cin >> s;
		for (int j = 0; j < s.length(); j++)
			for (int k = 0; k < n; ++k)
				cout << s.at(j);
		cout << endl;
	}
	return 0;
}