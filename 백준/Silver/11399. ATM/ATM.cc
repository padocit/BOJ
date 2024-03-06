#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	vector<int> P;
	for (int i = 0; i < N; i++)
	{
		int p;
		cin >> p;
		P.push_back(p);
	}

	sort(P.begin(), P.end());
	
	int sum = 0;
	for (int i = 0; i < P.size(); i++)
	{
		int sum_i = 0;
		for (int j = 0; j < i + 1; j++)
			sum_i += P[j];
		sum += sum_i;
	}
	
	cout << sum;


	return 0;
}