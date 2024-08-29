#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int num[5];
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> num[i];
		sum += num[i];
	}

	int avg = sum / 5;
	// Insertion sort
	for (int i = 1; i < 5; i++)
	{
		int j = i - 1;
		int value = num[i];
		while (j >= 0 && num[j] > value)
		{
			num[j + 1] = num[j];
			j--;
		}
		j++;
		num[j] = value;
	}

	// print
	cout << avg << '\n';
	cout << num[2] << '\n';
}