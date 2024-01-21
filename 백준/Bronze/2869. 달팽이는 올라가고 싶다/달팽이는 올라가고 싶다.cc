#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int A, B, V;
	cin >> A >> B >> V;

	if (V <= A) cout << 1 << endl;
	else
	{
		int res = ceil(double(V - A) / (A - B)) + 1;
		cout << res << endl;
	}

	return 0;
}