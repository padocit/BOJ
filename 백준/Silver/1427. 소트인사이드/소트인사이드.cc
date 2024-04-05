#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string N;
	cin >> N;

	vector<int> v;

	for (int i = 0; i < N.size(); i++)
		v.push_back(N[i] - '0');
	
	sort(v.begin(), v.end(), greater<>());

	for (auto i : v)
		cout << i;

	return 0;
}