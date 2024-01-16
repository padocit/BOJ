#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int* num = new int[N];
	for (int i = 0; i < N; i++)
		cin >> num[i];
	
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		if (num[i] == 1) continue;
		else if (num[i] <= 3) ++count;
		else
		{
			int val = int(sqrt(num[i]));
			int j;
			for (j = 2; j < val + 1; ++j)
				if (num[i] % j == 0) break;
			if (j == val + 1) ++count;
		}
	}
	cout << count << endl;

	return 0;
}