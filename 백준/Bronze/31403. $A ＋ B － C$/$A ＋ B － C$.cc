#include <string>
#include <iostream>

int main()
{
	using namespace std;

	int a, b, c;
	cin >> a >> b >> c;

	// 1. 수
	cout << a + b - c << endl;

	// 2. 문자열
	string AB = to_string(a) + to_string(b);
	int res = stoi(AB) - c;
	cout << res << endl;
}