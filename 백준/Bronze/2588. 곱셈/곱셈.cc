#include <iostream>

using namespace std;

int main()
{
	int x, y;
	cin >> x >> y;
	
	int y1, y2, y3;
	y1 = y / 100;
	y2 = (y % 100) / 10;
	y3 = (y % 10);

	cout << x * y3 << '\n';
	cout << x * y2 << '\n';
	cout << x * y1 << '\n';
	cout << x * y;

	return 0;
}