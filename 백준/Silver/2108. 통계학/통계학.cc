#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	vector<int> v;
	
	int count[8001] = { 0, };
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		v.push_back(n);
		sum += n;
		count[n + 4000]++;
	}

	sort(v.begin(), v.end());

	int freq_count = 0;
	int freq_value = 0;
	int T = 0; // 최빈값 두 번째로 작은 값 자물쇠
	for (int i = 0; i < 8001; i++)
	{
		if (freq_count < count[i])
		{
			freq_count = count[i];
			freq_value = i - 4000;
			T = 1;
		}
		else if (freq_count == count[i])
		{
			if (T > 1)
				continue;
			else 
			{
				freq_value = i - 4000;
				T++;
			}
		}

	}

	//산술평균
	cout << (int)round((double)sum / N) << '\n';
	
	//중앙값
	cout << v[N / 2] << '\n';

	//최빈값
	cout << freq_value << '\n';

	//범위
	cout << v[N - 1] - v[0] << '\n';

	return 0;
}