#include <iostream>

using namespace std;

int main(void)
{
	int sum = 0;
	int A;
	for (int i = 0; i < 5; i++)
	{
		cin >> A;
		sum += A;
	}
	cout << sum << endl;
	return 0;
}