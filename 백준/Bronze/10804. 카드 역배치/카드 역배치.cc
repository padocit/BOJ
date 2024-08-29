#include <bits/stdc++.h>

using namespace std;

void Print(vector<int>& num)
{
	for (int i = 1; i < num.size(); i++)
		cout << num[i] << ' ';

	cout << '\n';
}

int main(void)
{
	vector<int> num(21);
	for (int i = 0; i < 21; i++)
		num[i] = i;

	//Print(num);

	int T = 10;
	while (T > 0)
	{
		int a, b;
		cin >> a >> b;

		std::reverse(num.begin() + a, num.begin() + b + 1);
		//Print(num);
		T--;
	}

	Print(num);

	return 0;
}