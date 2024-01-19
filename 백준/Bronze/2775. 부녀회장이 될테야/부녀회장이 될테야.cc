#include <iostream>

using namespace std;

class Apartment
{
public:
	struct room
	{
		int floor = 1;
		int num = 1;
	};

	Apartment(int k, int n)
	{
		r_.floor = k;
		r_.num = n;
	}

	int count() // How many ppl there?
	{
		if (r_.num == 1) return 1;

		return recur_count(r_.floor, r_.num);
	}

	int recur_count(int k, int n)
	{
		if (k == 0) return n;

		int sum = 0;
		for (int i = 1; i <= n; i++)
			sum += recur_count(k - 1, i);
		
		return sum;
	}

private:
	room r_;
};

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int k, n;
		cin >> k >> n;
		Apartment apart(k, n);
		cout << apart.count() << endl;
	}


	return 0;
}