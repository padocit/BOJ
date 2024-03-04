#include <iostream>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	// 1~n 숫자 미리 큐에 저장
	queue<int> q;
	for (int i = 0; i < n; i++)
		q.push(i + 1);

	// 마지막 출력 메시지를 담은 덱
	deque<char> msg;

	// 실제로 테스트할 스택
	stack<int> t;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		if (t.empty() || t.top() < num) // 목표 숫자만큼 스택에 넣어야함
		{
			do 
			{
				t.push(q.front());
				q.pop();
				msg.push_back('+');
			} while (t.top() < num);
			t.pop();
			msg.push_back('-');
		}
		else if (t.top() == num) // 목표 숫자가 스택 top 위에 있다면 팝
		{
			t.pop();
			msg.push_back('-');
		}
		else // 목표 숫자가 스택 top 보다 작으면 - 스택 구조상 불가능함
		{
			msg.push_front('N');
		}
	}

	// 마지막 메시지 출력
	while (!msg.empty())
	{
		if (msg.front() == 'N')
		{
			cout << "NO" << '\n';
			return 0;
		}

		cout << msg.front() << '\n';
		msg.pop_front();
	}

	return 0;
}