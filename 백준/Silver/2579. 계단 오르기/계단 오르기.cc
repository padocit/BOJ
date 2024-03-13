#include <iostream>
#include <vector>

using namespace std;

class Stair
{
public:
	Stair()
	{
		cin >> N_;

		for (int i = 0; i < N_; i++)
		{
			int num;
			cin >> num;
			stairs_.push_back(num);
			count_.push_back(calc(i));
		}
	}

	int calc(int K)
	{
		if (K == 0) return stairs_[0];
		else if (K == 1) return stairs_[0] + stairs_[1];
		else if (K == 2) return max(stairs_[0], stairs_[1]) + stairs_[2];

		return max(count_[K - 2], count_[K - 3] + stairs_[K - 1]) + stairs_[K];
	}

	void print()
	{
		cout << count_[N_ - 1] << '\n';
	}


private:
	int N_;
	vector<int> stairs_;
	vector<int> count_; // DP (다이나믹 프로그래밍 = 동적 계획법)
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Stair T;
	T.print();

	return 0;
}