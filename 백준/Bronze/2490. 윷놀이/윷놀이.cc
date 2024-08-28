#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 3;
	while (t > 0)
	{
		int arr[4]; // 윷짝
		int check = 0; // 배 개수 초기화

		for (int i = 0; i < 4; i++)
		{
			cin >> arr[i];
			if (arr[i] == 0) check++; // 배 개수 카운트
		}

		switch (check)
		{
		case 0: // 모
			cout << "E\n";
			break;
		case 1: // 도
			cout << "A\n";
			break;
		case 2: // 개
			cout << "B\n";
			break;
		case 3: // 걸
			cout << "C\n";
			break;
		case 4: // 윷
			cout << "D\n";
			break;
		}

		t--;
	}
}