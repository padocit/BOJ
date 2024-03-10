#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, M;
	cin >> N >> M;

	map<string, string> pw_dict;

	for (int i = 0; i < N; i++)
	{
		string site, pw;
		cin >> site >> pw;
		pw_dict[site] = pw;
	}

	for (int i = 0; i < M; i++)
	{
		string site;
		cin >> site;
		cout << pw_dict[site] << '\n';
	}

	return 0;
}