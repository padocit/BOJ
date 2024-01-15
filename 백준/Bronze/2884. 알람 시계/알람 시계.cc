// 버전1
#include <iostream>

using namespace std;

int main()
{
	int H, M;
	cin >> H >> M;

	if (M < 45)
	{
		M = M + 60 - 45;
		--H;
	}
	else M -= 45;

	if (H < 0) H = 23;

	cout << H << " " << M;
	return 0;
}

/*
버전2
int main()
{
	int H, M, total;
	cin >> H >> M;

	total = H * 60 + M - 45;
	if (total < 0) total = 60 * 24 + total;
	H = total / 60;
	M = total % 60;
	
	cout << H << " " << M;
	return 0;
}
*/
