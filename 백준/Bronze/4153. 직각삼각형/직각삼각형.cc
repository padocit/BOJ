#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int x, y, z;
	while (true)
	{
		cin >> x >> y >> z;
		if (!x && !y && !z) break;
		if (pow(x, 2) + pow(y, 2) == pow(z, 2) ||
			pow(x, 2) + pow(z, 2) == pow(y, 2) ||
			pow(y, 2) + pow(z, 2) == pow(x, 2))
			cout << "right" << endl;
		else
			cout << "wrong" << endl;
	}
	return 0;
}