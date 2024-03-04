#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	// 스택에 push할 자연수.
	int x = 1;

	// 마지막 출력 메시지를 담는 큐
	queue<char> msg;

	// 실제로 테스트할 스택
	stack<int> t;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		while (x <= num)
		{
			t.push(x++);
			msg.push('+');
		}

		if (t.top() == num) // 목표 숫자가 스택 top 위에 있다면 팝
		{
			t.pop();
			msg.push('-');
		}
		else // 목표 숫자가 스택 top 보다 작으면 - 스택 구조상 불가능함
		{
			cout << "NO" << '\n';
			return 0;
		}
	}

	// 마지막 메시지 출력
	while (!msg.empty())
	{
		cout << msg.front() << '\n';
		msg.pop();
	}

	return 0;
}
