#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	// ex. 영식:   10 + 10 * (시간 / 30)
	int N;
	cin >> N;

	int sumY = 0; // 영식
	int sumM = 0; // 민식
	for (int i = 0; i < N; i++)
	{
		int t;
		cin >> t;
		
		sumY += 10 + 10 * (t / 30);
		sumM += 15 + 15 * (t / 60);
	}

	if (sumY < sumM)
		cout << "Y " << sumY;
	else if (sumM < sumY)
		cout << "M " << sumM;
	else
		cout << "Y M " << sumY;

	return 0;
}