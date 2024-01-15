#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int k = 0; k < n; ++k)
	{
		string s;
		cin >> s;
		int sum = 0;
		int temp = 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (s.at(i) == 'O') ++temp;
			else temp = 0;
			sum += temp;
		}
		cout << sum << endl;
	}
	return 0;
}