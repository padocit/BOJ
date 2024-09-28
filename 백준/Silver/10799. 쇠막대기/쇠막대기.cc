#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	stack<char> s;
	string str;
	cin >> str;
	int count = 0;
	int stick = 0; // 막대
	for (char c : str)
	{
		if (c == '(')
			stick++;
		else
		{
			// 레이저인 경우: 이전 단계에 막대로 착각했으므로 stick--
			// 막대 끝인 경우: 막대 하나가 끝났으므로 stick--
			stick--;
			if (s.top() == '(')
				count += stick; // 레이저가 지나가면 현재 막대의 수만큼 생겨남
			else 
				count += 1; // 막대가 끝나면 해당 막대의 끝동이 정의됨
		}
		s.push(c); // '레이저' or '막대 끝'을 판단하기 위해 모두 push => pop은 없음
	}
	cout << count;
	return 0;
}

// 1. stack을 쓰고, '레이저'인지 '막대 끝'인지 구별하기 위한 방법으로 'stick' 변수 대신 string 인덱싱을 사용할수도 있음.
// 2. stack을 안쓰고, 'stick' 변수만 이용하는 방법도 있음. (str 순회만 하면 가능)
