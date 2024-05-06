#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	int z = int(sqrt(n));
	int A = int(sqrt(n) / 2);
	int count = 4;
	for (int a = z; a > A; a--) 
	{
		for (int b = a; b >= 0; b--)
			for (int c = b; c >= 0; c--)
				for (int d = c; d >= 0; d--)
				{
					//if (a * a + b * b + c * c + d * d == n)
					//{
					//	cout << "발견! (a,b,c,d) : " << a << ' '
					//		<< b << ' ' << c << ' ' << d << '\n';
					//}
					if (a * a == n) 
						count = min(count, 1);
					else if (a * a + b * b == n) 
						count = min(count, 2);
					else if (a * a + b * b + c * c == n) 
						count = min(count, 3);
					else if (a * a + b * b + c * c + d * d == n) 
						count = min(count, 4);
				}
	}
	cout << count;
	return 0;
}