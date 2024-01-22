#include <iostream>

using namespace std;

int biCoef(int n, int k)
{
	int num = 1; // 분자
	for (int i = 0; i < k; i++)
		num *= (n - i);
	
	int d = 1; // 분모
	for (int i = 0; i < k; i++)
		d *= (k - i);

	return num / d;
}

int main()
{
	int N, K;
	cin >> N >> K;

	int res = biCoef(N, K);
	cout << res << endl;

	return 0;
}