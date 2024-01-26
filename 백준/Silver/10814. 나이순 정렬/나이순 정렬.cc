#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct User
{
	int key = 0;
	string name;
};

bool cmp(const User& left, const User& right)
{
	return left.key < right.key;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	User* users = new User[N];
	for (int i = 0; i < N; i++)
		cin >> users[i].key >> users[i].name;

	stable_sort(users, users + N, cmp);

	for (int i = 0; i < N; i++)
		cout << users[i].key << ' ' << users[i].name << '\n';

	delete[] users;

	return 0;
}