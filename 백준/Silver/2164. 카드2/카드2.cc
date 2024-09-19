#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	queue<int> q;
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
		q.push(i);

	while (q.size() > 1)
	{
		q.pop();
		int card = q.front();
		q.pop();
		q.push(card);
	}
	cout << q.front();
	return 0;
}