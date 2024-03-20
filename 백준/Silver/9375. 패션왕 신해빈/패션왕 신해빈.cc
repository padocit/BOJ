#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int n;
		cin >> n;

		map<string, int> closet;

		for (int i = 0; i < n; i++)
		{
			string name;
			string kind;
			cin >> name >> kind;

			if (closet.find(kind) != closet.end()) 
				closet[kind]++;
			else 
				closet[kind] = 1;
		}

		int count = 1;
		for (auto i : closet)
			count *= (i.second + 1);
		count--;

		cout << count << '\n';
	}
	return 0;
}