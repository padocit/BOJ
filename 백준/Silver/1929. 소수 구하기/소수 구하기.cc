#include <iostream>
#include <map>

using namespace std;

class Eratos
{
public:
	Eratos()
	{
		cin >> M >> N;
		for (int i = 2; i <= N; i++)
			prime[i] = true;
	}

	void Run()
	{
		for (int i = 2; i * i <= N; i++)
			if (prime[i])
				for (int j = i * i; j <= N; j += i)
					prime[j] = false;

	}

	void Print()
	{
		for (int i = M; i <= N; i++)
			if (prime[i]) cout << i << '\n';
	}

private:
	int M = 0;
	int N = 0;
	map<int, bool> prime;
};


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	Eratos test;
	test.Run();
	test.Print();

	return 0;
}