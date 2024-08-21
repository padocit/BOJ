#include <iostream>

using namespace std;

int main(void)
{
	int N;
	cin >> N;
	int* arr = new int[N];
	int max = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		if (max < arr[i]) max = arr[i];
	}
	cout << max << endl;

	delete[]arr;
	return 0;
}