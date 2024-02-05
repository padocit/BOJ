#include <iostream>
#include <map>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	map<int, int> m;

	int N;
	cin >> N;
	while (N-- > 0)
	{
		int num;
		cin >> num;
		if (m.count(num)) // 이미 존재하는 경우
			m[num]++;
		else
			m[num] = 1;
	}
	
	int M;
	cin >> M;
	while (M-- > 0)
	{
		int num;
		cin >> num;
		cout << m[num] << ' ';
	}

	return 0;
}