#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	string s;
	cin >> s;

	int N = stoi(s);
	int size = s.length(); // 자리수

	for (int i = 0; i < N; i++)
	{
		int x = i;
		int sum = 0;
		for (int t = pow(10, size - 1); t > 1; t /= 10)
		{
			sum += x / t;
			x = x % t;
		}
		sum += x; // 1의 자리
		if (sum + i == N)
		{
			cout << i << endl;
			return 0;
		}
	}
	cout << '0' << endl;
	return 0;
}