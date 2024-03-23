#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int C;
	cin >> C;

	for (int c = 0; c < C; c++)
	{
		int N;
		cin >> N;

		int* stu = new int[N];
		int sum = 0;
		for (int i = 0; i < N; i++)
		{
			int score;
			cin >> score;
			stu[i] = score;
			sum += score;
		}
		double avg = (double)sum / N;

		int count = 0;
		for (int i = 0; i < N; i++)
			if (stu[i] > (int)avg) 
				count++;
		double ratio = (double)count / N;
		ratio *= 100;
		cout << fixed;
		cout.precision(3);
		cout << ratio << "%\n";
	}

	return 0;
}