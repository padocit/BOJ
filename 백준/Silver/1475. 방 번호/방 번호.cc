#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	string room = to_string(N);

	int num[10] = { 0, }; // 0~9 
	for (auto c : room) 
	{
		int i = c - '0';
		if (i == 9) i = 6; // 9 -> 6 한번에 저장
		num[i]++;
	}
	num[6] = round(num[6] / 2.0); // 1세트당 2개 but '홀수'개 필요하다면? -> 반올림

	int max = 0;
	for (auto i : num) 
		max = max > i ? max : i;

	cout << max;

	return 0;
}