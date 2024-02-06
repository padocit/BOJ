#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	int sum = 0;
	sum += N / 5;
	sum += N / 25;
	sum += N / 125;

	cout << sum;

	return 0;
}
