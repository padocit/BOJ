#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int count = 0;
	int i = 1;
	int x = 1;
	while (x < N) x += 6 * i++;
	count = count + i;
	cout << count << endl;
	return 0;
}