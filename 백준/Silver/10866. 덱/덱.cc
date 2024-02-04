#include <iostream>
#include <string>
#include <cassert>
#include <cstring>

using namespace std;

// only int
class mydeque
{
public:
	mydeque()
	{
		q_ = new int[capacity_];
	}

	void resize()
	{
		int* temp = new int[capacity_ * 2];
		int start = front_ + 1;
		memcpy(temp + 1, q_ + start, (capacity_ - start) * sizeof(int));
		if (rear_ < front_)
			memcpy(temp + 1 + (capacity_ - start), q_, front_ * sizeof(int));
		
		delete[] q_;
		q_ = temp;
		rear_ = size();
		front_ = 0;
		capacity_ *= 2;
	}

	bool isEmpty()
	{
		return front_ == rear_;
	}

	bool isFull()
	{
		return (rear_ + 1) % capacity_ == front_;
	}

	int size()
	{
		if (front_ <= rear_)
			return rear_ - front_;
		else
			return capacity_ - (front_ - rear_);
	}

	void push_front(int item)
	{
		if (isFull()) resize();

		q_[front_] = item;
		front_ = (front_ - 1 + capacity_) % capacity_;
	}

	void push_back(int x)
	{
		if (isFull()) resize();

		rear_ = (rear_ + 1) % capacity_;
		q_[rear_] = x;
	}

	void pop_front()
	{
		if (isEmpty()) return;

		front_ = (front_ + 1) % capacity_;
	}

	void pop_back()
	{
		if (isEmpty()) return;

		rear_ = (rear_ - 1 + capacity_) % capacity_;
	}

	int front()
	{
		if (isEmpty()) return -1;

		return q_[(front_ + 1) % capacity_];
	}

	int back()
	{
		if (isEmpty()) return -1;

		return q_[rear_];
	}

private:
	int front_ = 0;
	int rear_ = 0;
	int capacity_ = 2;
	int* q_ = nullptr;
};

int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	mydeque q;
	int N;
	cin >> N;

	string op;
	while (N-- > 0)
	{
		cin >> op;
		if (op == "push_front")
		{
			int x;
			cin >> x;
			q.push_front(x);
		}
		else if (op == "push_back")
		{
			int x;
			cin >> x;
			q.push_back(x);
		}
		else if (op == "pop_front")
		{
			cout << q.front() << '\n';
			q.pop_front();
		}
		else if (op == "pop_back")
		{
			cout << q.back() << '\n';
			q.pop_back();
		}
		else if (op == "size")
		{
			cout << q.size() << '\n';
		}
		else if (op == "empty")
		{
			cout << q.isEmpty() << '\n';
		}
		else if (op == "front")
		{
			cout << q.front() << '\n';
		}
		else if (op == "back")
		{
			cout << q.back() << '\n';
		}
		else
		{
			return -1;
		}
	}

	return 0;
}