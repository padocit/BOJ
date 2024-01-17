#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int* arr = new int[N];
	int sum = 0;
	int M = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		sum += arr[i];
		if (M < arr[i]) M = arr[i];
	}
	double avg = double(sum) / M * 100 / N;
	cout << avg << endl;
	return 0;
}