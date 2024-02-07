#include <iostream>
#include <vector>

using namespace std;

struct body
{
	int w = 0;
	int h = 0;

	bool operator< (body &x)
	{
		return w < x.w&& h < x.h;
	}
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	
	vector<body> v;
	while (N-- > 0)
	{
		body temp;
		cin >> temp.w >> temp.h;

		v.push_back(temp);
	}

	N = v.size();
	for (int i = 0; i < N; i++)
	{
		int count = 1;
		for (int j = 0; j < N; j++)
			if (v[i] < v[j]) count++;
		cout << count << ' ';
	}
	return 0;
}