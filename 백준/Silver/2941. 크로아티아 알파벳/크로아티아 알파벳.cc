#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string word;
	cin >> word;

	int count = 1;

	for (int i = 1; i < word.size(); i++)
	{
		char prev = word[i - 1];
		char curr = word[i];
		string temp = "";
		temp = temp + prev + curr;
		if (temp == "c=" || temp == "c-" || temp == "d-" || temp == "lj"
			|| temp == "nj" || temp == "s=")
		{
			continue;
		}
		else if (temp == "z=")
		{
			if (i > 1 && word[i - 2] == 'd') count--;
			continue;
		}
		else
		{
			count++;
		}
	}

	cout << count;

	return 0;
}