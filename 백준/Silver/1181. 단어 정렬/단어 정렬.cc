#include <iostream>
#include <set>

using namespace std;

struct Myless
{
	bool operator() (const string &left, const string &right) const
	{
		if (left.length() == right.length())
			return left < right;
		else
			return left.length() < right.length();
	}
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	set<string, Myless> myset;
	string temp;

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		myset.insert(temp);
	}

	for (auto str : myset)
		cout << str << '\n';

	/*
	for (set<string>::iterator iter = myset.begin();
		iter != myset.end(); iter++)
		cout << *iter << '\n';
	*/

	return 0;
}