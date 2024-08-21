#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
	long long K, N;
	cin >> K >> N;

	// (X - K) * N >= X
	long long X;
	if (N == 1) X = -1;
	else
	{
		X = K * N / (N - 1);
		if (K * N % (N - 1) != 0) 
			X += 1;
	}
	cout << X << endl;
	return 0;
}