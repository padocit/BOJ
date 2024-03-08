#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, M;
	cin >> N >> M;

	set<string> notHear;
	set<string> notHearSee;

	for (int i = 0; i < N; i++)
	{
		string name;
		cin >> name;
		notHear.insert(name);
	}
	for (int i = 0; i < M; i++)
	{
		string name;
		cin >> name;
		if (notHear.find(name) != notHear.end())
			notHearSee.insert(name);
	}

	cout << notHearSee.size() << '\n';
	for (string name : notHearSee)
		cout << name << '\n';

	return 0;
}