#include <iostream>

using namespace std;

int main()
{
	int T; // 테스트 횟수
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int H, W, N; 
		cin >> H >> W >> N;

		int Y = N % H; // 층수
		if (!Y) Y = H;

		int X = (N - 1) / H + 1; // 호수

		if (X < 10) cout << Y << '0' << X << endl;
		else cout << Y << X << endl;
	}
	return 0;
}